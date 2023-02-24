#pragma once
#include "Shader.h"
#include "Camera/Camera.h"
#include "VertexArray.h"

TINY_ENGINE_NAMESPACE_BEGIN

class Render
{
public:
	static void Init();
	static void OnWindowResize(unsigned int uiWidth, unsigned int uiHeight);
	static void BeginScene(const Ref<Camera>& spCamera);
	static void EndScene();
	static void Submit(const Ref<Shader>& spShader,
		const Ref<VertexArray>& spVertexArray,
		const glm::mat4& mat4Transform = glm::mat4(1.0f));
private:
	struct SceneData
	{
		glm::mat4 m_mat4ViewProjectionMatrix;
	};

	static Ref<SceneData> m_spSceneData;
};

TINY_ENGINE_NAMESPACE_END