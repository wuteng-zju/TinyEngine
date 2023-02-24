#pragma once
#include "TinyEngine/Core/KeyCode.h"
#include "TinyEngine/Core/MouseCode.h"

TINY_ENGINE_NAMESPACE_BEGIN

// 输入类
class Input
{
public:
	// 按键
	static bool IsKeyPressed(KeyCode keyCode);

	// 鼠标
	static bool IsMouseButtonPressed(KeyCode keyCode);
	static glm::vec2 GetMousePos();
	static float GetMouseXPos();
	static float GetMouseYPos();

	~Input() = default;
protected:
	virtual bool IsKeyPressedImpl(KeyCode keyCode) = 0;
	virtual bool IsMouseButtonPressedImpl(MouseCode mouseCode) = 0;
	virtual glm::vec2 GetMousePosImpl() = 0;
	virtual float GetMouseXPosImpl() = 0;
	virtual float GetMouseYPosImpl() = 0;

protected:
	Input() = default;
private:
	Input(Input&) = delete;
	Input& operator=(const Input&) = delete;

private:
	static Ref<Input> m_spInput;
};

TINY_ENGINE_NAMESPACE_END