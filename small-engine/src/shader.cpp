#include "shader.h"

#include <glad/glad.h>

#include <vector>
#include <iostream>

Shader::Shader(const char* src, GLenum shaderType)
{
	id = glCreateShader(shaderType);
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	GLint isCompiled = 0;

	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);

	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;

		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		std::cerr << &errorLog[0] << std::endl;

		glDeleteShader(id);

		exit(EXIT_FAILURE);
	}
}

Shader::~Shader()
{
	glDeleteShader(id);
}
