#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "deplacement.h"



void scrollingright(SDL_Rect *rect , SDL_Rect *positionFond )
     {

  

  if ((( rect->x>=640 )||(rect->x>=1280))&&(positionFond->x<3840))
{
 positionFond->x+=640;
rect->x=0 ; 

}

}
void scrollingleft(SDL_Rect *rect , SDL_Rect *positionFond )
     {

  

if ( rect->x==0)
{
 positionFond->x-=640;
rect->x=640-rect->x ; 

}

}
