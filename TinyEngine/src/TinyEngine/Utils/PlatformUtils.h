#pragma once
#include "pch.h"

TINY_ENGINE_NAMESPACE_BEGIN

class PlatformUtils
{
public:
	// ���ļ�
	static std::string OpenFile(const char* filter);
	// �����ļ�
	static std::string SaveFile(const char* filter);
};

TINY_ENGINE_NAMESPACE_END