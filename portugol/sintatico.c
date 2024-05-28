#include "sintatico.h"
#include "util.h"

int start_nt(Stack *stack, int input_token);

int procedimento_funcao_nt(Stack *stack, int input_token);

int declara_procedimento_nt(Stack *stack, int input_token);

int declara_funcao_nt(Stack *stack, int input_token);

int parametros_nt(Stack *stack, int input_token);

int declara_parametros_nt(Stack *stack, int input_token);

int bloco_variaveis_nt(Stack *stack, int input_token);

int declaracoes_nt(Stack *stack, int input_token);

int declaracoes_aux_nt(Stack *stack, int input_token);

int declara_tipo_nt(Stack *stack, int input_token);

int declara_variaveis_nt(Stack *stack, int input_token);

int declara_identificador_nt(Stack *stack, int input_token);

int declara_identificador_aux_nt(Stack *stack, int input_token);

int vetor_matriz_nt(Stack *stack, int input_token);

int dimensao_nt(Stack *stack, int input_token);

int dimenso_auxiliar_nt(Stack *stack, int input_token);

int tipo_bastico_nt(Stack *stack, int input_token);

int bloco_comandos_nt(Stack *stack, int input_token);

int lista_comandos_nt(Stack *stack, int input_token);

int lista_comandos_aux_nt(Stack *stack, int input_token);

int comandos_nt(Stack *stack, int input_token);

int comandos_aux_1_nt(Stack *stack, int input_token);

int comandos_aux_2_nt(Stack *stack, int input_token);

int comandos_aux_3_nt(Stack *stack, int input_token);

int expressao_nt(Stack *stack, int input_token);

int expressao_aux_nt(Stack *stack, int input_token);

int expressao_simples_nt(Stack *stack, int input_token);

int expressao_simples_aux_nt(Stack *stack, int input_token);

int termo_nt(Stack *stack, int input_token);

int termo_aux_nt(Stack *stack, int input_token);

int fator_nt(Stack *stack, int input_token);

int fator_aux_nt(Stack *stack, int input_token);

int variavel_nt(Stack *stack, int input_token);

int variavel_aux_nt(Stack *stack, int input_token);

int expr_iter_nt(Stack *stack, int input_token);

int expr_iter_aux_nt(Stack *stack, int input_token);

int parser(int input_token, int stack_token, Stack *stack){
    switch (stack_token) {
        case START_NT:
            return start_nt(stack, input_token);
        case PROCEDIMENTO_FUNCAO_NT:
            return procedimento_funcao_nt(stack, input_token);
        case DECLARA_PROCEDIMENTO_NT:
            return declara_procedimento_nt(stack, input_token);
        case DECLARA_FUNCAO_NT:
            return declara_funcao_nt(stack, input_token);
        case PARAMETROS_NT:
            return parametros_nt(stack, input_token);
        case DECLARA_PARAMETROS_NT:
            return declara_parametros_nt(stack, input_token);
        case BLOCO_VARIAVEIS_NT:
            return bloco_variaveis_nt(stack, input_token);
        case DECLARACOES_NT:
            return declaracoes_nt(stack, input_token);
        case DECLARACOES_AUXILIAR_NT:
            return declaracoes_aux_nt(stack, input_token);
        case DECLARA_TIPO_NT:
            return declara_tipo_nt(stack, input_token);
        case DECLARA_VARIAVEIS_NT:
            return declara_variaveis_nt(stack, input_token);
        case DECLARA_IDENTIFICADOR_NT:
            return declara_identificador_nt(stack, input_token);
        case DECLARA_IDENTIFICADOR_AUXILIAR_NT:
            return declara_identificador_aux_nt(stack, input_token);
        case VETOR_MATRIZ_NT:
            return vetor_matriz_nt(stack, input_token);
        case DIMENSAO_NT:
            return dimensao_nt(stack, input_token);
        case DIMENSAO_AUXILIAR_NT:
            return dimenso_auxiliar_nt(stack, input_token);
        case TIPO_BASICO_NT:
            return tipo_bastico_nt(stack, input_token);
        case BLOCO_COMANDOS_NT:
            return bloco_comandos_nt(stack, input_token);
        case LISTA_COMANDOS_NT:
            return lista_comandos_nt(stack, input_token);
        case LISTA_COMANDOS_AUXILIAR_NT:
            return lista_comandos_aux_nt(stack, input_token);
        case COMANDOS_NT:
            return comandos_nt(stack, input_token);
        case COMANDOS_AUX_1_NT:
            return comandos_aux_1_nt(stack, input_token);
        case COMANDOS_AUX_2_NT:
            return comandos_aux_2_nt(stack, input_token);
        case COMANDOS_AUX_3_NT:
            return comandos_aux_3_nt(stack, input_token);
        case EXPRESSAO_NT:
            return expressao_nt(stack, input_token);
        case EXPRESSAO_AUX_NT:
            return expressao_aux_nt(stack, input_token);
        case EXPRESSAO_SIMPLES_NT:
            return expressao_simples_nt(stack, input_token);
        case EXPRESSAO_SIMPLES_AUX_NT:
            return expressao_simples_aux_nt(stack, input_token);
        case TERMO_NT:
            return termo_nt(stack, input_token);
        case TERMO_AUX_NT:
            return termo_aux_nt(stack, input_token);
        case FATOR_NT:
            return fator_nt(stack, input_token);
        case FATOR_AUX_NT:
            return fator_aux_nt(stack, input_token);
        case VARIAVEL_NT:
            return variavel_nt(stack, input_token);
        case VARIAVEL_AUX_NT:
            return variavel_aux_nt(stack, input_token);
        case EXPR_ITER_NT:
            return expr_iter_nt(stack, input_token);
        case EXPR_ITER_AUX_NT:
            return expr_iter_aux_nt(stack, input_token);

        default:
            return 0;
    }
}

