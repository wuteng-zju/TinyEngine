#pragma once
#include "TinyEngine/Render/Context.h"

struct GLFWwindow;
TINY_ENGINE_NAMESPACE_BEGIN

class OpenGLContext :public Context
{
public:
	OpenGLContext(GLFWwindow* glfwWindow);
	virtual void Init() override;
	virtual void SwapBuffers()override;
private:
	GLFWwindow* m_pGLFWWindow;
};

TINY_ENGINE_NAMESPACE_END