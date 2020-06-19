void affichage_jeu_ia2(SDL_Surface *ecran,int t[7][7])
{SDL_Surface *table,*yellow,*red;
red=IMG_Load("red dot.png");
yellow=IMG_Load("yellow dot.png");
table=IMG_Load("ia2_tab(1).png");
int i;int j;SDL_Rect pos;
pos.x=0;pos.y=0;
SDL_BlitSurface(table,NULL,ecran,&pos);
for(i=0;i<7;i++)
for(j=0;j<7;j++)
{pos.x=56+j*328;pos.y=i*185;
if(t[i][j]==1) SDL_BlitSurface(yellow,NULL,ecran,&pos);
if(t[i][j]==2) SDL_BlitSurface(red,NULL,ecran,&pos);
}
SDL_Flip(ecran);
SDL_FreeSurface(yellow);
yellow=NULL;
SDL_FreeSurface(red);
red=NULL;
SDL_FreeSurface(table);
table=NULL;
}
************************************
void waiting(SDL_Surface *ecran,int t[7][7],int joueur)
{SDL_Event event;int done=0;int choix=-2,i,j;
while(done==0)
{
while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_KEYDOWN)
                {
			if(event.key.keysym.sym==SDLK_a)
			choix=0;
			if(event.key.keysym.sym==SDLK_z)
			choix=1;
			if(event.key.keysym.sym==SDLK_e)
			choix=2;
			if(event.key.keysym.sym==SDLK_r)
			choix=3;
			if(event.key.keysym.sym==SDLK_t)
			choix=4;
			if(event.key.keysym.sym==SDLK_y)
			choix=5;
                    	if(choix!=-2)if(t[0][choix]==0) {t[0][choix]=joueur;done=1;}
        	}
	}
if(choix==6) choix=0;
if(choix==-1) choix=5;
affichage_jeu_ia2(ecran,t);
}
}
************************************
void ia_2_(int t[7][7])
{int i,j;
for(i=0;i<5;i++)
for(j=0;j<7;j++)
if(t[i+1][j]==0) {t[i+1][j]=t[i][j];t[i][j]=0;}
}
int test_done(int t[7][7])
{int done=0,i,j,cpt_red_dots,cpt_yellow_dots;
for(i=0;i<5;i++)
{cpt_red_dots=0;cpt_yellow_dots=0;
for(j=0;j<5;j++)
{if(t[j][i]==1) {cpt_yellow_dots++;cpt_red_dots=0;}if(t[j][i]==2) {cpt_red_dots++;cpt_yellow_dots=0;}if(cpt_yellow_dots==4)return 2;if(cpt_red_dots==4) return 3;}}
for(i=0;i<5;i++)
for(j=0;j<5;j++)
if(t[i][j]==0) return 1;
return 0;
}
************************************
void ia2_thinking(int t[7][7])
{int i,j,choix[6],choix_sup,r;
for(i=0;i<5;i++) choix[i]=0;
for(i=0;i<5;i++)
for(j=0;j<5;j++)
{if(t[j][i]==1)choix[i]++;if(t[i][j]==2)choix[i]=0;}
choix_sup=choix[0];
for(i=0;i<5;i++)
{if(choix[i]>choix_sup) choix_sup=choix[i];}
do{r=rand()%6;}while(choix[r]!=choix_sup);
if(t[0][r]==0)t[0][r]=2;else {do {r=rand()%6;}while(t[0][r]!=0); t[0][r]=2;}
}
************************************
int  ia_2_joueur_contre_l_ordinateur(SDL_Surface *ecran)
{
ecran = SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE);
int t[7][7];
int i,j;
int done=1;
int joueur=1;
for(i=0;i<7;i++)
for(j=0;j<7;j++)
{
t[i][j]=0;
}
while(done==1)
{
waiting(ecran,t,joueur);
ia_2_(t);
SDL_Delay(200);
affichage_jeu_ia2(ecran,t);
done=test_done(t);
ia2_thinking(t);
ia_2_(t);
done=test_done(t);
affichage_jeu_ia2(ecran,t);
SDL_Delay(200);
}
return done;
}
