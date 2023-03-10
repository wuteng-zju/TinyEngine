// 入口函数
#include "TinyEngine/Core/EntryPoint.h"

// 实际应用需要定义自己的Layer并压入LayerStack
#include "SandBoxExampleLayer.h"
#include "SandBox2DLayer.h"
#include "SandBoxEditorLayer.h"
#include "SandBoxParticleLayer.h"



void TinyEngine::Application::CreateApplication()
{
	// 获取应用
	auto app = Application::GetApplication();

	// 创建SandBox编辑层
	auto appLayer = std::make_shared<SandBoxEditorLayer>();
	// 将该层压入应用的开启层栈
	app->PushLayer(appLayer);
}


