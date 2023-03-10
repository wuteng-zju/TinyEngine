#pragma once
#include "TinyEngine.h"
#include <imgui/imgui.h>

using namespace TinyEngine;
class SandBoxExampleLayer :public Layer
{
public:
	SandBoxExampleLayer();
	virtual ~SandBoxExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(const Time& timeStep) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Event& e) override;
private:
	Ref<OrthoGraphicCameraController> m_spOrthoGraphicCameraController;

	Ref<VertexArray> m_spTextureArray;
	Ref<Shader> m_spTextureShader;

	Ref<VertexArray> m_spColorArray;
	Ref<Shader> m_spColorShader;
	glm::vec4 m_vec4Color;

	Ref<Texture> m_spTexture2DRGB, m_spTexture2DRGBA;
};