int start_nt(Stack *stack, int input_token){
    switch (input_token) {
        case ALGORITMO:
            inserePilha(stack, PONTO);
            inserePilha(stack, BLOCO_COMANDOS_NT);
            inserePilha(stack, PROCEDIMENTO_FUNCAO_NT);
            inserePilha(stack, BLOCO_VARIAVEIS_NT);
            inserePilha(stack, PONTO_E_VIRGULA);
            inserePilha(stack, IDENTIFICADOR);
            inserePilha(stack, ALGORITMO);
            break;
        default:
            return 0;
    }
    return 1;
}

int procedimento_funcao_nt(Stack *stack, int input_token){
    switch (input_token) {
        case PROCEDIMENTO:
            inserePilha(stack, PROCEDIMENTO_FUNCAO_NT);
            inserePilha(stack, DECLARA_PROCEDIMENTO_NT);
            break;

        case FUNCAO:
            inserePilha(stack, PROCEDIMENTO_FUNCAO_NT);
            inserePilha(stack, DECLARA_FUNCAO_NT);
            break;

        case INICIO:
            break;

        default:
            return 0;
    }
    return 1;
}

int declara_procedimento_nt(Stack *stack, int input_token){
    switch (input_token) {
        case PROCEDIMENTO:
            inserePilha(stack, PONTO_E_VIRGULA);
            inserePilha(stack, BLOCO_COMANDOS_NT);
            inserePilha(stack, BLOCO_VARIAVEIS_NT);
            inserePilha(stack, DECLARA_PARAMETROS_NT);
            inserePilha(stack, PONTO_E_VIRGULA);
            inserePilha(stack, PARAMETROS_NT);
            inserePilha(stack, IDENTIFICADOR);
            inserePilha(stack, PROCEDIMENTO);
            break;

        default:
            return 0;
    }
    return 1;
}
int declara_funcao_nt(Stack *stack, int input_token){
    switch (input_token) {
        case FUNCAO:
            inserePilha(stack, PONTO_E_VIRGULA);
            inserePilha(stack, BLOCO_COMANDOS_NT);
            inserePilha(stack, BLOCO_VARIAVEIS_NT);
            inserePilha(stack, DECLARA_PARAMETROS_NT);
            inserePilha(stack, PONTO_E_VIRGULA);
            inserePilha(stack, TIPO_BASICO_NT);
            inserePilha(stack, DOIS_PONTOS);
            inserePilha(stack, PARAMETROS_NT);
            inserePilha(stack, IDENTIFICADOR);
            inserePilha(stack, FUNCAO);
            break;
        default:
            return 0;
    }
    return 1;
}

int parametros_nt(Stack *stack, int input_token){
    switch (input_token) {
        case ABRE_PARENTESES:
            inserePilha(stack, FECHA_PARENTESES);
            inserePilha(stack, DECLARA_IDENTIFICADOR_NT);
            inserePilha(stack, ABRE_PARENTESES);
            break;
        case PONTO_E_VIRGULA:
        case DOIS_PONTOS:
            break;
        default:
            return 0;
    }
    return 1;
}

