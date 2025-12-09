#include <SDL2/SDL.h>

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface* psurface = 0;
	SDL_Window* pwin = 0;

	const char* wtitle = "sjon";
	int width = 900;
	int height = 600;

	pwin = SDL_CreateWindow(wtitle,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			0);

	psurface = SDL_GetWindowSurface(pwin);

	SDL_FillRect(psurface,
			0,
			SDL_MapRGB(psurface->format, 0, 0, 0));
	
	SDL_UpdateWindowSurface(pwin);
	SDL_Delay(3000);
}
