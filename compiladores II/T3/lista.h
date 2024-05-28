#ifndef __lista__
#define __lista__

#include "stdio.h"

/* typedef struct info {
    int id;
    int tempo_inicio;
    int tempo_fim;
} Info; */

typedef struct node {
    int id;
    int tempo_inicio;
    int tempo_fim;
    struct node *prox;
} Node;

typedef struct lista {
    Node *inicio;
    int tamanho;
} Lista;


Lista* criarLista();
Node* novoNo(int id, int inicio, int fim);
void inserir(Lista* lista, Node* no);
void printarLista(Lista* lista);
Node* getNode(Lista* lista, int id);
//Info* createInfo(int id, int inicio, int fim);
//void setInfo(Info info, int id, int inicio, int fim);


#endif
