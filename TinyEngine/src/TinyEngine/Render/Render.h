#pragma once
#include "Shader/Shader.h"
#include "Camera/Camera.h"
#include "VertexArray/VertexArray.h"

TINY_ENGINE_NAMESPACE_BEGIN
// ��������
struct SceneData
{
	// VP����
	glm::mat4 m_mat4ViewProjectionMatrix;
};

// ��Ⱦ������
class Render
{
public:
	// ��ʼ��
	static void Init();
	// �ı䴰�ڴ�С
	static void OnWindowResize(unsigned int uiWidth, unsigned int uiHeight);

	/********************************** ��Ⱦ���� **********************************/
	// ����ÿ֡��Ⱦǰ�Ļ������ã�����Scene��������ز���������Camera��lighting, ��֤shaders�ܹ��õ���ȷ�Ļ�����ص�uniforms
	static void BeginScene(const Ref<Camera>& spCamera);
	// �ռ��������ݣ�ͬʱ�ռ���Ⱦ����ύ��Ⱦ�������� ���VAOͨ��RenderCommand�µ�ָ����ݸ�RenderCommandQueue
	static void Submit(const Ref<Shader>& spShader,
		const Ref<VertexArray>& spVertexArray,
		const glm::mat4& mat4Transform = glm::mat4(1.0f));
	// ���ռ����ĳ������ݽ����Ż�
	static void EndScene();
	
private:
	// ��������
	static Ref<SceneData> m_spSceneData;
};
TINY_ENGINE_NAMESPACE_END