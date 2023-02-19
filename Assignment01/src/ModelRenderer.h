#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "primitives/Camera.h"

struct ControlsWrapper {
	Camera* camera;
};

class ModelRenderer
{
private:
	std::string m_WindowTitle;
	unsigned int m_WindowWidth;
	unsigned int m_WindowHeight;
public:
	ModelRenderer(const std::string windowTitle, unsigned int windowWidth, unsigned int windowHeight);

	int DrawModel();
};
