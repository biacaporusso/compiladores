#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define INITIAL_CAPACITY 10

Pilha* create_pilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    pilha->top = NULL;
    pilha->size = 0;
    return pilha;
}

// Function to push a new node onto the pilha
void insert_info(Pilha* pilha, float value, char caractere) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->value = value;
    newNode->caractere = caractere;
    newNode->next = pilha->top;
    pilha->top = newNode;
    pilha->size++;
}

// Function to pop the top element from the pilha
Node* pop(Pilha* pilha) {
    if (pilha->top == NULL) {
        //printf("Pilha is empty\n");
        return NULL;
    }

    Node* temp = pilha->top;
    pilha->top = pilha->top->next;  // temp->next 
    pilha->size--;
    return temp;
}

// Function to free all memory allocated for the pilha
void free_pilha(Pilha* pilha) {
    while (pilha->top != NULL) {
        Node* temp = pilha->top;
        pilha->top = pilha->top->next;
        free(temp);
    }
    pilha->size = 0;
    free(pilha);
}

void print_pilha(Pilha* pilha) {
    if (pilha->top == NULL) {
        return;
    }

    Node* current = pilha->top;
    while (current != NULL) {
        current = current->next;
    }
}

// Function to clear the content of the stack
void clear_stack(Pilha* pilha) {
    while (pilha->top != NULL) {
        Node* temp = pilha->top;
        pilha->top = pilha->top->next;
        free(temp);
    }
    pilha->size = 0;
}