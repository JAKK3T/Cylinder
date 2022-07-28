#pragma once

#ifdef CYL_PLATFORM_WINDOWS
	#ifdef CYL_BUILD_DLL
		#define CYLINDER_API _declspec(dllexport)
	#else
		#define CYLINDER_API _declspec(dllimport)
	#endif
#else
	#error Cylinder only supports Windows!
#endif

#define BIT(x) (1 << x)