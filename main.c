#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fonction.h"


int main(){

char pause;
int  continuer =1;
int i=0;
SDL_Surface  * screen =NULL;

SDL_Event event;
SDL_TimerID timer;

personnage joueur;

SDL_Init(SDL_INIT_VIDEO);
 
 screen= SDL_SetVideoMode(800, 640, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("animation", NULL);

  
initialiser_joueur(&joueur);


i=0;

while(continuer){

SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 145, 255));
SDL_SetColorKey(joueur.perso[i], SDL_SRCCOLORKEY, SDL_MapRGB(joueur.perso[i]->format, 0, 0, 255)); 
SDL_BlitSurface(joueur.perso[i], NULL, screen, &joueur.pos) ;
SDL_BlitSurface(joueur.vie.vie[9], NULL, screen, &joueur.vie.pos_vie) ;
SDL_BlitSurface(joueur.score.score, NULL, screen, &joueur.score.pos_score) ;


i = animation_perso(i);
  SDL_Flip(screen); 
}



for(i=0;i<3;i++){
SDL_FreeSurface(joueur.perso[i]);
}

SDL_FreeSurface(joueur.vie.vie[9]);

pause =getchar();

return 0;
}
