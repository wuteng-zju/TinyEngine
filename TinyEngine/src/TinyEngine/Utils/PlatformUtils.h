#pragma once
#include "pch.h"

TINY_ENGINE_NAMESPACE_BEGIN

class PlatformUtils
{
public:
	static std::string OpenFile(const char* filter);
	static std::string SaveFile(const char* filter);
};

TINY_ENGINE_NAMESPACE_END