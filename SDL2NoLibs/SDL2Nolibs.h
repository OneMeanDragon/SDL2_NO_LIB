#if !defined(SDL_INITIALIZER_H)
#define SDL_INITIALIZER_H
#pragma once

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


#include <libloaderapi.h>
#include <cinttypes>

#define SDL_MAIN_HANDLED
#include <SDL.h>

#define SDL_MAIN_DLL TEXT("SDL2.DLL")
#define SDL_INIT_FUNCTION "SDL_Init"
#define SDL_CREATEWINDOW_FUNCTION "SDL_CreateWindow"
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
#define SDL_RENDERCOPYEX_FUNCTION "SDL_RenderCopyEx"
#define SDL_RENDERDRAWLINE_FUNCTION "SDL_RenderDrawLine"
#define SDL_GETBASEPATH_FUNCTION "SDL_GetBasePath"
#define SDL_GETTICKS_FUNCTION "SDL_GetTicks"
#define SDL_QUERYTEXTURE_FUNCTION "SDL_QueryTexture"
#define SDL_GETKEYBOARDSTATE_FUNCTION "SDL_GetKeyboardState"
#define SDL_GETMOUSESTATE_FUNCTION "SDL_GetMouseState"
#define SDL_RENDERFILLRECT_FUNCTION "SDL_RenderFillRect"
#define SDL_GETPERFORMANCECOUNTER_FUNCTION "SDL_GetPerformanceCounter"
#define SDL_GETPERFORMANCEFREQUENCY_FUNCTION "SDL_GetPerformanceFrequency"
#define SDL_DELAY_FUNCTION "SDL_Delay"

/* Renderer Inits */
#define SDL_CREATERENDERER_FUNCTION "SDL_CreateRenderer"
#define SDL_GETNUMRENDERDRIVERS_FUNCTION "SDL_GetNumRenderDrivers"
#define SDL_GETNUMRENDERDRIVERINFO_FUNCTION "SDL_GetRenderDriverInfo"

/* Memory Func */
#define SDL_RWFROMFILE_FUNCTION "SDL_RWFromFile"
#define SDL_RWFROMMEM_FUNCTION "SDL_RWFromMem"
#define SDL_RWFROMCONSTMEM_FUNCTION "SDL_RWFromConstMem"


typedef int32_t(*sdl_init_t)(uint32_t flags);
typedef void(*sdl_quit_t)(void);
typedef const char* (*sdl_geterror_t)(void);

