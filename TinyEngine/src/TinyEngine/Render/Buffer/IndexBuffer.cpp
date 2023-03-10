#include "pch.h"
#include "TinyEngine/Render/RenderAPI/RenderAPI.h"
#include "PlatForm/OpenGL/Buffer/OpenGLIndexBuffer.h"

TINY_ENGINE_NAMESPACE_BEGIN

Ref<Buffer> IndexBuffer::Create(const std::vector<unsigned int>& vecIndex)
{
	switch (RenderAPI::GetAPIType())
	{
	case RenderAPI::APIType::OpenGL:
		return CreateRef<OpenGLIndexBuffer>(vecIndex);
	default:
		TINY_ENGINE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
	}
}

const std::vector<unsigned int> IndexBuffer::GetIndex() const
{
	return m_vecIndex;
}

IndexBuffer::IndexBuffer(const std::vector<unsigned int>& vecIndex) :
	m_vecIndex(vecIndex),
	m_uiRenderID(0)
{

}

TINY_ENGINE_NAMESPACE_END