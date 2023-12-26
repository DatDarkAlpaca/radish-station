project "imgui-bindings"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir(binaries_path .. "/%{prj.name}")
    objdir(intermediate_path .. "/%{prj.name}")

    files {
        "imgui/*.h",
        "imgui/*.cpp",
    }

    -- Configurations
    filter { "configurations:Debug" }
        runtime "Debug"
        symbols "on"
        defines { "RDS_DEBUG" }
    filter { }
        
    filter { "configurations:Release" }
        runtime "Release"
        optimize "on"
        inlining "auto"
    filter { }

    conan_setup()