#pragma once
#include <glm/glm.hpp>

#include "Core/Transform/Transform.h"

#include "Graphics/GraphicsSystem.h"
#include "Graphics/Objects/Pipeline.h"
#include "Graphics/Objects/Buffer.h"
#include "Graphics/Types/BufferMask.h"

#include "Graphics/Shape/Quad.h"
#include "Graphics/Shape/Triangle.h"

namespace rds
{
	class BaseRenderer
	{
	public:
		BaseRenderer(NON_OWNING GraphicsSystem* system);

	public:
		void SetClearMasks(uint32_t masks);

		void Clear(const glm::vec4& color = glm::vec4(1.0f));

	public:
		void Begin();

		void BindPipeline(const PipelineHandle& handle);

		void SubmitQuad(const Quad& quad, const Transform& transform);

		void End();

	private:
		NON_OWNING GraphicsSystem* m_System = nullptr;
		uint32_t m_BufferMasks = InvalidValue;
		uint32_t m_VAO = InvalidValue;

	private:
		std::vector<uint32_t> m_Indices;
		Buffer m_VBO;
	};
}