#include <ast.h>
#include <sintatico.tab.h>
#include <math.h>
#include "hash.h"
#include <string.h>
#include "settings.h"

float global_X;
int erro_eval_exp = 0;

Result* RPN_Walk(TreeNode* aux, HashTable* hash) {

	Result* resultado = (Result*)malloc(sizeof(Result));

    if(aux) {

        Result* valor_esquerdo = RPN_Walk(aux->left, hash);
        Result* valor_direito = RPN_Walk(aux->right, hash);

        //if((aux->left->node_type == NUMERO_REAL && aux->right->node_type == NUMERO_REAL) || 
        //(aux->left->node_type == NUMERO_INTEIRO && aux->right->node_type == NUMERO_INTEIRO)) {
		switch(aux->node_type) {
			case ADICAO: 
				if ((valor_esquerdo->type == NUMERO_REAL && valor_direito->type == NUMERO_REAL) ||
				(valor_esquerdo->type == NUMERO_INTEIRO  && valor_direito->type == NUMERO_REAL) ||
				(valor_esquerdo->type == NUMERO_REAL     && valor_direito->type == NUMERO_INTEIRO) ||
				(valor_esquerdo->type == NUMERO_INTEIRO  && valor_direito->type == NUMERO_INTEIRO)) {
					resultado->value = valor_esquerdo->value + valor_direito->value;
					resultado->type = NUMERO_REAL;
				} else if(valor_esquerdo->type == MATRIX && valor_direito->type == MATRIX) {
					soma_matriz(valor_esquerdo, valor_direito, hash, resultado);
				} else {
					if(erro_eval_exp==0)
					{
						//erro_eval_exp = 1;
						if(valor_esquerdo->type == NUMERO_REAL || valor_esquerdo->type == NUMERO_INTEIRO)
							printf("\nIncorrect type for operator '+' - have FLOAT and MATRIX\n");
						else 
							printf("\nIncorrect type for operator '+' - have MATRIX and FLOAT\n");
					}
				}
				break;
			case SUBTRACAO:
				if ((valor_esquerdo->type == NUMERO_REAL && valor_direito->type == NUMERO_REAL) ||
				(valor_esquerdo->type == NUMERO_INTEIRO  && valor_direito->type == NUMERO_REAL) ||
				(valor_esquerdo->type == NUMERO_REAL     && valor_direito->type == NUMERO_INTEIRO) ||
				(valor_esquerdo->type == NUMERO_INTEIRO  && valor_direito->type == NUMERO_INTEIRO)) {
					resultado->value = valor_esquerdo->value - valor_direito->value;
					resultado->type = NUMERO_REAL;
				} else if(valor_esquerdo->type == MATRIX && valor_direito->type == MATRIX) {
					subtracao_matriz(valor_esquerdo, valor_direito, hash, resultado);
				} else {
					if(erro_eval_exp==0)
					{
						//erro_eval_exp = 1;

						if(valor_esquerdo->type == NUMERO_REAL || valor_esquerdo->type == NUMERO_INTEIRO)
							printf("\nIncorrect type for operator '-' - have FLOAT and MATRIX\n");
						else 
							printf("\nIncorrect type for operator '-' - have MATRIX and FLOAT\n");
					}
				}
				break;
			case MULTIPLICACAO:
				if ((valor_esquerdo->type == NUMERO_REAL && valor_direito->type == NUMERO_REAL) ||
				(valor_esquerdo->type == NUMERO_INTEIRO  && valor_direito->type == NUMERO_REAL) ||
				(valor_esquerdo->type == NUMERO_REAL     && valor_direito->type == NUMERO_INTEIRO) ||
				(valor_esquerdo->type == NUMERO_INTEIRO  && valor_direito->type == NUMERO_INTEIRO)) {
					resultado->value = valor_esquerdo->value * valor_direito->value;
					resultado->type = NUMERO_REAL;
				} else if(valor_esquerdo->type == MATRIX && valor_direito->type == MATRIX) {
					//resultado = multiplicacao_matriz(aux->left, aux->right, hash);
					//resultado->type = MATRIX;
					multiplicacao_matriz(valor_esquerdo, valor_direito, hash, resultado);
				} else if((valor_esquerdo->type == MATRIX && valor_direito->type == NUMERO_REAL) ||
				(valor_esquerdo->type == MATRIX && valor_direito->type == NUMERO_INTEIRO)) {
					//resultado = multiplicacao2_matriz(aux->left, aux->right, hash);
					//resultado->type = MATRIX;
					multiplicacao2_matriz(aux->left, aux->right, hash, resultado);
				} else if((valor_esquerdo->type == NUMERO_REAL && valor_direito->type == MATRIX) ||
				(valor_esquerdo->type == NUMERO_INTEIRO  && valor_direito->type == MATRIX)){
					//resultado = multiplicacao3_matriz(aux->left, aux->right, hash);
					//resultado->type = MATRIX;
					multiplicacao3_matriz(aux->left, aux->right, hash, resultado);
				} 
				break;
			case DIVISAO:
				resultado->value = valor_esquerdo->value / valor_direito->value;
				resultado->type = NUMERO_REAL;
				break;
			case POTENCIACAO:
				resultado->value = pow(valor_esquerdo->value, valor_direito->value);
				resultado->type = NUMERO_REAL;
				break;
			case RESTO_DIVISAO:
				resultado->value = (int)valor_esquerdo->value % (int)valor_direito->value;
				resultado->type = NUMERO_REAL;
				break;
			case NUMERO_INTEIRO:
				resultado->value = (float) aux->value_int;
				resultado->type = NUMERO_REAL;
				break;
			case NUMERO_REAL:
				resultado->value = aux->value_float;
				resultado->type = NUMERO_REAL;
				break;
			case SEN:
				//float valor_grau = (float)valor_esquerdo->value * 3.141592 / 180;
				//resultado->value = valor_grau;     // fix
				if(valor_esquerdo->type != MATRIX) {
					resultado->value = (float)sin(valor_esquerdo->value);
					resultado->type = NUMERO_REAL;
				} else {
					if(erro_eval_exp==0)
					{
						erro_eval_exp = 1;
						printf("\nIncorrect type for operator 'SEN' - have MATRIX\n");
					}
				}
				break;
			case COS:
				if(valor_esquerdo->type != MATRIX) {
					resultado->value = cos(valor_esquerdo->value);
					resultado->type = NUMERO_REAL;
				} else {
					if(erro_eval_exp==0)
					{
						erro_eval_exp = 1;
						printf("\nIncorrect type for operator 'COS' - have MATRIX\n");
					}
				}
				break;
			case TAN:
				if(valor_esquerdo->type != MATRIX) {
					resultado->value = tan(valor_esquerdo->value);
					resultado->type = NUMERO_REAL;
				} else {
					if(erro_eval_exp==0)
					{
						erro_eval_exp = 1;
						printf("\nIncorrect type for operator 'TAN' - have MATRIX\n");
					}
				}
				break;
			case ABS:
				if(valor_esquerdo->type != MATRIX) {
					if (valor_esquerdo->value < 0)
						resultado->value = -valor_esquerdo->value;
					else {
						resultado->value = valor_esquerdo->value;
						resultado->type = NUMERO_REAL;
					}
				} else {
					if(erro_eval_exp==0)
					{
						erro_eval_exp = 1;
						printf("\nIncorrect type for operator 'ABS' - have MATRIX\n");
					}
				}
				break;
			case IDENTIFICADOR:
				HashNode* node_aux = get_node_hash(hash, aux->value_string);
				if(node_aux) {
					if(node_aux->type == NUMERO_REAL || node_aux->type == NUMERO_INTEIRO) {
						resultado->value = node_aux->value;
						resultado->type = NUMERO_REAL;
					} else if(node_aux->type == MATRIX) {
						resultado->matriz = copia_matriz(node_aux->valor_matriz);
						resultado->type = MATRIX;
					}
				} 
				break;
			case X:
				resultado->value = global_X;
				resultado->type = NUMERO_REAL;
				break;
			case MATRIX:
				resultado->matriz = get_matriz_hash(hash, aux->value_string);
				//resultado->type = X;   n sei oq é aqui
			default:
				printf("ERROR: INVALID TYPE ");
				break;

		} 
    }
    return resultado;
}

