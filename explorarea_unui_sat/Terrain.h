#pragma once
#include <glm.hpp>

#include "Object.h"

class Terrain :public Object
{
public:
	Terrain();
	void Update(const Camera& camera) override;
	void Draw() const override;
};

inline Terrain::Terrain()
{
	// Build Mesh
	Vertex vertices[] = {
		Vertex(glm::vec3(-500.0f,0.0f,-500.0f),glm::vec2(-10.0f,-10.0f)),
		Vertex(glm::vec3(500.0f,0.0f,-500.0f),	glm::vec2(10.0f,-10.0f)),
		Vertex(glm::vec3(-500.0f,0.0f,500.0f),	glm::vec2(-10.0f,10.0f)),
		Vertex(glm::vec3(500.0f,0.0f,500.0f),	glm::vec2(10.0f,10.0f))
	};
	unsigned indices[] = { 2,1,0,
							1,2,3 };

	// Initialize Object
	mesh = new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	shader = new Shader("./resources/shaders/basicShader");
	texture = new Texture("./resources/textures/grass3.jpg");
}

inline void Terrain::Update(const Camera& camera)
{
	shader->Bind();
	shader->Update(transform, camera);
	texture->Bind(0);
}

inline void Terrain::Draw() const
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glCullFace(GL_FRONT);
	mesh->Draw();
	glCullFace(GL_BACK);
	mesh->Draw();
}
