#pragma once
#include "pch.h"

TINY_ENGINE_NAMESPACE_BEGIN

// �������
class Buffer
{
public:
	// ʹ��Ĭ����������
	virtual ~Buffer() = default;
	// �󶨣����麯����
	virtual void Bind() const = 0;
	// ��󣨴��麯��
	virtual void UnBind() const = 0;
};

TINY_ENGINE_NAMESPACE_END