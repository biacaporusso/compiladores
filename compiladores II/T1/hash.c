#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 977

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- HASH FUNCTIONS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

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
void printar_hash(HashTable *ht) {
    //printf("Chaves na tabela hash:\n");
    for (int i = 0; i < SIZE; i++) {
        HashNode *current = ht->table[i];
        while (current != NULL) {
            printf("%s - FLOAT\n", current->key);
            current = current->next;
        }
    }
}



// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- MATRIX FUNCTIONS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-



Matriz* create_matrix() {

    Matriz *matriz = (Matriz*)malloc(sizeof(Matriz));
    matriz->linhas = 0;
    matriz->colunas = 0;
    matriz->dados = NULL;
    return matriz;
} 

void clear_matrix(Matriz *matriz) {
    if (matriz->dados != NULL) {
        // Free memory for each row
        for (int i = 0; i < matriz->linhas; i++) {
            free(matriz->dados[i]);
        }
        // Free memory for the array of pointers (rows)
        free(matriz->dados);
        matriz->dados = NULL;
    }
    matriz->linhas = 0;
    matriz->colunas = 0;
}

void insert_matrix(Matriz *matriz, Pilha* pilha_primeiros, Pilha* pilha, int num_linhas, int num_colunas) {

    int descarte;
    printf("linhas: %d\ncolunas: %d\n", num_linhas, num_colunas);

    if (num_linhas <= 10 && num_colunas <= 10) {

        // Allocate memory for the matrix if it hasn't been allocated yet
        if (matriz->dados == NULL) {
            matriz->dados = (float**)malloc(num_linhas * sizeof(float*));
            for (int i = 0; i < num_linhas; i++) {
                matriz->dados[i] = (float*)malloc(num_colunas * sizeof(float));
                for (int j = 0; j < num_colunas; j++) {
                    matriz->dados[i][j] = 0;
                }
            }
            matriz->linhas = num_linhas;
            matriz->colunas = num_colunas;
        }

        printf("matriz inicializada: \n");
        imprimir_matriz(matriz);

        Node* no_pilha;

        // Insert first values from pilha_primeiros into matrix
        for (int i = 0; i < num_linhas; i++) {
            if (pilha_primeiros->top != NULL) {
                printf("\n\ni: %d\n", i);
                printf("j: 0\n");
                printf("  value: %f caractere: %c\n", pilha_primeiros->top->value, pilha_primeiros->top->caractere);
                no_pilha = pop(pilha_primeiros);
                if(no_pilha != NULL)
                    matriz->dados[i][0] = no_pilha->value;
                //matriz->dados[i][0] = pop(pilha_primeiros);
            }
        }

        float descarte; 
        int aux_linha = num_linhas;
        int aux_coluna = 1;

        no_pilha = pop(pilha);

        while (no_pilha != NULL) {
            if (no_pilha->caractere == '|') {
                aux_linha--;
                aux_coluna = 1;
            } else {
                matriz->dados[aux_linha][aux_coluna] = no_pilha->value;
                aux_coluna++;
            }
            free(no_pilha);
            no_pilha = pop(pilha);
        }
    }

    clear_stack(pilha_primeiros);
    clear_stack(pilha);
}

#include <stdio.h>

#include <stdio.h>

void imprimir_matriz(Matriz *matrix) {
    // Verifica se a matriz está alocada corretamente
    if (matrix == NULL) {
        printf("Matriz não alocada.\n");
        return;
    }

    if (matrix->colunas == 1) {
        printf("\n");
        printf("+-");
        for (int i = 0; i < matrix->colunas*8; i++) {
            printf(" ");
        }
        printf("-+\n");
        // Percorre a matriz e imprime cada elemento
        for (int i = 0; i < matrix->linhas; i++) {
            printf("|");
            for (int j = 0; j < matrix->colunas; j++) {
                printf(" %f", matrix->dados[i][j]);
            }
            printf(" |\n");
        }
        printf("+-");
        for (int i = 0; i < matrix->colunas*8; i++) {
            printf(" ");
        }
        printf("-+\n");
    } 
    else 
    {
        printf("\n");
        printf("+-");
        for (int i = 0; i < matrix->colunas*8; i++) {
            printf(" ");
        }
        printf("-+\n");
        // Percorre a matriz e imprime cada elemento
        for (int i = 0; i < matrix->linhas; i++) {
            printf("|");
            for (int j = 0; j < matrix->colunas; j++) {
                printf(" %f", matrix->dados[i][j]);
            }
            printf(" |\n");
        }
        printf("+-");
        for (int i = 0; i < matrix->colunas*8; i++) {
            printf(" ");
        }
        printf("-+\n");
    }
}


void liberar_matriz(Matriz *matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        free(matriz->dados[i]);
    }
    free(matriz->dados);
    free(matriz);
    printf("saiu do libera");
}