 /*============================== ESET 2021-2022 ================================
**File Name   :  CompressionTexte.c                                             **
**Author      :  Benoit GIRAUD                                                  **
**Created on  :  October, 2021                                                  **
**------------------------------------------------------------------------------**
**Description :                                   **
=================================================================================*/

/*=============================================================================
**                               Includes                                     **
==============================================================================*/
#include "Compressiontexte.h"

  /*==============================================================================
**                           Public Functions                                   **
================================================================================*/

noeud *getAdress_recursif(noeud *ptrNoeud, uint8_t caractere, noeud *Adresse)
{
	if( ptrNoeud->gauche == NULL && ptrNoeud->droite == NULL )
    {
    	if( ptrNoeud->c == caractere )
    	{
    		return ptrNoeud;
    	}
    	else
    		return 0;
    }
    else
    {
    	if(Adresse==0) { Adresse = getAdress_recursif( ptrNoeud->droite, caractere, Adresse ); }
    	if(Adresse==0) { Adresse = getAdress_recursif( ptrNoeud->gauche, caractere, Adresse ); }
    }

	return Adresse;
}

uint16_t compresssionTexte(uint8_t *chaine, noeud *ptrNoeud, uint16_t texteCompress[TAILLE])
{
	uint8_t  i=0,colonne=0,bit=0;
	uint16_t ligne=0,rangBit=0;
	int j=0;

	printf("--> Test Compression: CompressionTexte()\r\n");

	while(chaine[i]!='\0')
	{
		noeud *tmp = (getAdress_recursif( ptrNoeud, chaine[i], 0 ));

		for( j=(tmp->tailleCode)-1; j>=0; j-- )//for( j=0; j<tmp->tailleCode; j++ )
		{
			bit = (tmp->code&(1<<j))>>j ;

			ligne = rangBit>>3;
			colonne = rangBit%8;
			printf("Ecriture de %d -> [%d %d] %lu\r\n", bit, ligne, colonne, tmp->code);

			texteCompress[ligne] |= bit<<colonne;
			rangBit++;
		}
		i++; printf("SUIVANT\r\n");
	}
	printf("  Fin compression\r\n");

	return rangBit;
}

void afficherTexteCompresse( uint16_t texteCompress[TAILLE], int16_t tailleC )
{
	int i=0,j=0;

	printf("Texte Compresse sur 3 cases mémoires\r\n");
	for( i=0; i<(tailleC/8)+1; i++ )
	{
		printf("[%3d]", i);
		for( j=0; j<8; j++ )
		{
			printf("%d ", (texteCompress[i]&(1<<j))>>j);
		}
		printf("\r\n");
	}
	printf("\r\n");
}

