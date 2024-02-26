//#define _AST_H_INCLUDED 1
#ifndef AST_C_AST_H
#define AST_C_AST_H 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node TreeNode;
struct node {
    int node_type;
    int value_int;
    float value_float;
    char value_string[1024];
    TreeNode* left;
    TreeNode* right;
};

float RPN_Walk(TreeNode* aux);
void Delete_Tree(TreeNode* aux);

#endif