#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"

typedef struct celula {
    int num;
    struct celula *prox;
} Celula;

typedef struct {
    int tamanho;
    Celula *prim, *ult;
} Fila;

Queue criaFila() {

    Fila *fila;
    fila = (Fila*) calloc(1, sizeof(Fila));
    fila->tamanho = 0;
    return(fila);
}

void inserirFila(Queue Q, int num) {

    Fila* fila = (Fila*) Q;
    Celula* novoEle = (Celula*) malloc(sizeof(Celula));

    novoEle->num = num;
    novoEle->prox = NULL;

    if(fila->tamanho == 0) {

        fila->ult = novoEle;
        fila->prim = novoEle;

    } else {

        (fila->ult)->prox = novoEle;
        fila->ult = novoEle;
    }
    fila->tamanho++;
}

void removeElemento(Queue Q) {

    Fila* fila = (Fila*) Q;

    if (fila->prim == NULL) {
        return;
    } else {
        Celula* celula = fila->prim;
        fila->prim = fila->prim->prox;
        free(celula);
        fila->tamanho--;
    }
    return;
}

int getItem(Queue Q) {
    Fila* fila = (Fila*) Q;
    if (fila->prim != NULL)
        return fila->prim->num;
    else   
        return -999999;
}

void liberaFila(Queue fila) {
    Cell celula = getInicio(fila);
    Cell celulaRemovida;

    // percorrendo a fila e dando free em todas as células
    while (celula != NULL) {

        celulaRemovida = celula;
        celula = getNext(celula);
        free(celulaRemovida);
    }
    // depois de ter liberado todas as células, libera a fila
    free(fila);
}
