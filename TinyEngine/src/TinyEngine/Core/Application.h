#pragma once
#include "Window.h"
#include "LayerStack.h"
#include "TinyEngine/ImGui/ImGuiLayer.h"


TINY_ENGINE_NAMESPACE_BEGIN
// ��Ϸ/Ӧ�û���
class Application
{
public:
	// �ڿͻ����ж���ʵ��
	static void CreateApplication();
	// ��ȡApplication
	static Ref<Application> GetApplication();
	// ����App
	void Run();

	// ���캯��
	Application();

	// ��������
	virtual~Application();

	// 
	void Close();

	// �¼����
	void OnEvent(Event& event);
	void BlockEvents(bool bBlock);

	// �������
	int GetWindowWidth() const;
	int GetWindowHeight() const;
	const Ref<Window>& GetWindow()const;

	// Layer���
	void PushLayer(Ref<Layer> spLayer);
	void PushOverlay(Ref<Layer> spLayer);

private:
	// ��ʼ��
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
	* ÿ��Ӧ��(��Ϸ)��״̬������
		m_bRunning����ǰӦ���Ƿ�������
		m_spWindow����ǰӦ�õ����д���
		m_spLayerStack����ǰӦ�õĲ�ջ��һ��Ӧ��ֻ��Ҫһ��LayerStack����Ŷ��Layer
		m_Minimized����ǰӦ�ô����Ƿ���С��
		m_fLastFrameTime����ǰӦ�����һ֡��Ⱦ��ʱ��
	*********************/
	// ��ǰApp�Ƿ�������
	bool m_bRunning;

	// �Ƿ���С��
	bool m_bMinimized;

	// ���һ֡��ʱ��
	float m_fLastFrameTime;

	// Ӧ�ô���
	Ref<Window> m_spWindow;

	// ��ջ
	Ref<LayerStack> m_spLayerStack;

	// 
	Ref<ImGuiLayer> m_spImGuiLayer;

	// 
	static Ref<Application> m_spApplication;
};

TINY_ENGINE_NAMESPACE_END