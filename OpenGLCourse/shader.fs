#version 330 core
in vec4 colour;
in vec2 uv;
uniform float time;

uniform sampler2D ourTexture0;
uniform sampler2D ourTexture1;

out vec4 FragColour;
void main()
{
    FragColour = mix(texture(ourTexture0, uv), texture(ourTexture1, uv), 0.2);
    FragColour = vec4(uv.x, uv.y, 0.0, 1.0);
}