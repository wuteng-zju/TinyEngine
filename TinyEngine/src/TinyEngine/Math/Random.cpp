#include "pch.h"

#include <limits>
#include "Random.h"


TINY_ENGINE_NAMESPACE_BEGIN

namespace
{
	static std::random_device RandomDevice;
	static std::mt19937_64 RandomEngine(RandomDevice());
	static std::uniform_int_distribution<uint64_t> UniformDistribution;
}

float Random::Float()
{
	return static_cast<float>(UniformDistribution(RandomEngine)) / static_cast<float>(UINT64_MAX);
}

uint64_t Random::Uint64_t()
{
	return static_cast<uint64_t>(UniformDistribution(RandomEngine));
}

TINY_ENGINE_NAMESPACE_END