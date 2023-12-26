CreateProject("radish-engine", "StaticLib")
links { "imgui-bindings" }
includedirs { "%{wks.location}/bindings/imgui" }