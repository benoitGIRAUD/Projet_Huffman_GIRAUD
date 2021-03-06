
 /*============================== ESET 2021-2022 ================================
**File Name   :  ArbreHuffman.h                                                  **
**Author      :  Benoit GIRAUD                                                  **
**Created on  :  October, 2021                                                  **
**------------------------------------------------------------------------------**
**Description : Header file of ArbreHuffman.c                                    **
=================================================================================*/


#ifndef NOEUD_H_INCLUDED
#define NOEUD_H_INCLUDED
/*=============================================================================
**                               Includes                                     **
==============================================================================*/
#include "Struct.h"
/*===============================================================================
**                            Prototype                                        **
===============================================================================*/

void creerFeuille( noeud *arbre[256], uint8_t tab[MAX_ARRAY] );
void afficherTableauArbreHuffman( noeud *arbre[MAX_ARRAY] );
void afficherArbreHuffman( noeud *arbre[MAX_ARRAY] );

#endif // NOEUD_H_INCLUDED
