#pragma once
#include "pch.h"

TINY_ENGINE_NAMESPACE_BEGIN

// 缓冲基类
class Buffer
{
public:
	// 使用默认析构函数
	virtual ~Buffer() = default;
	// 绑定（纯虚函数）
	virtual void Bind() const = 0;
	// 解绑（纯虚函数
	virtual void UnBind() const = 0;
};

TINY_ENGINE_NAMESPACE_END