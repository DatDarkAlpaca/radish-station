#include "pch.h"
#include "Pipeline.h"

static void CheckProgramLinkErrors(rds::ShaderHandle program)
{
	constexpr uint64_t LogBufferSize = 256;

	int success;
	char infoLog[LogBufferSize];

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, LogBufferSize, NULL, infoLog);
		// TUR_LOG_ERROR("Failed to link shader program: {}", infoLog);
	}
}

namespace rds 
{
	Pipeline::Pipeline(const PipelineDescriptor& descriptor)
	{
		SetupShaders(descriptor);
	}

	void Pipeline::SetupShaders(const PipelineDescriptor& descriptor)
	{
		m_ID = glCreateProgram();

		for (auto* shader : descriptor.shaders)
			glAttachShader(m_ID, *shader);
		
		glLinkProgram(m_ID);
		CheckProgramLinkErrors(m_ID);

		for (auto* shader : descriptor.shaders)
			glDeleteShader(*shader);
	}
}

