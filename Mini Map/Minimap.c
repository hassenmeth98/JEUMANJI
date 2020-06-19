#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>

int main()
{
SDL_Surface *screen=NULL;
SDL_Surface *joueur=NULL;
SDL_Surface *image1=NULL;
int done=0;
SDL_Surface *mario=NULL;
SDL_Surface *image3=NULL;
SDL_Event event;
SDL_Surface *image2=NULL;
SDL_Rect rect2;
SDL_Rect rect,positionFond;
rect.x=190;
rect.y=300;
rect2.x=0;
rect2.y=0;
SDL_Init(SDL_INIT_VIDEO);
positionFond.x=0;
positionFond.y=0;
positionFond.w=1920 ;
positionFond.h=1080 ; 
    screen = SDL_SetVideoMode(1280,720, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chargement Mini Map", NULL);  
mario = IMG_Load("2.png");
image1 = IMG_Load("map.png");
image2 = IMG_Load("minimap.png");
image3 = IMG_Load("minirajel.png");



while  ( done==0 )  { 
         while  (SDL_PollEvent ( &event ))  { 
             switch  ( event.type )  { 
             case  SDL_QUIT : 
                 done  =  1 ; 
                 break ;  
                 
             case SDL_KEYDOWN : 
                     switch( event.key.keysym.sym )
                        {
							case SDLK_RIGHT : 

  rect.x+=10; 
rect2.x+=1; 
 
 

SDL_BlitSurface(image1,NULL,screen,NULL);
SDL_BlitSurface(mario,NULL,screen,&rect);   
SDL_BlitSurface(image2,NULL, screen, NULL);
SDL_BlitSurface(image3,NULL,screen,&rect2);
SDL_Flip(screen) ; 
							break ; 
							case SDLK_LEFT : 
rect.x-=10 ; 
 rect2.x-=1 ; 

SDL_BlitSurface(image1,NULL,screen,NULL); 
SDL_BlitSurface(joueur,NULL,screen,&rect); 
SDL_BlitSurface(image2,NULL, screen, NULL);
SDL_BlitSurface(image3,NULL,screen,&rect2);
SDL_Flip(screen) ; 

							break ; 

}
}
}

}

 SDL_Quit();

return 0 ; 
}
