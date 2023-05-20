#include "Application.h"

#include <stdexcept>
#include <iostream>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLAD/gl.h>
#include <GLFW/glfw3.h>

Application::Application()
{
    InitializeGLFW();

    InitializeImGUI();
}

Application::~Application()
{
    TerminateImGUI();

    TerminateGLFW();    
}

void Application::Run()
{
	Initialize();

	while (!glfwWindowShouldClose(m_Window))
	{
        // Update
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        Update();

        // Render
        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(m_Window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);

        glClear(GL_COLOR_BUFFER_BIT);
        
        Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(m_Window);

        glfwPollEvents();
	}

	Terminate();
}

void Application::InitializeGLFW()
{
    if (glfwInit() != GLFW_TRUE)
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create window with graphics context
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    m_Window = glfwCreateWindow(mode->width / 2, mode->height / 2, "Alancraft", nullptr, nullptr);
    if (!m_Window)
    {
        throw std::runtime_error("Failed to create window");
    }

    glfwSetWindowPos(m_Window, mode->width / 4, mode->height / 4);

    glfwMakeContextCurrent(m_Window);

    // Enable Vsync
    glfwSwapInterval(1);

    // Load OpenGL Functions
    gladLoadGL((GLADloadfunc)glfwGetProcAddress);
}

void Application::TerminateGLFW()
{
    glfwDestroyWindow(m_Window);

    glfwTerminate();
}

void Application::InitializeImGUI()
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
}

void Application::TerminateImGUI()
{
    ImGui_ImplOpenGL3_Shutdown();

    ImGui_ImplGlfw_Shutdown();

    ImGui::DestroyContext();
}
