#pragma once
#include "Event.h"

TINY_ENGINE_NAMESPACE_BEGIN

// App
class AppTickEvent : public Event
{
public:
	AppTickEvent() = default;
	// ͨ�� Event �̳�
	EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

// App�����¼�
class AppUpdateEvent : public Event
{
public:
	AppUpdateEvent() = default;
	// ͨ�� Event �̳�
	EVENT_CLASS_TYPE(AppUpdate)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

// App��Ⱦ�¼�
class AppRenderEvent : public Event
{
public:
	AppRenderEvent() = default;
	// ͨ�� Event �̳�
	EVENT_CLASS_TYPE(AppRender)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

TINY_ENGINE_NAMESPACE_END