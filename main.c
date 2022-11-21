#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "struct.h"

int main(int argc, char* argv[]) 
{
    SDL_Window *window = NULL;
    SDL_Renderer * renderer = NULL;
    /*-----------------------------------*/
    creerFenetre(&window,&renderer);
    afficher_menu(&window,&renderer);
    int i=0;
    char **tableauMot = NULL;
    FILE *liste_mots_fr = fopen("tableau.csv" , "r");
    int nbr_ligne = nbrLigneFichier("tableau.csv");


    // tableauMot = (char**)malloc(nbr_ligne*sizeof(char*));
    // for (i=0; i < nbr_ligne; i++)
    // {
    //     tableauMot[i] =malloc(50*sizeof(char));
    // }
    if (remplirTab(tableauMot,liste_mots_fr))
    {
        printf("Tableau rempli !\n");
    };

    /*Affichage du tableau*/
    int j = 0;
    for (j=0;i<nbr_ligne;j++){
        printf("%s\n",tableauMot[j]);
    }
    
    SDL_bool programm_launched = SDL_TRUE;
    while(programm_launched)
    {
        SDL_Event evt;
        SDL_PollEvent(&evt);
        
            switch(evt.type)
            {
                
                case SDL_QUIT:
                    programm_launched=SDL_FALSE;;
                break;

                case SDL_MOUSEBUTTONDOWN:
                    if(evt.button.button == SDL_BUTTON_LEFT && (evt.button.x > 550 && evt.button.x < 700
                    && evt.button.y > 250 && evt.button.y < 320)){
                        //afficher_menu();   
                        
                    }
                break;
                default : 
                    break;
            }
    }
    
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}