#include "pch.h"
#include "TinyEngine/Render/RenderAPI.h"
#include "PlatForm/OpenGL/Buffer/OpenGLFrameBuffer.h"

TINY_ENGINE_NAMESPACE_BEGIN

Ref<Buffer> FrameBuffer::Create(const Ref<FrameBufferSpecification>& spFrameBufferSpecification)
{
	switch (RenderAPI::GetAPIType())
	{
	case RenderAPI::APIType::OpenGL:
		return CreateRef<OpenGLFrameBuffer>(spFrameBufferSpecification);
	default:
		TINY_ENGINE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
	}
}

FrameBuffer::FrameBuffer(const Ref<FrameBufferSpecification>& spFrameBufferSpecification) :
	m_spFrameBufferSpecification(spFrameBufferSpecification), m_uiRenderID(0)
{
}

const Ref<FrameBufferSpecification>& FrameBuffer::GetFrameBufferSpecification() const
{
	return m_spFrameBufferSpecification;
}

unsigned int FrameBuffer::GetColorAttachment(unsigned int uiIndex) const
{
	return m_vecColorAttachment[uiIndex];
}

unsigned int FrameBuffer::GetDepthAttachment() const
{
	return m_uiDepthAttachment;
}

TINY_ENGINE_NAMESPACE_END