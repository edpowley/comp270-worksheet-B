// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef _WIN32

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#include <malloc.h>
#include <tchar.h>

#else

// min and max are usually defined in windows.h, so we need to define them here

inline float min(float a, float b)
{
    return (a < b) ? a : b;
}

inline float max(float a, float b)
{
    return (a > b) ? a : b;
}

#endif

// C RunTime Header Files
#include <stdlib.h>
#include <memory.h>

// TODO: reference additional headers your program requires here

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <random>
#include <SDL.h>
#include <SDL_image.h>
