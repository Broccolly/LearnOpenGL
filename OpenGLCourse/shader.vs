#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aCol;
layout (location = 3) in vec2 aUV;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
uniform mat3 normMat;


uniform float time;
out vec3 FragPos;
out vec3 colour;
out vec3 Normal;
out vec2 uv;

void main()
{
	gl_Position = proj * view * model * vec4(aPos, 1.0);
	FragPos = vec3(model * vec4(aPos, 1.0));
	Normal = normMat * aNormal;
	colour = aCol;
	uv.xy = aUV.xy;
}