int declara_parametros_nt(Stack *stack, int input_token){
    switch (input_token) {
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
        case TIPO:
        case IDENTIFICADOR:
            inserePilha(stack, DECLARACOES_NT);
            break;
        case VARIAVEIS:
        case PROCEDIMENTO:
        case FUNCAO:
        case INICIO:
            break;
        default:
            return 0;
    }
    return 1;
}

int bloco_variaveis_nt(Stack *stack, int input_token){
    switch (input_token) {
        case VARIAVEIS:
            inserePilha(stack, DECLARACOES_NT);
            inserePilha(stack, VARIAVEIS);
            break;
        case INICIO:
        case PROCEDIMENTO:
        case FUNCAO:
            break;
        default:
            return 0;
    }
    return 1;
}


int declaracoes_aux_nt(Stack *stack, int input_token){
    switch (input_token) {
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
        case IDENTIFICADOR:
        case TIPO:
            inserePilha(stack, DECLARACOES_NT);
            break;
        case VARIAVEIS:
        case INICIO:
        case PROCEDIMENTO:
        case FUNCAO:
            break;
        default:
            return 0;
    }
    return 1;
}

int declaracoes_nt(Stack *stack, int input_token){
    switch (input_token) {
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
        case IDENTIFICADOR:
            inserePilha(stack, DECLARACOES_AUXILIAR_NT);
            inserePilha(stack, DECLARA_VARIAVEIS_NT);
            break;
        case TIPO:
            inserePilha(stack, DECLARACOES_AUXILIAR_NT);
            inserePilha(stack, DECLARA_TIPO_NT);
            break;
        default:
            return 0;
    }
    return 1;
}

int declara_tipo_nt(Stack *stack, int input_token){
    switch (input_token) {
        case TIPO:
            inserePilha(stack, PONTO_E_VIRGULA);
            inserePilha(stack, TIPO_BASICO_NT);
            inserePilha(stack, FECHA_COLCHETES);
            inserePilha(stack, DIMENSAO_NT);
            inserePilha(stack, ABRE_COLCHETES);
            inserePilha(stack, VETOR_MATRIZ_NT);
            inserePilha(stack, IGUAL);
            inserePilha(stack, IDENTIFICADOR);
            inserePilha(stack, TIPO);
            break;
        default:
            return 0;
    }
    return 1;
}

int declara_variaveis_nt(Stack *stack, int input_token){
    switch (input_token) {
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
        case IDENTIFICADOR:
            inserePilha(stack, PONTO_E_VIRGULA);
            inserePilha(stack, DECLARA_IDENTIFICADOR_NT);
            inserePilha(stack, DOIS_PONTOS);
            inserePilha(stack, TIPO_BASICO_NT);
            break;
        default:
            return 0;
    }
    return 1;
}

int declara_identificador_nt(Stack *stack, int input_token){
    switch (input_token) {
        case IDENTIFICADOR:
            inserePilha(stack, DECLARA_IDENTIFICADOR_AUXILIAR_NT);
            inserePilha(stack, IDENTIFICADOR);
            break;
        default:
            return 0;
    }
    return 1;
}
int declara_identificador_aux_nt(Stack *stack, int input_token){
    switch (input_token) {
        case VIRGULA:
            inserePilha(stack, DECLARA_IDENTIFICADOR_NT);
            inserePilha(stack, VIRGULA);
            break;
        case FECHA_PARENTESES:
        case PONTO_E_VIRGULA:
            break;
        default:
            return 0;
    }
    return 1;
}


int vetor_matriz_nt(Stack *stack, int input_token){
    switch (input_token) {
        case VETOR:
            inserePilha(stack, VETOR);
            break;
        case MATRIZ:
            inserePilha(stack, MATRIZ);
            break;
        default:
            return 0;
    }
    return 1;
}

int dimensao_nt(Stack *stack, int input_token){
    switch (input_token) {
        case NUMERO_INTEIRO:
            inserePilha(stack, DIMENSAO_AUXILIAR_NT);
            inserePilha(stack, NUMERO_INTEIRO);
            inserePilha(stack, DOIS_PONTOS);
            inserePilha(stack, NUMERO_INTEIRO);
            break;
        default:
            return 0;
    }
    return 1;

}

