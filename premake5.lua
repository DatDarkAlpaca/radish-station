require "scripts/clear"
include "scripts/platform"
include "scripts/project"
include "dependencies/conandeps.premake5.lua"

workspace "radish-station"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }

    startproject "radish-editor"

output_path         = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
binaries_path       = "%{wks.location}/build/bin/" .. "%{output_path}"
intermediate_path   = "%{wks.location}/build/intermediate/" .. "%{output_path}"

include "radish-engine/engine.lua"
include "radish-editor/editor.lua"
include "bindings/bindings.lua"