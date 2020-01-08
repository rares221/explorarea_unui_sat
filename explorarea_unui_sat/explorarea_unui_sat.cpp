#include <GL/glew.h>
#include <chrono>
#include <iostream>
#include "Window.h"
#include "GeneralWindowData.h"
#include "Terrain.h"
//#include "Vegetation.h"
#include "Skybox.h"
#include"Castle.h"

//#include"Castle.h"


int main()
{
	// Start Time
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	// Display
	Window window(WindowData::SCR_WIDTH, WindowData::SCR_HEIGHT, "Explorare-sat-Bran");

	// Camera & Transform
	Camera camera(glm::vec3(0, 10, -100), 70.0f, static_cast<float>(WindowData::SCR_WIDTH) / WindowData::SCR_HEIGHT, 0.01f, 1000.0f);
	window.SetCamera(camera);

	// Objects Vector
	std::vector<Object*> objects;

	// Vegetation
	/*objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(15, 0, -21))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(17, 0, -22))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(7, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(-3, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(-7, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(10, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-8, 0, -25))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-5, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-10, 0, -24))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(0, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(20, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(23, 0, 0))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -10))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -10))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(21, 0, -10))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(22, 0, -12))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -16))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -7))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, 5))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, 10))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(-23, 0, -5))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(-23, 0, 10))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-23, 0, 3))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(-10, 0, 23))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(5, 0, 23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(-5, 0, 23))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(23, 0, -17))));

	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(170, 0, -8))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, 0))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, 2))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, -2))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, -1))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(170, 0, 0))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(170, 0, 10))));

	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, -9))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(130, 0, 2))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(125, 0, -1))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(130, 0, -5))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, 8))));

	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, 8))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, 8))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, 8))));*/

	// Terrain
	objects.push_back(new Terrain);

	//House
	//objects.push_back(new House(Transform(glm::vec3(300, 6, -200))));

	//objects.push_back(new House(Transform(glm::vec3(10, 6, -100))));


	objects.push_back(new Castle(Transform(glm::vec3(-900, -400, 80), glm::vec3(0), glm::vec3(50, 50, 50))));


	//Skybox
	Skybox skybox;


	// Load Time measure: ~1.8s, ~2.5s, ~22.5s
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Load Time = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() / 1000.0f << "[seconds]" << std::endl;


	// Render loop
	while (!window.IsClosed())
	{
		window.Clear(0.0f, 0.15f, 0.3f);

		// Render skybox
		skybox.Draw(camera.GetView(), camera.GetViewProjection());


		// Render all objects in scene
		for (auto& object : objects)
		{
			object->UpdateThenDraw(camera);
		}

		window.Update();
	}

	return 0;
}