int dimenso_auxiliar_nt(Stack *stack, int input_token){
    switch (input_token) {
        case VIRGULA:
            inserePilha(stack, DIMENSAO_NT);
            inserePilha(stack, VIRGULA);
            break;
        case FECHA_COLCHETES:
            break;
        default:
            return 0;
    }
    return 1;
}
int tipo_bastico_nt(Stack *stack, int input_token){
    switch (input_token) {
        case INTEIRO:
            inserePilha(stack, INTEIRO);
            break;
        case REAL:
            inserePilha(stack, REAL);
            break;
        case CARACTERE:
            inserePilha(stack, CARACTERE);
            break;
        case LOGICO:
            inserePilha(stack, LOGICO);
            break;
        case IDENTIFICADOR:
            inserePilha(stack, IDENTIFICADOR);
            break;
        default:
            return 0;
    }
    return 1;
}

int bloco_comandos_nt(Stack *stack, int input_token){
    switch (input_token) {
        case INICIO:
            inserePilha(stack, FIM);
            inserePilha(stack, LISTA_COMANDOS_NT);
            inserePilha(stack, INICIO);
            break;
        default:
            return 0;
    }
    return 1;
}


int lista_comandos_nt(Stack *stack, int input_token){
    switch (input_token) {
        case IDENTIFICADOR:
        case SE:
        case ENQUANTO:
        case PARA:
        case REPITA:
        case LEIA:
        case IMPRIMA:
            inserePilha(stack, LISTA_COMANDOS_AUXILIAR_NT);
            inserePilha(stack, PONTO_E_VIRGULA);
            inserePilha(stack, COMANDOS_NT);
            break;
        default:
            return 0;
    }
    return 1;
}

int lista_comandos_aux_nt(Stack *stack, int input_token){
    switch (input_token) {
        case IDENTIFICADOR:
        case SE:
        case ENQUANTO:
        case PARA:
        case REPITA:
        case LEIA:
        case IMPRIMA:
            inserePilha(stack, LISTA_COMANDOS_NT);
        case FIM:
        case SENAO:
        case ATE:
            break;
        default:
            return 0;
    }
    return 1;
}

int comandos_nt(Stack *stack, int input_token){
    switch (input_token) {
        case IDENTIFICADOR:
            inserePilha(stack, COMANDOS_AUX_1_NT);
            inserePilha(stack, IDENTIFICADOR);
            break;
        case SE:
            inserePilha(stack, COMANDOS_AUX_2_NT);
            inserePilha(stack, LISTA_COMANDOS_NT);
            inserePilha(stack, ENTAO);
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, SE);
            break;
        case ENQUANTO:
            inserePilha(stack, ENQUANTO);
            inserePilha(stack, FIM);
            inserePilha(stack, LISTA_COMANDOS_NT);
            inserePilha(stack, FACA);
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, ENQUANTO);
            break;
        case PARA:
            inserePilha(stack, COMANDOS_AUX_3_NT);
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, ATE);
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, DE);
            inserePilha(stack, IDENTIFICADOR);
            inserePilha(stack, PARA);
            break;
        case REPITA:
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, ATE);
            inserePilha(stack, LISTA_COMANDOS_NT);
            inserePilha(stack, REPITA);
            break;
        case LEIA:
            inserePilha(stack, FECHA_PARENTESES);
            inserePilha(stack, VARIAVEL_NT);
            inserePilha(stack, ABRE_PARENTESES);
            inserePilha(stack, LEIA);
            break;
        case IMPRIMA:
            inserePilha(stack, FECHA_PARENTESES);
            inserePilha(stack, EXPR_ITER_NT);
            inserePilha(stack, ABRE_PARENTESES);
            inserePilha(stack, IMPRIMA);
            break;
        default:
            return 0;
    }
    return 1;
}

int comandos_aux_1_nt(Stack *stack, int input_token){
    switch (input_token) {
        case ABRE_PARENTESES:
            inserePilha(stack, FECHA_PARENTESES);
            inserePilha(stack, EXPR_ITER_NT);
            inserePilha(stack, ABRE_PARENTESES);
            break;
        case PONTO_E_VIRGULA:
            break;
        case ATRIBUICAO: 
        case ABRE_COLCHETES:
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, ATRIBUICAO);
            inserePilha(stack, VARIAVEL_AUX_NT);
            break;
        default:
            return 0;
    }
    return 1;
}

int comandos_aux_2_nt(Stack *stack, int input_token){
    switch(input_token) {
        case FIM:
            inserePilha(stack, SE);
            inserePilha(stack, FIM);
            break;
        case SENAO:
            inserePilha(stack, SE);
            inserePilha(stack, FIM);
            inserePilha(stack, LISTA_COMANDOS_NT);
            inserePilha(stack, SENAO);
            break;
        default:
            return 0;
    }
}

