#pragma once
#include "entt.hpp"
#include "Components.h"

TINY_ENGINE_NAMESPACE_BEGIN
// ʵ����
class Entity
{
public:
	/************************************** ���캯�� ********************************************/
	Entity(const Ref<entt::registry>& spRegistry);
	Entity(const Ref<entt::registry>& spRegistry, const entt::entity& Entity);
	Entity(const Ref<entt::registry>& spRegistry, int iEntityID);

	// ʵ�������
	void Destrory();


	// ������
	template<typename T, typename... Args>
	T& AddComponent(Args&&... args)
	{
		TINY_ENGINE_ASSERT(!HasComponent<T>(), "Entity already has component!");
		return m_spRegistry->emplace<T>(m_entity, std::forward<Args>(args)...);
	}

	//��ӻ��滻��� 
	template<typename T, typename... Args>
	T& AddOrReplaceComponent(Args&&... args)
	{
		return m_spRegistry->emplace_or_replace<T>(m_entity, std::forward<Args>(args)...);
	}

	// ��ȡ���
	template<typename T>
	T& GetComponent()
	{
		TINY_ENGINE_ASSERT(HasComponent<T>(), "Entity does not has component!");
		return m_spRegistry->get<T>(m_entity);
	}

	// �ж��Ƿ���ĳ�����
	template<typename T>
	bool HasComponent()
	{
		return m_spRegistry->has<T>(m_entity);
	}

	// �Ƴ�ĳ�����
	template<typename T>
	void RemoveComponent()
	{
		m_spRegistry->remove<T>(m_entity);
	}

	/***************************** ��������� ***********************************/
	bool operator==(const Entity& spEntity) const;
	bool operator!=(const Entity& spEntity) const;
	Entity& operator=(const Entity& spEntity);
	Ref<Entity>& operator=(const Ref<Entity>& spEntity);

	// ��ȡUUID
	UUID GetUUID();
	// ��ȡ�������
	const std::string& GetName();

	operator uint32_t() const;
	operator entt::entity()const;

private:
	// 
	Ref<entt::registry> m_spRegistry;
	// 
	entt::entity m_entity;
};

TINY_ENGINE_NAMESPACE_END

