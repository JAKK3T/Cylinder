workspace "Cylinder"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist",
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Cylinder"
	location "Cylinder"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"Cylinder/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
		"CYL_PLATFORM_WINDOWS",
		"CYL_BUILD_DLL"
		}

		postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "CYL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CYL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CYL_DIST"
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
		"Cylinder/vendor/spdlog/include",
		"Cylinder/src"
	}
	
	links
	{
		"Cylinder"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
		"CYL_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "CYL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CYL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CYL_DIST"
		optimize "On"