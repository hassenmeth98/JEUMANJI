#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "deplacement.h"
void animate(SDL_Surface *screen ,  SDL_Surface *Background ,SDL_Surface *image2, SDL_Rect *positionFond  , int *running)
{

SDL_Rect rect ;
rect.x=0;
rect.y=535;
rect.h=117 ; 
rect.w=78 ; 
int left,right,up;
 SDL_BlitSurface(Background ,positionFond,screen,NULL);
SDL_Flip(screen) ; 


//setrects(rects,78,117,5); 
SDL_EnableKeyRepeat(1,1) ; 
while(*running)
{
                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = 0;

                                        break;


     case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {
      case SDLK_ESCAPE : 
running=0 ;  
break ; 
case SDLK_RIGHT :

right=1;
left=0;
 rect.x+=10; 
  /*if ((rect.x>=640)&&(rect.x<=1280))
{
 positionFond->x+=640;
rect.x=0;
}
else if(positionFond->x==5120)
rect.x+=10;*/
scrollingright(&rect , positionFond );
SDL_BlitSurface(Background,positionFond,screen,NULL); 
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ;  
break ;
case SDLK_LEFT : 
 rect.x-=10 ; 
left=1;
right=0;
/*if ( rect.x==0)
{
 positionFond->x-=640;
rect.x=640-rect.x ; 

}
else if(positionFond->x==640 ) 
rect.x-= 10;*/
 


 scrollingleft(&rect ,positionFond );
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 

    
break ;
 case SDLK_SPACE:
if(right==1)
{
while((rect.y>400)&&(up==0))
{
rect.x+=40;
rect.y-=30;
 scrollingright(&rect , positionFond );
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
if(rect.y<=400)
{
up=1;
rect.x+=40;
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
while((rect.y<535)&&(up==1))
{
rect.y+=30;
rect.x+=40;
scrollingright(&rect , positionFond );
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
if(rect.y==535)
{
up=0;
}
}
else if(left==1) 
{
while((rect.y>400)&&(up==0))
{
rect.x-=40;
rect.y-=30;
scrollingleft(&rect ,positionFond );
 
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
if(rect.y<=400)
{
up=1;
rect.x-=40;
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
while((rect.y<535)&&(up==1))
{
rect.y+=30;
rect.x-=40;
scrollingleft(&rect ,positionFond );
 
SDL_BlitSurface(Background,positionFond,screen,NULL);
SDL_BlitSurface(image2,NULL, screen, &rect);
SDL_Flip(screen) ; 
}
if(rect.y==535)
{
up=0;
}
}

}
}
}
}
}

