#ifndef AST_C_AST_H
#define AST_C_AST_H 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"
#include <string.h>
#include "settings.h"

typedef struct node TreeNode;
struct node {
    int node_type;
    int value_int;
    float value_float;
    char value_string[1024];
    TreeNode* left;
    TreeNode* right;
};

float RPN_Walk(TreeNode* aux, HashTable* hash);
void Delete_Tree(TreeNode* aux);
TreeNode* create_ast_node(int node_type, int value_int, float value_float, char* value_string, TreeNode* left, TreeNode* right);
//void plot(TreeNode* aux, Settings* settings, HashTable* hash);

#endif