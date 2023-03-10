#pragma once
#include "TinyEngine.h"
#include <imgui/imgui.h>
#include "TinyEngine/Scene/SceneSerializer.h"

TINY_ENGINE_NAMESPACE_BEGIN

// SandBoxEditorLayer��
class SandBoxEditorLayer :public Layer
{
public:
	// ���캯��
	SandBoxEditorLayer();
	// ��������
	~SandBoxEditorLayer();
	// ��ѹ���ջʱ
	virtual void OnAttach() override;
	// ���Ƴ���ջʱ
	virtual void OnDetach() override;
	// ����ʱ
	virtual void OnUpdate(const Time& deltaTime) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Event& e) override;
private:
	bool OnKeyPressed(KeyPressedEvent& e);
	bool OnMousePressed(MouseButtonPressedEvent& e);
	void NewScene();
	void OpenScene();
	void OpenScene(const std::filesystem::path& path);
	void SaveSceneAs();
	void SaveScene();

	void OnScenePlay();
	void OnSceneSimulate();
	void OnSceneStop();

	void UIToolbar();
	void OnDuplicateEntity();
	void OnOverlayRender();
private:
	Ref<Texture> m_spIconPlay;
	Ref<Texture> m_spIcomSimulate;
	Ref<Texture> m_spIconStop;

	glm::vec4 m_vec4Color;

	Ref<Buffer> m_spFrameBuffer;

	bool m_bViewportHovered;
	bool m_bViewportFocused;
	ImVec2 m_vec2RenderViewPortSize;
	std::array<ImVec2, 2> m_vec2RenderViewPortBounds;

	Ref<Scene> m_spActiveScene;
	Ref<Scene> m_spEditorScene;
	std::filesystem::path m_sEditorScenePath;
	bool m_bShowPhysicsCollider;
	bool m_bShowDemoWindow;

	Ref<Entity> m_spSquareEntity;
	Ref<Entity> m_spCameraEntity;
	Ref<Entity> m_spHoveredEntity;

	//panel
	int m_iGizmoType;
	Ref<SceneHierarchyPanel> m_spSceneHierarchyPanel;
	Ref<ContentBrowserPanel> m_spContentBrowserPanel;

	Ref<SceneSerializer> m_spSceneSerializer;

	SceneState m_eSceneState;

	Ref<Camera> m_spEditCamera;
};

TINY_ENGINE_NAMESPACE_END

