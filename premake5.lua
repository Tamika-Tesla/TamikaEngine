workspace "TamikaEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.build}-%{cfg.system}-%{cfg.architecture}"

project "TamikaEngine"
	location "TamikaEngine"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TE_PLATFORM_WINDOWS",
			"TE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} .. /bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Release"
			defines "TE_RELEASE"
			optimize "On"

		filter "configurations:Debug"
			defines "TE_DEBUG"
			symbols "On"

		filter "configurations:Dist"
			defines "TE_DIST"
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
		"TamikaEngine/vendor/spdlog/include",
		"TamikaEngine/src"
	}

	links
	{
		"TamikaEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TE_PLATFORM_WINDOWS"
		}

		filter "configurations:Release"
			defines "TE_RELEASE"
			optimize "On"

		filter "configurations:Debug"
			defines "TE_DEBUG"
			symbols "On"

		filter "configurations:Dist"
			defines "TE_DIST"
			optimize "On"