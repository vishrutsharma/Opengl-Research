#version 330 core

out vec4 FragColor;
in vec2 uvCords;
in vec4 vertexColor;

uniform sampler2D ourTexture;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 ambientColor;

void main()
{
	FragColor = vec4(objectColor * lightColor,1.0) + vec4(ambientColor,1.0);
}