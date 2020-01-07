#include "Window.h"
#include"GeneralWindowData.h"

#include <GL/glew.h>
#include <iostream>

Window::Window(uint16_t width, uint16_t height, const std::string& title)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Anti-Aliasing
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
	glEnable(GL_MULTISAMPLE);

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	const GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		std::cerr << "Glew failed to initialized!" << std::endl;
	}

	m_isClosed = false;

	// Face culling
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// Blending
	glEnable(GL_BLEND);

	// Initialize mouse
	SDL_WarpMouseInWindow(m_window, WindowData::SCR_HEIGHT / 2,WindowData::SCR_WIDTH  / 2);
	SDL_ShowCursor(SDL_DISABLE);

	// Timing
	m_NOW = SDL_GetPerformanceCounter();
	m_LAST = 0;
	m_deltaTime = 0;
}

Window::~Window()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Window::Update()
{
	// Swap Window
	SDL_GL_SwapWindow(m_window);

	// per-frame Time Logic
	m_LAST = m_NOW;
	m_NOW = SDL_GetPerformanceCounter();
	m_deltaTime = (m_NOW - m_LAST) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency());

	// Camera movement
	const Uint8* keyState = SDL_GetKeyboardState(NULL);
	const float cameraSpeed = static_cast<float>(m_deltaTime)* pCamera->cameraSpeedFactor;
	if (keyState[SDL_SCANCODE_W])
	{
		pCamera->ProcessKeyboard(FORWARD, cameraSpeed);
	}
	else if (keyState[SDL_SCANCODE_S])
	{
		pCamera->ProcessKeyboard(BACKWARD,cameraSpeed);
	}
	if (keyState[SDL_SCANCODE_A])
	{
		pCamera->ProcessKeyboard(LEFT,cameraSpeed);
	}
	else if (keyState[SDL_SCANCODE_D])
	{
		pCamera->ProcessKeyboard(RIGHT,cameraSpeed);
	}

	// Event Handling
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		// Quit
		if (e.type == SDL_QUIT)
		{
			m_isClosed = true;
		}
		// Keyboard
		else if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_isClosed = true;
				break;
			default:
				break;
			}
		}
		// Mouse
		else if (e.type == SDL_MOUSEMOTION)
		{
			pCamera->MouseControl(e.motion.x, e.motion.y);
			SDL_WarpMouseInWindow(m_window, WindowData::SCR_HEIGHT / 2, WindowData::SCR_WIDTH / 2);
		}
	}
}

void Window::Clear(float red, float green, float blue, float alpha)
{
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::SetCamera(Camera& camera)
{
	pCamera = &camera;
}

bool Window::IsClosed() const
{
	return m_isClosed;
}