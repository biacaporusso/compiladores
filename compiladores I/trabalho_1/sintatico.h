#ifndef sintatico_h
#define sintatico_h

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

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
#define NUMERO_REAL 146
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

void startSintatico(Queue fila);
void advance(Queue fila);
void eat(int t, Queue fila);
void Programa(Queue fila);
void ProcedimentoFuncao(Queue fila);
void DeclaraProcedimento(Queue fila);
void DeclaraFuncao(Queue fila);
void Parametros(Queue fila);
void DeclaraParametros(Queue fila);
void BlocoVariaveis(Queue fila);
void Declaracoes(Queue fila);
void DeclaraTipo(Queue fila);
void DeclaraVariaveis(Queue fila);
void DeclaraIdentificador(Queue fila);
void VetorMatriz(Queue fila);
void Dimensao(Queue fila);
void TipoBasico(Queue fila);
void BlocoComandos(Queue fila);
void ListaComandos(Queue fila);
void Comandos(Queue fila);
void Expressao(Queue fila);
void ExpressaoSimples(Queue fila);
void Termo(Queue fila);
void Fator(Queue fila);
void Variavel(Queue fila);
void ExprIter(Queue fila);
//char* printarToken(char* entrada, int colunaInicialToken, int colunaFinalToken) ;

#endif
