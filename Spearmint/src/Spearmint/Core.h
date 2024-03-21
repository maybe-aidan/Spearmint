#ifndef CORE_H
#define CORE_H

#ifdef SM_PLATFORM_WINDOWS
	#ifdef SM_BUILD_DLL
		#define SPEARMINT_API __declspec(dllexport)
	#else
		#define SPEARMINT_API __declspec(dllimport)
	#endif // SM_BUILD_DLL
#else
	#error Spearmint only supports Windows!
#endif // SM_PLATFORM_WINDOWS

#ifdef SM_ENABLE_ASSERTS
	#define SM_ASSERT(x, ...) { if(!(x)) { SM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SM_CORE_ASSERT (x, ...) { if(!(x)) { SM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SM_ASSERT(x, ...)
	#define SM_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
#endif // CORE_H
