#ifndef HASH_C_HASH_H
#define HASH_C_HASH_H 1
#define SIZE 977

#include <stdio.h>
#include <stdlib.h>

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
HashNode *create_hash_node(char *key, float value);
void inserir_hash(HashTable *ht, char *key, float value);
int search_hash(HashTable *ht, char *key);
void deletar_hash(HashTable *ht, char *key);
float get_value(HashTable *hash_table, char *key);
//void printar_hash(HashTable *ht);

Matriz* create_matrix(int linhas, int colunas);
void inserir_matriz(Matriz* m, int linha, int coluna, float valor);
void imprimir_matriz(Matriz *matrix);


#endif