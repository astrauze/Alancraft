#include "Alancraft.h"

#include <imgui.h>
#include <GLAD/gl.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

Alancraft::Alancraft()
{

}

Alancraft::~Alancraft()
{

}

void Alancraft::Initialize()
{
        
}

void Alancraft::Update()
{
    ImGui::Begin("Info");
    
    auto io = ImGui::GetIO();
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
    
    static glm::vec3 color = { 100.0f / 256.0f,200.f / 256.0f,300.0f / 256.0f };
    
    ImGui::ColorEdit3("clear color:", &color.x);
    glClearColor(color.x, color.y, color.z, 1.0f);

    ImGui::End();
}

void Alancraft::Render()
{
    
}

void Alancraft::Terminate()
{

}