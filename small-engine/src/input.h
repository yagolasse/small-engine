#pragma once

struct GLFWwindow;

class Input
{
public:
	static void init(GLFWwindow* window);

	static bool getKey(int keyCode);

private:
	Input();

	static const int MAX_KEYS = 320;

	static bool keys[];
	static void onKey(GLFWwindow* window, int key, int scancode, int action, int mods);
};
