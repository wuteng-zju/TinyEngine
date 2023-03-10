#pragma once
#include "TinyEngine/Core/Input.h"

TINY_ENGINE_NAMESPACE_BEGIN
// Windows平台下的Input输入类
class WindowsInput :public Input
{
protected:
	virtual bool IsKeyPressedImpl(KeyCode keyCode) override;
	virtual bool IsMouseButtonPressedImpl(MouseCode mouseCode)override;
	virtual glm::vec2 GetMousePosImpl()override;
	virtual float GetMouseXPosImpl() override;
	virtual float GetMouseYPosImpl() override;
};

TINY_ENGINE_NAMESPACE_END