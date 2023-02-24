-- TinyEngine Dependencies
IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/TinyEngine/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/TinyEngine/vendor/yaml-cpp/include"
IncludeDir["GLFW"] = "%{wks.location}/TinyEngine/vendor/GLFW/include"
IncludeDir["GL3W"] = "%{wks.location}/TinyEngine/vendor/GL3W/include"
IncludeDir["ImGui"] = "%{wks.location}/TinyEngine/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/TinyEngine/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/TinyEngine/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/TinyEngine/vendor/entt/include"
IncludeDir["Box2D"] = "%{wks.location}/TinyEngine/vendor/Box2D/include"

--workspace 解决方案
workspace "MyTinyEngine"

  -- 启动项目
  startproject "SandBox"

  -- 解决方案配置项：Debug、Release、Dist
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

  -- 平台配置
  platforms
  {
    'x64'
  }

  -- x64平台配置属性
  filter "platforms:x64"
    -- 指定架构为x64
    architecture "x64"

  -- 指定输出目录和中间目录的文件夹名称
  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  group "Dependencies"
    -- include "vendor/premake"
    include "TinyEngine/vendor/GLFW"
    include "TinyEngine/vendor/GL3W"
    include "TinyEngine/vendor/imgui"
    include "TinyEngine/vendor/yaml-cpp"
    include "TinyEngine/vendor/Box2D"
  group ""

  group "Engine"
    include "TinyEngine"
  group ""

  group "Game"
    include "SandBox"
  group ""

