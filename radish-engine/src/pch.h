#pragma once
#pragma warning(push, 0)
	#define GLFW_INCLUDE_NONE
	#include <GLFW/glfw3.h>
	#include <glad/glad.h>
	
	#include <imgui.h>
	#include <imgui_impl_glfw.h>
	#include <imgui_impl_opengl3.h>

	#include <glm/glm.hpp>
	#include <spdlog/spdlog.h>
	#include <spdlog/sinks/stdout_color_sinks.h>
	#include <spdlog/sinks/basic_file_sink.h>

	#include <numeric>
	#include <vector>
	#include <string>
#pragma warning(pop)