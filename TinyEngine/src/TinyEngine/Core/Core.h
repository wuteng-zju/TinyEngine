#pragma once
#include <memory>

// 
#define BIT(x) (1<<x)

// 
#define BIND_EVENT_FUN(x) std::bind(&x, this, std::placeholders::_1)

// 定义命名空间 TinyEngine
#ifndef TINY_ENGINE_NAMESPACE_BEGIN
#define TINY_ENGINE_NAMESPACE_BEGIN \
	namespace  TinyEngine{
#endif 

#ifndef TINY_ENGINE_NAMESPACE_END
#define TINY_ENGINE_NAMESPACE_END \
	}
#endif 

// 
#ifdef TINY_ENGINE_ENABLE_ASSERTS
#define TINY_ENGINE_ASSERT(x,...) { if(!(x)) { LOG_DEV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}

#endif // TINY_ENGINE_ENABLE_ASSERTS

TINY_ENGINE_NAMESPACE_BEGIN
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
TINY_ENGINE_NAMESPACE_END