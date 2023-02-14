#include "LineRenderer.h"

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "callables/LGLErrors.h"
#include "primitives/Renderer.h"
#include "drawables/SimpleLine.h"
#include "drawables/BresenhamLine.h"

LineRenderer::LineRenderer(unsigned int windowWidth, unsigned int windowHeight)
    : m_WindowWidth(windowWidth), m_WindowHeight(windowHeight)
{
}

int LineRenderer::DrawLine(LineDrawingAlgorithm alg)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    std::string windowTitle = 
        (alg == LINE_ALGO_DEFAULT) ? "Simple Line" :
        (alg == LINE_ALGO_BRESENHAM) ? "Bresenham Line" :
        "";

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, windowTitle.c_str(), NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "Error in GLEW Init" << std::endl;
        return -1;
    }

    /* Enable Error Output */
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(LGLErrors::HandleGLDebugCallback, 0);

    /* Renderer */
    Renderer renderer;

    Drawable* line = 
        (alg == LINE_ALGO_DEFAULT) ? (Drawable*) new SimpleLine(m_WindowWidth, m_WindowHeight, { 10.0f, 10.0f }, { 630.0f, 470.0f }) :
        (alg == LINE_ALGO_BRESENHAM) ? (Drawable*) new BresenhamLine(m_WindowWidth, m_WindowHeight, { 10.0f, 10.0f }, { 630.0f, 470.0f }) :
        nullptr;
    
    if (line == nullptr) {
        return -1;
    }
    
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        renderer.Draw(*line);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    delete line;

    glfwTerminate();
    return 0;
}
