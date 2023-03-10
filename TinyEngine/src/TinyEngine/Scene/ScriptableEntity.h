#pragma once
#include "Entity.h"

TINY_ENGINE_NAMESPACE_BEGIN
class ScriptableEntity
{
public:
	ScriptableEntity();
	virtual ~ScriptableEntity() = default;
	void SetEntity(const Ref<Entity> spEntity);

	template<typename T>
	T& GetComponent()
	{
		return m_spEntity->GetComponent<T>();
	}
	virtual void OnCreate() {}
	virtual void OnUpdate(Time ts) {}
private:
	Ref<Entity> m_spEntity;
};

TINY_ENGINE_NAMESPACE_END