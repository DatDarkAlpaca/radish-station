#include "pch.h"
#include "ViewSystem.h"

namespace rds
{
	size_t ViewSystem::Add(rds_unique<View> view)
	{
		view->OnInstantiated();
		view->SetHandler(this);

		m_Views.push_back(std::move(view));

		return m_Views.size() - 1;
	}

	void ViewSystem::Remove(size_t index)
	{
		auto it = m_Views.begin() + index;
		it->get()->OnRemoved();

		m_Views.erase(it);
	}

	View& ViewSystem::GetView(size_t index)
	{
		RDS_ASSERT(m_Views.size() - 1 <= index, "Invalid view index selected");
		return *m_Views[index].get();
	}
}