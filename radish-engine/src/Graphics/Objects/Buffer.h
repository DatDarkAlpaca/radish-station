#pragma once
#include <glad/glad.h>
#include <numeric>
#include <vector>

#include "Common.h"

namespace rds
{
	using BufferHandle = uint32_t;

	struct BufferLayoutEntry
	{
		uint32_t size;
		uint32_t type;
		uint32_t normalized;
	};

	inline uint64_t GetTypeSize(uint32_t type)
	{
		if (type == GL_FLOAT)
			return sizeof(float);

		else if (type == GL_UNSIGNED_INT)
			return sizeof(unsigned int);

		return 0;
	}

	class Buffer
	{
	public:
		explicit Buffer() = default;

	public:
		template<typename Type>
		void Initialize(uint32_t target, const std::vector<Type>& data, uint32_t usage = GL_STATIC_DRAW)
		{
			m_Target = target;

			glGenBuffers(1, &m_ID);
			glBindBuffer(target, m_ID);
			glBufferData(target, data.size() * sizeof(Type), data.data(), usage);
		}

		void SetLayout(const std::vector<BufferLayoutEntry>& layout)
		{
			glBindBuffer(m_Target, m_ID);

			uint64_t stride = 0;
			for (const auto& entry : layout)
				stride += entry.size * GetTypeSize(entry.type);

			uint64_t index = 0;
			uint64_t offset = 0;
			for (const auto& entry : layout)
			{
				glEnableVertexAttribArray(index);
				glVertexAttribPointer(
					index,
					entry.size,
					entry.type,
					entry.normalized,
					stride,
					(void*)offset);

				offset += entry.size * GetTypeSize(entry.type);
				++index;
			}			
		}

		void Bind() const
		{
			glBindBuffer(m_Target, m_ID);
		}

	private:
		BufferHandle m_ID = InvalidValue;
		uint32_t m_Target = InvalidValue;
	};
}