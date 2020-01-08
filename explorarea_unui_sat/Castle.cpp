#include "Castle.h"

Castle::Castle(const Transform& transform) :
	Object(transform),
	m_base(transform)


{
	// empty
}

void Castle::UpdateThenDraw(const Camera& camera)
{
	glCullFace(GL_FRONT);
	m_base.UpdateThenDraw(camera);


	glCullFace(GL_BACK);
	m_base.UpdateThenDraw(camera);

}

Castle::Base::Base(const Transform& transform) :
	Object(transform)
{
	shader = new Shader("./resources/shaders/basicShader");
	mesh = new Mesh("./resources/models/House/castel.obj");
	texture = new Texture("./resources/textures/textura.jfif");
}




