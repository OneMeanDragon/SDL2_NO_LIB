#if !defined(SDL_INCLUDE_H)
#define SDL_INCLUDE_H
#pragma once

#if defined(INCLUDE_SDL2)
	#include "SDL2NoLibs/SDL2Nolibs.h"
#endif

#if defined(INCLUDE_SDL2) && defined(INCLUDE_SDL_TTF)
	#include "SDL2Ttf/SDL2Ttf.h"
#endif

#if defined(INCLUDE_SDL2) && defined(INCLUDE_SDL_MIXER)
	#include "SDL2Mixer/SDL2Mixer.h"
#endif

#if defined(INCLUDE_SDL2) && defined(INCLUDE_SDL_IMAGE)
	#include "SDL2Image/SDL2Image.h"
#endif

#endif