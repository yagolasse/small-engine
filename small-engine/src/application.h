#pragma once

#include <memory>

class Window;
class Scene;

class Application
{
public:
	Application();
	~Application();

	void run();

private:
	std::unique_ptr<Scene> scene;
	std::unique_ptr<Window> window;
};
