workspace "Spearmint"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

-- Include Directories relatove to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Spearmint/vendor/GLFW/include"

include "Spearmint/vendor/GLFW"

project "Spearmint"
    location "Spearmint"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-int/"..outputdir.."/%{prj.name}")

    pchheader "smpch.h"
    pchsource "Spearmint/src/smpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib",
        "dwmapi.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            "SM_PLATFORM_WINDOWS",
            "SM_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/"..outputdir.."/Sandbox/")
        }

    filter "configurations:Debug"
        defines "SM_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SM_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SM_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/"..outputdir.."/%{prj.name}")
    objdir ("bin-int/"..outputdir.."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Spearmint/vendor/spdlog/include",
        "Spearmint/src"
    }

    links
    {
        "Spearmint"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            "SM_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SM_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SM_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SM_DIST"
        optimize "On"
