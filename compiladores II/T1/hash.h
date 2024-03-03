#ifndef HASH_C_HASH_H
#define HASH_C_HASH_H 1
#define SIZE 977

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "settings.h"

typedef struct matriz {
    int linhas;
    int colunas;
    float **dados;
} Matriz;

// Definindo a estrutura do nó da tabela hash
typedef struct h_node {
    char *key;
    float value;
    Matriz *valor_matriz; 
    int type; // numero real ou matriz
    struct h_node *next;
} HashNode;

// Definindo a estrutura da tabela hash
typedef struct hash_table {
    HashNode *table[SIZE];
} HashTable;



HashTable* create_hash_table();
int calculo_hash(char *key);
HashNode *create_hash_node(char *key, float value, int tipo);
void inserir_hash(HashTable *ht, char *key, float value, int tipo);
int search_hash(HashTable *ht, char *key);
void deletar_hash(HashTable *ht, char *key);
float get_value(HashTable *hash_table, char *key);
void printar_hash(HashTable *ht);
void free_hash(HashTable *hash_table);


Matriz* create_matrix();
void insert_matrix(Matriz *matriz, Pilha* pilha_primeiros, Pilha* pilha, int num_linhas, int num_colunas);
void imprimir_matriz(Matriz *matrix, Settings* settings);
void free_matriz(Matriz *matriz);
void clear_matrix(Matriz *matriz);
float calculo_determinante(Matriz *matriz);
int calculo_sistema_linear(Matriz* matriz);
void LU(Matriz* matriz);

#endif