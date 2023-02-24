#pragma once

TINY_ENGINE_NAMESPACE_BEGIN
class Scene;
class Entity;
class SceneHierarchyPanel
{
public:
	SceneHierarchyPanel(const Ref<Scene>& spScene);
	void OnImGuiRender();
	void SetSelectedEntity(const Ref<Entity>& spEntity);
	const Ref<Entity>& GetSelectedEntity()const;
	void SetSelectedScene(const Ref<Scene>& spScene);

private:
	void DrawEntityNode(const Ref<Entity>& spEntity);
	void DrawComponents(const Ref<Entity>& spEntity);
private:
	Ref<Scene> m_spScene;
	Ref<Entity> m_spSelectedEntity;
};
TINY_ENGINE_NAMESPACE_END



