#ifndef sintatico_h
#define sintatico_h

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void startSintatico(Queue fila);
void advance(Queue fila);
void eat(int t, Queue fila);
void S(Queue fila);
void L(Queue fila);
void E(Queue fila);

#endif
