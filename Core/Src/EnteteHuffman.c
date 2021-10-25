#include "EnteteHuffman.h"
#include "Compressiontexte.h"

void creationEntete( uint16_t entete[100], uint16_t tFichierC, uint16_t nbrCaractereTotal, uint8_t tab[256], noeud *ptrNoeud )
{
	uint8_t i=0;

	entete[0] = 3;

	for( i=0; i<255; i++ )
	{
	    if( tab[i]!=0 )
	    {
	    	noeud *tmp = getAdress_recursif( ptrNoeud, i, 0 );

	    	entete[entete[0]] = tmp->c;
	    	entete[0]++;

	    	entete[entete[0]] = tmp->code>>8;
	    	entete[0]++;

	        entete[entete[0]] = (tmp->code<<8)>>8;
	        entete[0]++;

	    	entete[entete[0]] = tmp->tailleCode;
	    	entete[0]++;
	    }
	}
	entete[1] = tFichierC;
	entete[2] = nbrCaractereTotal;
}

void afficherEntete( uint16_t entete[100] )
{
	uint16_t i=0;

	printf("Taille entete = %d\r\n", entete[0]);
	printf("Taille fichierC = %d\r\n", entete[1]);
	printf("Taille nbrCaractereTotal = %d\r\n", entete[2]);

	printf("+-------+---------+--------+\r\n");
	printf("| ASCII | Huffman | Taille |\r\n");
	printf("+-------+---------+--------+\r\n");
	for( i=3; i<entete[0]; i+=4 )
	{
		printf("| %5c | %7d | %6d |\r\n", entete[i], ((entete[i+1]<<8)+entete[i+2]), entete[i+3]);
	}
	printf("+-------+---------+--------+\r\n");

}
