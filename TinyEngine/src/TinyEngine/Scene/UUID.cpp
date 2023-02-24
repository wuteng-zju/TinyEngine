#include "pch.h"
#include "UUID.h"
#include "TinyEngine/Math/Random.h"

TINY_ENGINE_NAMESPACE_BEGIN

UUID::UUID():
	m_uiUUID(Random::Uint64_t())
{

}

UUID::UUID(uint64_t uiUUID)
{
	m_uiUUID = uiUUID;
}

UUID::operator uint64_t() const
{
	return m_uiUUID;
}

TINY_ENGINE_NAMESPACE_END
