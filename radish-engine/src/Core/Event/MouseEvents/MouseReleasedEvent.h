#pragma once
#include "MouseEvent.h"

namespace rds
{
	struct MouseReleasedEvent : public Event
	{
		DEFINE_EVENT(EventType::MOUSE_RELEASED);

	public:
		MouseReleasedEvent(MouseButton button)
			: button(button)
		{

		}

	public:
		MouseButton button;
	};
}