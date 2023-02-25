#include <Windows.h>
#include <cinttypes>

#include <SDL.h>
#include <SDL_image.h>

#include "SDLInitializer.h"

CSDL* CSDL::sInstance = nullptr;

CSDL* CSDL::Instance() {
	if (sInstance == nullptr)
		sInstance = new CSDL();

	return sInstance;
}

void CSDL::Release()
{
	/* if anything else needs to be destroyed before this then do it above the instance deleteion */
	delete sInstance;
	sInstance = nullptr;
}

CSDL::CSDL() {
	SDL_LOADED_DLL = LoadLibrary(SDL_MAIN_DLL);
	if (SDL_LOADED_DLL)
	{
		SDL_Init = (sdl_init_t)GetProcAddress(SDL_LOADED_DLL, SDL_INIT_FUNCTION);
		SDL_Quit = (sdl_quit_t)GetProcAddress(SDL_LOADED_DLL, SDL_QUIT_FUNCTION);
		SDL_CreateWindow = (sdl_createwindow_t)GetProcAddress(SDL_LOADED_DLL, SDL_CREATEWINDOW_FUNCTION);
		SDL_CreateRenderer = (sdl_createrenderer_t)GetProcAddress(SDL_LOADED_DLL, SDL_CREATERENDERER_FUNCTION);
		SDL_SetRenderDrawColor = (sdl_setrenderdrawcolor_t)GetProcAddress(SDL_LOADED_DLL, SDL_SETRENDERDRAWCOLOR_FUNCTION);
		SDL_CreateTextureFromSurface = (sdl_createtexturefromsurface_t)GetProcAddress(SDL_LOADED_DLL, SDL_CREATETEXTUREFROMSURFACE_FUNCTION);
		SDL_FreeSurface = (sdl_freesurface_t)GetProcAddress(SDL_LOADED_DLL, SDL_FREESURFACE_FUNCTION);
		SDL_PollEvent = (sdl_pollevent_t)GetProcAddress(SDL_LOADED_DLL, SDL_POLLEVENT_FUNCTION);
		SDL_RenderClear = (sdl_renderclear_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERCLEAR_FUNCTION);
		SDL_RenderCopy = (sdl_rendercopy_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERCOPY_FUNCTION);
		SDL_RenderPresent = (sdl_renderpresent_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERPRESENT_FUNCTION);

		SDL_DestroyTexture = (sdl_destroytexture_t)GetProcAddress(SDL_LOADED_DLL, SDL_DESTROYTEXTURE_FUNCTION);
		SDL_DestroyRenderer = (sdl_destroyrenderer_t)GetProcAddress(SDL_LOADED_DLL, SDL_DESTROYRENDERER_FUNCTION);
		SDL_DestroyWindow = (sdl_destroywindow_t)GetProcAddress(SDL_LOADED_DLL, SDL_DESTROYWINDOW_FUNCTION);

		SDL_GetError = (sdl_geterror_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETERROR_FUNCTION);

	}
	IMAGE_LOADED_DLL = LoadLibrary(SDL_IMAGE_DLL);
	if (IMAGE_LOADED_DLL)
	{
		IMG_Init = (sdl_init_t)GetProcAddress(IMAGE_LOADED_DLL, IMAGE_INIT_FUNCTION);
		IMG_Quit = (sdl_quit_t)GetProcAddress(IMAGE_LOADED_DLL, IMAGE_IMAGEQUIT_FUNCTION);
		IMG_Load = (sdl_loadimage_t)GetProcAddress(IMAGE_LOADED_DLL, IMAGE_LOADIMAGE_FUNCTION);
	}
}

CSDL::~CSDL() {
	if (SDL_LOADED_DLL) {
		FreeLibrary(SDL_LOADED_DLL);
	}
	if (IMAGE_LOADED_DLL) {
		FreeLibrary(IMAGE_LOADED_DLL);
	}
}

/* SDL2_DLL */
int32_t CSDL::SDLInit(uint32_t dwFlag) {
	return Instance()->SDL_Init(dwFlag);
}

void CSDL::SDLQuit(void)
{
	return Instance()->SDL_Quit();
}

const char* CSDL::GetError(void)
{
	return Instance()->SDL_GetError();
}

SDL_Window* CSDL::CreateHWindow(const char* title, int32_t x, int32_t y, int32_t w, int32_t h, uint32_t flags)
{
	return Instance()->SDL_CreateWindow(title, x, y, w, h, flags);
}

SDL_Renderer* CSDL::CreateRenderer(SDL_Window* window, int32_t index, uint32_t flags)
{
	return Instance()->SDL_CreateRenderer(window, index, flags);
}

int32_t CSDL::SetRenderDrawColor(SDL_Renderer* renderer, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return Instance()->SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

SDL_Texture* CSDL::CreateTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface) {
	return Instance()->SDL_CreateTextureFromSurface(renderer, surface);
}

void CSDL::FreeSurface(SDL_Surface* surface)
{
	return Instance()->SDL_FreeSurface(surface);
}

int32_t CSDL::PollEvent(SDL_Event* sevent)
{
	return Instance()->SDL_PollEvent(sevent);
}

int32_t CSDL::RenderClear(SDL_Renderer* renderer)
{
	return Instance()->SDL_RenderClear(renderer);
}

int32_t CSDL::RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect)
{
	return Instance()->SDL_RenderCopy(renderer, texture, srcrect, dstrect);
}

void CSDL::RenderPresent(SDL_Renderer* renderer)
{
	return Instance()->SDL_RenderPresent(renderer);
}

void CSDL::DestroyTexture(SDL_Texture* texture)
{
	return Instance()->SDL_DestroyTexture(texture);
}

void CSDL::DestroyRenderer(SDL_Renderer* renderer)
{
	return Instance()->SDL_DestroyRenderer(renderer);
}

void CSDL::DestroyWindow(SDL_Window* window)
{
	return Instance()->SDL_DestroyWindow(window);
}


/* SDL_IMAGE_DLL */
int32_t CSDL::ImageInit(uint32_t dwFlag) {
	return Instance()->IMG_Init(dwFlag);
}

SDL_Surface* CSDL::ImageLoad(const char* file)
{
	return Instance()->IMG_Load(file);
}

void CSDL::ImageQuit(void)
{
	return Instance()->IMG_Quit();
}

const char* CSDL::ImageGetError(void)
{
	return Instance()->SDL_GetError();
}
