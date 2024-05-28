#ifndef AST_C_AST_H
#define AST_C_AST_H 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "hash.h"
#include <string.h>
#include "settings.h"

typedef struct hash_table HashTable;
typedef struct matriz Matriz;

typedef struct node TreeNode;
struct node {
    int node_type;
    int value_int;
    float value_float;
    char value_string[1024];
    TreeNode* left;
    TreeNode* right;
};

typedef struct result Result;
struct result {
    float value;
    int type;
    Matriz* matriz;
};

Result* RPN_Walk(TreeNode* aux, HashTable* hash);
float comando_RPN(TreeNode* aux, HashTable* hash, Settings* settings);
void Delete_Tree(TreeNode* aux);
TreeNode* create_ast_node(int node_type, int value_int, float value_float, char* value_string, TreeNode* left, TreeNode* right);
void plot(TreeNode* aux, Settings* settings, HashTable* hash);

void soma_matriz(Result* r_esquerda, Result* r_direita, HashTable* hash, Result* result);
void subtracao_matriz(Result* r_esquerda, Result* r_direita, HashTable* hash, Result* result);
void multiplicacao_matriz(Result* m_left, Result* m_right, HashTable* hash, Result* result);
void multiplicacao2_matriz(TreeNode* m_esquerda, TreeNode* valor_direita, HashTable* hash, Result* result);
void multiplicacao3_matriz(TreeNode* valor_esquerda, TreeNode* m_direita, HashTable* hash, Result* result);
void set_X(float value);
void plot(TreeNode* aux, Settings* settings, HashTable* hash);
void free_result(Result* result);

Result* RPN_identifier(TreeNode* aux, HashTable* hash);

#endif