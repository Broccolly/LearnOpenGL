#version 330 core
in vec4 colour;
in vec2 uv;
uniform float time;
out vec4 FragColour;
void main()
{
    FragColour = colour;
    FragColour.x = (0.5 + 0.3*(cos(11.0*(uv.x + uv.y) + 2.0*time)));
    FragColour.y = (0.3 + 0.1*(cos(5.0*(uv.y) + 3.5*time)));
    FragColour.z = (0.5 + 0.3*(cos(7.3*(uv.x) + 3.6*time)));

}