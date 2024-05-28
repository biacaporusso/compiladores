#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <hash.h>
#include <sintatico.tab.h>
#include <hash.h>


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
HashNode *create_hash_node(char *key, float value, int tipo, Matriz* matriz) {
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->type = tipo;

    if(matriz)
    {
    Matriz* copia;
        copia = copia_matriz(matriz);
        newNode->valor_matriz = copia;
    }
    newNode->next = NULL;
    return newNode;
}

Matriz* copia_matriz(Matriz* original) {
    Matriz* copia = create_matrix();
    copia->linhas = original->linhas;
    copia->colunas = original->colunas;

    copia->dados = (float**)malloc(original->linhas * sizeof(float*));
    for(int i=0; i<original->linhas; i++) {
        copia->dados[i] = (float*)malloc(original->colunas * sizeof(float));
        for (int j=0; j<original->colunas; j++) {
            copia->dados[i][j] = original->dados[i][j];
        }
    }

    return copia;
}

// Função para inserir um par chave-valor na tabela hash
void inserir_hash(HashTable *ht, char *key, float value, int tipo, Matriz* matriz) {

    int index = calculo_hash(key);
    HashNode *current = ht->table[index];
    HashNode *prev = NULL;
    
    // Percorrer a lista encadeada na posição hash correspondente
    while (current != NULL) {
        // Se a chave já existe, atualiza o valor e retorna
        if (strcmp(current->key, key) == 0) {
            current->type = tipo;
            if(tipo == MATRIX) {
                free_matriz(current->valor_matriz);
                current->valor_matriz = copia_matriz(matriz);
            } else if (tipo == NUMERO_INTEIRO || tipo == NUMERO_REAL) {
                current->value = value;
            }
            return;
        }
        // Avança para o próximo nó na lista encadeada
        prev = current;
        current = current->next;
    }

    // Se a chave não existir, insere um novo nó no início da lista encadeada
    HashNode *newNode = create_hash_node(key, value, tipo, matriz);
    if (prev == NULL) {
        // Se prev for NULL, significa que a lista está vazia
        ht->table[index] = newNode;
    } else {
        // Caso contrário, insira o novo nó após o nó anterior
        prev->next = newNode;
    }
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

HashNode* get_node_hash(HashTable* hash, char* key) {
    int index = calculo_hash(key);
    HashNode *node = hash->table[index];

    // Percorre a lista encadeada no índice correspondente da tabela hash
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node; // Retorna o nó se a chave for encontrada
        }
        node = node->next;
    }

    return NULL; // Retorna NULL se a chave não for encontrada

}

void set_value(HashTable *hash_table, char *key, float value) {
    int index = calculo_hash(key);
    HashNode *node = hash_table->table[index];

    // Percorre a lista encadeada no índice correspondente da tabela hash
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            node->value = value; // Retorna o valor se a chave for encontrada
            return;
        }
        node = node->next;
    }
}

// Função para imprimir a tabela hash
void printar_hash(HashTable *ht) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        HashNode *current = ht->table[i];
        while (current != NULL) {
            switch (current->type) {
                case NUMERO_REAL:
                    printf("%s - FLOAT\n", current->key);
                    break;
                case NUMERO_INTEIRO:
                    printf("%s - FLOAT\n", current->key);
                    break;
                case MATRIX:
                    printf("%s - MATRIX[%d][%d]\n", current->key, current->valor_matriz->linhas, current->valor_matriz->colunas);
                    break;
                default:
                    printf("tipo de no da hash invalido\n");
                    break;
            }
        
            current = current->next;
        }
    }
}

void free_hash(HashTable *hash_table) {
    if (hash_table == NULL)
        return;

    for (int i = 0; i < SIZE; i++) {
        HashNode *current_node = hash_table->table[i];
        while (current_node != NULL) {
            HashNode *temp = current_node;
            current_node = current_node->next;
            free(temp->key); // Free the key string
            free(temp->valor_matriz); // Free the matriz struct
            free(temp); // Free the node itself
        }
    }

    // Free the hash table structure itself
    free(hash_table);
}

