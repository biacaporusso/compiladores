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

void printaFila(Queue Q) {

    Fila* fila = (Fila*) Q;
    Celula *celula = fila->prim;
    printf("\n==== ");

    for (int i=0; i<fila->tamanho; i++) {
        printf("%d ", celula->num);
        celula = celula->prox;
    }
    printf("\n\n");
}

Queue criaFila() {

    Fila *fila;
    fila = (Fila*) calloc(1, sizeof(Fila));
    fila->tamanho = 0;
    return(fila);
}

void inserirFila(Queue Q, int num) {
    if (num == 28 || num == 29) return;

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

    // printf("(INSERIDO %d)\n", fila->ult->num);
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

int getToken(Queue Q) {
    Fila* fila = (Fila*) Q;
    if (fila->prim != NULL)
        return fila->prim->num;
    else   
        return -999999;
}

void liberaFila(Queue fila) {
    Fila* f = fila;
    Celula* celula = f->prim;
    Celula* celulaRemovida;

    // percorrendo a fila e dando free em todas as células
    while (celula != NULL) {

        celulaRemovida = celula->prox;
        free(celula);
        celula = celulaRemovida;
    }
    // depois de ter liberado todas as células, libera a fila
    free(fila);
}
