#include "window.h"
#include "renderer.h"

#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

Window::Window(const int width, const int height, const bool vsync) 
	:width(width), height(height), vsync(vsync)
{
	glfwSetErrorCallback(onError);

	if (!glfwInit())
	{
		std::cerr << "Could not initialize GLFW" << std::endl;

		exit(EXIT_FAILURE);
	}

	windowHandle = glfwCreateWindow(width, height, "Engine", nullptr, nullptr);

	if (!windowHandle)
	{
		std::cerr << "Could not create Window" << std::endl;

		exit(EXIT_FAILURE);
	}	
}

Window::~Window() 
{
	glfwDestroyWindow(windowHandle);
	glfwTerminate();
}

void Window::initialize()
{
	glfwMakeContextCurrent(windowHandle);
	glfwSetFramebufferSizeCallback(windowHandle, onFramebufferSize);

	if (vsync)
	{
		glfwSwapInterval(1);
	}
}

bool Window::shouldClose() const
{
	return glfwWindowShouldClose(windowHandle);
}

void Window::swapBuffers() const
{
	glfwSwapBuffers(windowHandle);
}

void Window::onError(int code, const char* message) 
{
	std::cerr << "Error Code: " << code << " Message: " << message << std::endl;
}

void Window::onFramebufferSize(GLFWwindow* window, const int width, const int height)
{
	Renderer::resizeViewport(width, height);
}
