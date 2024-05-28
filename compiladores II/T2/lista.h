#ifndef __lista__
#define __lista__

#include "stdio.h"

//representa um nó da lista
typedef void *N;

//representa um ponteiro para a lista
typedef void *Lista;

//representa as informações desse nó
typedef void *Info;

//função que retorna a chave de ordenação do dado armazenado
typedef char *funcGetChave(Info);


Lista create(funcGetChave f);
void insert(Lista L, Info info);
void insertAfter(Lista L, Info info, N n);
void insertBefore(Lista L, Info info, N n);
Info deleteLista(Lista L, N n);
int tamanhoLista(Lista L);
N getFirst(Lista L);
N getLast(Lista L);
N getNext(N n);
N getPrevious(N n);
Info getInfo(N n);
void destroiLista(Lista L, void (*funcaoAuxiliar)(void *));
void printaLista(Lista L, void (*printFunction)(void *, FILE *), FILE *arq);
N encontraNo(Lista L, char *chave);

#endif
