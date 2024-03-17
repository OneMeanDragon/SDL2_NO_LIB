#include "../SDL2NoLibs/SDL2Nolibs.h"
#include "SDL2Ttf.h"

#pragma region "SDL2_TTF.DLL"

#if defined(SDL_MUTEX)
std::mutex Singleton::mutex_; 
#endif
CTTF* CTTF::sInstance = nullptr;
bool CTTF::IsInitialized = false;

CTTF* CTTF::Instance() {
#if defined(SDL_MUTEX)
	std::lock_guard<std::mutex> lock(mutex_); 
#endif
	if (sInstance == nullptr)
		sInstance = new CTTF();

	return sInstance;
}

void CTTF::Release()
{
	/* if anything else needs to be destroyed before this then do it above the instance deleteion */
	delete sInstance;
	sInstance = nullptr;
}

CTTF::CTTF() {
	TTF_LOADED_DLL = LoadLibrary(SDL_TTF_DLL);
	if (TTF_LOADED_DLL)
	{
		TTF_Init = (sdl_ttfinit_t)GetProcAddress(TTF_LOADED_DLL, TTF_INIT_FUNCTION);
		TTF_Quit = (sdl_quit_t)GetProcAddress(TTF_LOADED_DLL, TTF_TTFQUIT_FUNCTION);
		TTF_CloseFont = (ttf_closefont_t)GetProcAddress(TTF_LOADED_DLL, TTF_CLOSEFONT_FUNCTION);
		TTF_OpenFont = (ttf_openfont_t)GetProcAddress(TTF_LOADED_DLL, TTF_OPENFONT_FUNCTION);
		TTF_OpenFontRW = (ttf_openfontrw_t)GetProcAddress(TTF_LOADED_DLL, TTF_OPENFONTRW_FUNCTION);

		TTF_RenderText_Solid = (sdl_rendertext_solid_t)GetProcAddress(TTF_LOADED_DLL, TTF_RENDERTEXT_SOLID_FUNCTION);
		TTF_RenderUNICODE_Solid = (sdl_renderunicode_solid_t)GetProcAddress(TTF_LOADED_DLL, TTF_RENDERUNICODE_SOLID_FUNCTION);

		TTF_RenderText_Blended = (ttf_rendertextblended_t)GetProcAddress(TTF_LOADED_DLL, TTF_RENDERTEXTBLENDED_FUNCTION);

		TTF_FontHeight = (ttf_fontheight_t)GetProcAddress(TTF_LOADED_DLL, TTF_FONTHEIGHT_FUNCTION);
		TTF_SizeText = (ttf_sizetext_t)GetProcAddress(TTF_LOADED_DLL, TTF_SIZETEXT_FUNCTION);

		IsInitialized = true;
	}
}

CTTF::~CTTF() {
	if (TTF_LOADED_DLL) {
		FreeLibrary(TTF_LOADED_DLL);
	}
}


int32_t CTTF::Init() {
	return Instance()->TTF_Init();
}

void CTTF::Quit(void)
{
	Instance()->TTF_Quit();
	return Instance()->Release();
}

const char* CTTF::GetError(void)
{
	return CSDL::Instance()->GetError();
}

void CTTF::CloseFont(TTF_Font* font)
{
	return Instance()->TTF_CloseFont(font);
}

TTF_Font* CTTF::OpenFont(const char* file, int32_t ptsize)
{
	return Instance()->TTF_OpenFont(file, ptsize);
}

TTF_Font* CTTF::OpenFontRW(SDL_RWops* src, int freesrc, int ptsize)
{
	return Instance()->TTF_OpenFontRW(src, freesrc, ptsize);
}

SDL_Surface* CTTF::RenderText_Solid(TTF_Font* font, const char* text, SDL_Color fg)
{
	return Instance()->TTF_RenderText_Solid(font, text, fg);
}

SDL_Surface* CTTF::RenderUNICODE_Solid(TTF_Font* font, const wchar_t* text, SDL_Color fg) {
	return Instance()->TTF_RenderUNICODE_Solid(font, text, fg);
}

SDL_Surface* CTTF::RenderText_Blended(TTF_Font* font, const char* text, SDL_Color fg) {
	return Instance()->TTF_RenderText_Blended(font, text, fg);
}

int32_t CTTF::FontHeight(const TTF_Font* font) {
	return Instance()->TTF_FontHeight(font);
}

int32_t CTTF::SizeText(TTF_Font* font, const char* text, int* w, int* h) {
	return Instance()->TTF_SizeText(font, text, w, h);
}

#pragma endregion // End SDL2_TTF.DLL
