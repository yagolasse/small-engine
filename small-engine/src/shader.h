#pragma once

typedef unsigned int GLuint;
typedef unsigned int GLenum;

class Shader
{
public:
	Shader(const char* src, GLenum shaderType);
	~Shader();

	inline GLuint getId() const { return id; }

private:
	GLuint id;
};

