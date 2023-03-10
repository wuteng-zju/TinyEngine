#pragma once
#include "pch.h"

TINY_ENGINE_NAMESPACE_BEGIN

class Context {
public:
	virtual void Init() = 0;
	virtual void SwapBuffers() = 0;
};

TINY_ENGINE_NAMESPACE_END