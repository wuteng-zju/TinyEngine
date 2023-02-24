#include "pch.h"
#include "PlatForm/OpenGL/OpenGLRenderAPI.h"

TINY_ENGINE_NAMESPACE_BEGIN

RenderAPI::APIType RenderAPI::GetAPIType()
{
#ifdef TINY_ENGINE_RENDER_OPENGL
	return APIType::OpenGL;
#else
	return APIType::None;
#endif
}

Ref<RenderAPI> RenderAPI::CreateRenderAPI()
{
	switch (GetAPIType())
	{
	case APIType::OpenGL:
		return CreateRef<OpenGLRenderAPI>();
	default:
	{
		TINY_ENGINE_ASSERT(false, "Unknown API Type");
		return nullptr;
	}
	}
}

TINY_ENGINE_NAMESPACE_END