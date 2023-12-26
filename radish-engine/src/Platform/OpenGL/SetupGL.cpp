#include "pch.h"
#include "SetupGL.h"
#include "Common.h"
#include "Core/Window/Window.h"

namespace rds
{
	void rds::ConfigureOpenGL(uint32_t versionMajor, uint32_t versionMinor)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef TUR_PLATFORM_APPLE
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	}

	void rds::InitializeOpenGL(Window* window)
	{
		glfwMakeContextCurrent(static_cast<GLFWwindow*>(window->GetHandle()));

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			RDS_LOG_CRITICAL("Failed to initialize a valid OpenGL context");
	}
}