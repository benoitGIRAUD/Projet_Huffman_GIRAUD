#ifndef NOEUD_H_INCLUDED
#define NOEUD_H_INCLUDED

#include "Struct.h"

void creerFeuille( noeud *arbre[256], uint8_t tab[MAX_ARRAY] );
void afficherTableauArbreHuffman( noeud *arbre[MAX_ARRAY] );
void afficherContenuArbreHuffman( noeud *arbre[MAX_ARRAY] );

#endif // NOEUD_H_INCLUDED
