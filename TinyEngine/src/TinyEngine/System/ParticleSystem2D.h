#pragma once

TINY_ENGINE_NAMESPACE_BEGIN
class Texture;
class Camera;
class QuadPrimitive;
enum class ParticleRenderType
{
	COLOR = 0,
	TEXTURE
};

struct ParticleProps
{
	glm::vec2 Position;
	glm::vec2 Velocity;
	glm::vec2 VelocityVariation;
	glm::vec4 ColorBegin;
	glm::vec4 ColorEnd;
	float SizeBegin;
	float SizeEnd;
	float SizeVariation;
	float LifeTime;
	Ref<Texture> RefTexture;
	ParticleRenderType ParticleType;
};


// 2D����ϵͳ
class ParticleSystem2D
{
public:
	// ���캯��
	ParticleSystem2D();

	void OnUpdate(Time timeStep);
	void OnRender(const Ref<Camera>& spCamera);

	void Emit(const ParticleProps& particleProps);
private:
	// ������
	struct Particle
	{
		glm::vec2 Position;
		glm::vec2 Velocity;
		glm::vec4 ColorBegin;
		glm::vec4 ColorEnd;
		float Rotation;
		float SizeBegin;
		float SizeEnd;

		float LifeTime;
		float LifeRemaining;

		ParticleRenderType ParticleType;
		Ref<Texture> RefTexture;

		bool Active;
	};

	// ���ӳ�
	std::vector<Particle> m_vecParticlePool;
	// ����ͼԪ
	Ref<QuadPrimitive> m_spQuadPrimtive;
};

TINY_ENGINE_NAMESPACE_END
