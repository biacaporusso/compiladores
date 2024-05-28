#ifndef LEXICO_C_PILHA_H
#define LEXICO_C_PILHA_H

#include <stdlib.h>

typedef struct stack_node {
    int value;
    struct Stack_Node *next;
}Stack_Node;

typedef struct stack {
    int size;
    Stack_Node *top;
}Stack;

Stack *criaPilha();

void inserePilha(Stack *stack, int value);

int pop(Stack *stack);

int is_empty(Stack *stack);

void stack_dump(Stack *stack);

void stack_free(Stack *stack);

#endif
