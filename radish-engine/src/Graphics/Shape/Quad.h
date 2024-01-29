#pragma once
#include "Graphics/Objects/Buffer.h"

namespace rds
{
	struct Quad
	{
	public:
		Quad()
		{
			std::vector<float> vertexData
			{
				-0.5f, -0.5f, 0.0f,    0.0f, 0.0f,
				 0.5f, -0.5f, 0.0f,    1.0f, 0.0f,
				 0.5f,  0.5f, 0.0f,    1.0f, 1.0f,
				-0.5f,  0.5f, 0.0f,    0.0f, 1.0f,
			};

			data.Initialize(GL_ARRAY_BUFFER, vertexData);

			std::vector<rds::BufferLayoutEntry> entries
			{
				{ 3, GL_FLOAT, false },
				{ 2, GL_FLOAT, false },
			};

			data.SetLayout(entries);

			std::vector<unsigned int> indicesData
			{
				0, 1, 2, 2, 3, 0
			};
			indices.Initialize(GL_ELEMENT_ARRAY_BUFFER, indicesData);
		}

	public:
		inline uint32_t Indices() const { return 12; }

		void Bind() const
		{
			data.Bind();
			indices.Bind();
		}

	public:
		Buffer data;
		Buffer indices;
	};
}