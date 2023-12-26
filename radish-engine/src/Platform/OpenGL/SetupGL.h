#pragma once
#pragma warning(push, 0)
	#define GLFW_INCLUDE_NONE
	#include <GLFW/glfw3.h>
#pragma warning(pop)

namespace rds
{
	class Window;

	void ConfigureOpenGL(uint32_t versionMajor, uint32_t versionMinor);

	void InitializeOpenGL(Window* window);
}