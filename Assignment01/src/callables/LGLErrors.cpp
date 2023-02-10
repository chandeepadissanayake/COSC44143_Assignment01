/*
 * Definitions for LGLErrors.h
 */
#include "LGLErrors.h"

#include <iostream>

void LGLErrors::HandleGLDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    std::cout << "[OpenGL Error] (" << source << "): " << message << std::endl;
}
