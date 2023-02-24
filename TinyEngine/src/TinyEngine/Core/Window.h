#pragma once
#include "TinyEngine/Events/KeyEvent.h"
#include "TinyEngine/Events/MouseEvent.h"
#include "TinyEngine/Events/ApplicationEvent.h"
#include "TinyEngine/Events/WindowEvent.h"

TINY_ENGINE_NAMESPACE_BEGIN

// ��������
struct WindowProps
{
	// ���ڱ���
	std::string Title;

	// ���ڿ�Ⱥ͸߶�
	int Width;
	int Height;

	// 
	int MajorVersion;
	int MinorVersion;

	// 
	int Samples;

	// ���캯��
	WindowProps(const std::string& sTitle = "TinyEngine", int iWidth = 1280, int iHeight = 720, int Samples = 0)
		: Title(sTitle),
		Width(iWidth),
		Height(iHeight),
		MajorVersion(4),
		MinorVersion(3),
		Samples(Samples)
	{
	}
};

// ���ڳ�����
class Window
{
public:
	// �¼��ص�����
	using EventCallbackFn = std::function<void(Event&)>;

	// ��������
	virtual ~Window() {}

	// ÿһ֡����
	virtual void OnUpdate() = 0;

	// ��ȡ���ڿ��
	virtual unsigned int GetWindowWidth() const = 0;

	// ��ȡ���ڸ߶�
	virtual unsigned int GetWindowHeight() const = 0;

	// Window attributes
	virtual void SetEventCallback(const EventCallbackFn& callback) = 0; // ���ô����¼��ص�����,ƽ̨����
	virtual void SetVSync(bool enabled) = 0; // 
	virtual bool IsVSync() const = 0;

	virtual void* GetNativeWindow()const = 0;

	// ��������
	static Ref<Window> Create(const WindowProps& windowPorps = WindowProps());
protected:
	// ���캯��
	Window(const WindowProps& windowPorps);
private:
	Window() = delete;
	Window(Window&) = delete;
	Window& operator=(const Window&) = delete;
protected:
	// ��������
	WindowProps m_WindowProps;
};

TINY_ENGINE_NAMESPACE_END