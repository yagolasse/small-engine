#pragma once

struct GLFWwindow;

class Window {
public:
	Window(const int width, const int height, const bool vsync);
	~Window();

	void initialize();

	bool shouldClose() const;
	void swapBuffers() const;

	inline GLFWwindow* getWindowHandle() const { return windowHandle; }

private:
	bool vsync;
	int width, height;
	GLFWwindow* windowHandle;

	static void onError(int code, const char* message);
	static void onFramebufferSize(GLFWwindow* window, const int width, const int height);
};
