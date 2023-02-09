#pragma once

#include <GL/glew.h>

class LGLErrors
{
private:
	LGLErrors();
public:
	LGLErrors(const LGLErrors& lGLErrors) = delete;

	static void HandleGLDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
};

