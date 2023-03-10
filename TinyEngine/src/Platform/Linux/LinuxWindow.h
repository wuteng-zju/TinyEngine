#pragma once
#include <GLFW/glfw3.h>
#include "TinyEngine/Render/Context.h"

// ���ڻ���
#include "TinyEngine/Core/Window.h"

TINY_ENGINE_NAMESPACE_BEGIN

// Windowsƽ̨�Ĵ�����
class WindowsWindow :public Window
{
public:
	// ���캯��
	WindowsWindow(const WindowProps& windowPorps);

	// ��������
	virtual ~WindowsWindow();

	// ÿһ֡����
	void OnUpdate() override;

	// ��ȡ���ڿ��
	inline unsigned int GetWindowWidth() const override;

	// ��ȡ���ڸ߶�
	inline unsigned int GetWindowHeight() const override;

	// Window attributes
	inline void SetEventCallback(const EventCallbackFn& eventCallBack) override; // 
	void SetVSync(bool bEnabled) override;
	bool IsVSync() const override;

	// 
	void* GetNativeWindow()const override;
private:
	virtual void Init();
	virtual void Shutdown();
private:
	// ������
	static Ref<Context> m_spContext;

	// GLFW����
	GLFWwindow* m_pGLFWWindow;

	// ���ڻص����������ݣ�
	struct WindowCallBack
	{
		std::string Title;
		int Width;
		int Height;
		bool VSync;

		EventCallbackFn EventCallback;
	};

	// 
	WindowCallBack m_windowCallBack;
};

TINY_ENGINE_NAMESPACE_END