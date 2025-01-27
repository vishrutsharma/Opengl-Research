#version 330 core

out vec4 FragColor;
in vec2 uvCords;
in vec4 vertexColor;

uniform sampler2D ourTexture;

void main()
{
	FragColor = vertexColor;
	//FragColor = texture(ourTexture,uvCords);
}