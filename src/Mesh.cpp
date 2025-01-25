#include "Mesh.h"
#include <iostream>
#include "AppConfig.h"


Mesh::Mesh(const char* _name):VBO(0),VAO(0),EBO(0),m_scale(1),m_rotation(0)
{
	name = _name;
	AddVertex(glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),glm::vec2(1.0f,1.0f));
	AddVertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),glm::vec2(1.0f,0.0f));
	AddVertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f),glm::vec2(0.0f,0.0f));
	AddVertex(glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f));

	std::vector<float> vertexData;
	for (const Components::Vertex* v : m_vertices)
	{
		glm::vec3 vertices = v->position;
		glm::vec3 colors = v->vertexColors;
		glm::vec2 uvs = v->uvCoodinates;

		vertexData.push_back(vertices[0]);
		vertexData.push_back(vertices[1]);
		vertexData.push_back(vertices[2]);
		vertexData.push_back(colors[0]);
		vertexData.push_back(colors[1]);
		vertexData.push_back(colors[2]);
		vertexData.push_back(uvs[0]);
		vertexData.push_back(uvs[1]);
	}
	unsigned int indices[] = { 0,1,3,1,2,3 };

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), vertexData.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

void Mesh::AddVertex(const glm::vec3 vector,const glm::vec3 colors,const glm::vec2 uvCoords)
{
	Components::Vertex* v = new Components::Vertex();
	v->position = vector;
	v->vertexColors = colors;
	v->uvCoodinates = uvCoords;
	m_vertices.push_back(v);
}

void Mesh::Render()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture->ID);
	glUseProgram(m_shader->ID);
	glUniform1i(glGetUniformLocation(m_shader->ID, "ourTexture"), 0);
	
	SET_TRANSFORMATION_MATRIX();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Mesh::Update()
{
	float time = glfwGetTime();
	SetRotation(time);
	SetScale(glm::sin(time));
}

void Mesh::SET_TRANSFORMATION_MATRIX()
{
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	glm::mat4 viewMatrix = glm::mat4(1.0f);
	glm::mat4 projectionMatrix = glm::mat4(1.0f);
	//modelMatrix = glm::translate(modelMatrix, m_position);
	modelMatrix = glm::rotate(modelMatrix, m_rotation, glm::vec3(1.0, 0.0, 0.0));
	//modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 1, 1) * (m_scale));
	
	viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0, 0.0, -3.0));
	projectionMatrix = glm::perspective(glm::radians(Config::CAMERA::FOV),
		(float)Config::WINDOW::SCREEN_WIDTH /(float) Config::WINDOW::SCREEN_HEIGHT,
		Config::CAMERA::NEAR_CLIP_PLANE, 
		Config::CAMERA::FAR_CLIP_PLANE);

	unsigned int modelLocation = glGetUniformLocation(m_shader->ID, "model");
	unsigned int viewLocation = glGetUniformLocation(m_shader->ID, "view");
	unsigned int projectionLocation = glGetUniformLocation(m_shader->ID, "projection");

	glad_glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
	glad_glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glad_glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	delete m_shader;
}