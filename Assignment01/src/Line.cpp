#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "callables/LGLErrors.h"
#include "primitives/Renderer.h"
#include "drawables/SimpleLine.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "Error in GLEW Init" << std::endl;
    }

    /* Enable Error Output */
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(LGLErrors::HandleGLDebugCallback, 0);

    /* Renderer */
    Renderer renderer;

    /* Defining the object to be drawn */
    SimpleLine line(WINDOW_WIDTH, WINDOW_HEIGHT, {10.0, 10.0}, {630.0, 470.0});

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        renderer.Draw(line);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}