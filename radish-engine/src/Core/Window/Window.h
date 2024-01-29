#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <memory>

#include "WindowProperties.h"

namespace rds
{
	struct GLFWWindowDeleter
	{
		void operator () (GLFWwindow* window)
		{
			glfwDestroyWindow(window);
		}
	};
	
	class Window
	{
	public:
		Window(const WindowProperties& properties);

	public:
		void PollEvent();

		void Swapbuffer();

	public:
		bool IsOpen();

	public:
		operator NON_OWNING const GLFWwindow* () const { return m_Window.get(); }
		operator NON_OWNING GLFWwindow* () { return m_Window.get(); }

	private:
		std::unique_ptr<GLFWwindow, GLFWWindowDeleter> m_Window;
	};
}