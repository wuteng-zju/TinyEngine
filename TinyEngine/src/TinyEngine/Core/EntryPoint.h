#pragma once
#include "pch.h"

#include "Application.h"
#include "Logger.h"
#include "TinyEngine/Debug/Instrumentor.h"

#ifdef TINY_ENGINE_PLATFORM_WINDOWS

// ���main����
int main(int argc, char**argv)
{
	// 
	LOG_DEV_WARN("Initialize Log!");

	// 
	TINY_ENGINE_PROFILE_BEGIN_SESSION("Startup", "TinyEngineProfile-Startup.json");
	// ����Ӧ��
	TinyEngine::Application::CreateApplication();
	TINY_ENGINE_PROFILE_END_SESSION();


	// 
	TINY_ENGINE_PROFILE_BEGIN_SESSION("Runtime", "TinyEngineProfile-Startup.json");
	// ��ȡӦ��
	auto app = TinyEngine::Application::GetApplication();
	// ����
	app->Run();
	TINY_ENGINE_PROFILE_END_SESSION();

	EXIT_SUCCESS;
}

#endif // TINY_ENGINE_PLATFORM_WINDOWS
