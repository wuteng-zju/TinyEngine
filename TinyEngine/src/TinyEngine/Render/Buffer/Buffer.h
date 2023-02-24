#pragma once
#include "pch.h"

TINY_ENGINE_NAMESPACE_BEGIN

class Buffer
{
public:
	virtual ~Buffer() = default;
	virtual void Bind() const = 0;
	virtual void UnBind() const = 0;
};

TINY_ENGINE_NAMESPACE_END