Result* RPN_identifier(TreeNode* aux, HashTable* hash) {

	Result* resultado = (Result*)malloc(sizeof(Result));
	resultado->value = 0;
	// result = 0 -> tudo certo
	// result = 1 -> erro
	if(aux) {

		Result* valor_esquerdo = RPN_identifier(aux->left, hash);
        Result* valor_direito = RPN_identifier(aux->right, hash);
		switch(aux->node_type) {
			case IDENTIFICADOR:
				if(search_hash(hash, aux->value_string) == -1) {
					printf("\nUndefined symbol [%s]", aux->value_string);
					resultado->value = 1;
					return resultado;
				} else {
					resultado->value = 0;
				}
				break;
			case X:
				printf("\nThe x variable cannot be present on expressions.\n");
				resultado->value = 1;
				return resultado;
				break;
			default:
				//resultado->value = 0;
				break;
		}
		if(valor_esquerdo)
			resultado->value = resultado->value || valor_esquerdo->value;
		if(valor_direito)
			resultado->value = resultado->value || valor_direito->value;
	}

	return resultado;
}

void soma_matriz(Result* r_esquerda, Result* r_direita, HashTable* hash, Result* result) {

	//Result* result = (Result*)malloc(sizeof(Result));
	Matriz* result_matriz = create_matrix();

	if(r_esquerda->matriz->linhas == r_direita->matriz->linhas) {
		if(r_esquerda->matriz->colunas ==  r_direita->matriz->colunas) {

			int linhas = r_esquerda->matriz->linhas;
			int colunas = r_esquerda->matriz->colunas;

			result_matriz->linhas = linhas;
			result_matriz->colunas = colunas;

			result_matriz->dados = (float**)malloc(linhas * sizeof(float*));
			for (int i=0; i<linhas; i++) {
				result_matriz->dados[i] = (float*)malloc(colunas * sizeof(float));
				for (int j=0; j<colunas; j++) {
					result_matriz->dados[i][j] = r_esquerda->matriz->dados[i][j] + r_direita->matriz->dados[i][j];
				}
			}
		} else {
					if(erro_eval_exp==0)
					{
						erro_eval_exp = 1;
						printf("\nIncorrect dimensions for operator ’+’ - have MATRIX [%d][%d] and MATRIX [%d][%d]", r_esquerda->matriz->linhas, r_esquerda->matriz->colunas, r_direita->matriz->linhas, r_direita->matriz->colunas);
					}
		} 
	} else {
					if(erro_eval_exp==0)
					{
						erro_eval_exp = 1;
						printf("\nIncorrect dimensions for operator ’+’ - have MATRIX [%d][%d] and MATRIX [%d][%d]", r_esquerda->matriz->linhas, r_esquerda->matriz->colunas, r_direita->matriz->linhas, r_direita->matriz->colunas);
					}
	
	}
	result->matriz = copia_matriz(result_matriz);
	free_matriz(result_matriz);
	//result->matriz = result_matriz;
	result->type = MATRIX;
	//return result;
}

