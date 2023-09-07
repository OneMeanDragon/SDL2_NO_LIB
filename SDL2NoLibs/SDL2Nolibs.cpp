#include "SDL2Nolibs.h"

#pragma region "SDL2.DLL"

#if defined(SDL_MUTEX)
std::mutex Singleton::mutex_;
#endif
CSDL* CSDL::sInstance = nullptr;
bool CSDL::IsInitialized = false;

CSDL* CSDL::Instance() {
#if defined(SDL_MUTEX)
	std::lock_guard<std::mutex> lock(mutex_);
#endif
	if (sInstance == nullptr)
		sInstance = new CSDL();

	return sInstance;
}

void CSDL::Release()
{
	/* if anything else needs to be destroyed before this then do it above the instance deleteion */
	if (sInstance != nullptr) {
		delete sInstance;
		sInstance = nullptr;
	}
}

CSDL::CSDL() {
	SDL_LOADED_DLL = LoadLibrary(SDL_MAIN_DLL);
	if (SDL_LOADED_DLL)
	{
		SDL_Init = (sdl_init_t)GetProcAddress(SDL_LOADED_DLL, SDL_INIT_FUNCTION);
		SDL_Quit = (sdl_quit_t)GetProcAddress(SDL_LOADED_DLL, SDL_QUIT_FUNCTION);
		SDL_SetRenderDrawColor = (sdl_setrenderdrawcolor_t)GetProcAddress(SDL_LOADED_DLL, SDL_SETRENDERDRAWCOLOR_FUNCTION);
		SDL_CreateTextureFromSurface = (sdl_createtexturefromsurface_t)GetProcAddress(SDL_LOADED_DLL, SDL_CREATETEXTUREFROMSURFACE_FUNCTION);
		SDL_FreeSurface = (sdl_freesurface_t)GetProcAddress(SDL_LOADED_DLL, SDL_FREESURFACE_FUNCTION);
		SDL_PollEvent = (sdl_pollevent_t)GetProcAddress(SDL_LOADED_DLL, SDL_POLLEVENT_FUNCTION);
		SDL_RenderClear = (sdl_renderclear_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERCLEAR_FUNCTION);
		SDL_RenderCopy = (sdl_rendercopy_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERCOPY_FUNCTION);
		SDL_RenderPresent = (sdl_renderpresent_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERPRESENT_FUNCTION);

		SDL_DestroyTexture = (sdl_destroytexture_t)GetProcAddress(SDL_LOADED_DLL, SDL_DESTROYTEXTURE_FUNCTION);
		SDL_DestroyRenderer = (sdl_destroyrenderer_t)GetProcAddress(SDL_LOADED_DLL, SDL_DESTROYRENDERER_FUNCTION);

		SDL_GetError = (sdl_geterror_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETERROR_FUNCTION);

		SDL_RenderCopyEx = (sdl_rendercopyex_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERCOPYEX_FUNCTION);
		SDL_RenderDrawLine = (sdl_renderdrawline_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERDRAWLINE_FUNCTION);

		SDL_GetBasePath = (sdl_geterror_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETBASEPATH_FUNCTION);

		SDL_GetTicks = (sdl_getticks_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETTICKS_FUNCTION);
		SDL_QueryTexture = (sdl_querytexture_t)GetProcAddress(SDL_LOADED_DLL, SDL_QUERYTEXTURE_FUNCTION);

		SDL_GetKeyboardState = (sdl_getkeyboardstate_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETKEYBOARDSTATE_FUNCTION);
		SDL_GetMouseState = (sdl_getmousestate_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETMOUSESTATE_FUNCTION);
		SDL_RenderFillRect = (sdl_renderfillrect_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERFILLRECT_FUNCTION);

		// DeltaTime (SDL_GetPerformanceCounter & SDL_GetPerformanceFrequency & SDL_Delay)
		SDL_GetPerformanceCounter = (sdl_getperformancecounter_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETPERFORMANCECOUNTER_FUNCTION);
		SDL_GetPerformanceFrequency = (sdl_getperformancefrequency_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETPERFORMANCEFREQUENCY_FUNCTION);
		SDL_Delay = (sdl_delay_t)GetProcAddress(SDL_LOADED_DLL, SDL_DELAY_FUNCTION);

		// Renderer Inits
		SDL_CreateRenderer = (sdl_createrenderer_t)GetProcAddress(SDL_LOADED_DLL, SDL_CREATERENDERER_FUNCTION);
		SDL_GetNumRenderDrivers = (sdl_getnumrenderdrivers_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETNUMRENDERDRIVERS_FUNCTION);
		SDL_GetRenderDriverInfo = (sdl_getnumrenderdriverinfo_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETNUMRENDERDRIVERINFO_FUNCTION);
		SDL_SetRenderTarget = (sdl_setrendertarget_t)GetProcAddress(SDL_LOADED_DLL, SDL_SETRENDERTARGET_FUNCTION);

		// Memory Func
		SDL_RWFromFile = (sdl_rwfromfile_t)GetProcAddress(SDL_LOADED_DLL, SDL_RWFROMFILE_FUNCTION);
		SDL_RWFromMem = (sdl_rwfrommem_t)GetProcAddress(SDL_LOADED_DLL, SDL_RWFROMMEM_FUNCTION);
		SDL_RWFromConstMem = (sdl_rwfromconstmem_t)GetProcAddress(SDL_LOADED_DLL, SDL_RWFROMCONSTMEM_FUNCTION);
		SDL_FreeRW = (sdl_freerw_t)GetProcAddress(SDL_LOADED_DLL, SDL_FREERW_FUNCTION);

		// Window Flags
		SDL_CreateWindow = (sdl_createwindow_t)GetProcAddress(SDL_LOADED_DLL, SDL_CREATEWINDOW_FUNCTION);
		SDL_DestroyWindow = (sdl_destroywindow_t)GetProcAddress(SDL_LOADED_DLL, SDL_DESTROYWINDOW_FUNCTION);
		SDL_GetWindowFlags = (sdl_getwindowflags_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETWINDOWFLAGS_FUNCTION);
		SDL_SetWindowFullscreen = (sdl_setwindowfullscreen_t)GetProcAddress(SDL_LOADED_DLL, SDL_SETWINDOWFULLSCREEN_FUNCTION);

		// Surfaces
		//SDL_CreateSurface() SDL3 only apparently
		SDL_CreateRGBSurfaceWithFormat = (sdl_creatergbsurfacewithformat_t)GetProcAddress(SDL_LOADED_DLL, SDL_CREATERGBSURFACEWITHFORMAT_FUNCTION);
		SDL_CreateRGBSurface = (sdl_creatergbsurface_t)GetProcAddress(SDL_LOADED_DLL, SDL_CREATERGBSURFACE_FUNCTION);
		SDL_SetSurfaceColorMod = (sdl_setsurfacecolormod_t)GetProcAddress(SDL_LOADED_DLL, SDL_SETSURFACECOLORMOD_FUNCTION);
		SDL_SetSurfaceAlphaMod = (sdl_setsurfacealphamod_t)GetProcAddress(SDL_LOADED_DLL, SDL_SETSURFACEALPHAMOD_FUNCTION);
		SDL_UpperBlit = (sdl_upperblit_t)GetProcAddress(SDL_LOADED_DLL, SDL_UPPERBLIT_FUNCTION);
		
		//Rects
		SDL_FillRect = (sdl_fillrect_t)GetProcAddress(SDL_LOADED_DLL, SDL_FILLRECT_FUNCTION);

		// Ex
		SDL_MapRGB = (sdl_maprgb_t)GetProcAddress(SDL_LOADED_DLL, SDL_MAPRGB_FUNCTION);

		// Textures
		SDL_SetTextureBlendMode = (sdl_settextureblendmode_t)GetProcAddress(SDL_LOADED_DLL, SDL_SETTEXTUREBLENDMODE_FUNCTION);
		SDL_SetTextureAlphaMod = (sdl_settexturealphamod_t)GetProcAddress(SDL_LOADED_DLL, SDL_SETTEXTUREALPHAMOD_FUNCTION);
		SDL_CreateTexture = (sdl_createtexture_t)GetProcAddress(SDL_LOADED_DLL, SDL_CREATETEXTURE_FUNCTION);
		SDL_LockTexture = (sdl_locktexture_t)GetProcAddress(SDL_LOADED_DLL, SDL_LOCKTEXTURE_FUNCTION);
		SDL_UnlockTexture = (sdl_unlocktexture_t)GetProcAddress(SDL_LOADED_DLL, SDL_UNLOCKTEXTURE_FUNCTION);


		// Event
		SDL_PushEvent = (sdl_pushevent_t)GetProcAddress(SDL_LOADED_DLL, SDL_PUSHEVENT_FUNCTION);

		// Cursor
		SDL_GetCursor = (sdl_getcursor_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETCURSOR_FUNCTION);
		SDL_SetCursor = (sdl_setcursor_t)GetProcAddress(SDL_LOADED_DLL, SDL_SETCURSOR_FUNCTION);
		SDL_FreeCursor = (sdl_freecursor_t)GetProcAddress(SDL_LOADED_DLL, SDL_FREECURSOR_FUNCTION);
		SDL_CreateSystemCursor = (sdl_createsystemcursor_t)GetProcAddress(SDL_LOADED_DLL, SDL_CREATESYSTEMCURSOR_FUNCTION);
		SDL_ShowCursor = (sdl_showcursor_t)GetProcAddress(SDL_LOADED_DLL, SDL_SHOWCURSOR_FUNCTION);


		IsInitialized = true;
	}
}

