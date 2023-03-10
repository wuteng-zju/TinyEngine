#include "pch.h"
#include "TinyEngine/Render/RenderAPI/RenderAPI.h"
#include "PlatForm/OpenGL/Buffer/OpenGLUniformBuffer.h"

TINY_ENGINE_NAMESPACE_BEGIN

Ref<Buffer> UniformBuffer::Create(unsigned int uiSize, unsigned int uiBinding)
{
	switch (RenderAPI::GetAPIType())
	{
	case RenderAPI::APIType::OpenGL:
		return CreateRef<OpenGLUniformBuffer>(uiSize, uiBinding);
	default:
		TINY_ENGINE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
	}
}

TINY_ENGINE_NAMESPACE_END
