#pragma once

TINY_ENGINE_NAMESPACE_BEGIN

// ʱ����
class Time
{
public:
	// ���캯��
	Time(float fTime = 0.f);
	// ����Ϊ��λ��ȡʱ��
	const float GetSeconds() const;
	// �Ժ���Ϊ��λ��ȡʱ��
	const float GetMilliSeconds()const;
	// ��������
	operator float()const;
	// ��ȡʱ��
	static float GetTime();
private:
	// ʱ��ֵ
	float m_fTime;
};

TINY_ENGINE_NAMESPACE_END