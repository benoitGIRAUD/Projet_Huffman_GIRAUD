#include "ArbreHuffman.h"

void creerFeuille( noeud *arbre[MAX_ARRAY], uint8_t tab[MAX_ARRAY] )
{
    int i=0,j=0;

    printf( "--> On cree l'arbre de Huffman: creerFeuille() \r\n" );

    for ( i=0; i<MAX_ARRAY; i++ )
    {
        if( tab[i]!=0 )
        {
            arbre[j] = malloc(sizeof(noeud));   // On conserve l'@
            arbre[j]->c = i;
            arbre[j]->occurence = tab[i];
            arbre[j]->code = 0;
            arbre[j]->tailleCode = 0;
            arbre[j]->gauche = NULL;
            arbre[j]->droite = NULL;
            j++;
        }
    }
}

void afficherTableauArbreHuffman( noeud *arbre[MAX_ARRAY] )
{
    int i=0,j=0;

    printf( "Adresses des caractere:\r\n" );

    printf("|---------------------------------------|\r\n");
    printf("|   Indice  |    Adresse   |  Caractere |\r\n");
    printf("|-----------|--------------|------------|\r\n");
    for( i=0; i<MAX_ARRAY; i++ )
    {
        if( arbre[i]!=0)
        {
            printf( "|%10d |  %10p  | %10c |\r\n", i, arbre[j], arbre[j]->c );
            j++;
        }
    }
    printf("|---------------------------------------|\r\n\r\n");
}

void afficherContenuArbreHuffman( noeud *arbre[MAX_ARRAY] )
{
    int i=0,j=0;

    printf( "Tableau Huffman:\r\n" );

    printf("+------------------------------------------------------------------------------------------------+\r\n");
    printf("|  Caractere |  Occurence |    Code    |   Taille   |    Adresse   |    Gauche    |    Droite    |\r\n");
    printf("+------------+------------+------------+------------+--------------+-----------------------------+\r\n");
    for( i=0; i<MAX_ARRAY; i++ )
    {
        if( arbre[i] != 0 )
        {
            printf("| %10c | %10d | %10lu | %10d |  %10p  |  %10p  |  %10p  |\r\n", arbre[j]->c, arbre[j]->occurence, arbre[j]->code, arbre[j]->tailleCode, arbre[j], arbre[j]->gauche, arbre[j]->droite);
            j++;
        }

    }
    printf("+------------------------------------------------------------------------------------------------+\r\n\r\n");
}
