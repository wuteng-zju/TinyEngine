#pragma once
#include "entt.hpp"
#include "Components.h"

TINY_ENGINE_NAMESPACE_BEGIN
// 实体类
class Entity
{
public:
	/************************************** 构造函数 ********************************************/
	Entity(const Ref<entt::registry>& spRegistry);
	Entity(const Ref<entt::registry>& spRegistry, const entt::entity& Entity);
	Entity(const Ref<entt::registry>& spRegistry, int iEntityID);

	// 实体的销毁
	void Destrory();


	// 添加组件
	template<typename T, typename... Args>
	T& AddComponent(Args&&... args)
	{
		TINY_ENGINE_ASSERT(!HasComponent<T>(), "Entity already has component!");
		return m_spRegistry->emplace<T>(m_entity, std::forward<Args>(args)...);
	}

	//添加或替换组件 
	template<typename T, typename... Args>
	T& AddOrReplaceComponent(Args&&... args)
	{
		return m_spRegistry->emplace_or_replace<T>(m_entity, std::forward<Args>(args)...);
	}

	// 获取组件
	template<typename T>
	T& GetComponent()
	{
		TINY_ENGINE_ASSERT(HasComponent<T>(), "Entity does not has component!");
		return m_spRegistry->get<T>(m_entity);
	}

	// 判断是否有某个组件
	template<typename T>
	bool HasComponent()
	{
		return m_spRegistry->has<T>(m_entity);
	}

	// 移除某个组件
	template<typename T>
	void RemoveComponent()
	{
		m_spRegistry->remove<T>(m_entity);
	}

	/***************************** 运算符重载 ***********************************/
	bool operator==(const Entity& spEntity) const;
	bool operator!=(const Entity& spEntity) const;
	Entity& operator=(const Entity& spEntity);
	Ref<Entity>& operator=(const Ref<Entity>& spEntity);

	// 获取UUID
	UUID GetUUID();
	// 获取组件名称
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

