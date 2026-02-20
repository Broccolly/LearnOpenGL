#version 330 core
in vec4 colour;
in vec3 FragPos;
in vec3 Normal;
in vec2 uv;

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light
{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;
out vec4 FragColour;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    vec3 viewDir = normalize(-FragPos);

    vec3 r = reflect(-lightDir, norm);
    float spec = pow(max(dot(r,viewDir),0.0),material.shininess*128.0);

    vec3 ambient = light.ambient * material.ambient;
    vec3 diffuse = light.diffuse * max(dot(norm, lightDir), 0.0) * material.diffuse;
    vec3 specular = light.specular * spec * material.specular;

    vec3 result = (ambient + diffuse + specular);
    FragColour = vec4(result,1.0);
}
