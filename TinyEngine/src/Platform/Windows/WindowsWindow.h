#pragma once

/* 
	gl3w.hһ��Ҫ����glfw3.h�����棬
	��Ϊgl3w��װ��GL.h
*/
#define GL_GLEXT_PROTOTYPES
#include "GL/gl3w.h"
#include <GLFW/glfw3.h>

// ���ڻ���
#include "TinyEngine/Core/Window.h"

#include "Platform/OpenGL/Context/OpenGLContext.h"

TINY_ENGINE_NAMESPACE_BEGIN

// ���ڻص����������ݣ�
struct WindowCallBack
{
	std::string Title; // ���ڱ���
	int Width;         // ���ڿ��
	int Height;        // ���ڸ߶�
	bool VSync;        // 

	EventCallbackFn EventCallback; // �¼��ص�����
};

// Windowsƽ̨ʵ�ֵĴ�����
class WindowsWindow :public Window
{
public:
	// ���캯��
	WindowsWindow(const WindowProps& windowPorps);

	// ��������
	virtual ~WindowsWindow();

	// ÿһ֡����
	void OnUpdate() override;

	/********************** �������� ************************/
	// ��ȡ���ڿ��
	inline unsigned int GetWindowWidth() const override;
	// ��ȡ���ڸ߶�
	inline unsigned int GetWindowHeight() const override;
	//���ô����¼��ص�����,ƽ̨����
	inline void SetEventCallback(const EventCallbackFn& eventCallBack) override;
	// ���ô�ֱͬ��
	void SetVSync(bool bEnabled) override;
	// �Ƿ�����ֱͬ��
	bool IsVSync() const override;

	// 
	void* GetNativeWindow()const override;
private:
	// ���ڳ�ʼ��
	virtual void Init();
	// ��������
	virtual void Shutdown();
private:
	// GLFW����
	GLFWwindow* m_pGLFWWindow;

	static Ref<Context> m_spContext;

	// 
	WindowCallBack m_windowCallBack;
};

TINY_ENGINE_NAMESPACE_END