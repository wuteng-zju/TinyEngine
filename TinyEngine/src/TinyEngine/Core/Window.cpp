#include "pch.h"

// Window平台下实现的窗口类
#include "Platform/Windows/WindowsWindow.h"

TINY_ENGINE_NAMESPACE_BEGIN

// 创建窗口
Ref<Window> Window::Create(const WindowProps& windowPorps)
{
// 如果当前编译平台是Windows，则使用WindowsWindow创建窗口
#ifdef TINY_ENGINE_PLATFORM_WINDOWS
	return CreateRef<WindowsWindow>(windowPorps);
#else
	TINY_ENGINE_ASSERT(false, "Unkown platform");
	return nullptr;
#endif // TINY_ENGINE_PLATFORM_WINDOW
}

// 构造函数
Window::Window(const WindowProps& windowPorps) :
	m_WindowProps(windowPorps)
{
}

TINY_ENGINE_NAMESPACE_END