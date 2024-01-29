#include "pch.h"
#include "Window.h"

namespace rds
{
	Window::Window(const WindowProperties& properties)
	{
		GLFWwindow* glfwWindow = glfwCreateWindow(
			properties.dimensions.x,
			properties.dimensions.y,
			properties.title.c_str(),
			nullptr, nullptr
		);

		if (!glfwWindow)
			throw "Failed to create GLFW window";

		m_Window.reset(glfwWindow);
	}

	void Window::PollEvent()
	{
		glfwPollEvents();
	}

	void Window::Swapbuffer()
	{
		glfwSwapBuffers(*this);
	}

	bool Window::IsOpen()
	{
		return !glfwWindowShouldClose(*this);
	}
}

