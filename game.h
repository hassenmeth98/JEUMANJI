#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>



typedef struct
{

SDL_Rect  position_enemy;
SDL_Surface * image_enemy;
SDL_Rect positionmax_enemy;
SDL_Rect positionmin_enemy;


}enemy;



void initialiser_enemy(enemy *E);
int position_aleatoire(int positionmax_enemy,int positionmin_enemy);
void deplacement_aleatoire(enemy  E,SDL_Surface*screen);



















































#endif /* FONCTIONS_H_ */
