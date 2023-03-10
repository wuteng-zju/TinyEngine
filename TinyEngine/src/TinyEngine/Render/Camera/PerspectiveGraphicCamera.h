#pragma once
#include "Camera.h"

TINY_ENGINE_NAMESPACE_BEGIN
// ͸�������
class PerspectiveGraphicCamera :public Camera
{
public:
	PerspectiveGraphicCamera();
	PerspectiveGraphicCamera(float fFOV, float fAspectRatio, float fNearClip = 0.1f, float fFarClip = 1000.f);
	void SetPerspectiveFOV(float fFOV);
	float GetPerspectiveFOV();
private:
	void RecalculateProjectionMatrix() override;
private:
	float m_fFOV;
};

TINY_ENGINE_NAMESPACE_END

