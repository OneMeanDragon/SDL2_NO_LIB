#if !defined(SDL_TTFDLL_H)
#define SDL_TTFDLL_H
#pragma once

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


#include <libloaderapi.h>
#include <cinttypes>

#include <SDL_ttf.h>

#define SDL_TTF_DLL TEXT("SDL2_TTF.DLL")
#define TTF_INIT_FUNCTION "TTF_Init"
#define TTF_TTFQUIT_FUNCTION "TTF_Quit"
#define TTF_RENDERTEXT_SOLID_FUNCTION "TTF_RenderText_Solid"
#define TTF_CLOSEFONT_FUNCTION "TTF_CloseFont"
#define TTF_OPENFONT_FUNCTION "TTF_OpenFont"

/*
extern DECLSPEC TTF_Font * SDLCALL TTF_OpenFont(const char *file, int ptsize);
*/
typedef int32_t(*sdl_ttfinit_t)();
typedef void(*sdl_quit_t)(void);
typedef SDL_Surface* (*sdl_rendertext_solid_t)(TTF_Font* font, const char* text, SDL_Color fg);
typedef void(*ttf_closefont_t)(TTF_Font* font);
typedef TTF_Font* (*ttf_openfont_t)(const char* file, int32_t ptsize);

class CTTF {
private:
	static CTTF* sInstance;

	CTTF();
	~CTTF();

public:
	static bool IsInitialized;

	static CTTF* Instance();
	static void Release();

	static int32_t Init();
	static void Quit(void);
	static const char* GetError(void);

	static SDL_Surface* RenderText_Solid(TTF_Font* font, const char* text, SDL_Color fg);
	static void CloseFont(TTF_Font* font);
	static TTF_Font* OpenFont(const char* file, int32_t ptsize);

private:
	sdl_ttfinit_t TTF_Init = nullptr;
	sdl_quit_t TTF_Quit = nullptr;

	sdl_rendertext_solid_t TTF_RenderText_Solid = nullptr;
	ttf_closefont_t TTF_CloseFont = nullptr;
	ttf_openfont_t TTF_OpenFont = nullptr;

private:
	HINSTANCE TTF_LOADED_DLL;
};



#endif