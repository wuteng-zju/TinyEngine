#pragma once
#include "Window.h"
#include "LayerStack.h"
#include "TinyEngine/ImGui/ImGuiLayer.h"


TINY_ENGINE_NAMESPACE_BEGIN
// 游戏/应用基类
class Application
{
public:
	// 在客户端中定义实现
	static void CreateApplication();
	// 获取Application
	static Ref<Application> GetApplication();
	// 运行App
	void Run();

	// 构造函数
	Application();

	// 析构函数
	virtual~Application();

	// 
	void Close();

	// 事件相关
	void OnEvent(Event& event);
	void BlockEvents(bool bBlock);

	// 窗口相关
	int GetWindowWidth() const;
	int GetWindowHeight() const;
	const Ref<Window>& GetWindow()const;

	// Layer相关
	void PushLayer(Ref<Layer> spLayer);
	void PushOverlay(Ref<Layer> spLayer);

private:
	// 初始化
	void Init();
	// 
	Application(Application&) = delete;
	// 
	Application& operator=(const Application&) = delete;

private:
	bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
	bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
	bool OnMouseMovedEvent(MouseMovedEvent& event);
	bool OnMouseScrolledEvent(MouseScrolledEvent& event);

	bool OnKeyPressedEvent(KeyPressedEvent& event);
	bool OnKeyReleasedEvent(KeyReleasedEvent& event);
	bool OnKyeTypedEvent(KeyEvent& event);

	bool OnWindowResizedEvent(WindowResizedEvent& event);
	bool OnWindowClosedEvent(WindowCloseEvent& e);
private:
	/***************** 
	* 每个应用(游戏)的状态包括：
		m_bRunning：当前应用是否在运行
		m_spWindow：当前应用的运行窗口
		m_spLayerStack：当前应用的层栈，一个应用只需要一个LayerStack，存放多个Layer
		m_Minimized：当前应用窗口是否被最小化
		m_fLastFrameTime：当前应用最近一帧渲染的时间
	*********************/
	// 当前App是否在运行
	bool m_bRunning;

	// 是否最小化
	bool m_bMinimized;

	// 最后一帧的时间
	float m_fLastFrameTime;

	// 应用窗口
	Ref<Window> m_spWindow;

	// 层栈
	Ref<LayerStack> m_spLayerStack;

	// 
	Ref<ImGuiLayer> m_spImGuiLayer;

	// 
	static Ref<Application> m_spApplication;
};

TINY_ENGINE_NAMESPACE_END