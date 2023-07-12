#include "input.h"

#include <GLFW/glfw3.h>
#include <iostream>

bool Input::keys[Input::MAX_KEYS];

void Input::init(GLFWwindow* window)
{
	glfwSetKeyCallback(window, onKey);

	for (int i = 0; i < MAX_KEYS; i++)
	{
		keys[i] = false;
	}
}

bool Input::getKey(int keyCode) 
{
	return keyCode < MAX_KEYS && keys[keyCode];
}
 
void Input::onKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key < MAX_KEYS)
	{
		keys[key] = action != GLFW_RELEASE;
	}
}
