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

// 2D���������
struct RigidBody2DComponent
{
	BodyType Type = BodyType::Static;
	bool FixedRotation = false;
	void* RuntimeBody;

	// Ĭ�Ϲ��캯��
	RigidBody2DComponent() = default;
	// Ĭ�Ͽ������캯��
	RigidBody2DComponent(const RigidBody2DComponent&) = default;
};

// �������������
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

// Բ�����������
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

// 2D����ϵͳ
class PhysicsSystem2D
{
public:
	// ���캯��
	PhysicsSystem2D();
	// ��������
	~PhysicsSystem2D();

	// 
	void CreateBody(RigidBody2DComponent& rigidBody2D, const TransformComponent& transform);

	// ����������״
	void CreatePolygonShape(BoxCollider2DComponent& boxCollider2D, const TransformComponent& transform);
	// ����Բ����״
	void CreateCircleShape(CircleCollider2DComponent& circleCollider2D, const TransformComponent& transform);

	// ����ÿһ֡�ĸ���
	void OnUpdate(const Time& timeStep);
	// ����ϵͳ
	void UpdateSystem(RigidBody2DComponent& rigidBody2D, TransformComponent& transform);
private:
	// 2D����
	Ref<b2World> m_spPhysicsWorld;
	// 
	b2Body* m_pBody;
};

TINY_ENGINE_NAMESPACE_END

