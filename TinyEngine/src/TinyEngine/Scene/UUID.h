#pragma once
#include <xhash>

TINY_ENGINE_NAMESPACE_BEGIN
// UUID¿‡
class UUID
{
public:
	UUID();
	UUID(uint64_t uiUUID);
	UUID(const UUID&) = default;
	operator uint64_t() const;
private:
	uint64_t m_uiUUID;
};

TINY_ENGINE_NAMESPACE_END

namespace std
{
	template<>
	struct hash<TinyEngine::UUID>
	{
		std::size_t operator()(const TinyEngine::UUID& uuid) const
		{
			return static_cast<uint64_t>(uuid);
		}
	};
}