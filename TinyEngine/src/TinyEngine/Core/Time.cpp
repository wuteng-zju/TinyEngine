#include "pch.h"
#include "Time.h"

#include <GLFW/glfw3.h>

TINY_ENGINE_NAMESPACE_BEGIN

// 构造函数
Time::Time(float fTime) :m_fTime(fTime)
{

}

// 以秒为单位获取时间
const float Time::GetSeconds() const
{
	return m_fTime;
}

// 以毫秒为单位获取时间
const float Time::GetMilliSeconds() const
{
	return m_fTime * 1000.f;
}

// 重载()运算符，可以直接获取时间
Time::operator float() const
{
	return m_fTime;
}

// 返回时间
float Time::GetTime()
{
	return glfwGetTime();
}

TINY_ENGINE_NAMESPACE_END