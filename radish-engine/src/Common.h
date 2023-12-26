#pragma once
#include <numeric>

#include "Core/Defines.h"
#include "Core/NonCopyable.h"

#include "Core/Memory/Memory.h"
#include "Core/Logger/Logger.h"

#define BIND(function, argument) std::bind(function, argument, std::placeholders::_1)

#define EXPOSE_PROPERTY(ClassName, SetterName, PropertyName)						\
	const ClassName& SetterName() const { return PropertyName; }					\
	ClassName& SetterName() { return PropertyName; }

namespace rds
{
	inline void __rds_assert(const char* condition, const char* message, const char* file, uint64_t line)
	{
		RDS_LOG_CRITICAL("[Assert]: '{}' failed. [{}]\nFile: {} [{}]", condition, message, file, line);
	}

#define RDS_ASSERT(condition, message)									\
	{																		\
		if(condition) { }													\
		else																\
		{																	\
			rds::__rds_assert(#condition, message, __FILE__, __LINE__);		\
		}																	\
	}

#define RDS_ASS(condition)																\
	{																						\
		if(condition) { }																	\
		else																				\
		{																					\
			rds::__rds_assert(#condition, "No message provided", __FILE__, __LINE__);		\
		}																					\
	}
}