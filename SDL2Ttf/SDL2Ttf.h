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
typedef SDL_Surface* (*sdl_rendertext_solid_t)(TTF_Font* font, const char* text, SDL_Color fg);
#define TTF_RENDERUNICODE_SOLID_FUNCTION "TTF_RenderUNICODE_Solid"
typedef SDL_Surface* (*sdl_renderunicode_solid_t)(TTF_Font* font, const wchar_t* text, SDL_Color fg);

#define TTF_CLOSEFONT_FUNCTION "TTF_CloseFont"
#define TTF_OPENFONT_FUNCTION "TTF_OpenFont"
#define TTF_OPENFONTRW_FUNCTION "TTF_OpenFontRW"
// Memory Func
//TTF_OpenFontRW

//extern DECLSPEC TTF_Font* SDLCALL TTF_OpenFontRW(SDL_RWops* src, int freesrc, int ptsize);

/*
extern DECLSPEC TTF_Font * SDLCALL TTF_OpenFont(const char *file, int ptsize);
*/
typedef int32_t(*sdl_ttfinit_t)();
typedef void(*sdl_quit_t)(void);
typedef void(*ttf_closefont_t)(TTF_Font* font);
typedef TTF_Font* (*ttf_openfont_t)(const char* file, int32_t ptsize);
typedef TTF_Font* (*ttf_openfontrw_t)(SDL_RWops* src, int freesrc, int ptsize);

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

	static void CloseFont(TTF_Font* font);
	static TTF_Font* OpenFont(const char* file, int32_t ptsize);
	static TTF_Font* OpenFontRW(SDL_RWops* src, int freesrc, int ptsize);

	static SDL_Surface* RenderText_Solid(TTF_Font* font, const char* text, SDL_Color fg);
	static SDL_Surface* RenderUNICODE_Solid(TTF_Font* font, const wchar_t* text, SDL_Color fg);

private:
	sdl_ttfinit_t TTF_Init = nullptr;
	sdl_quit_t TTF_Quit = nullptr;

	ttf_closefont_t TTF_CloseFont = nullptr;
	ttf_openfont_t TTF_OpenFont = nullptr;
	ttf_openfontrw_t TTF_OpenFontRW = nullptr;
	sdl_rendertext_solid_t TTF_RenderText_Solid = nullptr;
	sdl_renderunicode_solid_t TTF_RenderUNICODE_Solid = nullptr;

private:
	HINSTANCE TTF_LOADED_DLL;
};



#endif
