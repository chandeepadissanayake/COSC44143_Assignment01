#include "ModelRenderer.h"

#include <iostream>
#include <functional>

#include "callables/LGLErrors.h"
#include <stb/stb_image.h>
#include "primitives/Renderer.h"
#include "primitives/Shader.h"
#include "drawables/Model.h"

ModelRenderer::ModelRenderer(const std::string windowTitle, unsigned int windowWidth, unsigned int windowHeight)
	: m_WindowTitle(windowTitle), m_WindowWidth(windowWidth), m_WindowHeight(windowHeight)
{
}

void CallbackFrameBufferSize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void CallbackScroll(GLFWwindow* window, double xoffset, double yoffset)
{
    ControlsWrapper* wrapperControls = static_cast<ControlsWrapper*>(glfwGetWindowUserPointer(window));
    wrapperControls->camera->ProcessMouseScroll(static_cast<float>(yoffset));
}

int ModelRenderer::DrawModel()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, m_WindowTitle.c_str(), NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error in GLEW Init" << std::endl;
        return -1;
    }

    /* Flip loaded texture on y-axis */
    stbi_set_flip_vertically_on_load(true);

    /* Global OpenGL state */
    glEnable(GL_DEPTH_TEST);

    /* Enable Error Output */
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(LGLErrors::HandleGLDebugCallback, 0);

    /* Renderer */
    Renderer renderer;

    /* Shader for model loading */
    Shader* shader = new Shader("res/shaders/model_loading.vs", "res/shaders/model_loading.fs");

    /* Loading the Model */
    Model gModel(m_WindowWidth, m_WindowHeight, shader, "res/models/backpack/backpack.obj");

    /* Sets the relevant pointers */
    struct ControlsWrapper wrapperControls = {
        gModel.GetCamera()
    };
    glfwSetWindowUserPointer(window, &wrapperControls);

    /* Set Window Resize Callback */
    glfwSetFramebufferSizeCallback(window, CallbackFrameBufferSize);
    /* Sets the scroll callback */
    glfwSetScrollCallback(window, CallbackScroll);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* Bind the Shader */
        shader->Bind();

        /* Render the Model */
        renderer.Draw(gModel);

        /* Unbind the Shader */
        shader->Unbind();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    delete shader;

    glfwTerminate();
    return 0;
}
