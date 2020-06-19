#include<SDL/SDL.h>
#include<SDL/SDL_image.h>

int main() {
	SDL_Surface *screen , *red, *blue, *bg;
	SDL_Event event;
	int running = 1;

	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);  //HWsurface: allocation dans la memoire video

	red = SDL_CreateRGBSurface(0,32,32,32,0,0,0,0); //create an empty sdl_surface
	SDL_FillRect(red,NULL,0xff0000); // giving the rectangle a color

	blue = SDL_CreateRGBSurface(0,32,32,32,0,0,0,0);
	SDL_FillRect(blue,NULL,0xff);

	bg = IMG_Load("map.png");

	SDL_Rect topClip = {0,450,7500,300}; //xywh
	SDL_Rect topPosition = {0,0};

	SDL_Rect bottomClip = {0,450,7500,300};
	SDL_Rect bottomPosition = {0,300};

	SDL_Rect player1 = {400-16-32,300-32};
	SDL_Rect player2 = {400-16+32,600-32};

	SDL_EnableKeyRepeat(10,10);

	while(running) {
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
					running = 0;
			if(event.type == SDL_KEYDOWN) {
				if(event.key.keysym.sym == SDLK_ESCAPE)
						running = 0;
				if(event.key.keysym.sym == SDLK_RIGHT) {
					player1.x += 5;
				}
				if(event.key.keysym.sym == SDLK_LEFT) {
					player1.x -= 5;
				}
				if(event.key.keysym.sym == SDLK_d) {
					player2.x += 5;
				}
				if(event.key.keysym.sym == SDLK_s) {
					player2.x -= 5;
				}
			}
		}

		SDL_BlitSurface(bg,&bottomClip,screen,&bottomPosition);
		SDL_BlitSurface(bg,&topClip,screen,&topPosition);

		SDL_Rect player1Top = {player1.x - topClip.x,300-32};
		SDL_BlitSurface(red,NULL,screen,&player1Top);
		SDL_Rect player1Bottom = {player1.x - bottomClip.x,600-32};
		SDL_BlitSurface(red,NULL,screen,&player1Bottom);

		SDL_Rect player2Top = {player2.x - topClip.x,300-32};
		SDL_BlitSurface(blue,NULL,screen,&player2Top);
		SDL_Rect player2Bottom = {player2.x - bottomClip.x,600-32};
		SDL_BlitSurface(blue,NULL,screen,&player2Bottom);

		topClip.x = player1.x - 384;
		if(topClip.x < 0)
			topClip.x = 0;
		if(topClip.x > 7100)
			topClip.x = 7100;

		bottomClip.x = player2.x - 384;
		if(bottomClip.x < 0)
			bottomClip.x = 0;
		if(bottomClip.x > 7100)
			bottomClip.x = 7100;


		SDL_Flip(screen);
		SDL_Delay(16);
	}

	SDL_Quit();