void subtracao_matriz(Result* r_esquerda, Result* r_direita, HashTable* hash, Result* result) {

	Matriz* result_matriz = create_matrix();

	if(r_esquerda->matriz->linhas == r_direita->matriz->linhas) {
		if(r_esquerda->matriz->colunas ==  r_direita->matriz->colunas) {

			int linhas = r_esquerda->matriz->linhas;
			int colunas = r_esquerda->matriz->colunas;

			result_matriz->linhas = linhas;
			result_matriz->colunas = colunas;

			result_matriz->dados = (float**)malloc(linhas * sizeof(float*));
			for (int i=0; i<linhas; i++) {
				result_matriz->dados[i] = (float*)malloc(colunas * sizeof(float));
				for (int j=0; j<colunas; j++) {
					result_matriz->dados[i][j] = r_esquerda->matriz->dados[i][j] - r_direita->matriz->dados[i][j];
				}
			}
		} else {
			if(erro_eval_exp==0)
					{
						erro_eval_exp = 1;
						printf("\nIncorrect dimensions for operator ’-’ - have MATRIX [%d][%d] and MATRIX [%d][%d]", r_esquerda->matriz->linhas, r_esquerda->matriz->colunas, r_direita->matriz->linhas, r_direita->matriz->colunas);
						//return;
					}
		} 
	} else {
		if(erro_eval_exp==0)
					{
						erro_eval_exp = 1;
						printf("\nIncorrect dimensions for operator ’-’ - have MATRIX [%d][%d] and MATRIX [%d][%d]", r_esquerda->matriz->linhas, r_esquerda->matriz->colunas, r_direita->matriz->linhas, r_direita->matriz->colunas);
						//return;
					}
	
	}
	result->matriz = copia_matriz(result_matriz);
	free_matriz(result_matriz);
	//result->matriz = result_matriz;
	result->type = MATRIX;
	//return result;
}

