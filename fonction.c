#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "struct.h"


int nbrLigneFichier(char * fichier)
{
    char ligne[1024];
    int nbr_ligne=0;
    FILE * liste_mots_fr = NULL;
    liste_mots_fr = fopen( fichier , "r");
    while(fgets(ligne, 1024, liste_mots_fr) != NULL)
    {
        nbr_ligne++;
    }
    rewind(liste_mots_fr);
    return nbr_ligne;
}
int remplirTab(char **tableauMot, FILE* liste_mots_fr)
{
    int i=0;
    char Nom[50];
    while(fscanf(liste_mots_fr,"%s", Nom)!=EOF)
    {
        char* s = strdup(Nom);
        char *val = strsep(&s, ",");
        int j=1;
        while(val!=NULL)
        {
            if (j==1){
                *tableauMot = val;
            }
            val = strsep(&s, ",");
        }

        (tableauMot)++;
        i++;
    }

}
int creerFenetre(SDL_Window **window,SDL_Renderer ** renderer)
{
    SDL_Init(SDL_INIT_VIDEO);          
        TTF_Init();

        *window = SDL_CreateWindow(
            "Jeu",                             // Titre
            SDL_WINDOWPOS_UNDEFINED,           // x position
            SDL_WINDOWPOS_UNDEFINED,           // y position
            1080,                              // largeur
            720,                               // hauteur
            SDL_WINDOW_OPENGL                  // Flags
        );

        *renderer = SDL_CreateRenderer(*window, -1, 0);
}
int afficher_menu(SDL_Window ** window,SDL_Renderer ** renderer)
{
        TTF_Font * police1;
        TTF_Font * police;
        SDL_Color blanc = {255, 255, 255}; 
        SDL_Color noir = {0, 0, 0}; 
        police = TTF_OpenFont("fonts/times.ttf", 50);
        police1 = TTF_OpenFont("fonts/milkyboba.ttf", 50);
         /*-----------------------------------Fond d'écran------------------------------------*/    

        SDL_Texture * background;
        background = IMG_LoadTexture(*renderer, "images/forest_wallpaper.png");
        SDL_RenderCopy(*renderer, background, NULL, NULL);
    
        /*--------------------------------------Nom du jeu------------------------------------*/

        police1 = TTF_OpenFont("fonts/times.ttf", 50);
        police = TTF_OpenFont("fonts/milkyboba.ttf", 50);
        SDL_Surface* nom_jeu = TTF_RenderText_Solid(police, "Mon jeu", blanc) ;
        SDL_Texture * nom_jeu_texte = SDL_CreateTextureFromSurface(*renderer,nom_jeu);
        SDL_FreeSurface(nom_jeu);
        SDL_Rect rectangleTexte = {330,100,400,100};
        SDL_QueryTexture(nom_jeu_texte,NULL,NULL,0,0);
        SDL_RenderCopy(*renderer, nom_jeu_texte, NULL, &rectangleTexte);

    /*-----------------------------------Selection du mode--------------------------------*/
        /*Choix nombre joueur*/
        SDL_Surface * choix_nbr = TTF_RenderText_Solid(police, "Nombre de joueurs : ",noir);
        SDL_Texture * choix_nbr_texture = SDL_CreateTextureFromSurface(*renderer, choix_nbr);
        SDL_Rect rectangleTexte0 = {150,250,350,70};
        SDL_SetRenderDrawColor(*renderer, 0, 255 ,255, 255);/*Couleur remplissage*/
        // SDL_RenderFillRect(renderer, &rectangleTexte0);/*Remplir le rectangle d'une couleur*/
        // SDL_QueryTexture(choix_nbr_texture,NULL,NULL,0,0);//Affichage du rectangle
        SDL_RenderCopy(*renderer, choix_nbr_texture, NULL, &rectangleTexte0);

        /*Un joueur*/
        
        SDL_Surface  * singleplayer = TTF_RenderText_Solid(police, "1  joueur", noir);
        SDL_Texture * singleplayer_texte = SDL_CreateTextureFromSurface(*renderer, singleplayer);
        SDL_Rect rectangleTexte1 = {550,250,150,70};
        // SDL_SetRenderDrawColor(renderer, 0, 255 ,255, 255);/*Couleur remplissage*/
        // SDL_RenderFillRect(renderer, &rectangleTexte1);/*Remplir le rectangle d'une couleur*/
        //SDL_QueryTexture(singleplayer_texte,NULL,NULL,0,0);
        SDL_RenderCopy(*renderer, singleplayer_texte, NULL, &rectangleTexte1);

        /*Deux joueurs*/
        SDL_Surface  * multiplayer = TTF_RenderText_Solid(police, "2  joueurs", noir);
        SDL_Texture * multiplayer_texte = SDL_CreateTextureFromSurface(*renderer, multiplayer);
        SDL_Rect rectangleTexte2 = {750,250,150,70};
        // SDL_SetRenderDrawColor(renderer, 0, 255 ,255, 255);/*Couleur remplissage*/
        // SDL_RenderFillRect(renderer, &rectangleTexte2);/*Remplir le rectangle d'une couleur*/
        //SDL_QueryTexture(multiplayer_texte,NULL,NULL,0,0);
        SDL_RenderCopy(*renderer, multiplayer_texte, NULL, &rectangleTexte2);
        /*-----------------------------------Drapeau Français---------------------------------*/

        SDL_Texture * Drapeau_Fr;
        Drapeau_Fr = IMG_LoadTexture(*renderer, "images/drapeau_fr.png");
        SDL_Rect rectangle={120,350,360,244};
        SDL_RenderCopy(*renderer, Drapeau_Fr, NULL, &rectangle);

        /*------------------------------------Drapeau Anglais---------------------------------*/

        SDL_Texture * Drapeau_En;
        Drapeau_En = IMG_LoadTexture(*renderer, "images/drapeau_en.png");
        SDL_Rect rectangle1={600,350,360,244};
        SDL_RenderCopy(*renderer, Drapeau_En, NULL, &rectangle1);

        SDL_RenderPresent(*renderer);

        
        SDL_DestroyTexture(Drapeau_Fr);
        SDL_DestroyTexture(Drapeau_En);
        SDL_DestroyTexture(nom_jeu_texte);
        SDL_DestroyTexture(background);
}
