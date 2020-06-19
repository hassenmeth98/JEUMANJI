#include"game.h"
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include<time.h>


void initialiser_enemy(enemy* E)
{
    E->position_enemy.x = 0;
    E->position_enemy.y = 0;
    E->image_enemy = IMG_Load("pieuvre.jpeg");//SDL_LoadBMP("fish.bmp");
    SDL_SetColorKey(E->image_enemy, SDL_SRCCOLORKEY, SDL_MapRGB(E->image_enemy->format, 0, 0, 255));
     E->positionmin_enemy.x=0;
  E->positionmax_enemy.x=0;

}






int position_aleatoire(int positionmax,int positionmin)
{
int pos;
 srand(time(NULL));
pos=rand()%(positionmax-positionmin+1)+positionmin;


return pos;
}





void deplacement_aleatoire(enemy E,SDL_Surface *screen)
{
SDL_Event event;

int continuer = 1;
int tempsPrecedent = 0, tempsActuel = 0;

int pos;
static int k=0;
    
char temps[20];


E.positionmax_enemy.x=screen->w / 2 ;//- E.image_enemy->w / 2;

pos=position_aleatoire(E.positionmax_enemy.x,E.positionmin_enemy.x);



    SDL_EnableKeyRepeat(10, 10);

    while (continuer)
    {
        SDL_PollEvent(&event); /* On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme */
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        tempsActuel = SDL_GetTicks();



        if (tempsActuel - tempsPrecedent > 30) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
        {
           
               if(k==0)

                   {
                     if(E.position_enemy.x<pos)/*positionmax)*/
                          {
                            E.position_enemy.x++;

                          }
                     else k=1;

                   }
              if(k==1)
                  {
                    if(E.position_enemy.x>E.positionmin_enemy.x)
                            E.position_enemy.x--;
                    else
                         k=0;
                  }             
                                    /* On bouge l'ennemi */
            tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
        }




        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(E.image_enemy, NULL, screen, &E.position_enemy);
        SDL_Flip(screen);
    }

   
   

}
