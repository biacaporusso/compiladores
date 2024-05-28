#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para criar um novo nó
Node* novoNo(int id, int inicio, int fim) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo != NULL) {
        novo->id = id;
        novo->tempo_inicio = inicio;
        novo->tempo_fim = fim;
        novo->prox = NULL;
    }
    return novo;
}

// Função para criar uma nova lista vazia
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista != NULL) {
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

// Função para inserir um novo nó no final da lista
void inserir(Lista* lista, Node* no) {

    if (lista->inicio == NULL) {
        lista->inicio = no;
    } else {
        Node* atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = no;
    }
    no->prox = NULL;
    lista->tamanho++;
}

void printarLista(Lista* lista) {
    Node* atual = lista->inicio;
    printf("Lista de nós:\n");
    while (atual != NULL) {
        printf("vr%d ==> %d %d\n", atual->id, atual->tempo_inicio, atual->tempo_fim);
        atual = atual->prox;
    }
}

Node* getNode(Lista* lista, int id) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->id == id) {
            return atual;
        } 
        atual = atual->prox;
    }
    return NULL;
}