#pragma once
#include <glad/glad.h>
#include <numeric>
#include <string>

#include "Common.h"

namespace rds
{
	using ShaderHandle = uint32_t;

	enum class ShaderType
	{
		NONE = 0,
		VERTEX,
		TESS_CONTROL,
		TESS_EVALUATION,
		GEOMETRY,
		FRAGMENT,
		COMPUTE
	};

	struct ShaderDescriptor
	{
		std::string filepath;
		ShaderType type;
	};

	struct Shader
	{
	public:
		explicit Shader(const ShaderDescriptor& descriptor);

	public:
		operator ShaderHandle() { return m_ID; }

	private:
		ShaderHandle m_ID;
	};
}