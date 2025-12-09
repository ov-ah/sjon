#include <stdio.h>

#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	if(argc < 1)
	{
		printf("incorrect usage.");
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		const char *filename = argv[i];
		FILE *file = fopen(filename, "rb");

		if(!file)
		{
			printf("error reading file");
			return 0;
		}

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

		SDL_Rect pixel;
		pixel.x = 0;
		pixel.y = 0;
		pixel.w = 1;
		pixel.h = 1;
		for(int x=0; x < width; x++)
		{
			pixel.x = x;
			for(int y=0; y < height; y++)
			{
				pixel.y = y;
				SDL_FillRect(
					psurface,
					&pixel,
					SDL_MapRGB(psurface->format, 255, 0, 0));
					
			}
		}

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
}
