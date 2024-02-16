#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"

typedef struct celula {
    int num;
    char stringToken[1000];
    int inicioColuna, fimColuna; // para conseguir printar o conteudo do token
    int linha; // para caso der erro, conseguir identificar em qual linha e coluna que foi
    struct celula *prox;
} Celula;

typedef struct {
    int tamanho;
    Celula *prim, *ult;
} Fila;

void printaFila(Queue Q) {

    Fila* fila = (Fila*) Q;
    Celula *celula = fila->prim;

    for (int i=0; i<fila->tamanho; i++) {
        //printf("\n==== ");
        printf("\n%s ", celula->stringToken);
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

void inserirFila(Queue Q, int num, char* string, int inicioColuna, int fimColuna, int linha) {
    //if (num == 28 || num == 29) return;

    Fila* fila = (Fila*) Q;
    Celula* novoEle = (Celula*) malloc(sizeof(Celula));

    novoEle->num = num;
    strcpy(novoEle->stringToken, string);
    novoEle->inicioColuna = inicioColuna;
    novoEle->fimColuna = fimColuna;
    novoEle->linha = linha;
    novoEle->prox = NULL;

    if(fila->tamanho == 0) {

        fila->ult = novoEle;
        fila->prim = novoEle;

    } else {

        (fila->ult)->prox = novoEle;
        fila->ult = novoEle;
    }

    //printf("(INSERIDO %d)\n", fila->ult->num);
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

int getLinhaToken(Queue Q) {
    Fila* fila = (Fila*) Q;
    if (fila->prim != NULL)
        return fila->prim->linha;
    else   
        return -8888888;
}

int getColunaInicialToken(Queue Q) {
    Fila* fila = (Fila*) Q;
    if (fila->prim != NULL)
        return fila->prim->inicioColuna;
    else   
        return -7777777;
}

char* getStringToken(Queue Q) {
    Fila* fila = (Fila*) Q;
    if (fila->prim != NULL)
        return fila->prim->stringToken;
    else   
        return NULL;
}

int getColunaFinalToken(Queue Q) {
    Fila* fila = (Fila*) Q;
    if (fila->prim != NULL)
        return fila->prim->fimColuna;
    else   
        return -6666666;
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
