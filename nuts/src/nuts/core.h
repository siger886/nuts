#pragma once
#ifdef NT_PLATFORM_WINDOWS
	#ifdef NT_BUILD_DLL
			#define NUTS_API  __declspec(dllexport)
	#else 
			#define NUTS_API  __declspec(dllimport)
	#endif
#else
#error nuts  only support Windows
#endif // NT_PLATFORM_WINDOWS
#ifdef NT_ENABLE_ASSERTS
			#define NT_ASSERT(X,...){if(!(x)){HZ_ERROR("Assertion Failed:{0}",
__VA_ARGS__); __debugbreak(); }}
			#define NT_CORE_ASSERT(X,...){if(!(x)){NT_CORE_ERROR("AssertionFailed:{0}",__VA_ARGS__);__debugbreak();}}
#else
			#define NT_ASSERT(x,...)
			#define NT_CORE_ASSERT(x,...)
#endif
#define BIT(x) (1<<x)
