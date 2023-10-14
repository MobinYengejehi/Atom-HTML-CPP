/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomDOM/AtomDOM.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#include <iostream>
#include <string>
#include <memory.h>

#include "AtomDOM.h"

//#include <glad/glad.h>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

ATOM_C_ENV_OPEN

void atom_dom_init() {
	glfwInit();
	std::cout << "glfw init!" << std::endl;

	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Atom3D", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create glfw window!" << std::endl;
		atom_dom_uninit();
		return;
	}

	//int status = gladLoadGL();
	
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "couldn't init glew!" << std::endl;
		return;
	}

	std::cout << "gl version is : " << glGetString(GL_VERSION) << std::endl;

	float positions[6] = {
		-0.5f, -0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f
	};

	std::string vertexShaderCode = ATOM_GLSL(
		\#version 330 core\n

		layout(location = 0) in vec4 position;

		void main() {
			gl_Position = position;
		}
	);

	std::string fragmentShaderCode = ATOM_GLSL(
		\#version 330 core\n

		layout(location = 0) out vec4 color;

		void main() {
			color = vec4(1.0, 0.0, 0.0, 1.0);
		}
	);

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	GLuint shaderProgram = glCreateProgram();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const char* vsrc = vertexShaderCode.c_str();
	glShaderSource(vertexShader, 1, &vsrc, NULL);
	glCompileShader(vertexShader);

	GLint result;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		GLint length;
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);

		char* message = new char[length];

		glGetShaderInfoLog(vertexShader, length, &length, message);
		std::cout << "Failed to compile vertex shader (" << message << ")" << std::endl;

		ATOM_FREE_SAFE(message);
	}

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fsrc = fragmentShaderCode.c_str();
	glShaderSource(fragmentShader, 1, &fsrc, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		GLint length;
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);

		char* message = new char[length];
		
		glGetShaderInfoLog(fragmentShader, length, &length, message);
		std::cout << "Failed to compile fragment shader (" << message << ")" << std::endl;

		ATOM_FREE_SAFE(message);
	}

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	glValidateProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glUseProgram(shaderProgram);

	while (!glfwWindowShouldClose(window)) {
		//glViewport(0, 0, 800, 800);

		//glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glDeleteProgram(shaderProgram);

	glfwDestroyWindow(window);
}

void atom_dom_uninit() {
	glfwTerminate();
	std::cout << "glfw uninit!" << std::endl;
}

void atom_dom_create_element(const char* type, const char* ns) {
	std::string namesp = ns == NULL ? "default namespace" : ns;

	std::cout << "creating an element here! " << type << " | " << namesp << std::endl;
}

ATOM_C_ENV_CLOSE