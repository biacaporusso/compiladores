#ifndef PILHA_C_PILHA_H
#define PILHA_C_PILHA_H 1

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    float value;
    char caractere;
    struct no* next;
} Node;

typedef struct pilha {
    Node* top;
    int size;
} Pilha;

Pilha* create_pilha();
void insert_info(Pilha* pilha, float value, char caractere);
Node* pop(Pilha* pilha);
void free_pilha(Pilha* pilha);
void print_pilha(Pilha* pilha);
void clear_stack(Pilha* pilha);

#endif