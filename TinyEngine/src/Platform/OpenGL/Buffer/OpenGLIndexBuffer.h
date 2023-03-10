#pragma once
#include "TinyEngine/Render/Buffer/IndexBuffer.h"

TINY_ENGINE_NAMESPACE_BEGIN

class OpenGLIndexBuffer :public IndexBuffer
{
public:
	OpenGLIndexBuffer(const std::vector<unsigned int>& vecIndex);
	~OpenGLIndexBuffer();
	virtual void Bind() const override;
	virtual void UnBind() const override;
};

TINY_ENGINE_NAMESPACE_END