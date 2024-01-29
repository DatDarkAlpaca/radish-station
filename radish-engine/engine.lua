create_project("radish-engine", "StaticLib")

pchheader "pch.h"
pchsource "src/pch.cpp"

-- Dear ImGUI:
files {
    "%{dependencies_path}" .. "imgui-bindings/imgui_impl_glfw.cpp",
    "%{dependencies_path}" .. "imgui-bindings/imgui_impl_glfw.h",
    "%{dependencies_path}" .. "imgui-bindings/imgui_impl_opengl3.cpp",
    "%{dependencies_path}" .. "imgui-bindings/imgui_impl_opengl3.h",
}

includedirs { "%{dependencies_path}" .. "imgui-bindings" }

filter { 'files:../dependencies/imgui-bindings/*.cpp' }
   flags { 'NoPCH' }
filter { }