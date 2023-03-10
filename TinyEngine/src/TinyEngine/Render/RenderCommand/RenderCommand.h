#pragma once
#include "TinyEngine/Render/RenderApi/RenderApi.h"
#include "TinyEngine/Render/VertexArray/VertexArray.h"

TINY_ENGINE_NAMESPACE_BEGIN

class RenderCommand
{
public:
	static void Init();
	static void SetClearColor(const glm::vec4& vec4Color);
	static void SetViewPort(unsigned int uiWidth, unsigned int uiHeight);
	static void Clear();
	static void DrawTriangles(const Ref<VertexArray>& spVertexArray, unsigned int uiIndexCount = 0);
	static void DrawLines(const Ref<VertexArray>& spVertexArray, unsigned int uiIndexCount = 0);
	static void SetLineWidth(float fWidth);
private:
	static Ref<RenderAPI> m_spRenderAPI;
};

TINY_ENGINE_NAMESPACE_END