#ifndef lexico_h
#define lexico_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "fila.h"

#define NUM_STATES 174
#define NUM_SYMBOLS 83
#define NUM_ESTADOSFINAIS 58

int percorreVetor(char caractere);
bool ehEstadoFinal(int estadoDepois);

#endif