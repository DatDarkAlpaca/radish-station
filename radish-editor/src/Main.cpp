#include "pch.h"
#include <RadishEngine.h>
#include <Entry.h>

using namespace rds;

class MainView : public View
{
public:
	explicit MainView() = default;
};

class RadishEditor : public RadishEngine
{
public:
	explicit RadishEditor()
	{
		View().Add(rds::MakeUnique<MainView>());
	}
};

rds::rds_unique<rds::RadishEngine> CreateApplication()
{
	return rds::MakeUnique<RadishEditor>();
}