#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

#define NXMAP      45     // Nombre de tuiles en largeur sur le terrain
#define NYMAP      35     // Nombre de tuiles en longueur








void poserBat(int niveau, FILE* niveau0, FILE* newFile)
{
    int Mterrain[NXMAP][NYMAP] = {{0}};
    int type, coordx,coordy, compteurBat = 0, choix=0 ;
    int route=0,xroute,yroute;
    int couleur;
    BITMAP* page;
    BITMAP* fond1;
    BITMAP* fond2;
    page=create_bitmap(SCREEN_W,SCREEN_H);
    fond1 = load_bitmap("fond1.bmp",NULL);
    if (!fond1)
    {
        allegro_message("pas pu trouver fond1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    fond2 = load_bitmap("fond2.bmp",NULL);
    if (!fond2)
    {
        allegro_message("pas pu trouver fond2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    while(!key[KEY_ESC])
    {
        blit(fond1,page,0,0,0,0,SCREEN_W,SCREEN_H);
        if (compteurBat != 0)
        {
            rewind(niveau0);
            for (int i =0 ; i<compteurBat; i++)
            {
                fscanf(niveau0,"%d %d %d",&type,&coordx,&coordy);
                if (type == 1)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(0,255,255));
                }
                if (type == 2)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(255,255,0));
                }
                if (type == 3)
                {
                    rectfill(page,coordx,coordy,coordx+60,coordy+60,makecol(0,0,255));
                }
                if (type == 4)
                {
                    rectfill(page,coordx,coordy,coordx+20,coordy+20,makecol(127,127,127));
                }
            }
        }
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        if (key[KEY_S])
        {
            choix=5;
        }
        while (choix==5)
        {
            clear_bitmap(page);
            blit(fond2,page,0,0,0,0,SCREEN_W,SCREEN_H);
            rewind(niveau0);
            for (int i =0 ; i<compteurBat; i++)
            {
                fscanf(niveau0,"%d %d %d",&type,&coordx,&coordy);
                if (type == 1)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(0,255,255));
                }
                if (type == 2)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(255,255,0));
                }
                if (type == 3)
                {
                    rectfill(page,coordx,coordy,coordx+60,coordy+60,makecol(0,0,255));
                }
                if (type == 4)
                {
                    rectfill(page,coordx,coordy,coordx+20,coordy+20,makecol(127,127,127));
                }
            }
            rectfill(page,mouse_x/20*20,mouse_y/20*20,mouse_x/20*20+20,mouse_y/20*20+20,makecol(255,255,255));
            if (mouse_b&1)
            {
                supprimer(Mterrain,niveau0,newFile,mouse_x/20,mouse_y/20,compteurBat);
                choix=0;
            }
             blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        if (key[KEY_U])
        {
            choix = 2;
        }
        while (choix == 2)
        {
            clear_bitmap(page);
            blit(fond2,page,0,0,0,0,SCREEN_W,SCREEN_H);
            rewind(niveau0);
            rectfill(page,(mouse_x-60)/20*20,(mouse_y-40)/20*20,(mouse_x+60)/20*20,(mouse_y+40)/20*20,makecol(255,255,0));
            for (int i =0 ; i<compteurBat; i++)
            {
                fscanf(niveau0,"%d %d %d",&type,&coordx,&coordy);
                if (type == 1)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(0,255,255));
                }
                if (type == 2)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(255,255,0));
                }
                if (type == 3)
                {
                    rectfill(page,coordx,coordy,coordx+60,coordy+60,makecol(0,0,255));
                }
                if (type == 4)
                {
                    rectfill(page,coordx,coordy,coordx+20,coordy+20,makecol(127,127,127));
                }
            }
            for (int t = 0 ; t<6; t++)
            {
                for (int j = 0; j<4; j++)
                {
                    if (Mterrain[(mouse_x-60)/20+t][(mouse_y-40)/20+j]==1)
                        rectfill(page,(mouse_x-60)/20*20,(mouse_y-40)/20*20,(mouse_x+60)/20*20,(mouse_y+40)/20*20,makecol(255,0,0));
                }
            }
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            couleur=getpixel(page,mouse_x,mouse_y);
            if (mouse_b & 1 && couleur !=makecol(255,0,0))
            {
                rectfill(page,(mouse_x-60)/20*20,(mouse_y-40)/20*20,(mouse_x+60)/20*20,(mouse_y+40)/20*20,makecol(255,255,0));
                fprintf(niveau0,"\n%d %d %d",choix,(mouse_x-60)/20*20,(mouse_y-40)/20*20);
                compteurBat++;
                for (int t= 0; t<6; t++)
                {
                    for (int j =0 ; j<4; j++)
                    {
                        Mterrain[(mouse_x-60)/20+t][(mouse_y-40)/20+j]=1;
                    }
                }
                choix=0;
            }
            if (mouse_b & 2)
                choix=0;
        }
        if (key[KEY_C])
        {
            choix = 1;
        }
        while (choix == 1)
        {
            clear_bitmap(page);
            blit(fond2,page,0,0,0,0,SCREEN_W,SCREEN_H);
            rewind(niveau0);
            rectfill(page,(mouse_x-60)/20*20,(mouse_y-40)/20*20,(mouse_x+60)/20*20,(mouse_y+40)/20*20,makecol(0,255,255));
            for (int i =0 ; i<compteurBat; i++)
            {
                fscanf(niveau0,"%d %d %d",&type,&coordx,&coordy);
                if (type == 1)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(0,255,255));
                }
                if (type == 2)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(255,255,0));
                }
                if (type == 3)
                {
                    rectfill(page,coordx,coordy,coordx+60,coordy+60,makecol(0,0,255));
                }
                if (type == 4)
                {
                    rectfill(page,coordx,coordy,coordx+20,coordy+20,makecol(127,127,127));
                }
            }
            for (int t = 0 ; t<6; t++)
            {
                for (int j = 0; j<4; j++)
                {
                    if (Mterrain[(mouse_x-60)/20+t][(mouse_y-40)/20+j]==1)
                        rectfill(page,(mouse_x-60)/20*20,(mouse_y-40)/20*20,(mouse_x+60)/20*20,(mouse_y+40)/20*20,makecol(255,0,0));
                }
            }
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            couleur=getpixel(page,mouse_x,mouse_y);
            if (mouse_b & 1 && couleur !=makecol(255,0,0))
            {
                rectfill(page,(mouse_x-60)/20*20,(mouse_y-40)/20*20,(mouse_x+60)/20*20,(mouse_y+40)/20*20,makecol(0,255,255));
                fprintf(niveau0,"\n%d %d %d",choix,(mouse_x-60)/20*20,(mouse_y-40)/20*20);
                compteurBat++;
                for (int t= 0; t<6; t++)
                {
                    for (int j =0 ; j<4; j++)
                    {
                        Mterrain[(mouse_x-60)/20+t][(mouse_y-40)/20+j]=1;
                    }
                }
                choix=0;
            }
            if (mouse_b & 2)
                choix=0;
        }
        if (key[KEY_SPACE])
        {
            choix=3;
        }
        while (choix == 3)
        {
            clear_bitmap(page);
            blit(fond2,page,0,0,0,0,SCREEN_W,SCREEN_H);
            rewind(niveau0);
            rectfill(page,(mouse_x-30)/20*20,(mouse_y-30)/20*20,(mouse_x+30)/20*20,(mouse_y+30)/20*20,makecol(0,0,255));
            for (int i =0 ; i<compteurBat; i++)
            {
                fscanf(niveau0,"%d %d %d",&type,&coordx,&coordy);
                if (type == 1)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(0,255,255));
                }
                if (type == 2)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(255,255,0));
                }
                if (type == 3)
                {
                    rectfill(page,coordx,coordy,coordx+60,coordy+60,makecol(0,0,255));
                }
                if (type == 4)
                {
                    rectfill(page,coordx,coordy,coordx+20,coordy+20,makecol(127,127,127));
                }
            }
            for (int t = 0 ; t<3; t++)
            {
                for (int j = 0; j<3; j++)
                {
                    if (Mterrain[(mouse_x-30)/20+j][(mouse_y-30)/20+t]==1)
                        rectfill(page,(mouse_x-30)/20*20,(mouse_y-30)/20*20,(mouse_x+30)/20*20,(mouse_y+30)/20*20,makecol(255,0,0));
                }
            }
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            couleur=getpixel(page,mouse_x,mouse_y);
            if (mouse_b & 1 && couleur !=makecol(255,0,0))
            {
                rectfill(page,(mouse_x-30)/20*20,(mouse_y-30)/20*20,(mouse_x+30)/20*20,(mouse_y+30)/20*20,makecol(0,0,255));
                fprintf(niveau0,"\n%d %d %d",choix,(mouse_x-30)/20*20,(mouse_y-30)/20*20);
                compteurBat++;
                for (int t= 0; t<3; t++)
                {
                    for (int j =0 ; j<3; j++)
                    {
                        Mterrain[(mouse_x-30)/20+j][(mouse_y-30)/20+t]=1;
                    }
                }
                choix=0;
            }
            if (mouse_b & 2)
                choix=0;
        }
        if (key[KEY_R])
        {
            choix = 4;
        }
        while (choix == 4)
        {
            clear_bitmap(page);
            blit(fond2,page,0,0,0,0,SCREEN_W,SCREEN_H);
            rewind(niveau0);
            for (int i =0 ; i<compteurBat; i++)
            {
                fscanf(niveau0,"%d %d %d",&type,&coordx,&coordy);
                if (type == 1)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(0,255,255));
                }
                if (type == 2)
                {
                    rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(255,255,0));
                }
                if (type == 3)
                {
                    rectfill(page,coordx,coordy,coordx+60,coordy+60,makecol(0,0,255));
                }
                if (type == 4)
                {
                    rectfill(page,coordx,coordy,coordx+20,coordy+20,makecol(127,127,127));
                }
            }
            rectfill(page,mouse_x/20*20,mouse_y/20*20,mouse_x/20*20+20,mouse_y/20*20+20,makecol(127,127,127));
            if (Mterrain[mouse_x/20][mouse_y/20]==1)
            {
                rectfill(page,mouse_x/20*20,mouse_y/20*20,mouse_x/20*20+20,mouse_y/20*20+20,makecol(255,0,0));
            }
            if (mouse_b & 1 && Mterrain[mouse_x/20][mouse_y/20]==0)
            {
                route=1;
                xroute=mouse_x/20*20;
                yroute=mouse_y/20*20;
                rectfill(page,xroute,yroute,xroute+20,yroute+20,makecol(127,127,127));
            }
            if (mouse_b &2)
                choix=0;
            while (route == 1)
            {
                blit(fond2,page,0,0,0,0,SCREEN_W,SCREEN_H);
                rectfill(page,xroute,yroute,xroute+20,yroute+20,makecol(127,127,127));
                rewind(niveau0);
                for (int i =0 ; i<compteurBat; i++)
                {
                    fscanf(niveau0,"%d %d %d",&type,&coordx,&coordy);
                    if (type == 1)
                    {
                        rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(0,255,255));
                    }
                    if (type == 2)
                    {
                        rectfill(page,coordx,coordy,coordx+120,coordy+80,makecol(255,255,0));
                    }
                    if (type == 3)
                    {
                        rectfill(page,coordx,coordy,coordx+60,coordy+60,makecol(0,0,255));
                    }
                    if (type == 4)
                    {
                        rectfill(page,coordx,coordy,coordx+20,coordy+20,makecol(127,127,127));
                    }
                }
                if (mouse_y>yroute && mouse_y<yroute+20 && mouse_x<xroute && Mterrain[xroute/20-1][yroute/20]==0)
                {
                    rectfill(page,mouse_x/20*20,yroute,xroute,yroute+20,makecol(0,127,127));
                    if (mouse_b & 1)
                    {
                        rectfill(page,mouse_x/20*20,yroute,xroute,yroute+20,makecol(127,127,127));
                        for (int i = 0 ; i<(abs(mouse_x/20*20-xroute))/20+1; i++)
                        {
                            if (Mterrain[(xroute-20*i)/20][yroute/20]==0)
                            {
                                fprintf(niveau0,"\n%d %d %d",choix,xroute-20*i,yroute);
                                compteurBat++;
                                Mterrain[(xroute-20*i)/20][yroute/20]=4;
                            }
                        }
                        xroute=mouse_x/20*20;
                    }
                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                if (mouse_y>yroute && mouse_y<yroute+20 && mouse_x>xroute+20 && Mterrain[xroute/20+1][yroute/20]==0)
                {
                    rectfill(page,xroute+20,yroute,mouse_x/20*20+20,yroute+20,makecol(0,127,127));
                    if (mouse_b & 1)
                    {
                        rectfill(page,xroute+20,yroute,mouse_x/20*20+20,yroute+20,makecol(127,127,127));
                        for (int i = 0 ; i<(mouse_x/20*20-xroute)/20+1; i++)
                        {
                            if (Mterrain[(xroute+20*i)/20][yroute/20]==0)
                            {
                                fprintf(niveau0,"\n%d %d %d",choix,xroute+20*i,yroute);
                                compteurBat++;
                                Mterrain[(xroute+20*i)/20][yroute/20]=4;
                            }
                        }
                        xroute=mouse_x/20*20;
                    }
                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                if (mouse_x>xroute && mouse_x<xroute+20 && mouse_y<yroute+20 && Mterrain[xroute/20][yroute/20-1]==0)
                {
                    rectfill(page,xroute,mouse_y/20*20,xroute+20,yroute,makecol(0,127,127));

                    if (mouse_b & 1)
                    {
                        rectfill(page,xroute,mouse_y/20*20,xroute+20,yroute,makecol(127,127,127));
                        for (int i = 0 ; i<(abs(mouse_y/20*20-yroute))/20+1; i++)
                        {
                            if(Mterrain[xroute/20][(yroute-20*i)/20]==0)
                            {
                                fprintf(niveau0,"\n%d %d %d",choix,xroute,yroute-20*i);
                                compteurBat++;
                                Mterrain[xroute/20][(yroute-20*i)/20]=4;
                            }
                        }
                        yroute=mouse_y/20*20;
                    }
                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                if (mouse_x>xroute && mouse_x<xroute+20 && mouse_y>yroute+20 && Mterrain[xroute/20][yroute/20+1]==0)
                {
                    rectfill(page,xroute,yroute+20,xroute+20,mouse_y/20*20+20,makecol(0,127,127));
                    if (mouse_b & 1)
                    {
                        rectfill(page,xroute,yroute+20,xroute+20,mouse_y/20*20+20,makecol(127,127,127));
                        for (int i = 0 ; i<(mouse_y/20*20-yroute)/20+1; i++)
                        {
                            if (Mterrain[xroute/20][(yroute+20*i)/20]==0)
                            {
                                fprintf(niveau0,"\n%d %d %d",choix,xroute,yroute+20*i);
                                compteurBat++;
                                Mterrain[xroute/20][(yroute+20*i)/20]=4;
                            }
                        }
                        yroute=mouse_y/20*20;
                    }
                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                if (mouse_b & 2)
                {
                    route=0;
                    choix=0;
                }
            }
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
}
