#pragma once
#include "Event.h"

TINY_ENGINE_NAMESPACE_BEGIN

// ���ڴ�С�����¼�
class WindowResizedEvent : public Event
{
public:
	WindowResizedEvent(unsigned int uiWidth, unsigned int uiHeight);
	unsigned int GetWidth()const;
	unsigned int GetHeight()const;
	std::string ToString() const override;

	// ͨ�� Event �̳�
	EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
private:
	unsigned int m_uiWidth;
	unsigned int m_uiHeight;
};

// ���ڹر��¼�
class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent() = default;
	// ͨ�� Event �̳�
	EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

TINY_ENGINE_NAMESPACE_END