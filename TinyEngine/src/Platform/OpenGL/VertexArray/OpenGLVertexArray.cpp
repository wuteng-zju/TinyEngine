#include "pch.h"
#include "OpenGLVertexArray.h"

#include "GL/gl3w.h"
#include "TinyEngine/Debug/Instrumentor.h"

TINY_ENGINE_NAMESPACE_BEGIN

GLenum GetDataType(VertexDataType dataType)
{
	switch (dataType)
	{
	case VertexDataType::Float:		return GL_FLOAT;
	case VertexDataType::Float2:		return GL_FLOAT;
	case VertexDataType::Float3:		return GL_FLOAT;
	case VertexDataType::Float4:		return GL_FLOAT;
	case VertexDataType::Mat3:		return GL_FLOAT;
	case VertexDataType::Mat4:		return GL_FLOAT;
	case VertexDataType::Int:			return GL_INT;
	case VertexDataType::Int2:		return GL_INT;
	case VertexDataType::Int3:		return GL_INT;
	case VertexDataType::Int4:		return GL_INT;
	case VertexDataType::Bool:		return GL_BOOL;
	default:
	{
		TINY_ENGINE_ASSERT(false, "Unknown DataType");
		return 0;
	}
	}
}

OpenGLVertexArray::OpenGLVertexArray()
{
	TINY_ENGINE_PROFILE_FUNCTION();
	glGenVertexArrays(1, &m_uiRenderID);
}

OpenGLVertexArray::~OpenGLVertexArray()
{
	glDeleteVertexArrays(1, &m_uiRenderID);
}

void OpenGLVertexArray::Bind() const
{
	glBindVertexArray(m_uiRenderID);
}

void OpenGLVertexArray::UnBind() const
{
	glBindVertexArray(0);
}

void OpenGLVertexArray::AddVertexBuffer(const Ref<Buffer>& spBuffer)
{
	auto spVertexBuffer = std::dynamic_pointer_cast<VertexBuffer>(spBuffer);
	TINY_ENGINE_ASSERT(spVertexBuffer, "Vertex Buffer in OpenGLVertexArray is null");

	const auto& spVertexBufferLayout = spVertexBuffer->GetVertexBufferLayout();
	TINY_ENGINE_ASSERT(spVertexBufferLayout->GetVertexBufferElements().size(), "Vertex Buffer has no layout");

	glBindVertexArray(m_uiRenderID);
	spVertexBuffer->Bind();

	GLuint uiIndex(0);
	for (const auto& element : spVertexBufferLayout->GetVertexBufferElements())
	{
		glEnableVertexAttribArray(uiIndex);
		glVertexAttribPointer(
			uiIndex,
			element.GetDataCount(),
			GetDataType(element.DataType),
			element.Normalized ? GL_TRUE : GL_FALSE,
			spVertexBufferLayout->GetStride(),
			(const void*)(element.Offset));
		uiIndex++;
	}

	spVertexBuffer->UnBind();
	glBindVertexArray(0);
	m_vecVertexBuffer.push_back(spVertexBuffer);
}

const std::vector<Ref<VertexBuffer>>& OpenGLVertexArray::GetVertexBuffer() const
{
	return m_vecVertexBuffer;
}

void OpenGLVertexArray::SetIndexBuffer(const Ref<Buffer>& spBuffer)
{
	m_spIndexBuffer = std::dynamic_pointer_cast<IndexBuffer>(spBuffer);
	TINY_ENGINE_ASSERT(m_spIndexBuffer, "Vertex Buffer in OpenGLVertexArray is null");

	Bind();
	m_spIndexBuffer->Bind();
}

const Ref<IndexBuffer>& OpenGLVertexArray::GetIndexBuffer() const
{
	return m_spIndexBuffer;
}

TINY_ENGINE_NAMESPACE_END