#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Core/Event/Event.h"
#include "Core/NonCopyable.h"
#include "Core/Window/WindowProperties.h"

namespace rds
{
	struct GLFWWindowDeleter
	{
		void operator () (GLFWwindow* window) 
		{
			glfwDestroyWindow(window);
		}
	};

	class Window : public NonCopyable
	{
	public:
		Window(const WindowProperties& properties);

	public:
		void Initialize(const WindowProperties& properties);

		void Shutdown();

	public:
		void SetEventCallback(const FnEventCallback& callback);

		void SetProperties(const WindowProperties& properties);

		void PollEvents();

		void Swapbuffers();

	public:
		void Hide();

		void Show();

	public:
		operator GLFWwindow* () { return m_Window.get(); }

		inline WindowProperties GetProperties() const { return m_Properties; }

		inline NON_OWNING GLFWwindow* GetHandle() const { return m_Window.get(); }

		inline bool IsOpen() const { return !glfwWindowShouldClose(m_Window.get()); }

	private:
		void SetWindowDataPointer();

		void SetWindowCallbacks();

	private:
		struct WindowData
		{
			FnEventCallback eventCallback;
		} m_WindowData;

		WindowProperties m_Properties;
		rds_unique<GLFWwindow, GLFWWindowDeleter> m_Window;
	};
}