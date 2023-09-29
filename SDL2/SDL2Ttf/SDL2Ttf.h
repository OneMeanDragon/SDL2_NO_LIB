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
typedef int32_t(*sdl_ttfinit_t)();

#define TTF_TTFQUIT_FUNCTION "TTF_Quit"
typedef void(*sdl_quit_t)(void);

#define TTF_RENDERTEXT_SOLID_FUNCTION "TTF_RenderText_Solid"
typedef SDL_Surface* (*sdl_rendertext_solid_t)(TTF_Font* font, const char* text, SDL_Color fg);

#define TTF_RENDERUNICODE_SOLID_FUNCTION "TTF_RenderUNICODE_Solid"
typedef SDL_Surface* (*sdl_renderunicode_solid_t)(TTF_Font* font, const wchar_t* text, SDL_Color fg);

#define TTF_CLOSEFONT_FUNCTION "TTF_CloseFont"
typedef void(*ttf_closefont_t)(TTF_Font* font);

#define TTF_OPENFONT_FUNCTION "TTF_OpenFont"
typedef TTF_Font* (*ttf_openfont_t)(const char* file, int32_t ptsize);

// Memory Func
#define TTF_OPENFONTRW_FUNCTION "TTF_OpenFontRW"
typedef TTF_Font* (*ttf_openfontrw_t)(SDL_RWops* src, int freesrc, int ptsize);

class CTTF {
private:
	static CTTF* sInstance;
#if defined(SDL_MUTEX)
	static std::mutex mutex_;
#endif
private:

	CTTF();
	~CTTF();

public:
	CTTF(const CTTF& obj) = delete;       /* Remove the copy constructor */
	void operator=(const CTTF&) = delete; /* Remove the assignment operator */
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
