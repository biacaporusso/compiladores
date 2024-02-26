#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 977

HashTable* create_hash_table() {
    HashTable *hashTable = (HashTable*)malloc(sizeof(HashTable)); // Alocando a tabela hash
    if (hashTable == NULL) {
        printf("Erro ao alocar memória para a tabela hash.\n");
    }

    // Inicializando todas as entradas da tabela hash como NULL
    for (int i = 0; i < SIZE; i++) {
        hashTable->table[i] = NULL;
    }

    return hashTable;
}

// Função de hash simples para calcular o índice
int calculo_hash(char *key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash + key[i]) % SIZE;
    }
    return hash;
}

// Função para criar um novo nó
HashNode *create_hash_node(char *key, int value) {
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um par chave-valor na tabela hash
void inserir_hash(HashTable *ht, char *key, int value) {
    int index = calculo_hash(key);
    HashNode *newNode = create_hash_node(key, value);
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Função para pesquisar um valor na tabela hash usando a chave
int search_hash(HashTable *ht, char *key) {
    int index = calculo_hash(key);
    HashNode *current = ht->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Retorna -1 se a chave não for encontrada
}

// Função para deletar um par chave-valor da tabela hash
void deletar_hash(HashTable *ht, char *key) {
    int index = calculo_hash(key);
    HashNode *current = ht->table[index];
    HashNode *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                ht->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Função para imprimir a tabela hash
/* void printar_hash(struct HashTable *ht) {
    for (int i = 0; i < SIZE; i++) {
        HashNode *current = ht->table[i];
        printf("%d: ", i);
        while (current != NULL) {
            printf("(%s, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
} */