#ifndef __pilha__
#define __pilha__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef void *Pilha;
typedef void *Info; // informação que a pilha vai usar
typedef void visitaElem(Info);

Pilha criaPilha();
void push(Pilha p, Info info);
Info pop(Pilha p);
Info getInfoTopoPilha(Pilha p);
Info getInfoProxTopoPilha(Pilha p);
void printPilha(Pilha p, visitaElem fPrint);
void destruirPilha(Pilha p, visitaElem fDesaloca);
int isEmpty(Pilha p);

#endif
