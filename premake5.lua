require "scripts/clear"
require "scripts/project"
include "dependencies/conandeps.premake5.lua"

output_path         = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
binaries_path       = "%{wks.location}/build/bin/" .. "%{output_path}"
intermediate_path   = "%{wks.location}/build/intermediate/" .. "%{output_path}"

workspace "template-workspace"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }


include "sample-project/build.lua"