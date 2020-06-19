#include <stdio.h> 
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>


typedef struct {
    SDL_Surface* img[3];
    Mix_Music* m;
    int valeur; 
}faracha;

