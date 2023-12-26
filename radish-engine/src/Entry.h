#pragma once
#include "Core/Memory/Memory.h"
#include "Core/Engine/RadishEngine.h"

extern rds::rds_unique<rds::RadishEngine> CreateApplication();

int main(int argc, char** argv)
{
	using namespace rds;

	rds_unique<RadishEngine> engine = CreateApplication();
	engine->Run();
}