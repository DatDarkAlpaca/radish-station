#pragma once
#include "Common.h"
#include "Core/Window/Window.h"

namespace rds
{
	class RenderSystem : public Singleton<RenderSystem>
	{
	public:
		void Initialize(const FnEventCallback& windowCallback, uint32_t versionMajor = 4, uint32_t versionMinor = 5);

	public:
		rds_unique<Window>& GetWindow() { return m_Window; }

	private:
		rds_unique<Window> m_Window;
	};
}
