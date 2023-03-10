#include "pch.h"
#include "WindowsInput.h"

#include "GLFW/glfw3.h"

#include "TinyEngine/Core/Application.h"

TINY_ENGINE_NAMESPACE_BEGIN

Ref<Input> Input::m_spInput = Ref<WindowsInput>(new WindowsInput());

bool WindowsInput::IsKeyPressedImpl(KeyCode keyCode)
{
	// 获取当前应用的窗口
	const auto& spWindow = Application::GetApplication()->GetWindow();
	TINY_ENGINE_ASSERT(spWindow, "WindowsInput get window failed");
	// 获取对应的glfw窗口
	auto glfwWindow = static_cast<GLFWwindow*>(spWindow->GetNativeWindow());
	TINY_ENGINE_ASSERT(glfwWindow, "WindowsInput get glfwWindow failed");

	// 调用GLFW的对应函数判断键盘是否按下
	auto state = glfwGetKey(glfwWindow, keyCode);
	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool WindowsInput::IsMouseButtonPressedImpl(MouseCode mouseCode)
{
	const auto& upWindow = Application::GetApplication()->GetWindow();
	TINY_ENGINE_ASSERT(upWindow, "WindowsInput get window failed");
	auto glfwWindow = static_cast<GLFWwindow*>(upWindow->GetNativeWindow());
	TINY_ENGINE_ASSERT(glfwWindow, "WindowsInput get glfwWindow failed");

	auto state = glfwGetMouseButton(glfwWindow, mouseCode);
	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

glm::vec2 WindowsInput::GetMousePosImpl()
{
	const auto& upWindow = Application::GetApplication()->GetWindow();
	TINY_ENGINE_ASSERT(upWindow, "WindowsInput get window failed");
	auto glfwWindow = static_cast<GLFWwindow*>(upWindow->GetNativeWindow());
	TINY_ENGINE_ASSERT(glfwWindow, "WindowsInput get glfwWindow failed");

	double dXPos(0.0), dYPos(0.0);
	glfwGetCursorPos(glfwWindow, &dXPos, &dYPos);
	return glm::vec2(dXPos, dYPos);
}

float WindowsInput::GetMouseXPosImpl()
{
	auto vec2Pos = GetMousePosImpl();
	return vec2Pos.x;
}

float WindowsInput::GetMouseYPosImpl()
{
	auto vec2Pos = GetMousePosImpl();
	return vec2Pos.y;
}

TINY_ENGINE_NAMESPACE_END