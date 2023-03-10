#include "pch.h"

// Windowƽ̨��ʵ�ֵĴ�����
#include "Platform/Windows/WindowsWindow.h"

TINY_ENGINE_NAMESPACE_BEGIN

// ��������
Ref<Window> Window::Create(const WindowProps& windowPorps)
{
// �����ǰ����ƽ̨��Windows����ʹ��WindowsWindow��������
#ifdef TINY_ENGINE_PLATFORM_WINDOWS
	return CreateRef<WindowsWindow>(windowPorps);
#else
	TINY_ENGINE_ASSERT(false, "Unkown platform");
	return nullptr;
#endif // TINY_ENGINE_PLATFORM_WINDOW
}

// ���캯��
Window::Window(const WindowProps& windowPorps) :
	m_WindowProps(windowPorps)
{
}

TINY_ENGINE_NAMESPACE_END