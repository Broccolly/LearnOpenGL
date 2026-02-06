#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 aUV;

uniform mat4 mat;
uniform mat4 view;
uniform mat4 proj;

uniform float time;
out vec3 colour;
out vec2 uv;
void main()
{
	gl_Position = proj * view * mat * vec4(aPos, 1.0);
	colour = aCol;
	uv.xy = aUV.xy;
}