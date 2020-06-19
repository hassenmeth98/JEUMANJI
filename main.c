#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "deplacement.h"

int main()
{
SDL_Surface *screen=NULL;
SDL_Surface *image=NULL;
SDL_Surface *image1=NULL;
SDL_Rect positionFond;
int running=1;
SDL_Init(SDL_INIT_VIDEO);
positionFond.x=0;
positionFond.y=0;
positionFond.w=1920 ;
positionFond.h=1080 ; 
    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chargement Backgroung", NULL);  
image = IMG_Load("Mario_Run.png");
image1 = IMG_Load("map.png");


animate(screen ,  image1 , image,  &positionFond  , &running);
SDL_FreeSurface(image);
SDL_FreeSurface(image1);
 SDL_Quit();

    return EXIT_SUCCESS;
}
