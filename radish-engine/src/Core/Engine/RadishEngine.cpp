#include "pch.h"
#include "RadishEngine.h"

namespace rds
{
	RadishEngine::RadishEngine()
	{
		// Logger system:
		g_LoggerSystem = new LoggerSystem;
		g_LoggerSystem->Get().Initialize();

		// View system:
		g_ViewSystem = new ViewSystem;
		g_ViewSystem->Get();

		// Render system:
		g_RenderSystem = new RenderSystem;
		g_RenderSystem->Get().Initialize(BIND(&RadishEngine::OnEvent, this), 4, 5);

		m_Initialized = true;
	}

	void RadishEngine::Run()
	{
		OnEngineInitialize();

		auto& window = RenderSystem::Get().GetWindow();
		window->Show();

		if (!m_Initialized)
			RDS_LOG_CRITICAL("Failed to initialize the required systems.");

		while (window->IsOpen())
		{
			window->PollEvents();

			OnUpdate();

			OnRender();

			OnRenderGUI();
		}

		window->Shutdown();
	}

	void RadishEngine::OnEngineInitialize()
	{
		for (const auto& view : g_ViewSystem->Get())
			view->OnEngineInitialize();
	}

	void RadishEngine::OnRender()
	{
		for (const auto& view : g_ViewSystem->Get())
			view->OnRender();
	}

	void RadishEngine::OnRenderGUI()
	{
		for (const auto& view : g_ViewSystem->Get())
			view->OnRenderGUI();
	}

	void RadishEngine::OnUpdate()
	{
		for (const auto& view : g_ViewSystem->Get())
			view->OnUpdate();
	}

	void RadishEngine::OnEvent(Event& event)
	{
		for (const auto& view : g_ViewSystem->Get())
			view->OnEvent(event);
	}
}