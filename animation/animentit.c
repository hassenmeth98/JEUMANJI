#include <stdio.h> 
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct {
    SDL_Surface* img[3];
    Mix_Music* m;
    int valeur; 
}faracha;

void init_fly(faracha* c)
{
    c->img[0] = SDL_LoadBMP("fly1.bmp");
    c->img[1] = SDL_LoadBMP("fly2.bmp");
    c->img[2] = SDL_LoadBMP("fly3.bmp");
    // c->img[3] = IMG_LoadBMP("4.png");
    c->valeur=10;
}
void main(){
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
int i=0 ;
faracha c;
SDL_Rect pos; 
pos.x=0;
pos.y=0;
SDL_Surface* bg; 
bg=SDL_SetVideoMode(300,300,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
init_fly(&c);

while(1){
SDL_Delay(80);
SDL_BlitSurface(c.img[i%4],NULL,bg,&pos); SDL_Flip(bg);
i++;
}
SDL_Quit();
}


