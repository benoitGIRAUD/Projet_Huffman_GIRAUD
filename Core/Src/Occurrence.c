 /*============================== ESET 2021-2022 ================================
**File Name   :  Occurrences.c                                                  **
**Author      :  Benoit GIRAUD                                                  **
**Created on  :  October, 2021                                                  **
**------------------------------------------------------------------------------**
**Description :                                                                 **
=================================================================================*/

/*=============================================================================
**                               Includes                                     **
==============================================================================*/
#include "Occurrence.h"


  /*==============================================================================
**                           Public Functions                                   **
================================================================================*/

uint16_t occurence( uint8_t *chaine, uint8_t tab[MAX_ARRAY] )
{
	uint16_t nbrCaractere=0;
//
	while(chaine[nbrCaractere]!='\0')
	{
		tab[chaine[nbrCaractere]] += 1;
		nbrCaractere++;
	}

	printf("Le texte en entree est: \r\n %s\r\n\r\n", chaine);
	printf( "--> On calcul la frequence d'apparition: Occurrences() \r\n" );
	printf("Nombre de caracteres     Total  = %10d\r\n", nbrCaractere);

	return nbrCaractere;
}

uint8_t compterNombreCaracteresDifferents( uint8_t tab[MAX_ARRAY] )
{
    uint8_t i=0,nbrCaractereDifferents=0;

    for( i=0; i<MAX_ARRAY_MOINS1; i++ )
    {
        if( tab[i]!=0 ) { nbrCaractereDifferents++; } // printf("%d\r\n", tab[i]);
    }

    printf("Nombre de caracteres differents = %10d\r\n\r\n", nbrCaractereDifferents);

    return nbrCaractereDifferents;
}

void afficherTabCaractere( uint8_t tab[MAX_ARRAY] )
{
	int i=0;
//Affichage caractere et occurences.
//Pour chaque fonction une fonction d'affichage distincte

	printf( "Occurrences des caracteres:\r\n" );
    printf("|-------------------------|\r\n");
    printf("| Caractere  |  Occurrence|\r\n");
    printf("|------------|------------|\r\n");
    for( i=0; i<MAX_ARRAY; i++ )
    {
        if( tab[i]!=0 ) { printf( "| %10c | %10d |\r\n", i, tab[i] ); }
    }
    printf("|-------------------------|\r\n\r\n");
}
