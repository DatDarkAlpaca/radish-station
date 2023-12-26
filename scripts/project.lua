function CreateProject(project_name, project_kind)
    project(project_name)
    kind(project_kind)
    language "C++"
    cppdialect "C++17"

    targetdir(binaries_path .. "/%{prj.name}")
    objdir(intermediate_path .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "src/pch.cpp"

    files {
        "src/**.h",
        "src/**.cpp",
    }
   
    defines {
        "GLFW_STATIC"
    }

    includedirs {
        "%{prj.location}",
        "%{prj.location}/src"
    }

    -- Platform 
    DetectPlatform()

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
end