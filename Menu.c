#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

void initAlleg()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    set_uformat(U_ASCII);
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,700,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
}

int afficherDebut()
{
    BITMAP* accueil;
    BITMAP* bouton;
    BITMAP* bouton1;
    BITMAP* page;
    BITMAP* logo;
    page= create_bitmap(SCREEN_W,SCREEN_H);
    accueil=load_bitmap("accueil00.bmp",NULL);
    if (!accueil)
    {
        allegro_message("pas pu trouver accueil.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    bouton=load_bitmap("bouto.bmp",NULL);
    logo=load_bitmap("logo.bmp",NULL);
    if (!bouton)
    {
        allegro_message("pas pu trouver bouto.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    bouton1=load_bitmap("boutonn.bmp",NULL);
    if (!bouton1)
    {
        allegro_message("pas pu trouver boutonn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    while(!key[KEY_ESC])
    {
        blit(accueil,page,0,0,0,0,SCREEN_W,SCREEN_H);

        masked_blit(logo,page,0,0,380,60,SCREEN_W,SCREEN_H);
        ///affichage bouton plus petit quand souris passe dessus
        if (mouse_x>=477 && mouse_x<=723 && mouse_y>=420 && mouse_y<=530)
        {
            masked_blit(bouton1,page,0,0,480,420,SCREEN_W,SCREEN_H);
        }
        else
        {

            masked_blit(bouton,page,0,0,477,420,SCREEN_W,SCREEN_H);
        }

        if(mouse_x>=477 && mouse_x<=723 && mouse_y>=420 && mouse_y<=530 && mouse_b & 1)
        {
            rest(1000);
            return 1;  //renvoi un a test pour lancer le choix du nombre de joueurs
        }
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

}


int menu(){
    BITMAP* accueil2;
    BITMAP* page1;
    BITMAP* accueil3;
    page1= create_bitmap(SCREEN_W,SCREEN_H);
    accueil2=load_bitmap("choixjeu1.bmp",NULL);
    accueil3=load_bitmap("choixjeu2.bmp",NULL);
    if (!accueil3)
    {
        allegro_message("pas pu trouver bouto.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!accueil2)
    {
        allegro_message("pas pu trouver menu.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
     while(!key[KEY_ESC])
    {

        if(mouse_x>=600)
        {
            blit(accueil2,page1,0,0,0,0,SCREEN_W,SCREEN_H);
            if (mouse_b & 1){
              rest(1000);
            return 1;  //renvoi un a test pour lancer le choix du nombre de joueurs
            }

        }
        else{
                blit(accueil3,page1,0,0,0,0,SCREEN_W,SCREEN_H);
                if (mouse_b & 1){
              rest(1000);
            return 2;  //renvoi un a test pour lancer le choix du nombre de joueurs
            }
        }
        blit(page1,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        }

}

int choix()
{
    BITMAP* accueil;
    BITMAP* bouton1;
    BITMAP* bouton12;
    BITMAP* bouton2;
    BITMAP* bouton22;
    BITMAP* page;

    page= create_bitmap(SCREEN_W,SCREEN_H);
    accueil=load_bitmap("Affichage2Menu.bmp",NULL);
    if (!accueil)
    {
        allegro_message("pas pu trouver affichache.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    bouton1=load_bitmap("capitalistSelec.bmp",NULL);
    if (!bouton1)
    {
        allegro_message("pas pu trouver bouton1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    bouton12=load_bitmap("capitalist.bmp",NULL);
    if (!bouton1)
    {
        allegro_message("pas pu trouver capitalist.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    bouton2=load_bitmap("commuSelec.bmp",NULL);
    if (!bouton1)
    {
        allegro_message("pas pu trouver commuSelec.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    bouton22=load_bitmap("commu.bmp",NULL);
    if (!bouton1)
    {
        allegro_message("pas pu trouver commu.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    while(!key[KEY_ESC])
    {
        blit(accueil,page,0,0,0,0,SCREEN_W,SCREEN_H);

        ///affichage bouton plus petit quand souris passe dessus
        if (mouse_x>=677 && mouse_x<=823 && mouse_y>=320 && mouse_y<=430)
        {
            masked_blit(bouton1,page,0,0,700,340,SCREEN_W,SCREEN_H);
        }
        else
        {

            masked_blit(bouton12,page,0,0,677,320,SCREEN_W,SCREEN_H);
        }

        if(mouse_x>=677 && mouse_x<=823 && mouse_y>=320 && mouse_y<=430 && mouse_b & 1)
        {
            rest(1000);
            return 1;  //renvoi un a test pour lancer le choix du nombre de joueurs
        }


        if (mouse_x>=177 && mouse_x<=423 && mouse_y>=320 && mouse_y<=430)
        {
            masked_blit(bouton2,page,0,0,210,340,SCREEN_W,SCREEN_H);
        }
        else
        {

            masked_blit(bouton22,page,0,0,180,320,SCREEN_W,SCREEN_H);
        }

        if(mouse_x>=177 && mouse_x<=423 && mouse_y>=320 && mouse_y<=430 && mouse_b & 1)
        {
            rest(1000);
            return 1;  //renvoi un a test pour lancer le choix du nombre de joueurs
        }
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

}




int map(){
    BITMAP* page1;
    BITMAP* map;
    page1= create_bitmap(SCREEN_W,SCREEN_H);
    map=load_bitmap("Map.bmp",NULL);
    while(!key[KEY_ESC])
    {
        blit(map,page1,0,0,0,0,SCREEN_W,SCREEN_H);

    blit(page1,screen,0,0,0,0,SCREEN_W,SCREEN_H);}
    return 1;
}

