#include "pch.h"
#include "Graphics/GraphicsSystem.h"

namespace rds
{
	GraphicsSystem::GraphicsSystem()
	{
		if (!glfwInit())
			throw "Failed to initialize GLFW";
	}

	void GraphicsSystem::Initialize(const WindowProperties& windowProperties, const GraphicsConfig& graphicsConfig)
	{
		glfwWindowHint(GLFW_DOUBLEBUFFER, graphicsConfig.enableDoubleBuffering);
		glfwWindowHint(GLFW_DEPTH_BITS, graphicsConfig.depthBits);
		glfwWindowHint(GLFW_STENCIL_BITS, graphicsConfig.stencilBits);
		
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, graphicsConfig.apiVersionMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, graphicsConfig.apiVersionMinor);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = std::make_unique<Window>(windowProperties);
		
		SetupOpenGL();
		SetupImGUI();
	}

	void GraphicsSystem::Destroy()
	{

	}

	void GraphicsSystem::SetupOpenGL()
	{
		glfwMakeContextCurrent(*m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			throw "Failed to initialize GLAD";
	}

	void GraphicsSystem::SetupImGUI()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(*m_Window, true);
		ImGui_ImplOpenGL3_Init("#version 450");
	}
}