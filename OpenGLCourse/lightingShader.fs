#version 330 core
in vec4 colour;
in vec3 FragPos;
in vec3 Normal;
in vec2 uv;


struct Material
{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct DirLight
{
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight
{
    vec4 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float kC;
    float kL;
    float kQ;
};
#define NR_POINT_LIGHTS 4

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];

uniform Material material;
out vec4 FragColour;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(-FragPos);

    vec3 result = CalcDirLight(dirLight, norm, viewDir);

    for (int i = 0; i < NR_POINT_LIGHTS; i++)
    {
        result += CalcPointLight(pointLights[i], norm, FragPos, viewDir);
    }

    FragColour = vec4(result, 1.0f);
   // FragColour = pow(vec4(result,1.0),vec4(1.0/2.2));
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(lightDir, normal), 0.0);
    
    vec3 refl = reflect(-lightDir, normal);
    float spec = pow(max(dot(refl, viewDir),0.0), 128 * material.shininess);

    vec3 ambient = light.ambient * vec3(texture(material.diffuse, uv));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, uv));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, uv));
    return (ambient + diffuse + specular);
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = light.position.xyz - FragPos;
    float d = length(lightDir);
    lightDir = normalize(lightDir);

    float diff = max(dot(lightDir, normal), 0.0);
    
    vec3 refl = reflect(-lightDir, normal);
    float spec = pow(max(dot(refl, viewDir),0.0), 128 * material.shininess);

    float attenuation = 1.0f / (light.kC + light.kL * d + light.kQ * d * d);

    vec3 ambient = light.ambient * vec3(texture(material.diffuse, uv));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, uv));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, uv));
    return (ambient + diffuse + specular) * attenuation;
}