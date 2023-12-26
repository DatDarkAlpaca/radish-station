#pragma once
#include "Common.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace rds::platform
{
	inline void GLFWErrorCallback(int errorCode, const char* description)
	{
		RDS_LOG_ERROR("[GLFW]: {} [{}]", description, errorCode);
	}

	inline void Setup()
	{
		glfwSetErrorCallback(GLFWErrorCallback);
		if (!glfwInit())
			RDS_LOG_CRITICAL("Failed to initialize GLFW. Perhaps it has already been initialized before?");

		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	}
}