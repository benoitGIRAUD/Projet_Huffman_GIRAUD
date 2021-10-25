 /*============================== ESET 2021-2022 ================================
**File Name   :  TriArbreHuffman.c                                              **
**Author      :  Benoit GIRAUD                                                  **
**Created on  :  October, 2021                                                  **
**------------------------------------------------------------------------------**
**Description :                                                                 **
=================================================================================*/

/*=============================================================================
**                               Includes                                     **
==============================================================================*/
#include "TriArbreHuffnan.h"

 /*==============================================================================
**                           Public Functions                                   **
================================================================================*/

void triArbreHuffman( noeud *arbre[MAX_ARRAY], uint32_t taille )
{
    int i=0,j=0;

    printf( "--> Tri ArbreHuffman par ordre croissant: TriArbreHuffman() \r\n" );

    for (i = 0; i<(taille); i++)
    {
        for (j=0; j<(taille-i); j++)
        {
        	if ( arbre[j]->occurence > arbre[j+1]->occurence )
            {
                noeud tmpon = *arbre[j];
                 *arbre[j] = *arbre[j+1];
                *arbre[j+1] = tmpon;
            }
        }
    }

}
