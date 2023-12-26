#include "pch.h"
#include "RenderSystem.h"
#include "Platform/Platform.h"

namespace rds
{
	void RenderSystem::Initialize(const FnEventCallback& windowCallback, uint32_t versionMajor, uint32_t versionMinor)
	{
		platform::Setup();

		ConfigureOpenGL(versionMajor, versionMinor);

		m_Window = rds::MakeUnique<Window>(WindowProperties());
		m_Window->SetEventCallback(windowCallback);

		InitializeOpenGL(m_Window.get());
	}
}
