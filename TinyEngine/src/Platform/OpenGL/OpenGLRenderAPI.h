#pragma once
#include "TinyEngine/Render/RenderAPI.h"

TINY_ENGINE_NAMESPACE_BEGIN

class OpenGLRenderAPI :public RenderAPI
{
public:
	// Í¨¹ý RenderAPI ¼Ì³Ð
	virtual void Init()override;
	virtual void SetClearColor(const glm::vec4& vec4Color) override;
	virtual void SetViewPort(unsigned int uiWidth, unsigned int uiHeight) override;
	virtual void Clear() override;
	virtual void DrawTriangles(unsigned int uiIndexCount) override;
	virtual void DrawLines(unsigned int uiIndexCount) override;
	virtual void SetLineWidth(float fWidth) override;
};

TINY_ENGINE_NAMESPACE_END