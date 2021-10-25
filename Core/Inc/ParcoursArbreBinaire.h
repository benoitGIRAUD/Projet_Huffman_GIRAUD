 /*============================== ESET 2021-2022 ================================
**File Name   :  ParcoursArbreHuffman.h                                         **
**Author      :  Benoit GIRAUD                                                  **
**Created on  :  October, 2021                                                  **
**------------------------------------------------------------------------------**
**Description : Header file of ParcoursArbreHuffman.c                           **
=================================================================================*/

#ifndef PARCOURS_ARBRE_H_INCLUDED
#define PARCOURS_ARBRE_H_INCLUDED

/*=============================================================================
**                               Includes                                     **
==============================================================================*/
#include "Struct.h"

/*===============================================================================
**                            Prototype                                        **
===============================================================================*/
void parcourirArbre(noeud *ptrNoeud );
void afficherFeuilles( noeud *ptrNoeud);
void creerCode(noeud *ptrNoeud, uint32_t code, uint32_t taille );

#endif // PARCOURS_ARBRE_H_INCLUDED
