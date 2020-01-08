#include <GL/glew.h>
#include <chrono>
#include <iostream>
#include "Window.h"
#include "Settings.h"
#include "Terrain.h"
//#include "Vegetation.h"
#include "Skybox.h"
#include"House.h"
#include"House1.h"
#include"Tree.h"
//#include"Castle.h"


int main()
{
	// Start Time
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	// Display
	Window window(Settings::WindowWidth, Settings::WindowHeight, "Explorare-sat-Bran");

	// Camera & Transform
	Camera camera(glm::vec3(0, 10, -100), 70.0f, static_cast<float>(Settings::WindowWidth) / Settings::WindowHeight, 0.01f, 1000.0f);
	window.SetCamera(camera);

	// Objects Vector
	std::vector<Object*> objects;

	

	// Terrain
	objects.push_back(new Terrain);

	//House
	objects.push_back(new House(Transform(glm::vec3(300, 6, -200))));
	objects.push_back(new House(Transform(glm::vec3(400, 6, -50))));
	objects.push_back(new House(Transform(glm::vec3(-300, 6, -40))));
	objects.push_back(new House(Transform(glm::vec3(-400, 6, -80))));


	//trees
	objects.push_back(new Tree(Transform(glm::vec3(200 ,0, -80), glm::vec3(0), glm::vec3(10, 10, 10))));
	objects.push_back(new Tree(Transform(glm::vec3(-300, 0, -300), glm::vec3(0), glm::vec3(10, 10, 10))));
	objects.push_back(new Tree(Transform(glm::vec3(-250, 0, -250), glm::vec3(0), glm::vec3(10, 10, 10))));
	objects.push_back(new Tree(Transform(glm::vec3(-250, 0, -80), glm::vec3(0), glm::vec3(10, 10, 10))));
	//objects.push_back(new Tree(Transform(glm::vec3(200, 0, -80), glm::vec3(0), glm::vec3(10, 10, 10))));
	//objects.push_back(new Tree(Transform(glm::vec3(200, 0, -80), glm::vec3(0), glm::vec3(10, 10, 10))));
	//objects.push_back(new Tree(Transform(glm::vec3(200, 0, -80), glm::vec3(0), glm::vec3(10, 10, 10))));
	//objects.push_back(new Tree(Transform(glm::vec3(200, 0, -75), glm::vec3(0), glm::vec3(10, 10, 10))));
	//objects.push_back(new Tree(Transform(glm::vec3(200, 0, -70), glm::vec3(0), glm::vec3(10, 10, 10))));
	//objects.push_back(new Tree(Transform(glm::vec3(200, 0, -65), glm::vec3(0), glm::vec3(10, 10, 10))));
	//objects.push_back(new Tree(Transform(glm::vec3(200, 0, -60), glm::vec3(0), glm::vec3(10, 10, 10))));
	//objects.push_back(new Tree(Transform(glm::vec3(200, 0, -55), glm::vec3(0), glm::vec3(10, 10, 10))));
	//objects.push_back(new Tree(Transform(glm::vec3(200, 0, -50), glm::vec3(0), glm::vec3(10, 10, 10))));
	//objects.push_back(new Tree(Transform(glm::vec3(200, 0, -45), glm::vec3(0), glm::vec3(10, 10, 10))));

	objects.push_back(new Tree(Transform(glm::vec3(200, 0, -80), glm::vec3(0), glm::vec3(10, 10, 10))));
	objects.push_back(new Tree(Transform(glm::vec3(200, 0, -80), glm::vec3(0), glm::vec3(10, 10, 10))));

	//castel+mountain
	objects.push_back(new House1(Transform(glm::vec3(-900, -400, 80), glm::vec3(0), glm::vec3(50, 50, 50))));


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
		skybox.Draw(camera.GetView(), camera.GetProjection());


		// Render all objects in scene
		for (auto& object : objects)
		{
			object->UpdateThenDraw(camera);
		}

		window.Update();
	}

	return 0;
}
