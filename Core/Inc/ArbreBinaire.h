
 /*============================== ESET 2021-2022 ================================
**File Name   :  ArbreBinaire.h                                                 **
**Author      :  Benoit GIRAUD                                                  **
**Created on  :  October, 2021                                                  **
**------------------------------------------------------------------------------**
**Description : Header file of ArbreBinaire.c                                   **
=================================================================================*/
#ifndef INC_ARBRE_BINAIRE_H_
#define INC_ARBRE_BINAIRE_H_

/*=============================================================================
**                               Includes                                     **
==============================================================================*/
#include "Struct.h"

/*===============================================================================
**                            Prototype                                        **
===============================================================================*/
void nouveauNoeud( noeud *arbre[MAX_ARRAY], uint8_t taille );
void constructionArbreBinaire( noeud *arbre[MAX_ARRAY], uint8_t taille );
void afficherRacineArbre( noeud *arbre );

#endif /* INC_ARBRE_BINAIRE_H_ */
