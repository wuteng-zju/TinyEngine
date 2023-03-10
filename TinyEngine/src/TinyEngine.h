#pragma once
/* 
	为Tiny Engine的客户端创建的 
*/
#include "pch.h"

// For use for application(应用端)
#include "TinyEngine/Core/Application.h"

// 
#include "TinyEngine/Core/KeyCode.h"
#include "TinyEngine/Core/MouseCode.h"
#include "TinyEngine/Core/Input.h"

#include "TinyEngine/ImGui/ImGuiLayer.h"
#include "TinyEngine/ImGui/SceneHierarchyPanel.h"
#include "TinyEngine/ImGui/ContentBrowserPanel.h"

#include "TinyEngine/Render/Render.h"
#include "TinyEngine/Render/Render2D/Render2D.h"
#include "TinyEngine/Render/RenderCommand/RenderCommand.h"
#include "TinyEngine/Render/VertexArray/VertexArray.h"
#include "TinyEngine/Render/Buffer/VertexBuffer.h"
#include "TinyEngine/Render/Buffer/IndexBuffer.h"
#include "TinyEngine/Render/Buffer/FrameBuffer.h"
#include "TinyEngine/Render/Shader/Shader.h"
#include "TinyEngine/Render/Texture/SubTexture2D.h"
#include "TinyEngine/Render/Camera/OrthoGraphicCameraController.h"
#include "TinyEngine/Render/Camera/EditorCamera.h"

#include "TinyEngine/Scene/Scene.h"
#include "TinyEngine/Scene/Components.h"
#include "TinyEngine/Scene/Entity.h"
#include "TinyEngine/Debug/DrawStatistics/QuadDrawStatics.h"

#include "TinyEngine/System/ParticleSystem2D.h"

#include "TinyEngine/Utils/PlatformUtils.h"

#include "TinyEngine/Math/MathUtils.h"