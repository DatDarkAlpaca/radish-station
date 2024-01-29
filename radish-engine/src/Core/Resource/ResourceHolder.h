#pragma once
#include <unordered_map>
#include <memory>
#include <string>

namespace rds
{
	// template: std::string -> Identifier
	//			 int -> Type

	using ResourceIdentifier = uint32_t;

	template<typename Type>
	class ResourceHolder
	{
	public:
		ResourceIdentifier AddResource(Type value)
		{
			m_Data.push_back(std::make_unique<Type>(value));
			return m_Data.size() - 1;
		}

		const std::unique_ptr<Type>& GetResource(ResourceIdentifier identifier) const
		{
			return m_Data[identifier];
		}

		void DeleteResource(ResourceIdentifier identifier)
		{
			auto resourceIterator = m_Data.begin() + identifier;
			resourceIterator->reset();
	
			m_Data.erase(resourceIterator);
		}

	private:
		std::vector<std::unique_ptr<Type>> m_Data;
	};
}