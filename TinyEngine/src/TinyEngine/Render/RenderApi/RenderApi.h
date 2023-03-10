#pragma once

TINY_ENGINE_NAMESPACE_BEGIN
// RenderApi类
class RenderAPI
{
public:
	// 当前使用的API平台
	enum class APIType
	{
		None = 0, OpenGL
	};

	// 初始化
	virtual void Init() = 0;
	virtual void SetClearColor(const glm::vec4& vec4Color) = 0;
	virtual void SetViewPort(unsigned int uiWidth, unsigned int uiHeight) = 0;
	virtual void Clear() = 0;
	virtual void DrawTriangles(unsigned int uiIndexCount) = 0;
	virtual void DrawLines(unsigned int uiIndexCount) = 0;
	virtual void SetLineWidth(float fWidth) = 0;
	static APIType GetAPIType();
	static Ref<RenderAPI> CreateRenderAPI();

protected:
	RenderAPI() = default;
	RenderAPI(const RenderAPI&) = delete;
	RenderAPI& operator=(const RenderAPI&) = delete;
};

TINY_ENGINE_NAMESPACE_END