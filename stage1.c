#include "stage1.h"


#include "fonction.h"

#define speed  6

void Blit(SDL_Surface* source,SDL_Surface* dest,int x,int y)
{
    SDL_Rect R;
    R.x = x;
    R.y = y;
    SDL_BlitSurface(source,NULL,dest,&R);
}


//stage1
void stage1(SDL_Surface *ecran,int *continuer,Mix_Music *intro,Mix_Chunk *effet,Mix_Chunk *effet2,Mix_Music *musique,int *mute,SDL_Rect *posvolb,Mix_Chunk *sonspell,Mix_Chunk *dying,Mix_Chunk *hit)
{
	SDL_Surface *health=NULL,*scoreS=NULL,*portal=NULL,*paragstage1=NULL,*magicien=NULL,*noir=NULL,*gameover=NULL,*attackr=NULL,*attackl=NULL,*hurt=NULL,*rock1=NULL,*rock2=NULL,*spell=NULL,*vie=NULL, *trap1=NULL,*background=NULL,*herod=NULL,*herog=NULL,*heroactu=NULL,*hpup=NULL,*police=NULL,*enemie=NULL,*enemied=NULL,*enemieg=NULL,*enemie1=NULL,*enemied1=NULL,*enemieg1=NULL,*score=NULL,*scoreint=NULL,
	*idlel=NULL,*idler=NULL,*terre1=NULL,*terre2=NULL,*terre3=NULL,*jumpr=NULL,*jumpl=NULL,*surfacesecondes=NULL,*surfaceminutes=NULL
	,*imgtime=NULL,*enigmestage1=NULL;
	SDL_Rect posback,poshero,posmagicien,posmagicienactu,posspell,framed[8],frame2[8],pospolice,posportal,posgo,pose1,posscoreS,pose2,pose3,pose4,pose5,pose6,pose7,posenemie1,posenemie2,posenemie3,posenemie4,posenemie5,posenemie6,posenemie7,poshp,posrock1,posvie,posscore,poshpup,posminutes,possecondes,posnoir,
	posscoreint,postrap1,posterre1,posterre2,posterre3,posterre4,posterre5,posterre6,posterre7,posterre8,posterre9,postime,posenigme1,posparagstage1;
	int boucle=1,i=0,jump=0,d1=6,e1=0,compteur1=0,hp=4,k=-1,hert=-1,posans,nbrspell=0,intspell=0,hite1,cmpsc=0,posactu,compteurmage=0;
	int CAR1=0,CAR2=0,CAR3=0,CAR4=0,CAR5=0,CAR6=0,CAR7=0,CAR8=0,CAR9=0,CAR10=0;
	int tempsPrecedent = 0, tempsActuel = 0,tsec=59,tmin=2,theur=0;
	int y=0;
	int x=0;
	int j=0;
	int camera=0,menu=0;
	int e=1;
	int coll=0;
	int enig=0;
	int souri,mouvemmentsouri=0,scorefinal=0;
	int sauvegarde=1;
	SDL_Event event;
	Uint8 *keystates = SDL_GetKeyState( NULL );
	TTF_Font *fonts = NULL;
	SDL_TimerID timer;
	fonts = TTF_OpenFont("fonts/Takota.ttf", 60);
	SDL_Color couleur ={235,144,234};
	SDL_Color couleur1 ={145,0,0};
	char scr[4];
	char chhp[0];
	char secondes[2];
	char minutes[2];
	Mix_Music *stage1;
	
	stage1 = Mix_LoadMUS("music/stage1.mp3");
	Mix_PlayMusic(stage1, -1);
	posparagstage1.y=770;
	posparagstage1.x=0;
	
	posgo.x=ecran->w/2-150;	
	posgo.y=ecran->h/2;

	poshp.x=30;
	poshp.y=30;

	posvie.x=125;
	posvie.y=25;
	
	posscore.x=190;
	posscore.y=30;
	postime.x=350;
	postime.y=30;
	
	posminutes.x=450;
	posminutes.y=25;
	possecondes.x=500;
	possecondes.y=25;
	
	posscoreint.x=270;
	posscoreint.y=25;
	
	
	postrap1.x=2800;
	postrap1.y=650;
	postrap1.h=91;
	postrap1.w=53;
	



poshero.x=0;
	poshero.y=460;
	poshero.w=20;
	poshero.h=20;


	posback.x=0;
	posback.y=0;
	SDL_Init(SDL_INIT_TIMER);
	//charger tous
	
	trap1=IMG_Load ("image/decoration/trap1.png");
	score=IMG_Load ("image/decoration/score.png");
	health=IMG_Load("image/health/heart.png");
	
	vie= TTF_RenderText_Blended(fonts, "4", couleur);
	imgtime=IMG_Load ("image/decoration/time.png");
	
	hurt=IMG_Load ("image/perso/hert.png");
	idler=IMG_Load ("image/perso/idlers.png");
	idlel=IMG_Load ("image/perso/idlels.png");
	
	background=IMG_Load ("image/stage/map1.png");
	herod=IMG_Load ("image/perso/wr.png");
	herog=IMG_Load ("image/perso/wl.png");
	
	portal=SDL_LoadBMP ("image/decoration/tabscore.bmp");
	SDL_BlitSurface(background, NULL, ecran, &posback);
	SDL_BlitSurface(health, NULL, ecran, &poshp);
	SDL_BlitSurface(vie, NULL, ecran, &posvie);
	SDL_BlitSurface(score, NULL, ecran, &posscore);
	SDL_BlitSurface(scoreint, NULL, ecran, &posscoreint);
	SDL_BlitSurface(imgtime, NULL, ecran, &postime);
	SDL_BlitSurface(trap1, NULL, ecran, &postrap1);

	for (i=0; i<8;i++)
	{
		if (j==4)
		{
			x=0;
			y=y+250;
			j=0;
		}
		framed[ i ].x=x;
		framed[ i ].y=y;
    		framed[ i ].w =140;
    		framed[ i ].h = 250;
    		x=x+140;
    		j++;
	}
	x=0;
	y=0;
	j=0;
	for (i=0; i<8;i++)
	{
		if (j==4)
		{
			x=0;
			y=y+250;
			j=0;
		}
		frame2[ i ].x=x;
		frame2[ i ].y=y;
    		frame2[ i ].w =250;
    		frame2[ i ].h = 250;
    		x=x+250;
    		j++;
	}
x=0;
	y=0;
    	i=0;
    	heroactu=herod;
	SDL_BlitSurface(herod, &framed[i], ecran, &poshero);
	SDL_Flip(ecran);
	SDL_EnableKeyRepeat(10,70);
	while ((boucle)&&((*continuer)))
    	{

//gestion de temp et score
    	keystates = SDL_GetKeyState(NULL);
    	sprintf(secondes, "%d",tsec);
    	surfacesecondes= TTF_RenderUTF8_Solid(fonts, secondes, couleur);
    	sprintf(minutes, "%d",tmin);
    	strcat(minutes,":");
    	surfaceminutes=  TTF_RenderUTF8_Solid(fonts, minutes, couleur);
    	sprintf(chhp, "%d",hp);
        vie= TTF_RenderText_Blended(fonts,chhp, couleur);
        sprintf(scr,"%d",cmpsc);
        scoreint=TTF_RenderText_Blended(fonts,scr, couleur);
        	while (SDL_PollEvent(&event))
       		switch(event.type)
        	{
       			case SDL_QUIT:
            		(*continuer) = 0;
            		break;
            		case SDL_VIDEORESIZE:
				ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE);
    				break;
            		case SDL_KEYDOWN:
            		switch (event.key.keysym.sym)
            		{	
				case SDLK_TAB:
				//option(ecran,effet,effet2,musique,mute,continuer,posvolb);
				break;
            		}
            		break;
            		case SDL_MOUSEBUTTONDOWN:
            		//souri
		
			break;
		}
                       


		if(keystates[SDLK_d])//right
		{
			        e=1;
            			animation(&heroactu,herod,&i);
            			if (coll==0)
            			{
            			
scrolling(&poshero.x,&posback.x,&pospolice.x,&postrap1.x,&camera,&ecran,&heroactu,e);
            		


}
            			else
            			{
				//	camera+=speed;
            				poshero.x+=speed;
            			}
					
		}
		if(keystates[SDLK_q])//left
		{
            			e=2;        			
            			animation(&heroactu,herog,&i);
            			if (coll==0)
            			{
            			scrolling(&poshero.x,&posback.x,&pospolice.x,&postrap1.x,&camera,&ecran,&heroactu,e);            			
}
            			else
            			{
            			       // camera-=speed;
            				poshero.x-=speed;
            			}
		
		}
		
		//time
		if (!(tmin==0&&tsec==0))
		{
			tempsActuel = SDL_GetTicks();
			int dt=tempsActuel-tempsPrecedent;
			if(dt>=1000)
			{
				tsec--;
				tempsPrecedent=tempsActuel;
			}
			if(tsec==0 && tmin!=0)
			{
				tmin--;
				tsec=59;
			}
			if (menu==1)
			{
				boucle=0;
			}
		}
		else
		{
			tmin=0;
			tsec=0;
		}
		
		k=-1;
		
				 
			//collision avec trap1
		if(collision(poshero,postrap1)==1&&e==1)
		{
		     mouvemmentsouri=0;
		     coll=1;
		     poshero.x-=100;
		     camera-=100;
		     if(cmpsc>0)
		     cmpsc-=5;
		     if(hp!=0)
		     hp--;



		}
		if(collision(poshero,postrap1)==1&&e==2)
		{
		     mouvemmentsouri=0;
		     coll=1;
		     poshero.x+=100;
		     camera+=100;
		     if(cmpsc>0)
		     cmpsc-=5;
		     if(hp!=0)
		     hp--;
		}
		
		//hpup
		

		
		//dying
			if (hp==0)
            		{
            		Mix_PlayChannel( -1, dying, 0 ) ;
            			heroactu=hurt;
            			for (j=0; j<43; j++)
            			{
            			        Blit(noir,ecran,posnoir.x,posnoir.y);
            				
		                        Blit(trap1,ecran,postrap1.x,postrap1.y);
		              
       		                       
       		                        SDL_BlitSurface(vie, NULL, ecran, &posvie);
       		                        SDL_BlitSurface(imgtime, NULL, ecran, &postime);	
		                        SDL_BlitSurface(health, NULL, ecran, &poshp);
		                        SDL_BlitSurface(score, NULL, ecran, &posscore);	
		                        SDL_BlitSurface(scoreint, NULL, ecran, &posscoreint);		
   	    	                        SDL_Flip(ecran);
            			}
            			gameover=TTF_RenderText_Blended(fonts, "GAME OVER", couleur1);
            			Blit(noir,ecran,posnoir.x,posnoir.y);
            			SDL_BlitSurface(heroactu, &frame2[7], ecran, &poshero);
 				Blit(gameover,ecran,posgo.x,posgo.y);
 				SDL_Flip(ecran);
 				SDL_Delay(4000);
 				boucle=0;
            			
            		}



			
        	//SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
       		Blit(background,ecran,posback.x,posback.y);
       		
		//affichages 
		
		Blit(trap1,ecran,postrap1.x,postrap1.y);
		
       		SDL_BlitSurface(heroactu, &framed[i/4], ecran, &poshero);
       		SDL_BlitSurface(vie, NULL, ecran, &posvie);
       		SDL_BlitSurface(imgtime, NULL, ecran, &postime);	
		SDL_BlitSurface(health, NULL, ecran, &poshp);
		SDL_BlitSurface(score, NULL, ecran, &posscore);	
		SDL_BlitSurface(scoreint, NULL, ecran, &posscoreint);
		SDL_BlitSurface(surfacesecondes, NULL, ecran, &possecondes);
	        SDL_BlitSurface(surfaceminutes, NULL, ecran, &posminutes);		
   	    	SDL_Flip(ecran);
    	}
       
    	SDL_FreeSurface(background);
}
