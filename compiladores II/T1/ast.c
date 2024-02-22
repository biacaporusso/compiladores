#include "ast.h"
#include <sintatico.tab.h>

float RPN_Walk(TreeNode* aux) {

    float resultado = 0;

    if(aux) {

        float valor_esquerdo = RPN_Walk(aux->left);
        float valor_direito = RPN_Walk(aux->right);

        switch(aux->node_type) {
            case ADICAO: 
                /*if (aux->right == NULL)
                    //unario
                else */
                resultado = valor_esquerdo + valor_direito;
                break;
            case SUBTRACAO:
                resultado = valor_esquerdo - valor_direito;
                break;
            case MULTIPLICACAO:
                printf(" ");
                break;
            case DIVISAO:
                printf(" ");
                break;
            case POTENCIACAO:
                printf(" ");
                break;
            case RESTO_DIVISAO:
                printf(" ");
                break;
            case NUMERO_INTEIRO:
                resultado = (float) aux->value_int;
                break;
            case NUMERO_REAL:
                resultado = aux->value_float;
                break;
            case IDENTIFICADOR:
                break;
                //verifica na hash se identificador tem valor atribuido 
                    // se sim, valor_esquerda = valor
            default:
                printf("ERROR: INVALID TYPE ");
                break;
        }
    }
    return resultado;
}

void Delete_Tree(TreeNode* aux) {

    if(aux) {

        Delete_Tree(aux->left);
        Delete_Tree(aux->right);
        free(aux);
    }
}