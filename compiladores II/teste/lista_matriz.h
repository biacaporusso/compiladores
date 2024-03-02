#ifndef LISTA_MATRIZ_C_LISTA_MATRIZ_H
#define LISTA_MATRIZ_C_LISTA_MATRIZ_H 1

#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista interna (valores daquela linha)
typedef struct lista_interna {
    int data;
    struct lista_interna* next;
} ListaColunas;

// Estrutura para um nó da lista externa (linhas da matriz)
typedef struct lista_externa {
    ListaColunas* head; // Ponteiro para o início da lista interna
    struct lista_externa* next;
} ListaLinhas;

ListaColunas* newNode_listaInterna(float data); // Cria um novo nó da lista interna (ou seja, um novo valor)
ListaLinhas* newNode_listaExterna(); // Cria um novo nó da lista externa (ou seja, uma nova linha)
void addValue_listaInterna(ListaLinhas* lista_externa, int rowIndex, int value); // Adiciona um valor na lista interna da lista externa passada
void printMatrix(ListaLinhas* list);

#endif