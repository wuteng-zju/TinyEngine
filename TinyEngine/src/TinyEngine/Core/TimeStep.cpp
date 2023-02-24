#include "pch.h"
#include "TimeStep.h"
#include <GLFW/glfw3.h>

TINY_ENGINE_NAMESPACE_BEGIN

TimeStep::TimeStep(float fTime) :m_fTime(fTime)
{

}

const float TimeStep::GetSeconds() const
{
	return m_fTime;
}

const float TimeStep::GetMilliSeconds() const
{
	return m_fTime * 1000.f;
}

TimeStep::operator float() const
{
	return m_fTime;
}

float TimeStep::GetTime()
{
	return glfwGetTime();
}

TINY_ENGINE_NAMESPACE_END