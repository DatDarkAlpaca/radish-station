#pragma once
#include <glad/glad.h>
#include <numeric>

#include "Common.h"
#include "Shader.h"

namespace rds
{
	using PipelineHandle = uint32_t;

	struct PipelineInput
	{
		std::vector<ShaderHandle> shaderHandles;
	};

	struct PipelineDescriptor
	{
		std::vector<Shader*> shaders;
	};

	struct Pipeline
	{
	public:
		explicit Pipeline(const PipelineDescriptor& descriptor);

	private:
		void SetupShaders(const PipelineDescriptor& descriptor);

	public:
		operator PipelineHandle() { return m_ID; }

	private:
		PipelineDescriptor m_Descriptor;
		PipelineHandle m_ID;
	};
}