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
#include <SDL_syswm.h> /* SDL_GetWindowID */


#define SDL_MAIN_DLL TEXT("SDL2.DLL")
#define SDL_INIT_FUNCTION "SDL_Init"
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

/* Initial */
#define SDL_SETHINT_FUNCTION "SDL_SetHint"
typedef SDL_bool(*sdl_sethint_t)(const char* name, const char* value);
#define SDL_GETWINDOWWMINFO_FUNCTION "SDL_GetWindowWMInfo"
typedef SDL_bool(*sdl_getwindowwminfo_t)(SDL_Window* window, SDL_SysWMinfo* info);
#define SDL_GETWINDOWID_FUNCTION "SDL_GetWindowID"
typedef uint32_t(*sdl_getwindowid_t)(SDL_Window* window);


/* Renderer Inits */
#define SDL_CREATERENDERER_FUNCTION "SDL_CreateRenderer"
#define SDL_GETNUMRENDERDRIVERS_FUNCTION "SDL_GetNumRenderDrivers"
#define SDL_GETNUMRENDERDRIVERINFO_FUNCTION "SDL_GetRenderDriverInfo"

//extern DECLSPEC int SDLCALL SDL_RenderSetLogicalSize(SDL_Renderer * renderer, int w, int h);
//extern DECLSPEC void SDLCALL SDL_RenderGetLogicalSize(SDL_Renderer * renderer, int *w, int *h);
//extern DECLSPEC int SDLCALL SDL_RenderSetIntegerScale(SDL_Renderer * renderer, SDL_bool enable);
//extern DECLSPEC SDL_bool SDLCALL SDL_RenderGetIntegerScale(SDL_Renderer * renderer);
//extern DECLSPEC int SDLCALL SDL_RenderSetViewport(SDL_Renderer * renderer,const SDL_Rect* rect);
//extern DECLSPEC void SDLCALL SDL_RenderGetViewport(SDL_Renderer * renderer,SDL_Rect* rect);
//extern DECLSPEC int SDLCALL SDL_RenderSetScale(SDL_Renderer * renderer,float scaleX, float scaleY);
//extern DECLSPEC void SDLCALL SDL_RenderGetScale(SDL_Renderer * renderer,float* scaleX, float* scaleY);


/* Memory Func */
#define SDL_RWFROMFILE_FUNCTION "SDL_RWFromFile"
#define SDL_RWFROMMEM_FUNCTION "SDL_RWFromMem"
#define SDL_RWFROMCONSTMEM_FUNCTION "SDL_RWFromConstMem"
#define SDL_FREERW_FUNCTION "SDL_FreeRW"
typedef void(*sdl_freerw_t)(SDL_RWops* area);


/* Window Flags */
#define SDL_CREATEWINDOW_FUNCTION "SDL_CreateWindow"
#define SDL_DESTROYWINDOW_FUNCTION "SDL_DestroyWindow"
#define SDL_GETWINDOWFLAGS_FUNCTION "SDL_GetWindowFlags"
#define SDL_SETWINDOWFULLSCREEN_FUNCTION "SDL_SetWindowFullscreen"


/* Surfaces */
#define SDL_CREATERGBSURFACEWITHFORMAT_FUNCTION "SDL_CreateRGBSurfaceWithFormat"
typedef SDL_Surface* (*sdl_creatergbsurfacewithformat_t)(Uint32 flags, int width, int height, int depth, Uint32 format);
#define SDL_CREATERGBSURFACE_FUNCTION "SDL_CreateRGBSurface"
typedef SDL_Surface*(*sdl_creatergbsurface_t)(uint32_t flags, int32_t width, int32_t height, int32_t depth, uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask);
#define SDL_SETSURFACECOLORMOD_FUNCTION "SDL_SetSurfaceColorMod"
typedef int32_t(*sdl_setsurfacecolormod_t)(SDL_Surface* surface, uint8_t r, uint8_t g, uint8_t b);
#define SDL_SETSURFACEALPHAMOD_FUNCTION "SDL_SetSurfaceAlphaMod"
typedef int32_t(*sdl_setsurfacealphamod_t)(SDL_Surface* surface, uint8_t alpha);
#define SDL_UPPERBLIT_FUNCTION "SDL_UpperBlit"
typedef int32_t(*sdl_upperblit_t)(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect);
#define SDL_CREATERGBSURFACEWITHFORMATFROM_FUNCTION "SDL_CreateRGBSurfaceWithFormatFrom"
typedef SDL_Surface* (*sdl_creatergbsurfacewithformatfrom_t)(void* pixels, int width, int height, int depth, int pitch, Uint32 format);


