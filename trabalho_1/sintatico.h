#ifndef sintatico_h
#define sintatico_h

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

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

#endif
