#include "pch.h"
#include "BaseRenderer.h"

namespace rds
{
	BaseRenderer::BaseRenderer(NON_OWNING GraphicsSystem* system)
		: m_System(system)
	{
		SetClearMasks(GL_COLOR_BUFFER_BIT);
		
		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);
	}

	void BaseRenderer::SetClearMasks(uint32_t masks)
	{
		m_BufferMasks = masks;
	}

	void BaseRenderer::Clear(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
		glClear(m_BufferMasks);
	}

	void BaseRenderer::Begin()
	{
		glBindVertexArray(m_VAO);
	}

	void BaseRenderer::BindPipeline(const PipelineHandle& handle)
	{
		glUseProgram(*m_System->GetPipeline(handle));
	}

	void BaseRenderer::SubmitQuad(const Quad& quad, const Transform& transform)
	{
		quad.Bind();
		glDrawElements(GL_TRIANGLES, quad.Indices(), GL_UNSIGNED_INT, nullptr);
	}

	void BaseRenderer::End()
	{
		/* Blank */
	}
}