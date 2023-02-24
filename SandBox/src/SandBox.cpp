#include "TinyEngine/Core/EntryPoint.h"

#include "SandBoxExampleLayer.h"
#include "SandBox2DLayer.h"
#include "SandBoxEditorLayer.h"
#include "SandBoxParticleLayer.h"

void TinyEngine::Application::CreateApplication()
{
	auto app = Application::GetApplication();
	auto appLayer = std::make_shared<SandBoxEditorLayer>();
	app->PushLayer(appLayer);
}


