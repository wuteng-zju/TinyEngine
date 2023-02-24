#pragma once
#include "Buffer.h"

TINY_ENGINE_NAMESPACE_BEGIN

class IndexBuffer :public Buffer
{
public:
	~IndexBuffer() = default;
	static Ref<Buffer> Create(const std::vector<unsigned int>& vecIndex);
	const std::vector<unsigned int> GetIndex()const;

private:
	IndexBuffer() = delete;
	IndexBuffer(IndexBuffer&) = delete;
	IndexBuffer& operator=(const IndexBuffer&) = delete;

protected:
	IndexBuffer(const std::vector<unsigned int>& vecIndex);

protected:
	unsigned int m_uiRenderID;
	std::vector<unsigned int> m_vecIndex;
};

TINY_ENGINE_NAMESPACE_END