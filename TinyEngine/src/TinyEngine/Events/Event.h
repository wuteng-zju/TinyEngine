#pragma once
#include "pch.h"

TINY_ENGINE_NAMESPACE_BEGIN

// �¼�����
enum class EventType
{
	// ���¼�
	None = 0,
	// ���ڲ���
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
	// App����
	AppTick, AppUpdate, AppRender,
	// ���̲���������ĳ�������ͷ�ĳ����������ĳ������
	KeyPressed, KeyReleased, KeyTyped,
	// ������
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

// �¼����ÿһ��������λ��Ӧһ�����,֧��һ��Event��Ӧ���EventCategory�������չ֧��64���¼����
enum EventCategory
{
	// ���¼�
	None = 0,
	// App�¼�
	EventCategoryApplication = BIT(0),
	// �����¼�
	EventCategoryInput = BIT(1),
	// �����¼�
	EventCategoryKeyBoard = BIT(2),
	// ����¼�
	EventCategoryMouse = BIT(3),
	// ��갴ť�¼�
	EventCategoryMouseButton = BIT(4)
};

// �¼�����
#define EVENT_CLASS_TYPE(type) \
	static EventType GetStaticType(){return EventType::##type; }\
	virtual EventType GetEventType()const override {return GetStaticType(); }\
	virtual const char* GetName()const override {return #type;}

// �¼����
#define EVENT_CLASS_CATEGORY(category) \
	virtual int GetCategoryFlags() const override { return category; }

// Event��
class Event
{
public:
	// ��������
	virtual ~Event() = default;

	// //��ȡ�¼����ͣ����麯����
	virtual EventType GetEventType() const = 0;

	// ��ȡ���¼������ƣ����麯����
	virtual const char* GetName() const = 0;

	// ��ȡ���¼��������¼���𣨿ɶ���������麯����
	virtual int GetCategoryFlags() const = 0;
	
	// �����ӡ���ԣ����麯����
	virtual std::string ToString() const { return GetName(); }

	// �жϸ��¼��Ƿ�����ĳһ���
	inline bool IsInCategory(EventCategory category)
	{
		// �����¼��������¼����������������������
		return GetCategoryFlags() & category;
	}
public:
	// �¼��ַ�һ�δ�����ɱ�ǣ���������ֹ�¼����´���
	bool Handle = false;

};

// �¼��ַ��࣬���ڸ����¼����͵Ĳ�ͬ�����ò�ͬ�ĺ���
class EventDispatcher
{
	// EventFn�洢��һ������Ϊ�������͵����ã�����ֵΪbool�ĺ���ָ��
	template<typename T>
	using EventFn = std::function<bool(T&)>;
public:
	// ���캯��
	EventDispatcher(Event& event) :m_event(event)
	{

	}

	// ����һ��EventFn���͵ĺ���ָ��
	template<typename T>
	bool Dispatch(EventFn<T> func)
	{
		// �����ǰ�¼���������¼����
		if (m_event.GetEventType() == T::GetStaticType())
		{
			m_event.Handle |= func(static_cast<T&>(m_event));
			return true;
		}
		return false;
	}
private:
	// �¼�
	Event& m_event;
};

// ����������������������¼������ƣ�
inline std::ostream& operator<<(std::ostream& os, const Event& e)
{
	return os << e.ToString();
}

TINY_ENGINE_NAMESPACE_END