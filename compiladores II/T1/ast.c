#include "ast.h"
#include <sintatico.tab.h>
#include <math.h>
#include "hash.h"
#include <string.h>
#include "settings.h"

float RPN_Walk(TreeNode* aux, HashTable* hash) {

    float resultado = 0;

    if(aux) {

        float valor_esquerdo = RPN_Walk(aux->left, hash);
        float valor_direito = RPN_Walk(aux->right, hash);

        if((aux->left->node_type == NUMERO_REAL && aux->right->node_type == NUMERO_REAL) || 
        (aux->left->node_type == NUMERO_INTEIRO && aux->right->node_type == NUMERO_INTEIRO)) {
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
                    resultado = valor_esquerdo * valor_direito;
                    break;
                case DIVISAO:
                    resultado = valor_esquerdo / valor_direito;
                    break;
                case POTENCIACAO:
                    resultado = pow(valor_esquerdo, valor_direito);
                    break;
                case RESTO_DIVISAO:
                    resultado = (int)valor_esquerdo % (int)valor_direito;
                    break;
                case NUMERO_INTEIRO:
                    resultado = (float) aux->value_int;
                    break;
                case NUMERO_REAL:
                    resultado = aux->value_float;
                    break;
                case SEN:
                    resultado = (float)sin(valor_esquerdo);        // fix
                    break;
                case COS:
                    resultado = cos(valor_esquerdo);
                    break;
                case TAN:
                    resultado = tan(valor_esquerdo);
                    break;
                case ABS:
                    if (valor_esquerdo < 0)
                        resultado = -valor_esquerdo;
                    else
                        resultado = valor_esquerdo;
                    break;
                case IDENTIFICADOR:
                    //verifica na hash se identificador tem valor atribuido 
                    // se sim, valor_esquerda = valor
                    /*if(search_hash(hash, aux->value_string) == -1) {
                        printf("Undefined symbol [%s]", aux->value_string);
                    } else {
                        //aux->left = get_value(hash, aux->value_string);
                        resultado = get_value(hash, aux->value_string);
                    }*/
                    if(search_hash(hash, aux->value_string) != -1) {
                        resultado = get_value(hash, aux->value_string);
                    } 
                    break;
                default:
                    printf("ERROR: INVALID TYPE ");
                    break;

            } 
        } else {
            printf("Incorrect type for operator '%d' - have %d and %d\n", aux->node_type, aux->left->node_type, aux->right->node_type);
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

TreeNode* create_ast_node(int node_type, int value_int, float value_float, char* value_string, TreeNode* left, TreeNode* right) {
    
    TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
    aux->node_type = node_type;
    aux->value_int = value_int;
    aux->value_float = value_float;
    if(value_string)
    {
        strcpy(aux->value_string, value_string);
    }
    aux->left = left;
    aux->right = right;

    return aux;
}


/*
void plot(TreeNode* aux, Settings* settings, HashTable* hash) {
    
	char display[25][80];
	int i, j;
	float k;
	float result;
	int xDisplay = 0, yDisplay;

	for(i=0; i < 25; i++) {
		for(j=0; j < 80; j++) {
			display[i][j] = ' ';
		}
	}

	if(settings->draw_axis) {
		for(i=0; i < 25; i++) {
			display[i][40] = '|';
		}

		for(j=0; j < 80; j++) {
			display[12][j] = '-';
		}
		display[12][40] = '*';
	}

	for(k = settings->h_view_lo; k< settings->h_view_hi; k = k + ((settings->h_view_hi + abs(settings->h_view_lo)) / 80)) {
		if(xDisplay >= 80)
			break;

		result = RPN_Walk(aux, hash);
		
		yDisplay = 12 - round(result/((settings->v_view_hi + abs(settings->v_view_lo)) / 25));

		if(yDisplay < 0 || yDisplay > 24) {
			xDisplay ++;
			continue;
		}

		display[yDisplay][xDisplay] = '*';
		xDisplay++;
	}

	for(i=0; i < 25; i++) {
		for(j=0; j < 80; j++) {
			printf("%c", display[i][j]);
		}
	}	
}
*/