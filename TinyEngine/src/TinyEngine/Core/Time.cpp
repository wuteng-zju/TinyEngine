#include "pch.h"
#include "Time.h"

#include <GLFW/glfw3.h>

TINY_ENGINE_NAMESPACE_BEGIN

// ���캯��
Time::Time(float fTime) :m_fTime(fTime)
{

}

// ����Ϊ��λ��ȡʱ��
const float Time::GetSeconds() const
{
	return m_fTime;
}

// �Ժ���Ϊ��λ��ȡʱ��
const float Time::GetMilliSeconds() const
{
	return m_fTime * 1000.f;
}

// ����()�����������ֱ�ӻ�ȡʱ��
Time::operator float() const
{
	return m_fTime;
}

// ����ʱ��
float Time::GetTime()
{
	return glfwGetTime();
}

TINY_ENGINE_NAMESPACE_END