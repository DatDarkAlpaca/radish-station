#pragma once
#include <memory>

#include "Common.h"
#include "GraphicsConfig.h"
#include "Core/Window/Window.h"
#include "Core/Window/WindowProperties.h"
#include "Core/Resource/ResourceHolder.h"

#include "Objects/Shader.h"
#include "Objects/Pipeline.h"

namespace rds
{
	class GraphicsSystem
	{
	public:
		GraphicsSystem();

	public:
		void Initialize(const WindowProperties& windowProperties, const GraphicsConfig& graphicsConfig);

		void Destroy();

	public:
		ShaderHandle CreateShader(const ShaderDescriptor& descriptor)
		{
			Shader shader(descriptor);
			return m_ShaderHolder.AddResource(std::move(shader));
		}

		NON_OWNING Shader* GetShader(ShaderHandle handle)
		{
			return m_ShaderHolder.GetResource(handle).get();
		}

		PipelineHandle CreatePipeline(const PipelineInput& input)
		{
			std::vector<Shader*> shaders;
			for (const auto& shaderHandle : input.shaderHandles)
				shaders.push_back(m_ShaderHolder.GetResource(shaderHandle).get());

			PipelineDescriptor descriptor;
			descriptor.shaders = shaders;

			Pipeline pipeline(descriptor);

			for (const auto& shaderHandle : input.shaderHandles)
				m_ShaderHolder.GetResource(shaderHandle);

			return m_PipelineHolder.AddResource(std::move(pipeline));
		}

		NON_OWNING Pipeline* GetPipeline(PipelineHandle handle)
		{
			return m_PipelineHolder.GetResource(handle).get();
		}

	private:
		void SetupOpenGL();

		void SetupImGUI();

	public:
		const std::unique_ptr<Window>& GetWindow() const { return m_Window; }

	private:
		std::unique_ptr<Window> m_Window;

	private:
		ResourceHolder<Shader> m_ShaderHolder;
		ResourceHolder<Pipeline> m_PipelineHolder;
	};
}