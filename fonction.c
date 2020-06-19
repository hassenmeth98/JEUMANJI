#include"fonction.h"
void initialiser_joueur(personnage *joueur)
{

    
    int i;
   

	joueur->perso[0] = IMG_Load("marche.1.png");
        joueur->perso[1] = IMG_Load("marche.2.png");
        joueur->perso[2] = IMG_Load("marche.3.png");
        joueur->perso[3] = IMG_Load("marche.4.png");
        
char vieName[80];
for (i=0; i<10; i++)
    {
        sprintf(vieName ,"vie.%d.png",i);
        joueur->vie.vie[i] = IMG_Load(vieName);
    }

    joueur->pos.x = 100;
    joueur->pos.y = 400;

    joueur->vie.pos_vie.x = 550;
    joueur->vie.pos_vie.y = 40;
    joueur->score.pos_score.x=40;
    joueur->score.pos_score.y=40;
    joueur->score.score=IMG_Load("score.png"); 
   

    
}
	
void affichage(personnage joueur){
SDL_Surface * screen;
int i;
 
    
    SDL_SetColorKey(joueur.perso[i], SDL_SRCCOLORKEY, SDL_MapRGB(joueur.perso[i]->format, 0, 0, 255));
    SDL_BlitSurface(joueur.perso[i], NULL, screen, &joueur.pos) ;


}
int animation_perso(int i){
if(i==2){
i=0;
}
else{
i++;
}
return i;
}

