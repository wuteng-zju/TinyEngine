#include "pch.h"
#include "OpenGLContext.h"

#include "GL/gl3w.h"
#include "GLFW/glfw3.h"
#include "TinyEngine/Debug/Instrumentor.h"

TINY_ENGINE_NAMESPACE_BEGIN

OpenGLContext::OpenGLContext(GLFWwindow* glfwWindow) :
	m_pGLFWWindow(glfwWindow)
{
	TINY_ENGINE_ASSERT(m_pGLFWWindow, "GLFW window in OpenGLContext is null");
}

void OpenGLContext::Init()
{
	TINY_ENGINE_PROFILE_FUNCTION();
	glfwMakeContextCurrent(m_pGLFWWindow);

	// 初始化gl3w
	int bInit = gl3wInit();
	TINY_ENGINE_ASSERT(!bInit, "Failed to initialize GL3W");

	// 浮点数大小
	LOG_DEV_INFO("{0}", sizeof(float));

	// 通过OpenGL获取设备的显卡信息
	LOG_DEV_INFO("OpenGL Info:");
	LOG_DEV_INFO("Vendor: {0}", glGetString(GL_VENDOR)); //打印厂商
	LOG_DEV_INFO("Renderer:{0}", glGetString(GL_RENDERER));
	LOG_DEV_INFO("Version: {0}", glGetString(GL_VERSION));
}

void OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_pGLFWWindow);
}

TINY_ENGINE_NAMESPACE_END