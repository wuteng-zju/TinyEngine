#pragma once
#include "pch.h"

TINY_ENGINE_NAMESPACE_BEGIN

class PlatformUtils
{
public:
	// 打开文件
	static std::string OpenFile(const char* filter);
	// 保存文件
	static std::string SaveFile(const char* filter);
};

TINY_ENGINE_NAMESPACE_END