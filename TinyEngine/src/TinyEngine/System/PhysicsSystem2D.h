#pragma once
#include "TinyEngine/Scene/Components.h"
#include "box2d/b2_world.h"

TINY_ENGINE_NAMESPACE_BEGIN

enum class BodyType
{
	Static = 0,
	Dynamic,
	Kinematic
};

const std::array<std::string, 3> BodyTypeStrings = { "Static","Dynamic","Kinematic" };

// 2D刚体组件类
struct RigidBody2DComponent
{
	BodyType Type = BodyType::Static;
	bool FixedRotation = false;
	void* RuntimeBody;

	// 默认构造函数
	RigidBody2DComponent() = default;
	// 默认拷贝构造函数
	RigidBody2DComponent(const RigidBody2DComponent&) = default;
};

// 矩形物体组件类
struct BoxCollider2DComponent
{
	glm::vec2 Offset = glm::vec2(0.f);
	glm::vec2 Size = glm::vec2(0.5f);

	float Density = 1.f;
	float Friction = 0.5f;
	float Restitution = 0.f;
	float RestitutionThreshold = 0.5f;

	BoxCollider2DComponent() = default;
	BoxCollider2DComponent(const BoxCollider2DComponent&) = default;
};

// 圆形物体组件类
struct CircleCollider2DComponent
{
	glm::vec2 Offset = glm::vec2(0.f);
	float Radius = 0.5f;

	float Density = 1.f;
	float Friction = 0.5f;
	float Restitution = 0.f;
	float RestitutionThreshold = 0.5f;

	CircleCollider2DComponent() = default;
	CircleCollider2DComponent(const CircleCollider2DComponent&) = default;
};

// 2D物理系统
class PhysicsSystem2D
{
public:
	// 构造函数
	PhysicsSystem2D();
	// 析构函数
	~PhysicsSystem2D();

	// 
	void CreateBody(RigidBody2DComponent& rigidBody2D, const TransformComponent& transform);

	// 创建矩形形状
	void CreatePolygonShape(BoxCollider2DComponent& boxCollider2D, const TransformComponent& transform);
	// 创建圆形形状
	void CreateCircleShape(CircleCollider2DComponent& circleCollider2D, const TransformComponent& transform);

	// 用于每一帧的更新
	void OnUpdate(const Time& timeStep);
	// 更新系统
	void UpdateSystem(RigidBody2DComponent& rigidBody2D, TransformComponent& transform);
private:
	// 2D世界
	Ref<b2World> m_spPhysicsWorld;
	// 
	b2Body* m_pBody;
};

TINY_ENGINE_NAMESPACE_END

