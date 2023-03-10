#pragma once
#include "TinyEngine/System/PhysicsSystem2D.h"
#include "Entity.h"

TINY_ENGINE_NAMESPACE_BEGIN

enum class SceneState
{
	Play = 0,
	Edit,
	Simulate
};

class UUID;

// Scene������
class Scene
{
public:
	// ���캯��
	Scene();
	// ��������
	~Scene();
	// �������캯��
	Scene(const Ref<Scene>& spScene);

	/********************************* ����Entity ********************************************/
	Ref<Entity> CreateEntity(const Ref<Entity>& spSrcEntity);
	Ref<Entity> CreateEntity(const std::string& sName = std::string());
	Ref<Entity> CreateEntityWithUUID(const UUID& uuid, const std::string& sName);

	// 
	void OnRuntimeStart();
	void OnRuntimeStop();

	// 
	void OnSimulationStart();
	void OnSimulationStop();

	// 
	void OnShowPhysicsCollider(const Ref<Camera>& spCamera);

	// 
	void OnUpdate(const Time& timeStep);
	void OnUpdate(const Ref<Camera>& spCamera);
	void OnUpdate(const Time& timeStep, const Ref<Camera>& spCamera);
	void OnViewPortResize(unsigned int uiWidth, unsigned int uiHeight);
	const Ref<entt::registry>& Registry()const;

	// 
	Ref<Entity> GetPrimaryCameraEntity();

private:
	void OnPhysics2DStart();
	void OnPhysics2DStop();
	void RenderScene(const Ref<Camera>& spCamera);
private:
	// 
	unsigned int m_uiWidth;
	unsigned int m_uiHeight;
	Ref<entt::registry> m_spRegistry;
	Ref<PhysicsSystem2D> m_spPhysicsSystem2D;
};

TINY_ENGINE_NAMESPACE_END

