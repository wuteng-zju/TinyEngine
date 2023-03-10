#pragma once
#include <GLFW/glfw3.h>
#include "TinyEngine/Render/Context.h"

// 窗口基类
#include "TinyEngine/Core/Window.h"

TINY_ENGINE_NAMESPACE_BEGIN

// Windows平台的窗口类
class WindowsWindow :public Window
{
public:
	// 构造函数
	WindowsWindow(const WindowProps& windowPorps);

	// 析构函数
	virtual ~WindowsWindow();

	// 每一帧调用
	void OnUpdate() override;

	// 获取窗口宽度
	inline unsigned int GetWindowWidth() const override;

	// 获取窗口高度
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
	// 上下文
	static Ref<Context> m_spContext;

	// GLFW窗口
	GLFWwindow* m_pGLFWWindow;

	// 窗口回调（窗口数据）
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