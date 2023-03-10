#pragma once
#include <glm/gtc/matrix_transform.hpp>

TINY_ENGINE_NAMESPACE_BEGIN

// 投影类型：透视投影或正交投影
enum class ProjectionType
{
	Perspective = 0,
	Orthographic
};

const std::array<std::string, 2> ProjectionTypeStrings = { "Perspective","Orthographic" };


struct CameraMatrix
{
	glm::mat4 ViewProjection;
};

// 相机抽象类
class Camera
{
public:
	Camera(float fAspectRatio, float fNear, float fFar, ProjectionType eProjectionType);
	~Camera() = default;
	void SetPosition(const glm::vec3& vec3Position);
	const glm::vec3& GetPositon()const;
	void SetScale(const glm::vec3& vec3Scale);
	const glm::vec3& GetScale()const;
	void SetRotation(const glm::quat& quatRotation);
	const glm::quat& GetRotaion()const;

	void SetProjectionMatrix(const glm::mat4& mat4ProjectionMatrix);
	const glm::mat4& GetProjectionMatrix()const;
	void SetViewMatrix(const glm::mat4& mat4ViewMatrix);
	const glm::mat4& GetViewMatrix()const;
	const glm::mat4& GetViewProjectionMatrix()const;
	ProjectionType GetProjectionType();
	void SetProjectionType(ProjectionType eProjectionType);

	void SetNearAndFarClip(float fNear, float fFar);
	void SetNearClip(float fNear);
	float GetNearClip() const;
	void SetFarClip(float fFar);
	float GetFarClip() const;

	void SetViewPortSize(unsigned int uiWidth, unsigned int uiHeight);
	void SetAspectRatio(float fAspectRatio);
	float GetAspectRatio();

protected:
	virtual void RecalculateProjectionMatrix() = 0;
	void RecalculateViewProjectionMatrix();
	void RecalculateViewMatrix();

protected:
	ProjectionType m_eProjectionType;
	glm::mat4 m_mat4ProjectionMatrix;

	glm::mat4 m_mat4ViewMatrix;
	glm::mat4 m_mat4ViewProjectionMatrix;
	glm::vec3 m_vec3Position;
	glm::vec3 m_vec3Scale;
	glm::quat m_quatRotation;

	float m_fNearClip;
	float m_fFarClip;
	float m_fAspectRatio;
	unsigned int m_uiWidth;
	unsigned int m_uiHeight;
};

TINY_ENGINE_NAMESPACE_END
