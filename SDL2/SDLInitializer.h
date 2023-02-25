#if !defined(SDL_INITIALIZER_H)
#define SDL_INITIALIZER_H
#pragma once

#include <SDL.h>
#include <SDL_image.h>

#define SDL_MAIN_DLL TEXT("SDL2.DLL")
#define SDL_INIT_FUNCTION "SDL_Init"
#define SDL_CREATEWINDOW_FUNCTION "SDL_CreateWindow"
#define SDL_CREATERENDERER_FUNCTION "SDL_CreateRenderer"
#define SDL_SETRENDERDRAWCOLOR_FUNCTION "SDL_SetRenderDrawColor"
#define SDL_CREATETEXTUREFROMSURFACE_FUNCTION "SDL_CreateTextureFromSurface"
#define SDL_FREESURFACE_FUNCTION "SDL_FreeSurface"
#define SDL_POLLEVENT_FUNCTION "SDL_PollEvent"
#define SDL_RENDERCLEAR_FUNCTION "SDL_RenderClear"
#define SDL_RENDERCOPY_FUNCTION "SDL_RenderCopy"
#define SDL_RENDERPRESENT_FUNCTION "SDL_RenderPresent"
/* destroys */
#define SDL_DESTROYTEXTURE_FUNCTION "SDL_DestroyTexture"
#define SDL_DESTROYRENDERER_FUNCTION "SDL_DestroyRenderer"
#define SDL_DESTROYWINDOW_FUNCTION "SDL_DestroyWindow"
/* quit */
#define SDL_QUIT_FUNCTION "SDL_Quit"
/* error */
#define SDL_GETERROR_FUNCTION "SDL_GetError"

typedef int32_t(*sdl_init_t)(uint32_t flags);
typedef void(*sdl_quit_t)(void);
typedef const char*(*sdl_geterror_t)(void);

typedef SDL_Window* (*sdl_createwindow_t)(const char* title, int32_t x, int32_t y, int32_t w, int32_t h, uint32_t flags);
typedef SDL_Renderer* (*sdl_createrenderer_t)(SDL_Window* window, int32_t index, uint32_t flags);
typedef int32_t(*sdl_setrenderdrawcolor_t)(SDL_Renderer* renderer, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
typedef int32_t(*sdl_pollevent_t)(SDL_Event* sevent);
typedef int32_t(*sdl_renderclear_t)(SDL_Renderer* renderer);
typedef int32_t(*sdl_rendercopy_t)(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
typedef void (*sdl_renderpresent_t)(SDL_Renderer* renderer);
typedef void (*sdl_destroytexture_t)(SDL_Texture* texture);
typedef void (*sdl_destroyrenderer_t)(SDL_Renderer* renderer);
typedef void (*sdl_destroywindow_t)(SDL_Window* window);

#define SDL_IMAGE_DLL TEXT("SDL2_IMAGE.DLL")
#define IMAGE_INIT_FUNCTION "IMG_Init"
#define IMAGE_LOADIMAGE_FUNCTION "IMG_Load"
#define IMAGE_IMAGEQUIT_FUNCTION "IMG_Quit"

typedef SDL_Surface* (*sdl_loadimage_t)(const char* file);
typedef SDL_Texture* (*sdl_createtexturefromsurface_t)(SDL_Renderer* renderer, SDL_Surface* surface);
typedef void (*sdl_freesurface_t)(SDL_Surface* surface);

class CSDL {
private:
	static CSDL* sInstance;

	CSDL();
	~CSDL();

public:

	static CSDL* Instance();
	static void Release();

	/* SDL2 */
	/// <summary>
	/// SDL2 Initializer
	/// </summary>
	/// <param name="dwFlag"></param>
	/// <returns></returns>
	static int32_t SDLInit(uint32_t dwFlag);
	static void SDLQuit(void);
	static const char* GetError(void);

	static SDL_Window* CreateHWindow(const char* title, int32_t x, int32_t y, int32_t w, int32_t h, uint32_t flags);
	static SDL_Renderer* CreateRenderer(SDL_Window* window, int32_t index, uint32_t flags);
	static int32_t SetRenderDrawColor(SDL_Renderer* renderer, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	static SDL_Texture* CreateTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface);
	static void FreeSurface(SDL_Surface* surface);
	static int32_t PollEvent(SDL_Event* sevent);
	static int32_t RenderClear(SDL_Renderer* renderer);
	static int32_t RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
	static void RenderPresent(SDL_Renderer* renderer);
	static void DestroyTexture(SDL_Texture* texture);
	static void DestroyRenderer(SDL_Renderer* renderer);
	static void DestroyWindow(SDL_Window* window);

	/* Image */
	/// <summary>
	/// Image Initializer
	/// </summary>
	/// <param name="dwFlag"></param>
	/// <returns></returns>
	static int32_t ImageInit(uint32_t dwFlag);
	static void ImageQuit(void);
	static const char* ImageGetError(void);

	static SDL_Surface* ImageLoad(const char* file);
private:
	/* SDL2 Initialization calls */
	sdl_init_t SDL_Init = nullptr;
	sdl_init_t IMG_Init = nullptr;

	/* sdl2 */
	sdl_createwindow_t SDL_CreateWindow = nullptr;
	sdl_createrenderer_t SDL_CreateRenderer = nullptr;
	sdl_setrenderdrawcolor_t SDL_SetRenderDrawColor = nullptr;
	sdl_createtexturefromsurface_t SDL_CreateTextureFromSurface = nullptr;
	sdl_freesurface_t SDL_FreeSurface = nullptr;
	sdl_pollevent_t SDL_PollEvent = nullptr;
	sdl_renderclear_t SDL_RenderClear = nullptr;
	sdl_rendercopy_t SDL_RenderCopy = nullptr;
	sdl_renderpresent_t SDL_RenderPresent = nullptr;
	sdl_destroytexture_t SDL_DestroyTexture = nullptr;
	sdl_destroyrenderer_t SDL_DestroyRenderer = nullptr;
	sdl_destroywindow_t SDL_DestroyWindow = nullptr;
	sdl_quit_t SDL_Quit = nullptr;
	sdl_geterror_t SDL_GetError = nullptr;

	/* Image */
	sdl_loadimage_t IMG_Load = nullptr;
	sdl_quit_t IMG_Quit = nullptr;

private:
	HINSTANCE SDL_LOADED_DLL;
	HINSTANCE IMAGE_LOADED_DLL;
};



#endif