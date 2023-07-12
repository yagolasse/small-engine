#pragma once

#include <memory>

class Shader;

typedef unsigned int GLuint;

class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();

private:
	GLuint id;

	std::unique_ptr<Shader> vertexShader;
	std::unique_ptr<Shader> fragmentShader;
};