/* rects */
#define SDL_FILLRECT_FUNCTION "SDL_FillRect"
typedef int32_t(*sdl_fillrect_t)(SDL_Surface* dst, const SDL_Rect* rect, uint32_t color);

// Ex
#define SDL_MAPRGB_FUNCTION "SDL_MapRGB"
typedef uint32_t(*sdl_maprgb_t)(const SDL_PixelFormat* format, uint8_t r, uint8_t g, uint8_t b);

// Textures
#define SDL_SETTEXTUREBLENDMODE_FUNCTION "SDL_SetTextureBlendMode"
typedef int32_t(*sdl_settextureblendmode_t)(SDL_Texture* texture, SDL_BlendMode blendMode);
#define SDL_SETTEXTUREALPHAMOD_FUNCTION "SDL_SetTextureAlphaMod"
typedef int32_t(*sdl_settexturealphamod_t)(SDL_Texture* texture, uint8_t alpha);
#define SDL_CREATETEXTURE_FUNCTION "SDL_CreateTexture"
typedef SDL_Texture* (*sdl_createtexture_t)(SDL_Renderer* renderer, Uint32 format, int access, int w, int h);
#define SDL_LOCKTEXTURE_FUNCTION "SDL_LockTexture"
typedef int32_t(*sdl_locktexture_t)(SDL_Texture* texture, const SDL_Rect* rect, void** pixels, int* pitch);
#define SDL_UNLOCKTEXTURE_FUNCTION "SDL_UnlockTexture"
typedef void(*sdl_unlocktexture_t)(SDL_Texture* texture);


// Events
#define SDL_WAITEVENT_FUNCTION "SDL_WaitEvent"
typedef int32_t(*sdl_waitevent_t)(SDL_Event* evnt);
#define SDL_PUSHEVENT_FUNCTION "SDL_PushEvent"
typedef int32_t(*sdl_pushevent_t)(SDL_Event* evnt);

// Cursor
#define SDL_GETCURSOR_FUNCTION "SDL_GetCursor"
typedef SDL_Cursor*(*sdl_getcursor_t)(void);
#define SDL_SETCURSOR_FUNCTION "SDL_SetCursor"
typedef void(*sdl_setcursor_t)(SDL_Cursor* cursor);
#define SDL_FREECURSOR_FUNCTION "SDL_FreeCursor"
typedef void(*sdl_freecursor_t)(SDL_Cursor* cursor);
#define SDL_CREATESYSTEMCURSOR_FUNCTION "SDL_CreateSystemCursor"
typedef SDL_Cursor*(*sdl_createsystemcursor_t)(SDL_SystemCursor id);
#define SDL_SHOWCURSOR_FUNCTION "SDL_ShowCursor"
typedef int32_t(*sdl_showcursor_t)(int32_t toggle);

// Clipboard
#define SDL_SETCLIPBOARDTEXT_FUNCTION "SDL_SetClipboardText"
typedef int32_t(*sdl_setclipboardtext_t)(const char* text);


#define SDL_GETWINDOWSIZE_FUNCTION "SDL_GetWindowSize"
typedef void(*sdl_getwindowsize_t)(SDL_Window* window, int* w, int* h);


#define SDL_SAVEBMPRW_FUNCTION "SDL_SaveBMP_RW"
typedef int32_t(*sdl_savebmprw_t)(SDL_Surface* surface, SDL_RWops* dst, int freedst);


typedef int32_t(*sdl_init_t)(uint32_t flags);
typedef void(*sdl_quit_t)(void);
typedef const char* (*sdl_geterror_t)(void);

