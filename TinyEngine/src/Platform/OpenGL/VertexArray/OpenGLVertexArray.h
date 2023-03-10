#pragma once
#include "TinyEngine/Render/VertexArray/VertexArray.h"

TINY_ENGINE_NAMESPACE_BEGIN

class OpenGLVertexArray :public VertexArray
{
public:
	OpenGLVertexArray();
	virtual ~OpenGLVertexArray();
	virtual void Bind() const override;
	virtual void UnBind() const override;
	virtual void AddVertexBuffer(const Ref<Buffer>& spBuffer) override;
	virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffer() const override;
	virtual void SetIndexBuffer(const Ref<Buffer>& spBuffer) override;
	virtual const Ref<IndexBuffer>& GetIndexBuffer() const override;

private:
	std::vector<Ref<VertexBuffer>> m_vecVertexBuffer;
	Ref<IndexBuffer> m_spIndexBuffer;
};

TINY_ENGINE_NAMESPACE_END