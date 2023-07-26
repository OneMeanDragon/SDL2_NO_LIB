#include "SDL2Nolibs.h"
#include "SDL2Image.h"

CImage* CImage::sInstance = nullptr;
bool CImage::IsInitialized = false;

CImage* CImage::Instance() {
	if (sInstance == nullptr)
		sInstance = new CImage();

	return sInstance;
}

void CImage::Release()
{
	/* if anything else needs to be destroyed before this then do it above the instance deleteion */
	delete sInstance;
	sInstance = nullptr;
}

CImage::CImage() {
	IMAGE_LOADED_DLL = LoadLibrary(SDL_IMAGE_DLL);
	if (IMAGE_LOADED_DLL)
	{
		IMG_Init = (sdl_init_t)GetProcAddress(IMAGE_LOADED_DLL, IMAGE_INIT_FUNCTION);
		IMG_Quit = (sdl_quit_t)GetProcAddress(IMAGE_LOADED_DLL, IMAGE_IMAGEQUIT_FUNCTION);
		IMG_Load = (sdl_loadimage_t)GetProcAddress(IMAGE_LOADED_DLL, IMAGE_LOADIMAGE_FUNCTION);
		IMG_LoadPNG_RW = (sdl_loadpng_rw_t)GetProcAddress(IMAGE_LOADED_DLL, IMAGE_LOADPNG_RW_FUNCTION);

		IsInitialized = true;
	}
}

CImage::~CImage() {
	if (IMAGE_LOADED_DLL) {
		FreeLibrary(IMAGE_LOADED_DLL);
	}
}

/* SDL_IMAGE_DLL */
int32_t CImage::Init(uint32_t dwFlag) {
	return Instance()->IMG_Init(dwFlag);
}

SDL_Surface* CImage::Load(const char* file)
{
	return Instance()->IMG_Load(file);
}

void CImage::Quit(void)
{
	Instance()->IMG_Quit();
	return Instance()->Release();
}

const char* CImage::GetError(void)
{
	return CSDL::Instance()->GetError();
}

#pragma region "Mem Funcs"

SDL_Surface* CImage::LoadPNG_RW(SDL_RWops* src)
{
	return Instance()->IMG_LoadPNG_RW(src);
}

#pragma endregion
