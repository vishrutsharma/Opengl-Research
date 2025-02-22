#version 330 core

out vec4 FragColor;
in vec2 uvCords;
in vec4 vertexColor;

uniform sampler2D ourTexture;
uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
	FragColor = vec4(objectColor,1.0);
	//FragColor = vertexColor;
}