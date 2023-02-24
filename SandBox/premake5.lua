-- project Game
project "SandBox"

  -- 项目类型：控制台程序
	kind "ConsoleApp"

  -- 项目语言：C++
	language "C++"

  -- 
	cppdialect "C++17"

  -- 
	staticruntime "on"

  -- 指定输出目录
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")

  -- 指定中间目录
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

  -- 加载src目录下的所有.h,.cpp文件
	files
	{
		"src/**.h",
		"src/**.cpp"
	}

  -- 
	includedirs
	{
		"%{wks.location}/TinyEngine/src",
    "%{wks.location}/TinyEngine/vendor",
    "%{wks.location}/TinyEngine/vendor/spdlog/include",
    "%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.Box2D}"
	}

  -- 
	links
	{
		"TinyEngine"
	}

  -- 
	filter "system:windows"
		systemversion "latest"
		defines
		{
			"TINY_ENGINE_PLATFORM_WINDOWS",
      "TINY_ENGINE_ENABLE_ASSERTS"
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