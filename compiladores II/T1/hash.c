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

Matriz* create_matrix(int linhas, int colunas) {

    // Alocando memória para a estrutura da matriz
    Matriz *matrix = (Matriz*)malloc(sizeof(Matriz));
    if (matrix == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        return NULL; // Retorna NULL em caso de erro
    }

   // Alocando memória para as linhas da matriz
    matrix->dados = (float**)malloc(linhas * sizeof(float*));
    if (matrix->dados == NULL) {
        printf("Erro ao alocar memória para as linhas da matriz.\n");
        free(matrix); // Libera a memória alocada para a estrutura da matriz
        return NULL; // Retorna NULL em caso de erro
    }

    // Alocando memória para as colunas de cada linha da matriz
    for (int i = 0; i < linhas; i++) {
        matrix->dados[i] = (float*)malloc(colunas * sizeof(float));
        if (matrix->dados[i] == NULL) {
            printf("Erro ao alocar memória para as colunas da matriz.\n");
            // Libera a memória alocada para as linhas da matriz
            for (int j = 0; j < i; j++) {
                free(matrix->dados[j]);
            }
            free(matrix->dados); // Libera a memória alocada para a estrutura da matriz
            free(matrix);
            return NULL; // Retorna NULL em caso de erro
        }
    }

    // Inicializando a matriz com zeros
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            matrix->dados[i][j] = 0;
        }
    }

    matrix->linhas = linhas;
    matrix->colunas = colunas;

    return matrix;
}

void inserir_matriz(Matriz* m, int linha, int coluna, float valor) {
    // Verifica se a matriz e as coordenadas estão dentro dos limites
    if (m == NULL || linha < 0 || linha >= m->linhas || coluna < 0 || coluna >= m->colunas) {
        printf("Coordenadas inválidas ou matriz não alocada.\n");
        return;
    }

    // Insere o valor na posição especificada
    m->dados[linha][coluna] = valor;
    printf("inseriu %f\n", valor);
}

void imprimir_matriz(Matriz *matrix) {
    // Verifica se a matriz está alocada corretamente
    if (matrix == NULL) {
        printf("Matriz não alocada.\n");
        return;
    }

    // Percorre a matriz e imprime cada elemento
    for (int i = 0; i < matrix->linhas; i++) {
        for (int j = 0; j < matrix->colunas; j++) {
            printf(" %f ", matrix->dados[i][j]);
        }
        printf("\n");
    }
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
HashNode *create_hash_node(char *key, float value) {
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um par chave-valor na tabela hash
void inserir_hash(HashTable *ht, char *key, float value) {
    int index = calculo_hash(key);
    HashNode *newNode = create_hash_node(key, value);
    newNode->next = ht->table[index];
    ht->table[index] = newNode;

    //printf("ht->table[index]: %s", newNode->key);
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

// Função para buscar o valor associado a uma chave na tabela hash
float get_value(HashTable *hash_table, char *key) {
    int index = calculo_hash(key);
    HashNode *node = hash_table->table[index];

    // Percorre a lista encadeada no índice correspondente da tabela hash
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value; // Retorna o valor se a chave for encontrada
        }
        node = node->next;
    }

    return -1; // Retorna -1 se a chave não for encontrada
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