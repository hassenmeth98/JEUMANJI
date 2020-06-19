#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>

struct enemie
{
SDL_Surface *a[8];
int vie;
};
typedef struct enemie enemie;
struct hero
{
SDL_Surface *a;
int vie;
SDL_Surface *v[4];
int nbv;
};
typedef struct hero hero;
void Blit(SDL_Surface* source,SDL_Surface* dest,int x,int y);
void stage0(SDL_Surface *ecran,int *continuer,Mix_Music *intro,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Chunk *sonspell);
void stage1(SDL_Surface *ecran,int *continuer,Mix_Music *intro,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit);
