# SDL2NoLibs
SDL2 Singleton Class's, to remove the the need to include the ".LIB" files.

# Includes 
Currently what I actually use from the SDL2 dlls, so if your looking for a specific function add it.

### The _"SDL2" folder in here can be ignored unless you just want the basic window lol_
  - SDL2(NoLibs)
  - SDL2_Image
  - SDL2_TTF
  - SDL2_Mixer

#### _Example_
```cpp
#include <iostream>

#include "SDL2NoLibs.h"
#include "SDL2Image.h"

int main() {
	//const int FRAME_RATE = 120;
	//Timer* mTimer = Timer::Instance();

	CSDL::Init(SDL_INIT_VIDEO);
	if (!(CImage::Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		printf("IMG Initialization Error: %s\n", CImage::GetError());
		return;
	}

	SDL_Window* window = CSDL::CreateHWindow("PNG Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 536, 285, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = CSDL::CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	CSDL::SetRenderDrawColor(renderer, 0x5, 0x5, 0x5, 0xFF);

	
	SDL_Surface* imageSurface[19] = {
		CImage::Load("images\\background00.png"),
		CImage::Load("images\\background01.png"),
		CImage::Load("images\\background02.png"),
		CImage::Load("images\\background03.png"),
		CImage::Load("images\\background04.png"),
		CImage::Load("images\\background05.png"),
		CImage::Load("images\\background06.png"),
		CImage::Load("images\\background07.png"),
		CImage::Load("images\\background08.png"),
		CImage::Load("images\\background09.png"),
		CImage::Load("images\\background10.png"),
		CImage::Load("images\\background11.png"),
		CImage::Load("images\\background12.png"),
		CImage::Load("images\\background13.png"),
		CImage::Load("images\\background14.png"),
		CImage::Load("images\\background15.png"),
		CImage::Load("images\\background16.png"),
		CImage::Load("images\\background17.png"),
		CImage::Load("images\\background18.png")
	};

	SDL_Texture* imageTexture[19] = { nullptr };
	for (int i = 0; i < 19; i++)
	{
		imageTexture[i] = CSDL::CreateTextureFromSurface(renderer, imageSurface[i]);
		CSDL::FreeSurface(imageSurface[i]); /* unload the surface */
	}

	SDL_Event event;
	bool running = true;
	while (running) {
		//mTimer->Update();

		while (CSDL::PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		//if (mTimer->DeltaTime() >= (1.0f / FRAME_RATE)) {
			CSDL::RenderClear(renderer); /* start */

			for (int i = 0; i < 19; i++) /* just draw everything for now. */
			{
				CSDL::RenderCopy(renderer, imageTexture[i], nullptr, nullptr);
			}

			CSDL::RenderPresent(renderer); /* end */
		//	mTimer->Reset();
		//}
	}
	for (int i = 0; i < 19; i++)
	{
		CSDL::DestroyTexture(imageTexture[i]); /* destroy the textures */
	}
	CSDL::DestroyRenderer(renderer);
	CSDL::DestroyWindow(window);

	CImage::Quit(); /* Quit will also release the singleton */
	CSDL::Quit();
	//Timer::Release();
}
```
