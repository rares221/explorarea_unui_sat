#include "Tree.h"

Tree::Tree(const Transform& transform) :
	Object(transform),
	m_tree(transform)
	//m_roof(transform),
	//m_windows(transform),
	//m_door(transform)

{
	// empty
}

void Tree::UpdateThenDraw(const Camera& camera)
{
	glCullFace(GL_FRONT);
	m_tree.UpdateThenDraw(camera);


	glCullFace(GL_BACK);
	m_tree.UpdateThenDraw(camera);

}

Tree::tree::tree(const Transform& transform) :
	Object(transform)
{
	shader = new Shader("./resources/shaders/basicShader");
	mesh = new Mesh("./resources/models/Trees/Tree.obj");
	texture = new Texture("./resources/textures/tree.jpg");
}

