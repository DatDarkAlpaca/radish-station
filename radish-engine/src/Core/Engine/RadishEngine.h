#pragma once
#include "Common.h"

#include "Core/Event/Events.h"
#include "Core/View/ViewSystem.h"
#include "Graphics/RenderSystem.h"

namespace rds
{
	class RadishEngine
	{
	public:
		RadishEngine();

	public:
		void Run();

	private:
		void OnEngineInitialize();

		void OnRender();

		void OnRenderGUI();

		void OnUpdate();

		void OnEvent(Event& event);
		
	public:
		ViewSystem& View() { return g_ViewSystem->Get(); }

	private:
		LoggerSystem* g_LoggerSystem = nullptr;
		ViewSystem*   g_ViewSystem   = nullptr;
		RenderSystem* g_RenderSystem = nullptr;

		bool m_Initialized = false;
	};
}