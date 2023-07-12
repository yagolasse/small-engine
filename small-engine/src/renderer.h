#pragma once

class Renderer
{
private: 
	Renderer();

public:
	static void init(const int width, const int height);
	static void clear();
	static void setClearColor(const float r, const float g, const float b, const float a);
	static void resizeViewport(const int width, const int height);
};
