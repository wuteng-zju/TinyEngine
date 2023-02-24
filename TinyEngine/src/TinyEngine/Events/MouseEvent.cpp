#include "pch.h"
#include "MouseEvent.h"

TINY_ENGINE_NAMESPACE_BEGIN

MouseMovedEvent::MouseMovedEvent(float fMouseX, float fMouseY) :
	m_fMouseX(fMouseX), m_fMouseY(fMouseY)
{

}
float MouseMovedEvent::GetMouseX() const
{
	return m_fMouseX;
}
float MouseMovedEvent::GetMouseY() const
{
	return m_fMouseY;
}
std::string MouseMovedEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseMoved: " << m_fMouseX << " , " << m_fMouseY;
	return ss.str();
}


MouseScrolledEvent::MouseScrolledEvent(float fXOffset, float fYOffset) :
	m_fXOffset(fXOffset), m_fYOffset(fYOffset)
{
}
float MouseScrolledEvent::GetXOffset() const
{
	return m_fXOffset;
}
float MouseScrolledEvent::GetYOffset() const
{
	return m_fYOffset;
}
std::string MouseScrolledEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseScrolled: " << m_fXOffset << " , " << m_fYOffset;
	return ss.str();
}


MouseButtonEvent::MouseButtonEvent(MouseCode uiMouseCode) :
	m_uiMouseCode(uiMouseCode)
{

}

MouseButtonPressedEvent::MouseButtonPressedEvent(MouseCode uiMouseCode) :
	MouseButtonEvent(uiMouseCode)
{

}
std::string MouseButtonPressedEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseButtonPressed: " << m_uiMouseCode;
	return ss.str();;
}

MouseButtonReleasedEvent::MouseButtonReleasedEvent(MouseCode uiMouseCode) :
	MouseButtonEvent(uiMouseCode)
{
}
std::string MouseButtonReleasedEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseButtonRelease: " << m_uiMouseCode;
	return ss.str();;
}
MouseCode MouseButtonEvent::GetMouseButton() const
{
	return m_uiMouseCode;
}

TINY_ENGINE_NAMESPACE_END