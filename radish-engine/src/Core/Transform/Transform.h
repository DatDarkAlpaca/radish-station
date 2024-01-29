#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace rds 
{
	class Transform
	{
	public:
		operator glm::mat4()
		{
			glm::mat4 transform(1.0);

			transform = glm::translate(transform, position);
			transform = glm::scale(transform, scale);

			// TODO: euler angles
		}

	public:
		glm::vec3 position = glm::vec3(0.0f);
		glm::vec3 scale = glm::vec3(1.0f);
		glm::vec3 rotation = glm::vec3(0.f);
	};
}