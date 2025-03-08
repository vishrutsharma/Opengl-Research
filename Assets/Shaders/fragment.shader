#version 330 core

out vec4 FragColor;
in vec3 Normals;
in vec3 FragPos;

uniform sampler2D ourTexture;
uniform vec3 lightPos;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 ambientColor;

void main()
{
	vec3 norm = normalize(Normals);
	vec3 lightDir = normalize(lightPos-FragPos);
	float dot = max(dot(norm,lightDir),0.0);
	vec3 diff = dot*lightColor;
	vec3 result = diff * objectColor;
	FragColor = vec4(result,1.0);
}