CSDL::~CSDL() {
	if (SDL_LOADED_DLL) {
		FreeLibrary(SDL_LOADED_DLL);
	}
}

/* SDL2_DLL */
int32_t CSDL::Init(uint32_t dwFlag) {
	return Instance()->SDL_Init(dwFlag);
}

void CSDL::Quit(void)
{
	if (sInstance != nullptr) {
		Instance()->SDL_Quit();
		return Instance()->Release();
	}
	return;
}

const char* CSDL::GetError(void)
{
	return Instance()->SDL_GetError();
}

uint64_t CSDL::GetPerformanceCounter() {
	return Instance()->SDL_GetPerformanceCounter();
}

uint64_t CSDL::GetPerformanceFrequency() {
	return Instance()->SDL_GetPerformanceFrequency();
}

void CSDL::Delay(uint32_t ms) {
	return Instance()->SDL_Delay(ms);
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

int32_t CSDL::RenderCopyEx(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect, const double angle, const SDL_Point* center, const SDL_RendererFlip flip)
{
	return Instance()->SDL_RenderCopyEx(renderer, texture, srcrect, dstrect, angle, center, flip);
}

int32_t CSDL::RenderDrawLine(SDL_Renderer* renderer, int32_t x1, int32_t y1, int32_t x2, int32_t y2)
{
	return Instance()->SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

const char* CSDL::GetBasePath(void)
{
	return Instance()->SDL_GetBasePath();
}

uint32_t CSDL::GetTicks(void)
{
	return Instance()->SDL_GetTicks();
}

int32_t CSDL::QueryTexture(SDL_Texture* texture, uint32_t* format, int32_t* access, int32_t* w, int32_t* h)
{
	return Instance()->SDL_QueryTexture(texture, format, access, w, h);
}

const uint8_t* CSDL::GetKeyboardState(int32_t* numkeys)
{
	return Instance()->SDL_GetKeyboardState(numkeys);
}

uint32_t CSDL::GetMouseState(int32_t* x, int32_t* y)
{
	return Instance()->SDL_GetMouseState(x, y);
}

int32_t CSDL::RenderFillRect(SDL_Renderer* renderer, const SDL_Rect* rect)
{
	return Instance()->SDL_RenderFillRect(renderer, rect);
}

#pragma region "Texture"

int32_t CSDL::LockTexture(SDL_Texture* texture, const SDL_Rect* rect, void** pixels, int* pitch) {
	return Instance()->SDL_LockTexture(texture, rect, pixels, pitch);
}

void CSDL::UnlockTexture(SDL_Texture* texture) {
	return Instance()->SDL_UnlockTexture(texture);
}

#pragma endregion



#pragma region "Window"
SDL_Window* CSDL::CreateHWindow(const char* title, int32_t x, int32_t y, int32_t w, int32_t h, uint32_t flags)
{
	return Instance()->SDL_CreateWindow(title, x, y, w, h, flags);
}

void CSDL::DestroyWindow(SDL_Window* window)
{
	return Instance()->SDL_DestroyWindow(window);
}

uint32_t CSDL::GetWindowFlags(SDL_Window* window) {
	return Instance()->SDL_GetWindowFlags(window);
}

int32_t CSDL::SetWindowFullscreen(SDL_Window* window, uint32_t flags) {
	return Instance()->SDL_SetWindowFullscreen(window, flags);
}
#pragma endregion



#pragma region "Renderer Inits"
SDL_Renderer* CSDL::CreateRenderer(SDL_Window* window, int32_t index, uint32_t flags)
{
	return Instance()->SDL_CreateRenderer(window, index, flags);
}

int32_t CSDL::GetNumRenderDrivers(void) {
	return Instance()->SDL_GetNumRenderDrivers();
}

int32_t CSDL::GetRenderDriverInfo(int32_t index, SDL_RendererInfo* info) {
	return Instance()->SDL_GetRenderDriverInfo(index, info);
}

int32_t CSDL::SetRenderTarget(SDL_Renderer* renderer, SDL_Texture* texture) {
	return Instance()->SDL_SetRenderTarget(renderer, texture);
}
#pragma endregion



#pragma region "Memory Func"
SDL_RWops* CSDL::RWFromFile(const char* file, const char* mode)
{
	return Instance()->SDL_RWFromFile(file, mode);
}

SDL_RWops* CSDL::RWFromMem(void* mem, int size)
{
	return Instance()->SDL_RWFromMem(mem, size);
}

SDL_RWops* CSDL::RWFromConstMem(const void* mem, int size)
{
	return Instance()->SDL_RWFromConstMem(mem, size);
}

void CSDL::FreeRW(SDL_RWops* area)
{
	return Instance()->SDL_FreeRW(area);
}

#pragma endregion

#pragma region "Surfaces"

SDL_Surface* CSDL::CreateRGBSurfaceWithFormat(Uint32 flags, int width, int height, int depth, Uint32 format) {
	return Instance()->SDL_CreateRGBSurfaceWithFormat(flags, width, height, depth, format);
}

SDL_Surface* CSDL::CreateRGBSurface(uint32_t flags, int32_t width, int32_t height, int32_t depth, uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask) {
	return Instance()->SDL_CreateRGBSurface(flags, width, height, depth, Rmask, Gmask, Bmask, Amask);
}

int32_t CSDL::SetSurfaceColorMod(SDL_Surface* surface, uint8_t r, uint8_t g, uint8_t b) {
	return Instance()->SDL_SetSurfaceColorMod(surface, r, g, b);
}

int32_t CSDL::SetSurfaceAlphaMod(SDL_Surface* surface, uint8_t alpha) {
	return Instance()->SDL_SetSurfaceAlphaMod(surface, alpha);
}

int32_t CSDL::UpperBlit(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect) {
	return Instance()->SDL_UpperBlit(src, srcrect, dst, dstrect);
}

int32_t CSDL::BlitSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect) {
	return UpperBlit(src, srcrect, dst, dstrect);
}

#pragma endregion

#pragma region "Rects"

int32_t CSDL::FillRect(SDL_Surface* dst, const SDL_Rect* rect, uint32_t color) {
	return Instance()->SDL_FillRect(dst, rect, color);
}

// Ex
uint32_t CSDL::MapRGB(const SDL_PixelFormat* format, uint8_t r, uint8_t g, uint8_t b) {
	return Instance()->SDL_MapRGB(format, r, g, b);
}
#pragma endregion

#pragma region "Textures"
int32_t CSDL::SetTextureBlendMode(SDL_Texture* texture, SDL_BlendMode blendMode) {
	return Instance()->SDL_SetTextureBlendMode(texture, blendMode);
}

int32_t CSDL::SetTextureAlphaMod(SDL_Texture* texture, uint8_t alpha) {
	return Instance()->SDL_SetTextureAlphaMod(texture, alpha);
}

SDL_Texture* CSDL::CreateTexture(SDL_Renderer* renderer, Uint32 format, int access, int w, int h) {
	return Instance()->SDL_CreateTexture(renderer, format, access, w, h);
}

#pragma endregion

#pragma region "Events"
int32_t CSDL::PushEvent(SDL_Event* evnt) {
	return Instance()->SDL_PushEvent(evnt);
}
#pragma endregion

#pragma region "Cursor"
SDL_Cursor* CSDL::GetCursor(){
	return Instance()->SDL_GetCursor();
}
void CSDL::SetCursor(SDL_Cursor* cursor){
	return Instance()->SDL_SetCursor(cursor);
}
void CSDL::FreeCursor(SDL_Cursor* cursor){
	return Instance()->SDL_FreeCursor(cursor);
}
SDL_Cursor* CSDL::CreateSystemCursor(SDL_SystemCursor id){
	return Instance()->SDL_CreateSystemCursor(id);
}
int32_t CSDL::ShowCursor(int32_t toggle) {
	return Instance()->SDL_ShowCursor(toggle);
}
#pragma endregion

#pragma endregion // End SDL2.DLL