typedef SDL_Window* (*sdl_createwindow_t)(const char* title, int32_t x, int32_t y, int32_t w, int32_t h, uint32_t flags);
typedef int32_t(*sdl_setrenderdrawcolor_t)(SDL_Renderer* renderer, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
typedef int32_t(*sdl_pollevent_t)(SDL_Event* sevent);
typedef int32_t(*sdl_renderclear_t)(SDL_Renderer* renderer);
typedef int32_t(*sdl_rendercopy_t)(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
typedef void (*sdl_renderpresent_t)(SDL_Renderer* renderer);
typedef void (*sdl_destroytexture_t)(SDL_Texture* texture);
typedef void (*sdl_destroyrenderer_t)(SDL_Renderer* renderer);
typedef void (*sdl_destroywindow_t)(SDL_Window* window);
typedef SDL_Texture* (*sdl_createtexturefromsurface_t)(SDL_Renderer* renderer, SDL_Surface* surface);
typedef void (*sdl_freesurface_t)(SDL_Surface* surface);
typedef int32_t(*sdl_rendercopyex_t)(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect, const double angle, const SDL_Point* center, const SDL_RendererFlip flip);
typedef int32_t(*sdl_renderdrawline_t)(SDL_Renderer* renderer, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
typedef uint32_t(*sdl_getticks_t)(void);
typedef int32_t(*sdl_querytexture_t)(SDL_Texture* texture, uint32_t* format, int32_t* access, int32_t* w, int32_t* h);
typedef const uint8_t* (*sdl_getkeyboardstate_t)(int32_t* numkeys);
typedef uint32_t(*sdl_getmousestate_t)(int32_t* x, int32_t* y);
typedef int32_t(*sdl_renderfillrect_t)(SDL_Renderer* renderer, const SDL_Rect* rect);
typedef uint64_t(*sdl_getperformancecounter_t)();
typedef uint64_t(*sdl_getperformancefrequency_t)();
typedef void(*sdl_delay_t)(uint32_t);
// Renderer Inits
typedef SDL_Renderer* (*sdl_createrenderer_t)(SDL_Window* window, int32_t index, uint32_t flags);
typedef int32_t(*sdl_getnumrenderdrivers_t)(void);
typedef int32_t(*sdl_getnumrenderdriverinfo_t)(int32_t index, SDL_RendererInfo* info);

// Memory functions
typedef SDL_RWops* (*sdl_rwfromfile_t)(const char* file, const char* mode);
typedef SDL_RWops* (*sdl_rwfrommem_t)(void* mem, int size);
typedef SDL_RWops* (*sdl_rwfromconstmem_t)(const void* mem, int size);


class CSDL {
private:
	static CSDL* sInstance;

	CSDL();
	~CSDL();

public:
	static bool IsInitialized;

	static CSDL* Instance();
	static void Release();

	static int32_t Init(uint32_t dwFlag);
	static void Quit(void);
	static const char* GetError(void);

	static SDL_Window* CreateHWindow(const char* title, int32_t x, int32_t y, int32_t w, int32_t h, uint32_t flags);
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

	static int32_t RenderCopyEx(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect, const double angle, const SDL_Point* center, const SDL_RendererFlip flip);
	static int32_t RenderDrawLine(SDL_Renderer* renderer, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
	static const char* GetBasePath(void);
	static uint32_t GetTicks(void);
	static int32_t QueryTexture(SDL_Texture* texture, uint32_t* format, int32_t* access, int32_t* w, int32_t* h);

	static const uint8_t* GetKeyboardState(int32_t* numkeys);
	static uint32_t GetMouseState(int32_t* x, int32_t* y);

	static int32_t RenderFillRect(SDL_Renderer* renderer, const SDL_Rect* rect);

	// Delta timeing
	static uint64_t GetPerformanceCounter();
	static uint64_t GetPerformanceFrequency();
	static void Delay(uint32_t ms);

	// Renderer Inits
	static SDL_Renderer* CreateRenderer(SDL_Window* window, int32_t index, uint32_t flags);
	static int32_t GetNumRenderDrivers(void);
	static int32_t GetRenderDriverInfo(int32_t index, SDL_RendererInfo* info);



	// Memory func
	static SDL_RWops* RWFromFile(const char* file, const char* mode);
	static SDL_RWops* RWFromMem(void* mem, int size);
	static SDL_RWops* RWFromConstMem(const void* mem, int size);

private:
	/* SDL2 Initialization calls */
	sdl_init_t SDL_Init = nullptr;

	/* sdl2 */
	sdl_createwindow_t SDL_CreateWindow = nullptr;
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
	sdl_rendercopyex_t SDL_RenderCopyEx = nullptr;
	sdl_renderdrawline_t SDL_RenderDrawLine = nullptr;
	sdl_geterror_t SDL_GetBasePath = nullptr;
	sdl_getticks_t SDL_GetTicks = nullptr;
	sdl_querytexture_t SDL_QueryTexture = nullptr;
	sdl_getkeyboardstate_t SDL_GetKeyboardState = nullptr;
	sdl_getmousestate_t SDL_GetMouseState = nullptr;
	sdl_renderfillrect_t SDL_RenderFillRect = nullptr;
	sdl_getperformancecounter_t SDL_GetPerformanceCounter = nullptr;
	sdl_getperformancefrequency_t SDL_GetPerformanceFrequency = nullptr;
	sdl_delay_t SDL_Delay = nullptr;
	//renderer inits
	sdl_createrenderer_t SDL_CreateRenderer = nullptr;
	sdl_getnumrenderdrivers_t SDL_GetNumRenderDrivers = nullptr;
	sdl_getnumrenderdriverinfo_t SDL_GetRenderDriverInfo = nullptr;
	//memory func
	sdl_rwfromfile_t SDL_RWFromFile = nullptr;
	sdl_rwfrommem_t SDL_RWFromMem = nullptr;
	sdl_rwfromconstmem_t SDL_RWFromConstMem = nullptr;


private:
	HINSTANCE SDL_LOADED_DLL;
};

#endif
