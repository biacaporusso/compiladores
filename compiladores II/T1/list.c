#include "list.h"

List *criaLista(){
    List *list = (List*) malloc(sizeof (List));
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

void insereLista(List *list, char value){
    struct ListNode *new = (struct ListNode*) malloc(sizeof (struct ListNode));

    new->value = value;
    new->next = NULL;
    if(list->first == NULL){
        list->first = new;
        list->last = new;
    }else{
        list->last->next = new;
        list->last = new;
    }
    list->size++;
}

int is_list_empty(List *list){
    return !(list->size);
}

int get_list_size(List *list){
    return list->size;
}

char get_list_char(List *list, int i){
    int aux = 0;
    struct ListNode *node = list->first; // olha que legal

    for(node; node != NULL; node = node->next){
        if(aux == i){
            return node->value;
        }
        aux++;
    }

    return 0;
}

void remove_list_word(List *list, int i){
    int aux = 0;
    struct ListNode *node = list->first; // olha que legal

    while(node != NULL){
        if(aux == i){
            break;
        }
        struct ListNode *node_aux = node->next;
        free(node);
        node = node_aux;
        list->size--;
        aux++;
    }

    list->first = node;
    if(node == NULL){
        list->last = NULL;
    }
}

void remove_list(List *list){
    struct ListNode *node = list->first; // olha que legal


    while(node != NULL){
        struct ListNode *node_aux = node->next;
        free(node);
        node = node_aux;
    }

    free(list);
}

char *get_word_list(List *list, int i){

    char *word = malloc(sizeof(char) * i+1);
    int contador = 0;

    struct ListNode *node = list->first;
    for(node; node != NULL; node = node->next){
        if(contador == i ){
            break;
        }
        word[contador] = node->value;
        contador++;
    }

    word[i] = 0;

    return word;
}




