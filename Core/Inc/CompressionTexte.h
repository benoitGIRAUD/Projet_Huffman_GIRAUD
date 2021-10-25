 /*============================== ESET 2021-2022 ================================
**File Name   :  CompressionTexte.h                                             **
**Author      :  Benoit GIRAUD                                                  **
**Created on  :  October, 2021                                                  **
**------------------------------------------------------------------------------**
**Description : Header file of CompressionTexte.c                               **
=================================================================================*/
#ifndef SRC_COMPRESSION_TEXTE_H_
#define SRC_COMPRESSION_TEXTE_H_

/*=============================================================================
**                               Includes                                     **
==============================================================================*/
#include "Struct.h"

/*===============================================================================
**                            Prototype                                        **
===============================================================================*/
noeud *getAdress_recursif(noeud *ptrNoeud, uint8_t caractere, noeud *Adresse);
uint16_t compresssionTexte(uint8_t *chaine, noeud *ptrNoeud, uint16_t texteCompress[TAILLE]);
void afficherTexteCompresse(uint16_t texteCompress[TAILLE], int16_t tailleC);

#endif /* SRC_COMPRESSION_TEXTE_H_ */
