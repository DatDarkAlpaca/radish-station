#pragma once
#include "Core/Event/Event.h"

namespace rds
{
	class WindowCloseEvent : public Event
	{
		DEFINE_EVENT(EventType::WINDOW_CLOSE);
	};
}