int comandos_aux_3_nt(Stack *stack, int input_token){
    switch(input_token) {
        case FACA:
            inserePilha(stack, PARA);
            inserePilha(stack, FIM);
            inserePilha(stack, LISTA_COMANDOS_NT);
            inserePilha(stack, FACA);
            break;

        case PASSO:
            inserePilha(stack, PARA);
            inserePilha(stack, FIM);
            inserePilha(stack, LISTA_COMANDOS_NT);
            inserePilha(stack, FACA);
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, PASSO);
            break;
        default:
            return 0;
    }
    return 1;
}

int expressao_nt(Stack *stack, int input_token){
    switch(input_token) {
        case ABRE_PARENTESES:
        case NAO:
        case NUMERO_INTEIRO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case IDENTIFICADOR:
        case MAIS:
        case MENOS:
            inserePilha(stack, EXPRESSAO_AUX_NT);
            inserePilha(stack, EXPRESSAO_SIMPLES_NT);
            break;
        default:
            return 0;
    }
    return 1;
}

int expressao_aux_nt(Stack *stack, int input_token){
    switch(input_token) {
        case IGUAL:
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, IGUAL);
            break;
        case DIFERENTE:
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, DIFERENTE);
            break;
        case MENOR:
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, MENOR);
            break;
        case MENOR_IGUAL:
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, MENOR_IGUAL);
            break;
        case MAIOR_IGUAL:
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, MAIOR_IGUAL);
            break;
        case MAIOR:
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, MAIOR);
            break;
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case FECHA_PARENTESES:
        case VIRGULA:
        case PONTO_E_VIRGULA:
        case FECHA_COLCHETES:
            break;
        default:
            return 0;
    }
    return 1;

}
int expressao_simples_nt(Stack *stack, int input_token){

    switch(input_token) {
        case MAIS:
            inserePilha(stack, EXPRESSAO_SIMPLES_AUX_NT);
            inserePilha(stack, TERMO_NT);
            inserePilha(stack, MAIS);
            break;
        case MENOS:
            inserePilha(stack, EXPRESSAO_SIMPLES_AUX_NT);
            inserePilha(stack, TERMO_NT);
            inserePilha(stack, MENOS);
            break;
        case ABRE_PARENTESES:
        case NAO:
        case NUMERO_INTEIRO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case IDENTIFICADOR:
            inserePilha(stack, EXPRESSAO_SIMPLES_AUX_NT);
            inserePilha(stack, TERMO_NT);
            break;
        default:
            return 0;
    }
    return 1;

}

int expressao_simples_aux_nt(Stack *stack, int input_token){
    switch(input_token) {
        case MAIS:
            inserePilha(stack, EXPRESSAO_SIMPLES_NT);
            inserePilha(stack, MAIS);
            break;
        case MENOS:
            inserePilha(stack, EXPRESSAO_SIMPLES_NT);
            inserePilha(stack, MENOS);
            break;
        case OU:
            inserePilha(stack, EXPRESSAO_SIMPLES_NT);
            inserePilha(stack, OU);
            break;
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case FECHA_PARENTESES:
        case VIRGULA:
        case PONTO_E_VIRGULA:
        case FECHA_COLCHETES:
        case IGUAL:
        case DIFERENTE:
        case MENOR:
        case MENOR_IGUAL:
        case MAIOR:
        case MAIOR_IGUAL:
            break;
        default:
            return 0;
    }
    return 1;
}
int termo_nt(Stack *stack, int input_token){

    switch(input_token) {
        case ABRE_PARENTESES:
        case NAO:
        case NUMERO_INTEIRO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case IDENTIFICADOR:
            inserePilha(stack, TERMO_AUX_NT);
            inserePilha(stack, FATOR_NT);
            break;
        default:
            return 0;
    }
    return 1;
}



