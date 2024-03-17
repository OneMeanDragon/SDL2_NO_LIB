# SDL2NoLibs
SDL2 Singleton Class's, to remove the the need to include the ".LIB" files.

# Includes 
if your looking for a specific function add it
 - Functionality needed to run with:
   - Currently what I actually use from the SDL2 dlls.
   - [SDLUI](https://github.com/immortalx74/SDLUI)

## Info
You must still follow the SDL rules, Each of the classes need to be initalized in the same thread.
Also be sure your using the latest SDL2 DLL's (older dlls had problems, mainly the sdl mixer dll).

### _"SDL2, Image, TTF, and Mixer"_ - Just include what you need.
  - See defines in "SDL2/SDL2Inc.h"

#### _Example_ (Reminder: this example is running at unlocked fps, you may want to init with VSYNC)
```cpp
#define INCLUDE_SDL2
#define INCLUDE_SDL_IMAGE
#include <iostream>

#include "SDL2/SDL2Inc.h"

int main() {

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
		while (CSDL::PollEvent(&event)) { /* Events */
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		CSDL::RenderClear(renderer); /* Start */

		for (int i = 0; i < 19; i++) { /* just draw everything for now. */
			CSDL::RenderCopy(renderer, imageTexture[i], nullptr, nullptr);
		}

		CSDL::RenderPresent(renderer); /* End */
	}

	for (int i = 0; i < 19; i++)
	{
		CSDL::DestroyTexture(imageTexture[i]); /* destroy the textures */
	}

	CSDL::DestroyRenderer(renderer);
	CSDL::DestroyWindow(window);

	CImage::Quit(); /* Quit will also release the singleton */
	CSDL::Quit();
}
```
