#ifndef SRC_SHARED_H_
#define SRC_SHARED_H_

#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <string.h>

typedef struct noeud
{
    uint8_t c;                     // Caractère initial
    uint8_t tailleCode;            // Nombre de bits du code
    uint16_t occurence;            // Nombre d'occurence
    uint16_t code;                 // Code binaire dans l'arbre
    struct noeud *gauche, *droite; // Lien vers les noeuds suivants
    //uint8_t tailleCode;          // Nombre de bits du code
}noeud;

UART_HandleTypeDef COMM;

#define TAILLE  1000
#define MAX_ARRAY 256
#define MAX_ARRAY_MOINS1 255

#endif /* SRC_SHARED_H_ */
