#ifndef CORE_H
#define CORE_H

#ifdef SM_PLATFORM_WINDOWS
	#ifdef SM_BUILD_DLL
		#define SPEARMINT_API __declspec(dllexport)
	#else
		#define SPEARMINT_API __declspec(dllimport)
	#endif // SM_BUILD_DLL
#else
	#error Spearmint only supports Windows
#endif // SM_PLATFORM_WINDOWS
#endif // CORE_H
