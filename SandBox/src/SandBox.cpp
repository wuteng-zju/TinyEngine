// ��ں���
#include "TinyEngine/Core/EntryPoint.h"

// ʵ��Ӧ����Ҫ�����Լ���Layer��ѹ��LayerStack
#include "SandBoxExampleLayer.h"
#include "SandBox2DLayer.h"
#include "SandBoxEditorLayer.h"
#include "SandBoxParticleLayer.h"



void TinyEngine::Application::CreateApplication()
{
	// ��ȡӦ��
	auto app = Application::GetApplication();

	// ����SandBox�༭��
	auto appLayer = std::make_shared<SandBoxEditorLayer>();
	// ���ò�ѹ��Ӧ�õĿ�����ջ
	app->PushLayer(appLayer);
}


