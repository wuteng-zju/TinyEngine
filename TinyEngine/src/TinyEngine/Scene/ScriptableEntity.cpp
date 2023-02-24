#include "pch.h"
#include "ScriptableEntity.h"

TINY_ENGINE_NAMESPACE_BEGIN
ScriptableEntity::ScriptableEntity():m_spEntity(nullptr)
{

}

void ScriptableEntity::SetEntity(const Ref<Entity> spEntity)
{
	m_spEntity = spEntity;
}

TINY_ENGINE_NAMESPACE_END
