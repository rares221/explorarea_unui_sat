#include "House.h"

House::House(const Transform& transform) :
	Object(transform),
	m_base(transform)
	//m_roof(transform),
	//m_windows(transform),
	//m_door(transform)

{
	// empty
}

void House::UpdateThenDraw(const Camera& camera)
{
	glCullFace(GL_FRONT);
	m_base.UpdateThenDraw(camera);
	//m_roof.UpdateThenDraw(camera);
	//m_windows.UpdateThenDraw(camera);
	//m_door.UpdateThenDraw(camera);

	glCullFace(GL_BACK);
	m_base.UpdateThenDraw(camera);
	//m_roof.UpdateThenDraw(camera);
	//m_windows.UpdateThenDraw(camera);
	//m_door.UpdateThenDraw(camera);
}

House::Base::Base(const Transform& transform) :
	Object(transform)
{
	shader = new Shader("./resources/shaders/basicShader");
	mesh = new Mesh("./resources/models/House/Hut_low.obj");
	texture = new Texture("./resources/textures/wood.jpg");
}

//House::Roof::Roof(const Transform& transform) :
//	Object(transform)
//{
//	shader = new Shader("./resources/shaders/basicShader");
//	mesh = new Mesh("./resources/models/Hangar/roof.obj");
//	texture = new Texture("./resources/textures/green_metal6.jpg");
//}
//
//House::Windows::Windows(const Transform& transform) :
//	Object(transform)
//{
//	shader = new Shader("./resources/shaders/basicShader");
//	mesh = new Mesh("./resources/models/Hangar/windows.obj");
//	texture = new Texture("./resources/textures/window.png");
//}
//
//House::Door::Door(const Transform& transform) :
//	Object(transform)
//{
//	shader = new Shader("./resources/shaders/basicShader");
//	mesh = new Mesh("./resources/models/Hangar/door.obj");
//	texture = new Texture("./resources/textures/door.jpg");
//}


