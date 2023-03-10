#pragma once
#include "Shader/Shader.h"
#include "Camera/Camera.h"
#include "VertexArray/VertexArray.h"

TINY_ENGINE_NAMESPACE_BEGIN
// 场景数据
struct SceneData
{
	// VP矩阵
	glm::mat4 m_mat4ViewProjectionMatrix;
};

// 渲染抽象类
class Render
{
public:
	// 初始化
	static void Init();
	// 改变窗口大小
	static void OnWindowResize(unsigned int uiWidth, unsigned int uiHeight);

	/********************************** 渲染流程 **********************************/
	// 负责每帧渲染前的环境设置：接受Scene场景的相关参数，比如Camera、lighting, 保证shaders能够得到正确的环境相关的uniforms
	static void BeginScene(const Ref<Camera>& spCamera);
	// 收集场景数据，同时收集渲染命令，提交渲染命令到队列里， 会把VAO通过RenderCommand下的指令，传递给RenderCommandQueue
	static void Submit(const Ref<Shader>& spShader,
		const Ref<VertexArray>& spVertexArray,
		const glm::mat4& mat4Transform = glm::mat4(1.0f));
	// 对收集到的场景数据进行优化
	static void EndScene();
	
private:
	// 场景数据
	static Ref<SceneData> m_spSceneData;
};
TINY_ENGINE_NAMESPACE_END