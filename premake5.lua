

workspace "nuts"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "nuts/vendor/GLFW/include"

include "nuts/vendor/GLFW"


project "nuts"
	location "nuts"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ntpch.h"
	pchsource"nuts/src/ntpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{	"%{prj.name}/src",
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

		defines
		{
			"NT_PLATFORM_WINDOWS",
			"NT_BUILD_DLL"

		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NT_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"nuts/vendor/spdlog/include",
		"nuts/src"
	}

	links
	{
		"nuts"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NT_DIST"
		optimize "On"
