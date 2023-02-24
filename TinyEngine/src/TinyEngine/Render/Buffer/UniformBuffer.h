#pragma once
#include "Buffer.h"

TINY_ENGINE_NAMESPACE_BEGIN

class UniformBuffer :public Buffer
{
public:
	virtual ~UniformBuffer() {}

	static Ref<Buffer> Create(unsigned int uiSize, unsigned int uiBinding);

	virtual void SetData(const void* data, unsigned int uiSize, unsigned int uiOffset = 0) = 0;

protected:
	UniformBuffer() = default;

private:
	UniformBuffer(UniformBuffer&) = delete;
	UniformBuffer& operator=(const UniformBuffer&) = delete;

protected:
	unsigned int m_uiRenderID;
};

TINY_ENGINE_NAMESPACE_END

