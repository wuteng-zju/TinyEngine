#include "pch.h"
#include "Window.h"

#include "Platform/Windows/WindowsWindow.h"

TINY_ENGINE_NAMESPACE_BEGIN

Ref<Window> Window::Create(const WindowProps& windowPorps)
{
#ifdef TINY_ENGINE_PLATFORM_WINDOWS
	return CreateRef<WindowsWindow>(windowPorps);
#else
	TINY_ENGINE_ASSERT(false, "Unkown platform");
	return nullptr;
#endif // TINY_ENGINE_PLATFORM_WINDOW
}

Window::Window(const WindowProps& windowPorps) :
	m_WindowProps(windowPorps)
{
}

TINY_ENGINE_NAMESPACE_END