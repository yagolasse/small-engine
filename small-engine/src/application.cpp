#include "application.h"

#include "input.h"
#include "scene.h"
#include "window.h"
#include "renderer.h"
#include "shader_program.h"

#include <memory>
#include <iostream>
#include <GLFW/glfw3.h>

Application::Application()
{
	const int width = 640, height = 480;

	window = std::make_unique<Window>(width, height, true);

	window->initialize();

	Renderer::init(width, height);

	ShaderProgram program;

	Input::init(window->getWindowHandle());

	scene = std::make_unique<Scene>();
}

Application::~Application()
{

}

void Application::run()
{
	double frameTime = 0.0;
	double lastFrameTime = glfwGetTime();

	Renderer::setClearColor(0.8756f, 0.54234f, 0.4523f, 1.0f);

	scene->start();

	while (!window->shouldClose())
	{
		Renderer::clear();

		scene->update(frameTime);

		window->swapBuffers();

		glfwPollEvents();

		double time = glfwGetTime();
		frameTime = time - lastFrameTime;
		lastFrameTime = time;
	}
}
