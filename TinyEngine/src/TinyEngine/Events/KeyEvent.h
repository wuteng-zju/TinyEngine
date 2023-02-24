#pragma once
#include "TinyEngine/Core/KeyCode.h"
#include "Event.h"

TINY_ENGINE_NAMESPACE_BEGIN

// �����¼�
class KeyEvent : public Event
{
public:
	// 
	KeyCode GetKeyCode() const;

	// 
	EVENT_CLASS_CATEGORY(EventCategoryKeyBoard | EventCategoryInput)
protected:
	// ���캯��
	KeyEvent(KeyCode uiKeyCode);

	// 
	KeyCode m_uiKeyCode;
};

// ���������¼�
class KeyPressedEvent :public KeyEvent
{
public:
	// 
	KeyPressedEvent(KeyCode uiKeyCode, bool bRepeat = false);

	// 
	bool IsRepeat()const;

	// 
	std::string ToString()const override;

	// 
	EVENT_CLASS_TYPE(KeyPressed)
private:
	// 
	bool m_bRepeat;
};

// �����ͷ��¼�
class KeyReleasedEvent :public KeyEvent
{
public:
	// ���캯��
	KeyReleasedEvent(KeyCode uiKeyCode);

	// 
	std::string ToString()const override;

	// 
	EVENT_CLASS_TYPE(KeyReleased)
};


// ���������¼�
class KeyTypedEvent :public KeyEvent
{
public:
	// 
	KeyTypedEvent(KeyCode uiKeyCode);

	// 
	std::string ToString()const override;

	// 
	EVENT_CLASS_TYPE(KeyTyped)
};

TINY_ENGINE_NAMESPACE_END