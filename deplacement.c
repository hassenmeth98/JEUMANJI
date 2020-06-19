#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "deplacement.h"
void deplacement(SDL_Surface *ecran,SDL_Surface *image ,int continuer,SDL_Rect position)
{


    SDL_Event event;

        SDL_WaitEvent(&event);
         
        switch(event.type)
        {
 case SDL_QUIT:
         continuer = 0;
         break;

         case SDL_MOUSEBUTTONUP:
             if(event.button.button==SDL_BUTTON_LEFT)
              {
              position.x = event.button.x-513;
             position.y = event.button.y-400;
SDL_BlitSurface(image,NULL,ecran,&position);
              }
              else if (event.button.button==SDL_BUTTON_RIGHT)
              continuer=0;

              break ;
         case SDL_ACTIVEEVENT :/*gestion de fenetre*/
                   if ((event.active.state & SDL_APPMOUSEFOCUS) == SDL_APPMOUSEFOCUS)/*tester l eat de la souris */
{
      if (event.active.gain == 0)  /*la souris est sorti de la fenetre*/
        {
         position.x ++ ;
         position.y++ ;
SDL_BlitSurface(image,NULL,ecran,&position);
        }
      else if (event.active.gain == 1)  /*la souris est dans la fenetre*/
        {
                   position.x ++ ;
         position.y++ ;
SDL_BlitSurface(image,NULL,ecran,&position);

            break ;
        }

}

SDL_BlitSurface(image,NULL,ecran,&position);
}

}


    
   

