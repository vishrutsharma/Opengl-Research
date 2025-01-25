#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 uvs;

out vec4 vertexColor;
out vec2 uvCords;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position =  projection * view * model * vec4(aPos,1.0);
	vertexColor = vec4(vColor,1.0);
	uvCords = vec2(uvs.x,uvs.y);
}