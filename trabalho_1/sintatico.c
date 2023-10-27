#include "sintatico.h"

#define ALGORITMO 10
#define ATE 12
#define CARACTERE 21
#define DE 23
#define DIV 25
#define E 26
#define ENQUANTO 33
#define ENTAO 36
#define FIM 39
#define FACA 42
#define FALSO 45
#define FUNCAO 50
#define IMPRIMA 57
#define INICIO 62
#define INTEIRO 67
#define LOGICO 73
#define LEIA 76
#define MATRIZ 82
#define NAO 85
#define OU 87
#define PROCEDIMENTO 99
#define PARA 102
#define PASSO 105
#define REAL 109
#define REPITA 113
#define SE 115
#define SENAO 118
#define TIPO 122
#define VETOR 127
#define VERDADEIRO 135
#define VARIAVEIS 143
#define NUMERO_INTEIRO 144
#define REAL 146
#define PONTO_E_VIRGULA 147
#define VIRGULA 148
#define DOIS_PONTOS 149
#define PONTO 150
#define ABRE_COLCHETES 151
#define FECHA_COLCHETES 152
#define ABRE_PARENTESES 153
#define FECHA_PARENTESES 154
#define IGUAL 155
#define ESPACO_BRANCO 156
#define DIFERENTE 157
#define MAIOR 158
#define MAIOR_IGUAL 159
#define MENOR 160
#define MENOR_IGUAL 161
#define ATRIBUICAO 162
#define MAIS 163
#define MENOS 164
#define VEZES 165
#define DIVISAO 166
#define COMENTARIO_DE_LINHA 168
#define IDENTIFICADOR 169
#define COMENTARIO_DE_BLOCO 171
#define STRING 173
#define PULA_LINHA 174

int token;
int flagErro = 0;
int textoAntes = 0;

void startSintatico(Queue fila) {
    // printaFila(fila);
    // return;
    token = getToken(fila);
    // printf("token %d\n", token);
    S(fila);
    if (flagErro == 0) {
        if (textoAntes == 0) {
            printf("CADEIA ACEITA");
            textoAntes = 1;
        } else {
            printf("\nCADEIA ACEITA");
        }
        
    }
}

void advance(Queue fila) {
    removeElemento(fila);
    token = getToken(fila);
}

void eat(int t, Queue fila) {
    if (token == t) {
        advance(fila);
    } else {
        printf("error do eat\n");
    }
}

void Programa(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    eat(ALGORITMO, fila); 
    eat(IDENTIFICADOR, fila);
    eat(PONTO_E_VIRGULA, fila);
    BlocoVariaveis(fila);
    ProcedimentoFuncao(fila);
    BlocoComandos(fila);
    eat(PONTO, fila);
}

void DeclaraProcedimento(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    eat(PROCEDIMENTO, fila);
    eat(IDENTIFICADOR, fila);
    Parametros(fila);
    eat(PONTO_E_VIRGULA, fila);
    DeclaraParametros(fila);
    BlocoVariaveis(fila);
    BlocoComandos(fila);
    eat(PONTO_E_VIRGULA, fila);
}

void DeclaraFuncao(Queue fila) {
    eat(FUNCAO, fila);
    eat(IDENTIFICADOR, fila);
    Parametros(fila);
    eat(DOIS_PONTOS, fila);
    TipoBasico(fila);
    eat(PONTO_E_VIRGULA, fila);
    DeclaraParametros(fila);
    BlocoVariaveis(fila);
    BlocoComandos(fila); 
    eat(PONTO_E_VIRGULA, fila);
}

void Parametros(Queue fila) {
    eat(ABRE_PARENTESES, fila);
    DeclaraIdentificador(fila);
    eat(FECHA_PARENTESES, fila);
}
void BlocoVariaveis(Queue fila) {
    eat(VARIAVEIS, fila);
    Declaracoes(fila);
    // verificar a transição vazia
}

void L(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    // printf("token %d\n", token);
    switch(token) {
        case END:
            eat(END, fila); 
            break;
        case SEMI:
            eat(SEMI, fila); 
            S(fila); 
            L(fila); 
            break;
        default: 
            //char esperado = calloc(17, sizeof(char));
            char esperado[20] = "end, ;";
            if (textoAntes == 0) {
                printf("\nERRO SINTATICO EM: %d ESPERADO: %s", token, esperado);
                textoAntes = 1;
            } else {
                printf("\nERRO SINTATICO EM: %d ESPERADO: %s", token, esperado);
            }
            flagErro = 1;
            break;
    }
}

void E(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    // printf("token %d\n", token);
    eat(NUM, fila);
    eat(EQ, fila);
    eat(NUM, fila);
}

/* error() {
    print("ERRO SINTATICO EM: %s ESPERADO: %s\n", token, esperado);
} */