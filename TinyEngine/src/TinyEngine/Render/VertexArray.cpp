#include "pch.h"
#include "PlatForm/OpenGL/OpenGLVertexArray.h"
#include "RenderAPI.h"
#include "TinyEngine/Debug/Instrumentor.h"

TINY_ENGINE_NAMESPACE_BEGIN

Ref<VertexArray> VertexArray::Create()
{
	TINY_ENGINE_PROFILE_FUNCTION();
	switch (RenderAPI::GetAPIType())
	{
	case RenderAPI::APIType::OpenGL:
		return CreateRef<OpenGLVertexArray>();
	default:
		TINY_ENGINE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
	}
}

VertexArray::VertexArray() :m_uiRenderID(0)
{
}

TINY_ENGINE_NAMESPACE_END