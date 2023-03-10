#include "pch.h"
#include "Application.h"

#include "Input.h"

#include "TinyEngine/Events/ApplicationEvent.h"

#include "TinyEngine/Render/Render.h"
#include "TinyEngine/Render/Render2D/Render2D.h"

TINY_ENGINE_NAMESPACE_BEGIN

// 
Ref<Application> Application::m_spApplication = nullptr;

// ���캯��
Application::Application(): m_bRunning(true), m_fLastFrameTime(0.f), m_bMinimized(false)
{
	TINY_ENGINE_PROFILE_FUNCTION();
	// ��������
	m_spWindow = Window::Create();

	// ���ô��ڵ��¼��ص�����Ϊ��Ӧ�ö����OnEvent����
	m_spWindow->SetEventCallback(BIND_EVENT_FUN(Application::OnEvent));
}

// ��������
Application::~Application()
{

}

// 
void Application::Init()
{
	TINY_ENGINE_PROFILE_FUNCTION();
	// 
	Render::Init();
	// 
	Render2D::Init();
	// ������ջ
	m_spLayerStack = CreateRef<LayerStack>();
	// ����ImGuiLayer
	m_spImGuiLayer = CreateRef<ImGuiLayer>();
	// ��ImGui��Ϊ���ǲ�ѹ���ջ
	PushOverlay(m_spImGuiLayer);
}

// ����Ӧ�ó���
void Application::Run()
{
	// ��Ⱦѭ��
	while (m_bRunning)
	{
		// ��ȡ��ǰʱ��
		float fTime = Time::GetTime();
		// deltaTimeΪ��ǰ֡����һ֡��ʱ���
		Time deltaTime = fTime - m_fLastFrameTime;
		// ���µ�ǰ֡Ϊ��һ֡
		m_fLastFrameTime = fTime;

		// ��ȡ��ǰ�����е�Ӧ�õĿ�����ջ
		const auto& listLayers = m_spLayerStack->GetLayers();

		// �����ǰ����û����С��
		if (!m_bMinimized)
		{
			{
				TINY_ENGINE_PROFILE_SCOPE("Layer OnUpdate")
				// ���������ջ�����ε���ÿһ��ĸ��º���������ÿһ�㣩
				for (auto iter = listLayers.begin(); iter != listLayers.end(); iter++)
				{
					(*iter)->OnUpdate(deltaTime);
				}
			}

			// ͳһ�������в��ImGui����
			m_spImGuiLayer->BeginNewFrame();
			{
				// ÿһ��Layer���ڵ���ImGuiRender����
				TINY_ENGINE_PROFILE_SCOPE("Layer OnImGuiRender")
				for (auto iter = listLayers.begin(); iter != listLayers.end(); iter++)
				{
					(*iter)->OnImGuiRender();
				}
			}
			m_spImGuiLayer->EndNewFrame();
		}

		// ���´���(��Ⱦ)
		m_spWindow->OnUpdate();
	}
}

// 
void Application::OnEvent(Event& event)
{
	// �����¼��ַ���
	EventDispatcher dispatcher(event);
	dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FUN(Application::OnMouseButtonPressedEvent));
	dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FUN(Application::OnMouseButtonReleasedEvent));
	dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FUN(Application::OnMouseMovedEvent));
	dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FUN(Application::OnMouseScrolledEvent));
	dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FUN(Application::OnKeyPressedEvent));
	dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FUN(Application::OnKeyReleasedEvent));
	dispatcher.Dispatch<KeyTypedEvent>(BIND_EVENT_FUN(Application::OnKyeTypedEvent));
	dispatcher.Dispatch<WindowResizedEvent>(BIND_EVENT_FUN(Application::OnWindowResizedEvent));
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUN(Application::OnWindowClosedEvent));

	// ���������ջ�е�ÿһ�㴦���¼�
	const auto& listLayers = m_spLayerStack->GetLayers();
	for (auto iter = listLayers.rbegin(); iter != listLayers.rend(); iter++)
	{
		if (event.Handle)
		{
			break;
		}
		(*iter)->OnEvent(event);
	}
}

// 
void Application::BlockEvents(bool bBlock)
{
	m_spImGuiLayer->BlockEvents(bBlock);
}

// 
void Application::PushLayer(Ref<Layer> spLayer)
{
	TINY_ENGINE_PROFILE_FUNCTION();

	m_spLayerStack->PushLayer(spLayer);
	spLayer->OnAttach();
}

// 
void Application::PushOverlay(Ref<Layer> spLayer)
{
	TINY_ENGINE_PROFILE_FUNCTION();

	m_spLayerStack->PushOverlay(spLayer);
	spLayer->OnAttach();
}

// 
void Application::Close()
{
	m_bRunning = false;
}

// 
Ref<Application> Application::GetApplication()
{
	if (m_spApplication == nullptr)
	{
		// 
		m_spApplication = Ref<Application>(new Application());
		// 
		m_spApplication->Init();
	}
	return m_spApplication;
}

// 
bool Application::OnMouseButtonPressedEvent(MouseButtonPressedEvent& event)
{
	return false;
}

bool Application::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event)
{
	return false;
}

bool Application::OnMouseMovedEvent(MouseMovedEvent& event)
{
	return false;
}

bool Application::OnMouseScrolledEvent(MouseScrolledEvent& event)
{
	return false;
}

bool Application::OnKeyPressedEvent(KeyPressedEvent& event)
{
	if (event.GetKeyCode() == Key::Escape)
	{
		m_bRunning = false;
	}
	return false;
}

bool Application::OnKeyReleasedEvent(KeyReleasedEvent& event)
{
	return false;
}

bool Application::OnKyeTypedEvent(KeyEvent& event)
{
	return false;
}

bool Application::OnWindowResizedEvent(WindowResizedEvent& event)
{
	if (event.GetWidth() == 0 || event.GetHeight() == 0)
	{
		m_bMinimized = true;
		return false;
	}
	m_bMinimized = false;
	Render::OnWindowResize(event.GetWidth(), event.GetHeight());
	return false;
}

bool Application::OnWindowClosedEvent(WindowCloseEvent& /*event*/)
{
	m_bRunning = false;
	return true;
}

int Application::GetWindowWidth() const
{
	return m_spWindow->GetWindowWidth();
}

int Application::GetWindowHeight() const
{
	return m_spWindow->GetWindowHeight();
}

const Ref<Window>& Application::GetWindow() const
{
	return m_spWindow;
}

TINY_ENGINE_NAMESPACE_END