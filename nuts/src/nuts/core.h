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
