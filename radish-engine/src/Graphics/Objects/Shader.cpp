#include "pch.h"

#include "Core/File.h"
#include "Shader.h"

static uint32_t GetShaderTypeValue(rds::ShaderType type)
{
    using namespace rds;

    switch (type)
    {
        case ShaderType::VERTEX:
            return GL_VERTEX_SHADER;

        case ShaderType::TESS_CONTROL:
            return GL_TESS_CONTROL_SHADER;

        case ShaderType::TESS_EVALUATION:
            return GL_TESS_EVALUATION_SHADER;

        case ShaderType::GEOMETRY:
            return GL_GEOMETRY_SHADER;

        case ShaderType::FRAGMENT:
            return GL_FRAGMENT_SHADER;

        case ShaderType::COMPUTE:
            return GL_COMPUTE_SHADER;

        default:
            // TODO: logger
            break;
            // TUR_LOG_CRITICAL("OpenGL 4.5 does not support the following shader type: {}");
    }

    return InvalidValue;
}

static void CheckCompileErrors(rds::ShaderHandle shader, rds::ShaderType type)
{
    using namespace rds;
    constexpr uint64_t LogBufferSize = 256;

    int success;
    char infoLog[LogBufferSize];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, LogBufferSize, NULL, infoLog);
        // TODO: logger
        // TUR_LOG_ERROR("Failed to compile {} Shader: {}", GetShaderTypeName(type), infoLog);
    }
}

namespace rds
{
	Shader::Shader(const ShaderDescriptor& descriptor)
	{
        auto shaderContents = ReadFile(descriptor.filepath);
        const char* cShaderCode = shaderContents.c_str();

        m_ID = glCreateShader(GetShaderTypeValue(descriptor.type));
        glShaderSource(m_ID, 1, &cShaderCode, NULL);
        glCompileShader(m_ID);

        CheckCompileErrors(m_ID, descriptor.type);
	}
}