-- project Engine
project "TinyEngine"
  -- 项目类型：静态库
	kind "StaticLib"

  -- 语言：C++
	language "C++"

  -- 
	cppdialect "C++17"

  -- 
	staticruntime "on"

  -- 指定输出目录
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")

  -- 指定中间目录
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

  -- 
	pchheader "pch.h"

  -- 
	pchsource "src/pch.cpp"

  
	files
	{
    -- 加载src目录下的所有.h,.cpp文件
		"src/**.h",
		"src/**.cpp",

    -- 
    "vendor/stb_image/**.h",
		"vendor/stb_image/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",

		"vendor/ImGuizmo/ImGuizmo.h",
		"vendor/ImGuizmo/ImGuizmo.cpp"
	}

  -- 
	includedirs
	{
    -- 
		"src",

    -- 
    "vendor/spdlog/include",

    "%{IncludeDir.GLFW}",
		"%{IncludeDir.GL3W}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}",
		"%{IncludeDir.ImGuizmo}",
		"%{IncludeDir.Box2D}"
	}

  links
	{
		"GLFW",
		"GL3W",
		"ImGui",
		"yaml-cpp",
		"opengl32.lib",
		"Box2D"
	}

  -- 
  filter "files:vendor/ImGuizmo/**.cpp"
  
  -- 
	flags { "NoPCH" }

  -- 当当前系统是windows时
	filter "system:windows"
		systemversion "latest"

    -- 
		defines
		{
			"TINY_ENGINE_PLATFORM_WINDOWS",
			"TINY_ENGINE_BUILD_DLL",
      "TINY_ENGINE_ENABLE_ASSERTS",
      "TINY_ENGINE_RENDER_OPENGL",
		}

  -- Debug配置项属性
	filter "configurations:Debug"
    -- 定义TINY_ENGINE_DEBUG宏 
		defines "TINY_ENGINE_DEBUG"
		runtime "Debug"
    -- 开启调试符号
		symbols "on"

  -- Release配置项属性
	filter "configurations:Release"
    -- 定义TINY_ENGINE_RELEASE宏
		defines "TINY_ENGINE_RELEASE"
		runtime "Release"
    -- 开启优化参数
		optimize "on"

  -- Dist配置项属性
	filter "configurations:Dist"
    -- 定义TINY_ENGINE_DIST宏
		defines "TINY_ENGINE_DIST"
		runtime "Release"
    -- 开启优化参数
		optimize "on"