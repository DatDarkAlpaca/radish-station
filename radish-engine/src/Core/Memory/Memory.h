#pragma once
#include <memory>

// Raw pointer purpose identifier
#define NON_OWNING

namespace rds
{
	template<typename T, typename Deleter = std::default_delete<T>>
	using rds_unique = std::unique_ptr<T, Deleter>;

	template<typename T, typename ... Args>
	constexpr rds_unique<T> MakeUnique(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using rds_shared = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr rds_shared<T> MakeShared(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using rds_weak = std::weak_ptr<T>;
}