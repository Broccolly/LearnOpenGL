#version 330 core
in vec4 colour;
in vec3 FragPos;
in vec3 Normal;
in vec2 uv;

uniform float time;

uniform vec3 lightColour;
uniform vec3 lightPos;

out vec4 FragColour;
void main()
{
    float ambientFactor = 0.1f;
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    vec3 ambient = ambientFactor * lightColour;
    vec3 diffuse = max(dot(norm, lightDir), 0.0f) * lightColour;


    vec3 result = (ambient + diffuse) * colour.xyz;
    FragColour = vec4(result,1.0f);
}
