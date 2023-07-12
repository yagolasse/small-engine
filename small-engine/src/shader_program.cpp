#include "shader_program.h"

#include "shader.h"

#include <glad/glad.h>

ShaderProgram::ShaderProgram()
{
	const char* vertexShaderSrc =
		"#version 110\n"
		"uniform mat4 MVP;\n"
		"attribute vec3 vCol;\n"
		"attribute vec2 vPos;\n"
		"varying vec3 color;\n"
		"void main()\n"
		"{\n"
		"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
		"    color = vCol;\n"
		"}\n";

	const char* fragmentShaderSrc =
		"#version 110\n"
		"varying vec3 color;\n"
		"void main()\n"
		"{\n"
		"    gl_FragColor = vec4(color, 1.0);\n"
		"}\n";

	vertexShader = std::make_unique<Shader>(vertexShaderSrc, GL_VERTEX_SHADER);
	fragmentShader = std::make_unique<Shader>(fragmentShaderSrc, GL_FRAGMENT_SHADER);

	id = glCreateProgram();

	glAttachShader(id, vertexShader->getId());
	glAttachShader(id, vertexShader->getId());

	glLinkProgram(id);
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(id);
}
