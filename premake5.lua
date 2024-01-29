require "scripts/clear"
require "scripts/project"
include "dependencies/conandeps.premake5.lua"

output_path         = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
binaries_path       = "%{wks.location}/build/bin/" .. "%{output_path}"
intermediate_path   = "%{wks.location}/build/intermediate/" .. "%{output_path}"
dependencies_path   = "%{wks.location}/dependencies/"

workspace "radish-station"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }

    startproject "radish-editor"

include "radish-engine/engine.lua"
include "radish-editor/editor.lua"