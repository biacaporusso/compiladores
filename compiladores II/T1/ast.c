#include <ast.h>
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

        //if((aux->left->node_type == NUMERO_REAL && aux->right->node_type == NUMERO_REAL) || 
        //(aux->left->node_type == NUMERO_INTEIRO && aux->right->node_type == NUMERO_INTEIRO)) {
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
			printf("entrou no case\n");
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
        /*}  else {
            printf("Incorrect type for operator '%d' - have %d and %d\n", aux->node_type, aux->left->node_type, aux->right->node_type);
        } */
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

float matrixX[10][10];
int largura, altura;

int create_matrix(TreeNode* mat) {
	largura=1;
	altura=1;
	int i, j;
	TreeNode *aux, *aux2;

	// inicializa a matriz com 0
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            matrixX[i][j] = 0.0;
        }
    }

	i = 0; j = 0;

	aux = mat;
	while(aux != NULL) {

		if(i >= 10) {	//qtde maxima de linhas 
			return 1;
		}
		if(altura < i+1){
			altura = i+1;
		}
		matrixX[i][j] = aux->value_float;
		aux2 = aux->left;
		while(aux2 != NULL) {
			j++;
			if(j >= 10) {
				return 1;
			}
			matrixX[i][j] = aux2->value_float;
			if(largura < j+1){
				largura = j+1;
			}
			aux2 = aux2->right;
		}
		j = 0;
		i++;
		aux = aux->right;
	}
	return 0;
}

void show_matrix() {
	int i, j, aumento = 0;

	int vetorAumentos[largura];
	for(i = 0; i < largura; i++) {
		vetorAumentos[i] = 0;
	}

	i =0; j = 0;
	while(i < largura) {
		while(j < altura) {
			if(matrixX[j][i] < 0) {
				aumento ++;
				vetorAumentos[i] = 1;
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}

	printf("\n+-");
	for(i = 0; i <largura*10+aumento; i++) {
		printf(" ");
	}
	printf(" -+\n");

	for(i=0;i<altura;i++) {
		printf("|  ");
		for(j=0;j<largura;j++) {
			if(matrixX[i][j] < 0) {
				printf("%f ", matrixX[i][j]);
			} else {
				if(vetorAumentos[j] > 0) {
					printf(" %f ", matrixX[i][j]);
				} else {
					printf("%f ", matrixX[i][j]);
				}
			}

		}
		printf(" |\n");
	}

	printf("+-");
	for(i = 0; i <largura*10+aumento; i++) {
		printf(" ");
	}
	printf(" -+\n\n");
}

int solve_determinant() {
	if(largura != altura) {
		return 1;
	}

	float matriz[largura][largura];
	int i, j;
	for(i=0; i<largura; i++) {
        for(j=0; j<largura; j++) {
            matriz[i][j] = matrixX[i][j];
        }
    }

	printf("\n%f\n\n", laplace(largura, matriz));

	return 0;
}

float laplace(int tamanho, float matriz[tamanho][tamanho]) {
	if(tamanho == 1) {
		return matriz[0][0];
	} else {
		float det = 0;
		float fator;
		int i, j, k, l, m;
        
		// percorrendo linhas
        for(i = 0; i < tamanho; i++){
			// se o elemento da matriz for diferente de 0 (se for 0, det = 0 tbm)
            if (matriz[0][i] != 0) {
                float aux[tamanho - 1][tamanho - 1];
                k = 0, j = 0;            
                for(l = 1; l < tamanho; l++){
                    for(m = 0; m < tamanho; m++){
                        if(m != i){
                            aux[k][j] = matriz[l][m];
                            j++;
                        }
                    }
                    k++;
                    j = 0;
                }
				if(i % 2 == 0) {
					fator = matriz[0][i];
				} else {
					fator = -matriz[0][i];
				}
                det = det + fator * laplace(tamanho - 1, aux);
            }
        }
		return det;
	}
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