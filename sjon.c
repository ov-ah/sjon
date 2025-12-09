#include <SDL2/SDL.h>

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface* psurface = nullptr;
	SDL_Window* pwin = nullptr;

	int width = 900;
	int height = 600;

	pwin = SDL_CreateWindow(
			"sjon",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			0);

	psurface = SDL_GetWindowSurface(pwin);

	SDL_FillRect(
			psurface,
			nullptr,
			SDL_MapRGB(psurface->format, 0, 0, 0));
	
	SDL_UpdateWindowSurface(pwin);

	bool running = 1;
	while(running)
	{
		SDL_Event e;
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
				running = 0;
		}
		SDL_Delay(16);
	}

	SDL_DestroyWindow(pwin);
	SDL_Quit();
}
