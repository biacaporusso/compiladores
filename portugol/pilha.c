#include "pilha.h"


Stack *criaPilha(){
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void inserePilha(Stack *stack, int value){
    Stack_Node *node = (Stack_Node*) malloc(sizeof (Stack_Node));
    node->value = value;
    node->next = (struct Stack_Node *) stack->top;
    stack->top = node;
    stack->size++;
}

int pop(Stack *stack){
    Stack_Node *old = stack->top;
    int value = old->value;
    stack->top = (Stack_Node *) old->next;
    stack->size--;
    free(old);
    return value;
}

int is_empty(Stack *stack){ // 0 para não e 1 para sim
    return !(stack->size);
}

void stack_dump(Stack *stack){
    Stack_Node *old = stack->top;
    while(old != NULL){
        Stack_Node *aux = (Stack_Node *) old->next;
        free(old);
        old = aux;
    }
    stack->top = NULL;
    stack->size = 0;
}


void stack_free(Stack *stack){
    stack_dump(stack);
    free(stack);
}
