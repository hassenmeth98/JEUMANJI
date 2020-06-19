
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



typedef struct{

SDL_Surface *score;
SDL_Rect pos_score;

}score;

typedef struct{

SDL_Surface *vie[10];
SDL_Rect pos_vie;
}vie;



typedef struct{
SDL_Surface  *perso[20];
SDL_Rect pos;
vie vie;
score score;
int direction;
}personnage;


void initialiser_joueur(personnage *joueur);
void afficher_joueur(personnage joueur);
int animation_perso(int i);


