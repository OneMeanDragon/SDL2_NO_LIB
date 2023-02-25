# SDL2_NO_LIB
SDL2 Singleton Class, to remove the the need to include the ".LIB" files.

## Example
```cpp
	CSDL::SDLInit(SDL_INIT_VIDEO);
	if (!(CSDL::ImageInit(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		printf("IMG Initialization Error: %s\n", CSDL::ImageGetError());
		return;
	}

	SDL_Window* window = CSDL::CreateHWindow("PNG Image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 536, 285, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = CSDL::CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	CSDL::SetRenderDrawColor(renderer, 0x5, 0x5, 0x5, 0xFF); /* dark grey */

	SDL_Surface* imageSurface = CSDL::ImageLoad("images\\background.png");
	SDL_Texture* imageTexture = CSDL::CreateTextureFromSurface(renderer, imageSurface);

	CSDL::FreeSurface(imageSurface);

	SDL_Event event;
	bool running = true;
	while (running) {
		while (CSDL::PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		CSDL::RenderClear(renderer);
		CSDL::RenderCopy(renderer, imageTexture, nullptr, nullptr);
		CSDL::RenderPresent(renderer);
	}

	CSDL::DestroyTexture(imageTexture);
	CSDL::DestroyRenderer(renderer);
	CSDL::DestroyWindow(window);

	CSDL::ImageQuit();
	CSDL::SDLQuit();
	CSDL::Release(); /* release the sdl singleton from memory */
```
