#include <stdio.h>
#include <stdlib.h>
#include "lista_matriz.h"

// Função para criar um novo nó da lista externa
ListaLinhas* newNode_listaExterna() {
    ListaLinhas* node = (ListaLinhas*)malloc(sizeof(ListaLinhas));
    node->head = NULL;
    node->next = NULL;
    return node;
}

ListaColunas* newNode_listaInterna(float data) {
    ListaColunas* node = (ListaColunas*)malloc(sizeof(ListaColunas));
    node->data = data;
    node->next = NULL;
    return node;
}

// Função para adicionar um valor a uma linha da matriz
void addValue_listaInterna(ListaLinhas* lista_externa, int rowIndex, int value) {
    // Percorre até a linha desejada
    for (int i = 0; i < rowIndex; ++i) {
        if (lista_externa->next == NULL) {
            // Se a linha não existir, cria uma nova
            lista_externa->next = newNode_listaExterna();
        }
        lista_externa = lista_externa->next;
    }
    // Adiciona o valor ao final da linha
    if (lista_externa->head == NULL) {
        lista_externa->head = newNode_listaInterna(value);
    } else {
        ListaColunas* temp = lista_externa->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode_listaInterna(value);
    }
}



// Função para imprimir a matriz
void printMatrix(ListaLinhas* list) {
    ListaLinhas* currentRow = list;
    int rowIndex = 0;
    while (currentRow != NULL) {
        printf("Row %d: ", rowIndex);
        ListaColunas* currentElement = currentRow->head;
        while (currentElement != NULL) {
            printf("%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        printf("\n");
        currentRow = currentRow->next;
        rowIndex++;
    }
}