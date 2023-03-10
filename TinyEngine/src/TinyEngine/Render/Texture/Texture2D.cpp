#include "pch.h"
#include "PlatForm/OpenGL/Texture/OpenGLTexture2D.h"
#include "TinyEngine/Render/RenderAPI/RenderAPI.h"
#include "Texture2D.h"

TINY_ENGINE_NAMESPACE_BEGIN

Texture2D::Texture2D(const std::string& sPath) :
	m_sPath(sPath),
	m_iWidth(0),
	m_iHeight(0),
	m_iChannel(0),
	m_uiRenderID(0)
{
}

Texture2D::Texture2D(int iWidth, int iHeight):
	m_sPath(""),
	m_iWidth(iWidth),
	m_iHeight(iHeight),
	m_iChannel(0),
	m_uiRenderID(0)
{
}

int Texture2D::GetWidth() const
{
	return m_iWidth;
}

int Texture2D::GetHeight() const
{
	return m_iHeight;
}

Ref<Texture> Texture2D::Create(const std::string& sPath)
{
	switch (RenderAPI::GetAPIType())
	{
	case RenderAPI::APIType::OpenGL:
		return CreateRef<OpenGLTexture2D>(sPath);
	default:
		TINY_ENGINE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
	}
}

Ref<Texture> Texture2D::Create(unsigned int uiWidth, unsigned int uiHeight)
{
	switch (RenderAPI::GetAPIType())
	{
	case RenderAPI::APIType::OpenGL:
		return CreateRef<OpenGLTexture2D>(uiWidth, uiHeight);
	default:
		TINY_ENGINE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
	}
}

unsigned int Texture2D::GetRenderID() const
{
	return m_uiRenderID;
}

const std::string& Texture2D::GetTexturePath() const
{
	return m_sPath;
}


TINY_ENGINE_NAMESPACE_END