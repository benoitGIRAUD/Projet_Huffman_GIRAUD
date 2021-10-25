
 /*============================== ESET 2021-2022 ================================
**File Name   :  Occurrences.h                                                  **
**Author      :  Benoit GIRAUD                                                  **
**Created on  :  October, 2021                                                  **
**------------------------------------------------------------------------------**
**Description : Header file of Occurrences.c                                    **
=================================================================================*/

#ifndef OCCURENCE_H_INCLUDED
#define OCCURENCE_H_INCLUDED
  /*=============================================================================
  **                               Includes                                     **
  ==============================================================================*/
#include "Struct.h"

 /*===============================================================================
 **                            Prototype                                        **
 ===============================================================================*/

uint8_t compterNombreCaracteresDifferents(uint8_t tab[MAX_ARRAY]);
uint16_t occurence(uint8_t *chaine, uint8_t tab[MAX_ARRAY]);
void afficherTabCaractere(uint8_t tab[MAX_ARRAY]);

#endif // OCCURENCE_H_INCLUDED
