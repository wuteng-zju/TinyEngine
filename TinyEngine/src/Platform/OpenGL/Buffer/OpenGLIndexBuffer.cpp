#include "pch.h"
#include "OpenGLIndexBuffer.h"
#include "GL/gl3w.h"

TINY_ENGINE_NAMESPACE_BEGIN
OpenGLIndexBuffer::OpenGLIndexBuffer(const std::vector<unsigned int>& vecIndex) :
	IndexBuffer(vecIndex)
{
	glGenBuffers(1, &m_uiRenderID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uiRenderID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_vecIndex.size() * sizeof(unsigned int), vecIndex.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	glDeleteBuffers(1, &m_uiRenderID);
}

void OpenGLIndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uiRenderID);
}

void OpenGLIndexBuffer::UnBind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

TINY_ENGINE_NAMESPACE_END