int termo_aux_nt(Stack *stack, int input_token){
    switch(input_token) {
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case FECHA_PARENTESES:
        case VIRGULA:
        case PONTO_E_VIRGULA:
        case FECHA_COLCHETES:
        case IGUAL:
        case DIFERENTE:
        case MENOR:
        case MENOR_IGUAL:
        case MAIOR_IGUAL:
        case MAIOR:
        case MAIS:
        case MENOS:
        case OU:
            break;
        case VEZES:
            inserePilha(stack, TERMO_NT);
            inserePilha(stack, VEZES);
            break;
        case DIVISAO:
            inserePilha(stack, TERMO_NT);
            inserePilha(stack, DIVISAO);
            break;
        case DIV:
            inserePilha(stack, TERMO_NT);
            inserePilha(stack, DIV);
            break;
        case E:
            inserePilha(stack, TERMO_NT);
            inserePilha(stack, E);
            break;
        default:
            return 0;

    }
    return 1;
}

int fator_nt(Stack *stack, int input_token){
    switch(input_token) {
        case ABRE_PARENTESES:
            inserePilha(stack, FECHA_PARENTESES);
            inserePilha(stack, EXPRESSAO_NT);
            inserePilha(stack, ABRE_PARENTESES);
            break;
        case NAO:
            inserePilha(stack, FATOR_NT);
            inserePilha(stack, NAO);
            break;
        case NUMERO_INTEIRO:
            inserePilha(stack, NUMERO_INTEIRO);
            break;
        case NUMERO_REAL:
            inserePilha(stack, NUMERO_REAL);
            break;
        case VERDADEIRO:
            inserePilha(stack, VERDADEIRO);
            break;
        case FALSO:
            inserePilha(stack, FALSO);
            break;
        case STRING:
            inserePilha(stack, STRING);
            break;
        case IDENTIFICADOR:
            inserePilha(stack, FATOR_AUX_NT);
            inserePilha(stack, IDENTIFICADOR);
            break;
        default:
            return 0;
    }
    return 1;
}

int fator_aux_nt(Stack *stack, int input_token){
    switch(input_token) {
        case ABRE_PARENTESES:
            inserePilha(stack, FECHA_PARENTESES);
            inserePilha(stack, EXPR_ITER_NT);
            inserePilha(stack, ABRE_PARENTESES);
            break;
        case ATRIBUICAO:
        case FECHA_PARENTESES:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case VIRGULA:
        case PONTO_E_VIRGULA:
        case FECHA_COLCHETES:
        case IGUAL:
        case DIFERENTE:
        case MENOR:
        case MENOR_IGUAL:
        case MAIOR_IGUAL:
        case MAIOR:
        case MAIS:
        case MENOS:
        case OU:
        case VEZES:
        case DIVISAO:
        case DIV:
        case E:
        case ABRE_COLCHETES:
            inserePilha(stack, VARIAVEL_AUX_NT);
            break;
        default:
            return 0;
    }
    return 1;
}

int variavel_nt(Stack *stack, int input_token){
    switch(input_token) {
        case IDENTIFICADOR:
            inserePilha(stack, VARIAVEL_AUX_NT);
            inserePilha(stack, IDENTIFICADOR);
            break;
        default:
            return 0;
    }

    return 1;
}

int variavel_aux_nt(Stack *stack, int input_token){
    switch(input_token) {
        case ABRE_COLCHETES:
            inserePilha(stack, FECHA_COLCHETES);
            inserePilha(stack, EXPR_ITER_NT);
            inserePilha(stack, ABRE_COLCHETES);
            break;
        case ATRIBUICAO:
        case FECHA_PARENTESES:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case VIRGULA:
        case PONTO_E_VIRGULA:
        case FECHA_COLCHETES:
        case IGUAL:
        case DIFERENTE:
        case MENOR:
        case MENOR_IGUAL:
        case MAIOR_IGUAL:
        case MAIOR:
        case MAIS:
        case MENOS:
        case OU:
        case VEZES:
        case DIVISAO:
        case DIV:
        case E:
            break;
        default:
            return 0;
    }
    return 1;
}

int expr_iter_nt(Stack *stack, int input_token){
    switch(input_token) {
        case MAIS:
        case MENOS:
        case ABRE_PARENTESES:
        case NAO:
        case NUMERO_INTEIRO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case IDENTIFICADOR: //variavel
            inserePilha(stack, EXPR_ITER_AUX_NT);
            inserePilha(stack, EXPRESSAO_NT);
            break;

        default:
            return 0;
    }

    return 1;

}

int expr_iter_aux_nt(Stack *stack, int input_token) {

    switch (input_token) {
        case VIRGULA:
            inserePilha(stack, EXPR_ITER_NT);
            inserePilha(stack, VIRGULA);
            break;
        case FECHA_PARENTESES:
        case FECHA_COLCHETES:
            break;
        default:
            return 0;
    }


    return 1;
}