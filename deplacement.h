#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <SDL/SDL.h>
void scrollingleft(SDL_Rect *rect , SDL_Rect *positionFond );
void scrollingright(SDL_Rect *rect , SDL_Rect *positionFond );
void animate(SDL_Surface *screen ,  SDL_Surface *Background ,SDL_Surface *image2, SDL_Rect *positionFond  , int *running);
#endif // JEU_H_INCLUDED