typedef int32_t(*sdl_setrenderdrawcolor_t)(SDL_Renderer* renderer, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
typedef int32_t(*sdl_pollevent_t)(SDL_Event* sevent);
typedef int32_t(*sdl_renderclear_t)(SDL_Renderer* renderer);
typedef int32_t(*sdl_rendercopy_t)(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
typedef void (*sdl_renderpresent_t)(SDL_Renderer* renderer);
typedef void (*sdl_destroytexture_t)(SDL_Texture* texture);
typedef void (*sdl_destroyrenderer_t)(SDL_Renderer* renderer);
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
// Window
typedef SDL_Window* (*sdl_createwindow_t)(const char* title, int32_t x, int32_t y, int32_t w, int32_t h, uint32_t flags);
typedef void (*sdl_destroywindow_t)(SDL_Window* window);
typedef uint32_t(*sdl_getwindowflags_t)(SDL_Window* window);
typedef int32_t(*sdl_setwindowfullscreen_t)(SDL_Window* window, uint32_t flags);

// Renderer Inits
typedef SDL_Renderer* (*sdl_createrenderer_t)(SDL_Window* window, int32_t index, uint32_t flags);
typedef int32_t(*sdl_getnumrenderdrivers_t)(void);
typedef int32_t(*sdl_getnumrenderdriverinfo_t)(int32_t index, SDL_RendererInfo* info);
#define SDL_SETRENDERTARGET_FUNCTION "SDL_SetRenderTarget"
typedef int32_t(*sdl_setrendertarget_t)(SDL_Renderer* renderer, SDL_Texture* texture);
#define SDL_GETRENDEROUTPUTSIZE_FUNCTION "SDL_GetRendererOutputSize"
typedef int32_t(*sdl_getrendereroutputsize_t)(SDL_Renderer* renderer, int* w, int* h);
#define SDL_SETTEXTURECOLORMOD_FUNCTION "SDL_SetTextureColorMod"
typedef int32_t(*sdl_settexturecolormod_t)(SDL_Texture* texture, Uint8 r, Uint8 g, Uint8 b);
#define SDL_RENDERREADPIXELS_FUNCTION "SDL_RenderReadPixels"
typedef int32_t(*sdl_rendererreadpixels_t)(SDL_Renderer* renderer, const SDL_Rect* rect, Uint32 format, void* pixels, int pitch);
#define SDL_RENDERDRAWRECT_FUNCTION "SDL_RenderDrawRect"
typedef int32_t(*sdl_rendererdrawrect_t)(SDL_Renderer* renderer, const SDL_Rect* rect);

// Memory functions
typedef SDL_RWops* (*sdl_rwfromfile_t)(const char* file, const char* mode);
typedef SDL_RWops* (*sdl_rwfrommem_t)(void* mem, int size);
typedef SDL_RWops* (*sdl_rwfromconstmem_t)(const void* mem, int size);


class CSDL {
private:
	static CSDL* sInstance;
private:
	CSDL();
	~CSDL();

public:
	CSDL(const CSDL& obj) = delete;       /* Remove the copy constructor */
	void operator=(const CSDL&) = delete; /* Remove the assignment operator */
public:
	static bool IsInitialized;

	static CSDL* Instance();
	static void Release();

	static int32_t Init(uint32_t dwFlag);
	static void Quit(void);
	static const char* GetError(void);

	static int32_t SetRenderDrawColor(SDL_Renderer* renderer, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	static SDL_Texture* CreateTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface);
	static void FreeSurface(SDL_Surface* surface);
	static int32_t PollEvent(SDL_Event* sevent);
	static int32_t RenderClear(SDL_Renderer* renderer);
	static int32_t RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
	static void RenderPresent(SDL_Renderer* renderer);
	static void DestroyTexture(SDL_Texture* texture);
	static void DestroyRenderer(SDL_Renderer* renderer);

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
	static int32_t SetRenderTarget(SDL_Renderer* renderer, SDL_Texture* texture);
	static int32_t GetRendererOutputSize(SDL_Renderer* renderer, int* w, int* h);
	static int32_t SetTextureColorMod(SDL_Texture* texture, Uint8 r, Uint8 g, Uint8 b);
	static int32_t RenderReadPixels(SDL_Renderer* renderer, const SDL_Rect* rect, Uint32 format, void* pixels, int pitch);
	static int32_t RenderDrawRect(SDL_Renderer* renderer, const SDL_Rect* rect);

	// Memory func
	static SDL_RWops* RWFromFile(const char* file, const char* mode);
	static SDL_RWops* RWFromMem(void* mem, int size);
	static SDL_RWops* RWFromConstMem(const void* mem, int size);
	static void FreeRW(SDL_RWops* area);
	static void RWclose(SDL_RWops* ctx);

	// Window
	static SDL_Window* CreateHWindow(const char* title, int32_t x, int32_t y, int32_t w, int32_t h, uint32_t flags);
	static void DestroyWindow(SDL_Window* window);
	static uint32_t GetWindowFlags(SDL_Window* window);
	static int32_t SetWindowFullscreen(SDL_Window* window, uint32_t flags);
	static void GetWindowSize(SDL_Window* window, int* w, int* h);

	// Surfaces
	static SDL_Surface* CreateRGBSurfaceWithFormat(Uint32 flags, int width, int height, int depth, Uint32 format);
	static SDL_Surface* CreateRGBSurface(uint32_t flags, int32_t width, int32_t height, int32_t depth, uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask);
	static int32_t SetSurfaceColorMod(SDL_Surface* surface, uint8_t r, uint8_t g, uint8_t b);
	static int32_t SetSurfaceAlphaMod(SDL_Surface* surface, uint8_t alpha);
	static int32_t UpperBlit(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect);
	static int32_t BlitSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect);
	static SDL_Surface* CreateRGBSurfaceWithFormatFrom(void* pixels, int width, int height, int depth, int pitch, Uint32 format);

	// Rect
	static int32_t FillRect(SDL_Surface* dst, const SDL_Rect* rect, uint32_t color);

	// Ex
	static uint32_t MapRGB(const SDL_PixelFormat* format, uint8_t r, uint8_t g, uint8_t b);

	// Textures
	static int32_t SetTextureBlendMode(SDL_Texture* texture, SDL_BlendMode blendMode);
	static int32_t SetTextureAlphaMod(SDL_Texture* texture, uint8_t alpha);
	static SDL_Texture* CreateTexture(SDL_Renderer* renderer, Uint32 format, int access, int w, int h);
	static int32_t LockTexture(SDL_Texture* texture, const SDL_Rect* rect, void** pixels, int* pitch);
	static void UnlockTexture(SDL_Texture* texture);

	// Events
	static int32_t WaitEvent(SDL_Event* evnt);
	static int32_t PushEvent(SDL_Event* evnt);

	// Cursor
	static SDL_Cursor* GetCursor();
	static void SetCursor(SDL_Cursor* cursor);
	static void FreeCursor(SDL_Cursor* cursor);
	static SDL_Cursor* CreateSystemCursor(SDL_SystemCursor id);
	static int32_t ShowCursor(int32_t toggle);

	// Initial
	static SDL_bool SetHint(const char* name, const char* value);
	static SDL_bool GetWindowWMInfo(SDL_Window* window, SDL_SysWMinfo* info);
	static uint32_t GetWindowID(SDL_Window* window);

	// Clipboard
	static int32_t SetClipboardText(const char* text);

	// Math macros...
	static int32_t BYTESPERPIXEL(int32_t value);
	static int32_t BITSPERPIXEL(int32_t value);

	static int32_t SaveBMP_RW(SDL_Surface* surface, SDL_RWops* dst, int freedst);

	static int32_t SaveBMP(SDL_Surface* sur, const char* file);

	static void Log(const char *fmt, ...);
private:
	/* SDL2 Initialization calls */
	sdl_init_t SDL_Init = nullptr;

	/* sdl2 */
	sdl_setrenderdrawcolor_t SDL_SetRenderDrawColor = nullptr;
	sdl_createtexturefromsurface_t SDL_CreateTextureFromSurface = nullptr;
	sdl_freesurface_t SDL_FreeSurface = nullptr;
	sdl_pollevent_t SDL_PollEvent = nullptr;
	sdl_renderclear_t SDL_RenderClear = nullptr;
	sdl_rendercopy_t SDL_RenderCopy = nullptr;
	sdl_renderpresent_t SDL_RenderPresent = nullptr;
	sdl_destroytexture_t SDL_DestroyTexture = nullptr;
	sdl_destroyrenderer_t SDL_DestroyRenderer = nullptr;
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
	sdl_setrendertarget_t SDL_SetRenderTarget = nullptr;
	sdl_getrendereroutputsize_t SDL_GetRendererOutputSize = nullptr;
	sdl_settexturecolormod_t SDL_SetTextureColorMod = nullptr;
	sdl_rendererreadpixels_t SDL_RenderReadPixels = nullptr;
	sdl_rendererdrawrect_t SDL_RenderDrawRect = nullptr;

	//memory func
	sdl_rwfromfile_t SDL_RWFromFile = nullptr;
	sdl_rwfrommem_t SDL_RWFromMem = nullptr;
	sdl_rwfromconstmem_t SDL_RWFromConstMem = nullptr;
	sdl_freerw_t SDL_FreeRW = nullptr;

	//window
	sdl_createwindow_t SDL_CreateWindow = nullptr;
	sdl_destroywindow_t SDL_DestroyWindow = nullptr;
	sdl_getwindowflags_t SDL_GetWindowFlags = nullptr;
	sdl_setwindowfullscreen_t SDL_SetWindowFullscreen = nullptr;
	sdl_getwindowsize_t SDL_GetWindowSize = nullptr;

	// Surfaces
	sdl_creatergbsurfacewithformat_t SDL_CreateRGBSurfaceWithFormat = nullptr;
	sdl_creatergbsurface_t SDL_CreateRGBSurface = nullptr;
	sdl_setsurfacecolormod_t SDL_SetSurfaceColorMod = nullptr;
	sdl_setsurfacealphamod_t SDL_SetSurfaceAlphaMod = nullptr;
	sdl_upperblit_t SDL_UpperBlit = nullptr;
	sdl_creatergbsurfacewithformatfrom_t SDL_CreateRGBSurfaceWithFormatFrom = nullptr;


	// Rect
	sdl_fillrect_t SDL_FillRect = nullptr;
	// Ex
	sdl_maprgb_t SDL_MapRGB = nullptr;
	// Textures
	sdl_settextureblendmode_t SDL_SetTextureBlendMode = nullptr;
	sdl_settexturealphamod_t SDL_SetTextureAlphaMod = nullptr;
	sdl_createtexture_t SDL_CreateTexture = nullptr;
	sdl_locktexture_t SDL_LockTexture = nullptr;
	sdl_unlocktexture_t SDL_UnlockTexture = nullptr;

	// Events
	sdl_waitevent_t SDL_WaitEvent = nullptr;
	sdl_pushevent_t SDL_PushEvent = nullptr;

	// Cursor
	sdl_getcursor_t SDL_GetCursor = nullptr;
	sdl_setcursor_t SDL_SetCursor = nullptr;
	sdl_freecursor_t SDL_FreeCursor = nullptr;
	sdl_createsystemcursor_t SDL_CreateSystemCursor = nullptr;
	sdl_showcursor_t SDL_ShowCursor = nullptr;

	// Initial
	sdl_sethint_t SDL_SetHint = nullptr;
	sdl_getwindowwminfo_t SDL_GetWindowWMInfo = nullptr;
	sdl_getwindowid_t SDL_GetWindowID = nullptr;

	// Clipboard
	sdl_setclipboardtext_t SDL_SetClipboardText = nullptr;

	// bmp
	sdl_savebmprw_t SDL_SaveBMP_RW = nullptr;

private:
	HINSTANCE SDL_LOADED_DLL;
};

#endif
