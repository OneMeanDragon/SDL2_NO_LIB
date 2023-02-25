#if !defined(SDL_IMAGEDLL_H)
#define SDL_IMAGEDLL_H
#pragma once

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


#include <libloaderapi.h>
#include <cinttypes>

#include <SDL_image.h>

#define SDL_IMAGE_DLL TEXT("SDL2_IMAGE.DLL")
#define IMAGE_INIT_FUNCTION "IMG_Init"
#define IMAGE_IMAGEQUIT_FUNCTION "IMG_Quit"
#define IMAGE_LOADIMAGE_FUNCTION "IMG_Load"

typedef int32_t(*sdl_init_t)(uint32_t flags);
typedef void(*sdl_quit_t)(void);
typedef SDL_Surface* (*sdl_loadimage_t)(const char* file);

class CImage {
private:
	static CImage* sInstance;

	CImage();
	~CImage();

public:
	static bool IsInitialized;

	static CImage* Instance();
	static void Release();

	static int32_t Init(uint32_t dwFlag);
	static void Quit(void);
	static const char* GetError(void);

	static SDL_Surface* Load(const char* file);
private:
	/* SDL2 Initialization calls */
	sdl_init_t IMG_Init = nullptr;

	/* Image */
	sdl_loadimage_t IMG_Load = nullptr;
	sdl_quit_t IMG_Quit = nullptr;

private:
	HINSTANCE IMAGE_LOADED_DLL;
};



#endif