 /*============================== ESET 2021-2022 ================================
**File Name   :  ParcoursArbreBinaire.c                                         **
**Author      :  Benoit GIRAUD                                                  **
**Created on  :  October, 2021                                                  **
**------------------------------------------------------------------------------**
**Description :                                                                 **
=================================================================================*/

/*=============================================================================
**                               Includes                                     **
==============================================================================*/
#include "ParcoursArbreBinaire.h"

  /*==============================================================================
**                           Public Functions                                   **
================================================================================*/


void parcourirArbre(noeud *ptrNoeud)
{
    if( ptrNoeud->gauche == NULL && ptrNoeud->droite == NULL )
    {
        printf("| %c         | %10d | %10lu | %10d |  %10p  |  %10p  |  %10p  |\r\n", ptrNoeud->c, ptrNoeud->occurence, ptrNoeud->code, ptrNoeud->tailleCode, ptrNoeud, ptrNoeud->gauche, ptrNoeud->droite);

    }
    else
    {

    	parcourirArbre(ptrNoeud->droite);
    	parcourirArbre(ptrNoeud->gauche);
    }
}

void afficherFeuilles(noeud *ptrNoeud)
{
    printf("|-----------------------------------------------------------------------------------------------|\r\n");
    printf("| Caractere |  Occurence |    Code    |   Taille   |    Adresse   |    Gauche    |    Droite    |\r\n");
    printf("|-----------|------------|------------|------------|--------------|-----------------------------|\r\n");
    parcourirArbre(ptrNoeud);
}

void creerCode(noeud *ptrNoeud, uint32_t code, uint32_t taille)
{
    if(ptrNoeud->gauche == NULL && ptrNoeud->droite == NULL)
    {
    	ptrNoeud->tailleCode = taille;
    	ptrNoeud->code       = code;
    }
    else
    {
    	creerCode( ptrNoeud->droite, (code<<1)+1, taille+1 ); //recursif
    	creerCode( ptrNoeud->gauche, (code<<1), taille+1 );
    }
}
