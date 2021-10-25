 /*============================== ESET 2021-2022 ================================
**File Name   :  ArbreBinaire.c                                                 **
**Author      :  Benoit GIRAUD                                                  **
**Created on  :  October, 2021                                                  **
**------------------------------------------------------------------------------**
**Description :                                                                 **
=================================================================================*/

/*=============================================================================
**                               Includes                                     **
==============================================================================*/
#include "ArbreBinaire.h"
#include "TriArbreHuffnan.h"

  /*==============================================================================
**                           Public Functions                                   **
================================================================================*/

void nouveauNoeud(noeud *arbre[MAX_ARRAY], uint8_t taille)
{
    int i=0;

    printf("--> Creation des nouveaux noeuds: nouveauNoeud()\r\n");

    noeud *tmp = malloc(sizeof(noeud)); //tmp->c = '!';
    tmp->occurence = arbre[0]->occurence + arbre[1]->occurence;
    tmp->gauche    = arbre[0];
    tmp->droite    = arbre[1];
    arbre[0] = tmp;

    for( i=1; i<taille; i++ ) { arbre[i] = arbre[i+1]; } // Decalage d'une case vers le haut du tableau
    arbre[taille] = 0; // Suppression du dernier elements
}

void constructionArbreBinaire(noeud *arbre[256], uint8_t taille)
{
    int i=0;

    for( i=0; i< taille ; i++ )
    {
        nouveauNoeud(arbre, taille);
        triArbreHuffman(arbre, taille-i-1);
    }

	afficherRacineArbre(arbre[0]);
}


void afficherRacineArbre(noeud *arbre)
{
    printf( "Racine de l'arbre:\r\n" );
    printf("|---------------------------------------------------------|\r\n");
    printf("|   NbrCarac |    Adresse   |    Gauche    |    Droite    |\r\n");
    printf("|------------|--------------|--------------|--------------|\r\n");
    printf("| %10d |  %10p  |  %10p  |  %10p  |\r\n", arbre->occurence, arbre, arbre->gauche, arbre->droite);
    printf("|---------------------------------------------------------|\r\n\r\n");
}