void multiplicacao_matriz(Result* m_left, Result* m_right, HashTable* hash, Result* result) {

    //Result* result = (Result*)malloc(sizeof(Result));
    Matriz* result_matriz = create_matrix();

    //Matriz* m_left = get_matriz_hash(hash, m_esquerda->value_string);
    //Matriz* m_right = get_matriz_hash(hash, m_direita->value_string);

    if (m_left->matriz->colunas == m_right->matriz->linhas) {
        int linhas = m_left->matriz->linhas;
        int colunas = m_right->matriz->colunas;
        int inner = m_left->matriz->colunas;

        result_matriz->linhas = linhas;
        result_matriz->colunas = colunas;

        result_matriz->dados = (float**)malloc(linhas * sizeof(float*));
        for (int i = 0; i < linhas; i++) {
            result_matriz->dados[i] = (float*)malloc(colunas * sizeof(float));
            for (int j = 0; j < colunas; j++) {
                result_matriz->dados[i][j] = 0; // Initialize the element to zero
                for (int k = 0; k < inner; k++) {
                    result_matriz->dados[i][j] += m_left->matriz->dados[i][k] * m_right->matriz->dados[k][j];
                }
            }
        }
    } else if (m_left->matriz->linhas == 1 && m_left->matriz->colunas == 1) {
		int linhas = m_right->matriz->linhas;
		int colunas = m_right->matriz->colunas;

		result_matriz->linhas = linhas;
		result_matriz->colunas = colunas;

		result_matriz->dados = (float**)malloc(linhas * sizeof(float*));
		for (int i = 0; i < linhas; i++) {
			result_matriz->dados[i] = (float*)malloc(colunas * sizeof(float));
			for (int j = 0; j < colunas; j++) {
				result_matriz->dados[i][j] = m_left->matriz->dados[0][0] * m_right->matriz->dados[i][j];
			}
		}
	} else if (m_right->matriz->linhas == 1 && m_right->matriz->colunas == 1) {
		int linhas = m_left->matriz->linhas;
		int colunas = m_left->matriz->colunas;

		result_matriz->linhas = linhas;
		result_matriz->colunas = colunas;

		result_matriz->dados = (float**)malloc(linhas * sizeof(float*));
		for (int i = 0; i < linhas; i++) {
			result_matriz->dados[i] = (float*)malloc(colunas * sizeof(float));
			for (int j = 0; j < colunas; j++) {
				result_matriz->dados[i][j] = m_left->matriz->dados[i][j] * m_right->matriz->dados[0][0];
			}
		}
	} else {
		printf("\nIncorrect dimensions for operator ’*’ - have MATRIX [%d][%d] and MATRIX [%d][%d]", m_left->matriz->linhas, m_left->matriz->colunas, m_right->matriz->linhas, m_right->matriz->colunas);
		return;
	}

	result->matriz = copia_matriz(result_matriz);
	free_matriz(result_matriz);
    result->type = MATRIX;

}

void multiplicacao2_matriz(TreeNode* m_esquerda, TreeNode* valor_direita, HashTable* hash, Result* result) {

	//Result* result = (Result*)malloc(sizeof(Result));
	Matriz* result_matriz = create_matrix();

	Matriz* m_left = get_matriz_hash(hash, m_esquerda->value_string);
	float valor = valor_direita->value_float;

	int linhas = m_left->linhas;
	int colunas = m_left->colunas;

	result_matriz->linhas = linhas;
	result_matriz->colunas = colunas;

	result_matriz->dados = (float**)malloc(linhas * sizeof(float*));
	for (int i=0; i<linhas; i++) {
		result_matriz->dados[i] = (float*)malloc(colunas * sizeof(float));
		for (int j=0; j<colunas; j++) {
			result_matriz->dados[i][j] = m_left->dados[i][j] * valor;
		}
	}

	//result->matriz = result_matriz;
	result->matriz = copia_matriz(result_matriz);
	free_matriz(result_matriz);
	result->type = MATRIX;
	//return result;
}

