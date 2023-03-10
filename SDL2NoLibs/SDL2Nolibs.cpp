#include "SDL2Nolibs.h"

CSDL* CSDL::sInstance = nullptr;
bool CSDL::IsInitialized = false;

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

		SDL_RenderCopyEx = (sdl_rendercopyex_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERCOPYEX_FUNCTION);
		SDL_RenderDrawLine = (sdl_renderdrawline_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERDRAWLINE_FUNCTION);

		SDL_GetBasePath = (sdl_geterror_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETBASEPATH_FUNCTION);

		SDL_GetTicks = (sdl_getticks_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETTICKS_FUNCTION);
		SDL_QueryTexture = (sdl_querytexture_t)GetProcAddress(SDL_LOADED_DLL, SDL_QUERYTEXTURE_FUNCTION);

		SDL_GetKeyboardState = (sdl_getkeyboardstate_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETKEYBOARDSTATE_FUNCTION);
		SDL_GetMouseState = (sdl_getmousestate_t)GetProcAddress(SDL_LOADED_DLL, SDL_GETMOUSESTATE_FUNCTION);
		SDL_RWFromFile = (sdl_rwfromfile_t)GetProcAddress(SDL_LOADED_DLL, SDL_RWFROMFILE_FUNCTION);
		SDL_RenderFillRect = (sdl_renderfillrect_t)GetProcAddress(SDL_LOADED_DLL, SDL_RENDERFILLRECT_FUNCTION);

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
	Instance()->SDL_Quit();
	return Instance()->Release();
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

SDL_RWops* CSDL::RWFromFile(const char* file, const char* mode)
{
	return Instance()->SDL_RWFromFile(file, mode);
}

int32_t CSDL::RenderFillRect(SDL_Renderer* renderer, const SDL_Rect* rect)
{
	return Instance()->SDL_RenderFillRect(renderer, rect);
}


#pragma region "TIMER"
Timer* Timer::sInstance = NULL;

Timer* Timer::Instance() {

	//Create a new instance of Timer if no instance was created before
	if (sInstance == NULL)
		sInstance = new Timer();

	return sInstance;
}

void Timer::Release() {

	delete sInstance;
	sInstance = NULL;
}

Timer::Timer() {

	//Using Reset to initialize all the values beside mTimeScale
	Reset();
	mTimeScale = 1.0f;
}

Timer::~Timer() {

}

void Timer::Reset() {

	mStartTicks = CSDL::GetTicks();
	mElapsedTicks = 0;
	mDelataTime = 0.0f;
}

float Timer::DeltaTime() {

	return mDelataTime;
}

void Timer::TimeScale(float t) {

	mTimeScale = t;
}

float Timer::TimeScale() {

	return mTimeScale;
}

void Timer::Update() {

	mElapsedTicks = CSDL::GetTicks() - mStartTicks;
	//Converting milliseconds to seconds
	mDelataTime = mElapsedTicks * 0.001f;
}
#pragma endregion