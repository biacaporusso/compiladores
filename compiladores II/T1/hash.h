#ifndef HASH_C_HASH_H
#define HASH_C_HASH_H 1
#define SIZE 977

#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da tabela hash
typedef struct h_node {
    char *key;
    int value;
    struct h_node *next;
} HashNode;

// Definindo a estrutura da tabela hash
typedef struct hash_table {
    HashNode *table[SIZE];
} HashTable;


HashTable* create_hash_table();
int calculo_hash(char *key);
HashNode *create_hash_node(char *key, int value);
void inserir_hash(HashTable *ht, char *key, int value);
int search_hash(HashTable *ht, char *key);
void deletar_hash(HashTable *ht, char *key);
//void printar_hash(HashTable *ht);

#endif