void multiplicacao3_matriz(TreeNode* valor_esquerda, TreeNode* m_direita, HashTable* hash, Result* result) {

	//Result* result = (Result*)malloc(sizeof(Result));
	Matriz* result_matriz = create_matrix();

	float valor = valor_esquerda->value_float;
	Matriz* m_right = get_matriz_hash(hash, m_direita->value_string);

	int linhas = m_right->linhas;
	int colunas = m_right->colunas;

	result_matriz->linhas = linhas;
	result_matriz->colunas = colunas;

	result_matriz->dados = (float**)malloc(linhas * sizeof(float*));
	for (int i=0; i<linhas; i++) {
		result_matriz->dados[i] = (float*)malloc(colunas * sizeof(float));
		for (int j=0; j<colunas; j++) {
			result_matriz->dados[i][j] = m_right->dados[i][j] * valor;
		}
	}

	//result->matriz = result_matriz;
	result->matriz = copia_matriz(result_matriz);
	free_matriz(result_matriz);
	result->type = MATRIX;
	//return result;
}

float comando_RPN(TreeNode* aux, HashTable* hash, Settings* settings) {

    if(aux) {

        float valor_esquerdo = comando_RPN(aux->left, hash, settings);
        float valor_direito = comando_RPN(aux->right, hash, settings);

		switch(aux->node_type) {
			case ADICAO: 
				printf("+ ");
				break;
			case SUBTRACAO:
				printf("- ");
				break;
			case MULTIPLICACAO:
				printf("* ");
				break;
			case DIVISAO:
				printf("/ ");
				break;
			case POTENCIACAO:
				printf("^ ");
				break;
			case RESTO_DIVISAO:
				printf("%% ");
				break;
			case NUMERO_INTEIRO:
				printf("%.*f ", settings->float_precision, (float)aux->value_float);
				break;
			case NUMERO_REAL:
				printf("%.*f ", settings->float_precision, aux->value_float);
				break;
			case SEN:
				printf("SEN ");
				break;
			case COS:
				printf("COS ");
				break;
			case TAN:
				printf("TAN ");
				break;
			case ABS:
				printf("ABS ");
				break;
			case IDENTIFICADOR:
				printf("%s ", aux->value_string);
				break;
			case X:
				printf("x ");
				break;
			default:
				printf("ERROR: INVALID TYPE ");
				break;

		} 
    }
	return 1;
	printf("\n");
}

void Delete_Tree(TreeNode* aux) {

    if(aux) {

        Delete_Tree(aux->left);
        Delete_Tree(aux->right);
        free(aux);
    }
}

void free_result(Result* result) {
    if (result == NULL) {
        return; // No memory to free
    }

    // Free the matrix data
    if (result->matriz != NULL) {
        // Free individual rows
        for (int i = 0; i < result->matriz->linhas; i++) {
            free(result->matriz->dados[i]);
        }
        // Free the array of row pointers
        free(result->matriz->dados);
        // Free the Matriz structure itself
        free(result->matriz);
    }

    // Free the Result structure
    free(result);
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

void set_X(float value) {
	global_X = value;
}

void plot(TreeNode* aux, Settings* settings, HashTable* hash) {
    char display[25][80];
    int i, j;
    float k;
    int xDisplay = 0, yDisplay;

    for(i = 0; i < 25; i++) {
        for(j = 0; j < 80; j++) {
            display[i][j] = ' ';
        }
    }

    if(settings->draw_axis) {
        for(i = 0; i < 25; i++) {
            display[i][40] = '|';
        }

        for(j = 0; j < 80; j++) {
            display[12][j] = '-';
        }
        display[12][40] = '*';
    }

    for(k = settings->h_view_lo; k < settings->h_view_hi; k += ((settings->h_view_hi - settings->h_view_lo) / 80)) {
        if(xDisplay >= 80)
            break;

        Result* result = RPN_Walk(aux, hash);
        yDisplay = 12 - round(result->value / ((settings->v_view_hi - settings->v_view_lo) / 25));

        if(yDisplay >= 0 && yDisplay < 25) {
            display[yDisplay][xDisplay] = '*';
        }
        xDisplay++;
        free(result); // Free the memory allocated for Result
    }

    for(i = 0; i < 25; i++) {
        for(j = 0; j < 80; j++) {
            printf("%c", display[i][j]);
        }
        printf("\n");
    }
}
