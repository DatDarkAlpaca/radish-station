#pragma once
#include <memory>

#include "GraphicsConfig.h"
#include "Core/Window.h"
#include "Core/WindowProperties.h"

namespace rds
{
	class GraphicsSystem
	{
	public:
		GraphicsSystem();

	public:
		void Initialize(const WindowProperties& windowProperties, const GraphicsConfig& graphicsConfig);

		void Destroy();

	private:
		void SetupOpenGL();

		void SetupImGUI();

	public:
		const std::unique_ptr<Window>& GetWindow() const { return m_Window; }

	private:
		std::unique_ptr<Window> m_Window;
	};
}