int get_tipo(HashTable *hash_table, char *key) {
    int index = calculo_hash(key);
    HashNode *node = hash_table->table[index];

    // Percorre a lista encadeada no índice correspondente da tabela hash
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->type; // Retorna o valor se a chave for encontrada
        }
        node = node->next;
    }

    return -1; // Retorna -1 se a chave não for encontrada
}

Matriz* get_matriz_hash(HashTable *hash_table, char *key) {
    int index = calculo_hash(key);
    HashNode *node = hash_table->table[index];

    // Percorre a lista encadeada no índice correspondente da tabela hash
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->valor_matriz; // Retorna o valor se a chave for encontrada
        }
        node = node->next;
    }

    return NULL; // Retorna -1 se a chave não for encontrada
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

int insert_matrix(Matriz *matriz, Pilha* pilha_primeiros, Pilha* pilha, int num_linhas, int num_colunas) {

    int descarte;

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

        Node* no_pilha;

        // Insert first values from pilha_primeiros into matrix
        for (int i = 0; i < num_linhas; i++) {
            if (pilha_primeiros->top != NULL) {
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

        return 1;

    } else {
        printf("\nERROR: Matrix limits out of boundaries.\n");
        return 0;
    }
}

void imprimir_matriz(Matriz *matrix, Settings* settings) {
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
        int actual_precision = (int) settings->float_precision;
        for (int i = 0; i < matrix->linhas; i++) {
            printf("|");
            for (int j = 0; j < matrix->colunas; j++) {
                printf(" %.*f", actual_precision, matrix->dados[i][j]);
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

float calculo_determinante(Matriz *matriz) {
  // Check if the matrix is square
  if (matriz->linhas != matriz->colunas) {
    return 0.0; // Determinant of non-square matrix is 0
  }

  // Base case for 1x1 matrix
  if (matriz->linhas == 1) {
    return matriz->dados[0][0];
  }

  // Recursive case for larger matrices (using cofactor expansion)
  float det = 0.0;
  for (int i = 0; i < matriz->colunas; i++) {
    // Create sub-matrix excluding the first row and i-th column
    Matriz *sub_matrix = create_matrix();
    sub_matrix->linhas = matriz->linhas - 1;
    sub_matrix->colunas = matriz->colunas - 1;
    sub_matrix->dados = (float**)malloc(sizeof(float*) * (sub_matrix->linhas));
    for (int j = 1; j < matriz->linhas; j++) {
      sub_matrix->dados[j - 1] = (float*)malloc(sizeof(float) * (sub_matrix->colunas));
      int k = 0;
      // Copy elements excluding the i-th column from the corresponding row
      for (int col = 0; col < matriz->colunas; col++) {
        if (col != i) {
          sub_matrix->dados[j - 1][k++] = matriz->dados[j][col];
        }
      }
    }

    // Calculate cofactor and add to determinant
    float cofactor = ((i % 2) == 0) ? 1.0 : -1.0;
    det += cofactor * calculo_determinante(sub_matrix) * matriz->dados[0][i];

    // Free memory allocated for sub-matrix
    for (int j = 0; j < sub_matrix->linhas; j++) {
      free(sub_matrix->dados[j]);
    }
    free(sub_matrix->dados);
    free(sub_matrix);
  }

  return det;
}

int calculo_sistema_linear(Matriz* matriz) {
	if(matriz->colunas-1 != matriz->linhas) {
		return 1;
	}

	Matriz* aux = create_matrix();
    aux->linhas = matriz->linhas;
    aux->colunas = matriz->colunas;

	int i, j;
    if (aux->dados == NULL) {
        aux->dados = (float**)malloc(aux->linhas * sizeof(float*));
        for(i=0;i<matriz->linhas;i++) {
            aux->dados[i] = (float*)malloc(aux->colunas * sizeof(float));
            for(j=0;j<matriz->colunas;j++) {
                aux->dados[i][j] = matriz->dados[i][j];
            }
        }
    }

	LU(aux);

	return 0;
}

void LU(Matriz* matriz) {

    Matriz* l = create_matrix();
    l->linhas = matriz->linhas;
    l->colunas = matriz->linhas;
    l->dados = (float**)malloc(l->linhas * sizeof(float*));

    Matriz* u = create_matrix();
    u->linhas = matriz->linhas;
    u->colunas = matriz->linhas;
    u->dados = (float**)malloc(u->linhas * sizeof(float*));

    int n = matriz->linhas;
    int i, j, k;

    float values[matriz->linhas];
	float divisions[matriz->linhas];

    for (i = 0; i < n; i++) {
        l->dados[i] = (float*)malloc(l->colunas * sizeof(float));
        u->dados[i] = (float*)malloc(u->colunas * sizeof(float));
        for (j = 0; j < n; j++) {
            u->dados[i][j] = matriz->dados[i][j];
            if(i == j) {
                l->dados[i][j] = 1;
            } else {
                l->dados[i][j] = 0;
            }
        }
    }

    for (j = 0; j < n-1; j++) {
        for(i=j+1; i < n; i++) {
            l->dados[i][j] = u->dados[i][j] / u->dados[j][j];
            for(k=j+1; k < n; k++) {
                u->dados[i][k] = u->dados[i][k] - l->dados[i][j]*u->dados[j][k];
            }
            u->dados[i][j] = 0;
        }
    }

	for(i=0; i < n; i++) {
        for(j=i+1; j < n; j++) {
            for(k= 0; k < n; k++) {
                if(fmod(matriz->dados[i][k], matriz->dados[j][k]) != 0 && fmod(matriz->dados[j][k], matriz->dados[i][k]) != 0) {
                    break;
                }
                if(matriz->dados[i][k] > matriz->dados[j][k]) {
                    divisions[k] = matriz->dados[i][k]/matriz->dados[j][k];
                } else {
                    divisions[k] = matriz->dados[j][k]/matriz->dados[i][k];
                }
            }

            for(k= 0; k < n; k++) {

                if(divisions[k] != divisions[0]) {
                    break;
                }
                if(k == n-1 && (matriz->dados[i][n]/divisions[0] == matriz->dados[j][n] || matriz->dados[j][n]/divisions[0] == matriz->dados[i][n])) {
                    printf("\nSPI - The Linear System has infinitely many solutions\n");
                    return;
                } else if(k == n-1 && (matriz->dados[i][n]/divisions[0] != matriz->dados[j][n] && matriz->dados[j][n]/divisions[0] != matriz->dados[i][n])) {
                    printf("\nSI - The Linear System has no solution\n");
                    return;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
       values[i] = 5532;
    }

    for(i=0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if(l->dados[i][j] == 0) {
                continue;
            }

            if(values[j] != 5532) {
                matriz->dados[i][3] -= l->dados[i][j]*values[j];
            } else {
                values[i] = matriz->dados[i][3]/l->dados[i][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
       values[i] = 5532;
    }

    for(i=n-1; i >=0; i--) {
        for (j = n-1; j >= 0; j--) {
            if(u->dados[i][j] == 0) {
                continue;
            }

            if(values[j] != 5532) {
                matriz->dados[i][3] -= u->dados[i][j]*values[j];
            } else {
                values[i] = matriz->dados[i][3]/u->dados[i][j];
            }
        }
    }

	printf("\nMatrix x:\n\n");
    
    for (i = 0; i < n; i++) {
        printf("%.6f\n", values[i]);
    }
	//printf("\n");
}


void free_matriz(Matriz *matriz) {

    if(matriz == NULL)
        return;
    for (int i = 0; i < matriz->linhas; i++) {
        free(matriz->dados[i]);
    }
    free(matriz->dados);
    free(matriz);
}