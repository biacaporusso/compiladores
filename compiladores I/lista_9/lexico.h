#ifndef lexico_h
#define lexico_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "fila.h"

#define NUM_STATES 28
#define NUM_SYMBOLS 27
#define NUM_ESTADOSFINAIS 9

int percorreVetor(char caractere);
bool ehEstadoFinal(int estadoDepois);

#endif