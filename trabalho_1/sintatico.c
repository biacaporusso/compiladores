#include "sintatico.h"

int token = -987654321;
int flagErro = 0;
int textoAntes = 0;
int linha=0, coluna=0;

void estadoFinalIdentificador() {
    if(token != ALGORITMO && token != ATE && token != CARACTERE && token != DE && token != DIV && token != E 
    && token != ENQUANTO && token != ENTAO && token != FIM && token != FACA && token != FALSO && token != FUNCAO 
    && token != IMPRIMA && token != INICIO && token != INTEIRO && token != LOGICO && token != LEIA && 
    token != MATRIZ && token != NAO && token != OU && token != PROCEDIMENTO && token != PARA && token != PASSO 
    && token != REAL && token != REPITA && token != SE && token != SENAO && token != TIPO && token != VETOR && 
    token != VERDADEIRO && token != VARIAVEIS && token != NUMERO_INTEIRO && token != NUMERO_REAL && 
    token != PONTO_E_VIRGULA && token != VIRGULA && token != DOIS_PONTOS && token != PONTO && 
    token != ABRE_COLCHETES && token != FECHA_COLCHETES && token != ABRE_PARENTESES && token != FECHA_PARENTESES
    && token != IGUAL && token != ESPACO_BRANCO && token != DIFERENTE && token != MAIOR && token != MAIOR_IGUAL 
    && token != MENOR && token != MENOR_IGUAL && token != ATRIBUICAO && token != MAIS && token != MENOS && 
    token != VEZES && token != DIVISAO && token != COMENTARIO_DE_LINHA && token != 167 && token != IDENTIFICADOR && 
    token != COMENTARIO_DE_BLOCO && token != STRING && token != PULA_LINHA) {
        token = 169;
    }
}

void startSintatico(Queue fila) {
    //printaFila(fila);
    // return;
    token = getToken(fila);
    estadoFinalIdentificador();
    // printf("token %d\n", token);
    Programa(fila);
    if (flagErro == 0) {
        if (textoAntes == 0) {
            printf("PROGRAMA CORRETO.");
            textoAntes = 1;
        } else {
            printf("\nPROGRAMA CORRETO.");
        }
        
    }
}

void advance(Queue fila) {
    removeElemento(fila);
    token = getToken(fila);
    estadoFinalIdentificador();
}

void eat(int t, Queue fila) {
    if (token == t) {
        //printf("comeu %d\n", token);
        advance(fila);
    } else {
        printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLinhaToken(fila), getColunaInicialToken(fila), getStringToken(fila));
        flagErro = 1;
        exit(0);
    }
}

void Programa(Queue fila) {

    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case ALGORITMO:
            eat(ALGORITMO, fila); 
            eat(IDENTIFICADOR, fila);
            eat(PONTO_E_VIRGULA, fila);
            BlocoVariaveis(fila);
            ProcedimentoFuncao(fila);
            BlocoComandos(fila);
            eat(PONTO, fila);
            break;
        default:
            printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLinhaToken(fila), getColunaInicialToken(fila), getStringToken(fila));
            flagErro = 1;
            exit(0);
    }
}

void ProcedimentoFuncao(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        // -> DeclaraProcedimento
        case PROCEDIMENTO:
            eat(PROCEDIMENTO, fila);
            eat(IDENTIFICADOR, fila);
            Parametros(fila);
            eat(PONTO_E_VIRGULA, fila);
            DeclaraParametros(fila);
            BlocoVariaveis(fila);
            BlocoComandos(fila);
            eat(PONTO_E_VIRGULA, fila);
            ProcedimentoFuncao(fila);
            break;
        // -> DeclaraFuncao
        case FUNCAO:
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
            ProcedimentoFuncao(fila);
            break;
        default:
            break; // produção vazia -> sem erro
    }
}

void DeclaraProcedimento(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case PROCEDIMENTO:
            eat(PROCEDIMENTO, fila);
            eat(IDENTIFICADOR, fila);
            Parametros(fila);
            eat(PONTO_E_VIRGULA, fila);
            DeclaraParametros(fila);
            BlocoVariaveis(fila);
            BlocoComandos(fila);
            eat(PONTO_E_VIRGULA, fila);
            break;
        default:
            printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLinhaToken(fila), getColunaInicialToken(fila), getStringToken(fila));
            flagErro = 1;
            exit(0);
    }
}

void DeclaraFuncao(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case FUNCAO:
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
            break;
        default:
            printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLinhaToken(fila), getColunaInicialToken(fila), getStringToken(fila));
            flagErro = 1;
            exit(0);
    }
}

void Parametros(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case ABRE_PARENTESES:
            eat(ABRE_PARENTESES, fila);
            DeclaraIdentificador(fila);
            eat(FECHA_PARENTESES, fila);
            break;
        default:
            break; // produção vazia -> não dá erro
    }
}

void DeclaraParametros(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        // -> Declaracoes -> DeclaraVariaveis
        case INTEIRO:
            eat(INTEIRO, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila); // recursão de Declaracoes
            break;
        case REAL:
            eat(REAL, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila);
            break;
        case CARACTERE:
            eat(CARACTERE, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila);
            break;
        case LOGICO:
            eat(LOGICO, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila);
            break;
        case IDENTIFICADOR:
            eat(IDENTIFICADOR, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila);
            break;
        // -> Declaracoes -> DeclaraTipo
        case TIPO:
            eat(TIPO, fila);
            eat(IDENTIFICADOR, fila);
            eat(IGUAL, fila);
            VetorMatriz(fila);
            eat(ABRE_COLCHETES, fila);
            Dimensao(fila);
            eat(FECHA_COLCHETES, fila);
            TipoBasico(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila);
            break;
        default:
            break; // produção vazia -> nao da erro
    }
}

void BlocoVariaveis(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case VARIAVEIS:
            eat(VARIAVEIS, fila);
            Declaracoes(fila);
            break;
        default:
            break; // transição vazia -> não dá erro
    }
}

void Declaracoes(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        // -> DeclaraVariaveis 
        case INTEIRO:
            eat(INTEIRO, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila);
            break;
        case REAL:
            eat(REAL, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila);
            break;
        case CARACTERE:
            eat(CARACTERE, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila);
            break;
        case LOGICO:
            eat(LOGICO, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila);
            break;
        case IDENTIFICADOR:
            eat(IDENTIFICADOR, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila);
            break;
        // -> DeclaraTipo
        case TIPO:
            eat(TIPO, fila);
            eat(IDENTIFICADOR, fila);
            eat(IGUAL, fila);
            VetorMatriz(fila);
            eat(ABRE_COLCHETES, fila);
            Dimensao(fila);
            eat(FECHA_COLCHETES, fila);
            TipoBasico(fila);
            eat(PONTO_E_VIRGULA, fila);
            Declaracoes(fila);
            break;
        default:
            break;
    }
}

void DeclaraTipo(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    eat(TIPO, fila);
    eat(IDENTIFICADOR, fila);
    eat(IGUAL, fila);
    VetorMatriz(fila);
    eat(ABRE_COLCHETES, fila);
    Dimensao(fila);
    eat(FECHA_COLCHETES, fila);
    TipoBasico(fila);
    eat(PONTO_E_VIRGULA, fila);
}

void DeclaraVariaveis(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        // DeclaraVariaveis -> TipoBasico
        case INTEIRO:
            eat(INTEIRO, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            break;
        case REAL:
            eat(REAL, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            break;
        case CARACTERE:
            eat(CARACTERE, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            break;
        case LOGICO:
            eat(LOGICO, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            break;
        case IDENTIFICADOR:
            eat(IDENTIFICADOR, fila);
            eat(DOIS_PONTOS, fila);
            DeclaraIdentificador(fila);
            eat(PONTO_E_VIRGULA, fila);
            break;
        default:
            break;
    }
}

void DeclaraIdentificador(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    eat(IDENTIFICADOR, fila);
    switch(token) {
        case VIRGULA:
            eat(VIRGULA, fila);
            DeclaraIdentificador(fila);
            break;
        default: 
            break;
    }
}

void VetorMatriz(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case VETOR:
            eat(VETOR, fila);
            break;
        case MATRIZ:
            eat(MATRIZ, fila);
            break;
        default: 
            printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLinhaToken(fila), getColunaInicialToken(fila), getStringToken(fila));
            flagErro = 1;
            exit(0);
    }
}

void Dimensao(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    eat(NUMERO_INTEIRO, fila);
    eat(DOIS_PONTOS, fila);
    eat(NUMERO_INTEIRO, fila);
    switch (token) {
    case VIRGULA:
        eat(VIRGULA, fila);
        Dimensao(fila);
        break;
    default:
        printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLinhaToken(fila), getColunaInicialToken(fila), getStringToken(fila));
        flagErro = 1;
        exit(0);
    }
}

void TipoBasico(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case INTEIRO:
            eat(INTEIRO, fila);
            break;
        case REAL:
            eat(REAL, fila);
            break;
        case CARACTERE:
            eat(CARACTERE, fila);
            break;
        case LOGICO:
            eat(LOGICO, fila);
            break;
        case IDENTIFICADOR:
            eat(IDENTIFICADOR, fila);
            break;
        default:
            printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLinhaToken(fila), getColunaInicialToken(fila), getStringToken(fila));
            flagErro = 1;
            exit(0);
    }
}

void BlocoComandos(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case INICIO:
            eat(INICIO, fila);
            ListaComandos(fila);
            eat(FIM, fila);
            break;
        default:
            printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLinhaToken(fila), getColunaInicialToken(fila), getStringToken(fila));
            flagErro = 1;
            exit(0);
    }
} 

void ListaComandos(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        // -> Comandos
        case IDENTIFICADOR:
            eat(IDENTIFICADOR, fila);
            if(token == ABRE_PARENTESES) {
                eat(ABRE_PARENTESES, fila);
                ExprIter(fila);
                eat(FECHA_PARENTESES, fila);
            }
            if(token == ABRE_COLCHETES) {
                eat(ABRE_COLCHETES, fila);  // Variavel
                ExprIter(fila);             // Variavel
                eat(FECHA_COLCHETES, fila); // Variavel
                eat(ATRIBUICAO, fila);
                Expressao(fila);
            }
            eat(PONTO_E_VIRGULA, fila);
            ListaComandos(fila);
            break;
        case SE:
            eat(SE, fila);
            Expressao(fila);
            eat(ENTAO, fila);
            ListaComandos(fila);
            if (token == FIM) {
                eat(FIM, fila);
                eat(SE, fila);
            } 
            if (token == SENAO) {
                eat(SENAO, fila);
                ListaComandos(fila);
                eat(FIM, fila);
                eat(SE, fila);
            }
            eat(PONTO_E_VIRGULA, fila);
            ListaComandos(fila);
            break;
        case ENQUANTO:
            eat(ENQUANTO, fila);
            Expressao(fila);
            eat(FACA, fila);
            ListaComandos(fila);
            eat(FIM, fila);
            eat(ENQUANTO, fila);
            eat(PONTO_E_VIRGULA, fila);
            ListaComandos(fila);
            break;
        case PARA:
            eat(PARA, fila);
            eat(IDENTIFICADOR, fila);
            eat(DE, fila);
            Expressao(fila);
            eat(ATE, fila);
            Expressao(fila);
            if(token == FACA) {
                eat(FACA, fila);
                ListaComandos(fila);
                eat(FIM, fila);
                eat(PARA, fila);
            }
            if (token == PASSO) {
                eat(PASSO, fila);
                Expressao(fila);
                eat(FACA, fila);
                ListaComandos(fila);
                eat(FIM, fila);
                eat(PARA, fila);
            }
            eat(PONTO_E_VIRGULA, fila);
            ListaComandos(fila);
            break;
        case REPITA:
            eat(REPITA, fila);
            ListaComandos(fila);
            eat(ATE, fila);
            Expressao(fila);
            eat(PONTO_E_VIRGULA, fila);
            ListaComandos(fila);
            break;
        case LEIA:
            eat(LEIA, fila);
            eat(ABRE_PARENTESES, fila);
            Variavel(fila);
            eat(FECHA_PARENTESES, fila);
            eat(PONTO_E_VIRGULA, fila);
            ListaComandos(fila);
            break;
        case IMPRIMA:
            eat(IMPRIMA, fila);
            eat(ABRE_PARENTESES, fila);
            ExprIter(fila);
            eat(FECHA_PARENTESES, fila);
            eat(PONTO_E_VIRGULA, fila);
            ListaComandos(fila);
            break;
        default:
            break;
    }
}

void Comandos(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case IDENTIFICADOR:
            eat(IDENTIFICADOR, fila);
            if(token == ABRE_PARENTESES) {
                eat(ABRE_PARENTESES, fila);
                ExprIter(fila);
                eat(FECHA_PARENTESES, fila);
            }
            if(token == ABRE_COLCHETES) {
                eat(ABRE_COLCHETES, fila);  // Variavel
                ExprIter(fila);             // Variavel
                eat(FECHA_COLCHETES, fila); // Variavel
                eat(ATRIBUICAO, fila);
                Expressao(fila);
            }
            break;
        case SE:
            eat(SE, fila);
            Expressao(fila);
            eat(ENTAO, fila);
            ListaComandos(fila);
            if (token == FIM) {
                eat(FIM, fila);
                eat(SE, fila);
            } 
            if (token == SENAO) {
                eat(SENAO, fila);
                ListaComandos(fila);
                eat(FIM, fila);
                eat(SE, fila);
            }
            break;
        case ENQUANTO:
            eat(ENQUANTO, fila);
            Expressao(fila);
            eat(FACA, fila);
            ListaComandos(fila);
            eat(FIM, fila);
            eat(ENQUANTO, fila);
            break;
        case PARA:
            eat(PARA, fila);
            eat(IDENTIFICADOR, fila);
            eat(DE, fila);
            Expressao(fila);
            eat(ATE, fila);
            Expressao(fila);
            if(token == FACA) {
                eat(FACA, fila);
                ListaComandos(fila);
                eat(FIM, fila);
                eat(PARA, fila);
            }
            if (token == PASSO) {
                eat(PASSO, fila);
                Expressao(fila);
                eat(FACA, fila);
                ListaComandos(fila);
                eat(FIM, fila);
                eat(PARA, fila);
            }
            break;
        case REPITA:
            eat(REPITA, fila);
            ListaComandos(fila);
            eat(ATE, fila);
            Expressao(fila);
            break;
        case LEIA:
            eat(LEIA, fila);
            eat(ABRE_PARENTESES, fila);
            Variavel(fila);
            eat(FECHA_PARENTESES, fila);
            break;
        case IMPRIMA:
            eat(IMPRIMA, fila);
            eat(ABRE_PARENTESES, fila);
            ExprIter(fila);
            eat(FECHA_PARENTESES, fila);
            break;
        default:
            printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLinhaToken(fila), getColunaInicialToken(fila), getStringToken(fila));
            flagErro = 1;
            exit(0);
    }
}

void Expressao(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        // -> + Termo
        case MAIS:
            eat(MAIS, fila);
            Termo(fila);
            // (sinal) Expressao
            if(token == IGUAL) {
                eat(IGUAL, fila);
                Expressao(fila);
            }
            if(token == DIFERENTE) {
                eat(DIFERENTE, fila);
                Expressao(fila);
            }
            if(token == MENOR) {
                eat(MENOR, fila);
                Expressao(fila);
            }
            if(token == MAIOR) {
                eat(MAIOR, fila);
                Expressao(fila);
            }
            if(token == MENOR_IGUAL) {
                eat(MENOR_IGUAL, fila);
                Expressao(fila);
            }
            if(token == MAIOR_IGUAL) {
                eat(MAIOR_IGUAL, fila);
                Expressao(fila);
            }
            break;
        // -> - Termo
        case MENOS:
            eat(MENOS, fila);
            Termo(fila);
            // (sinal) Expressao
            if(token == IGUAL) {
                eat(IGUAL, fila);
                Expressao(fila);
            }
            if(token == DIFERENTE) {
                eat(DIFERENTE, fila);
                Expressao(fila);
            }
            if(token == MENOR) {
                eat(MENOR, fila);
                Expressao(fila);
            }
            if(token == MAIOR) {
                eat(MAIOR, fila);
                Expressao(fila);
            }
            if(token == MENOR_IGUAL) {
                eat(MENOR_IGUAL, fila);
                Expressao(fila);
            }
            if(token == MAIOR_IGUAL) {
                eat(MAIOR_IGUAL, fila);
                Expressao(fila);
            }
            break;
        // -> Termo (tudo)
        case ABRE_PARENTESES:
            eat(ABRE_PARENTESES, fila);
            Expressao(fila);
            eat(FECHA_PARENTESES, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            // (sinal) Expressao
            if(token == IGUAL) {
                eat(IGUAL, fila);
                Expressao(fila);
            }
            if(token == DIFERENTE) {
                eat(DIFERENTE, fila);
                Expressao(fila);
            }
            if(token == MENOR) {
                eat(MENOR, fila);
                Expressao(fila);
            }
            if(token == MAIOR) {
                eat(MAIOR, fila);
                Expressao(fila);
            }
            if(token == MENOR_IGUAL) {
                eat(MENOR_IGUAL, fila);
                Expressao(fila);
            }
            if(token == MAIOR_IGUAL) {
                eat(MAIOR_IGUAL, fila);
                Expressao(fila);
            }
            break;
        case NAO:
            eat(NAO, fila);
            Fator(fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            // (sinal) Expressao
            if(token == IGUAL) {
                eat(IGUAL, fila);
                Expressao(fila);
            }
            if(token == DIFERENTE) {
                eat(DIFERENTE, fila);
                Expressao(fila);
            }
            if(token == MENOR) {
                eat(MENOR, fila);
                Expressao(fila);
            }
            if(token == MAIOR) {
                eat(MAIOR, fila);
                Expressao(fila);
            }
            if(token == MENOR_IGUAL) {
                eat(MENOR_IGUAL, fila);
                Expressao(fila);
            }
            if(token == MAIOR_IGUAL) {
                eat(MAIOR_IGUAL, fila);
                Expressao(fila);
            }
            break;
        case NUMERO_INTEIRO:
            eat(NUMERO_INTEIRO, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            // (sinal) Expressao
            if(token == IGUAL) {
                eat(IGUAL, fila);
                Expressao(fila);
            }
            if(token == DIFERENTE) {
                eat(DIFERENTE, fila);
                Expressao(fila);
            }
            if(token == MENOR) {
                eat(MENOR, fila);
                Expressao(fila);
            }
            if(token == MAIOR) {
                eat(MAIOR, fila);
                Expressao(fila);
            }
            if(token == MENOR_IGUAL) {
                eat(MENOR_IGUAL, fila);
                Expressao(fila);
            }
            if(token == MAIOR_IGUAL) {
                eat(MAIOR_IGUAL, fila);
                Expressao(fila);
            }
            break;
        case NUMERO_REAL:
            eat(NUMERO_REAL, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            // (sinal) Expressao
            if(token == IGUAL) {
                eat(IGUAL, fila);
                Expressao(fila);
            }
            if(token == DIFERENTE) {
                eat(DIFERENTE, fila);
                Expressao(fila);
            }
            if(token == MENOR) {
                eat(MENOR, fila);
                Expressao(fila);
            }
            if(token == MAIOR) {
                eat(MAIOR, fila);
                Expressao(fila);
            }
            if(token == MENOR_IGUAL) {
                eat(MENOR_IGUAL, fila);
                Expressao(fila);
            }
            if(token == MAIOR_IGUAL) {
                eat(MAIOR_IGUAL, fila);
                Expressao(fila);
            }
            break;
        case VERDADEIRO:
            eat(VERDADEIRO, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            // (sinal) Expressao
            if(token == IGUAL) {
                eat(IGUAL, fila);
                Expressao(fila);
            }
            if(token == DIFERENTE) {
                eat(DIFERENTE, fila);
                Expressao(fila);
            }
            if(token == MENOR) {
                eat(MENOR, fila);
                Expressao(fila);
            }
            if(token == MAIOR) {
                eat(MAIOR, fila);
                Expressao(fila);
            }
            if(token == MENOR_IGUAL) {
                eat(MENOR_IGUAL, fila);
                Expressao(fila);
            }
            if(token == MAIOR_IGUAL) {
                eat(MAIOR_IGUAL, fila);
                Expressao(fila);
            }
            break;
        case FALSO:
            eat(FALSO, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            // (sinal) Expressao
            if(token == IGUAL) {
                eat(IGUAL, fila);
                Expressao(fila);
            }
            if(token == DIFERENTE) {
                eat(DIFERENTE, fila);
                Expressao(fila);
            }
            if(token == MENOR) {
                eat(MENOR, fila);
                Expressao(fila);
            }
            if(token == MAIOR) {
                eat(MAIOR, fila);
                Expressao(fila);
            }
            if(token == MENOR_IGUAL) {
                eat(MENOR_IGUAL, fila);
                Expressao(fila);
            }
            if(token == MAIOR_IGUAL) {
                eat(MAIOR_IGUAL, fila);
                Expressao(fila);
            }
            break;
        case STRING:
            eat(STRING, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            // (sinal) Expressao
            if(token == IGUAL) {
                eat(IGUAL, fila);
                Expressao(fila);
            }
            if(token == DIFERENTE) {
                eat(DIFERENTE, fila);
                Expressao(fila);
            }
            if(token == MENOR) {
                eat(MENOR, fila);
                Expressao(fila);
            }
            if(token == MAIOR) {
                eat(MAIOR, fila);
                Expressao(fila);
            }
            if(token == MENOR_IGUAL) {
                eat(MENOR_IGUAL, fila);
                Expressao(fila);
            }
            if(token == MAIOR_IGUAL) {
                eat(MAIOR_IGUAL, fila);
                Expressao(fila);
            }
            break;
        case IDENTIFICADOR:
            eat(IDENTIFICADOR, fila);
            if (token == ABRE_PARENTESES) {
                eat(ABRE_PARENTESES, fila);
                ExprIter(fila);
                eat(FECHA_PARENTESES, fila);
            }
            if (token == ABRE_COLCHETES) {
                eat(ABRE_COLCHETES, fila);
                ExprIter(fila);
                eat(FECHA_COLCHETES, fila);
            }
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            // (sinal) Expressao
            if(token == IGUAL) {
                eat(IGUAL, fila);
                Expressao(fila);
            }
            if(token == DIFERENTE) {
                eat(DIFERENTE, fila);
                Expressao(fila);
            }
            if(token == MENOR) {
                eat(MENOR, fila);
                Expressao(fila);
            }
            if(token == MAIOR) {
                eat(MAIOR, fila);
                Expressao(fila);
            }
            if(token == MENOR_IGUAL) {
                eat(MENOR_IGUAL, fila);
                Expressao(fila);
            }
            if(token == MAIOR_IGUAL) {
                eat(MAIOR_IGUAL, fila);
                Expressao(fila);
            }
            break;
        default:
            break;
    }
}

void ExpressaoSimples(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        // -> + Termo
        case MAIS:
            eat(MAIS, fila);
            Termo(fila);
            break;
        // -> - Termo
        case MENOS:
            eat(MENOS, fila);
            Termo(fila);
            break;
        // -> Termo (tudo)
        case ABRE_PARENTESES:
            eat(ABRE_PARENTESES, fila);
            Expressao(fila);
            eat(FECHA_PARENTESES, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            break;
        case NAO:
            eat(NAO, fila);
            Fator(fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            break;
        case NUMERO_INTEIRO:
            eat(NUMERO_INTEIRO, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            break;
        case NUMERO_REAL:
            eat(NUMERO_REAL, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            break;
        case VERDADEIRO:
            eat(VERDADEIRO, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            break;
        case FALSO:
            eat(FALSO, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            break;
        case STRING:
            eat(STRING, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            break;
        case IDENTIFICADOR:
            eat(IDENTIFICADOR, fila);
            if (token == ABRE_PARENTESES) {
                eat(ABRE_PARENTESES, fila);
                ExprIter(fila);
                eat(FECHA_PARENTESES, fila);
            }
            if (token == ABRE_COLCHETES) {
                eat(ABRE_COLCHETES, fila);
                ExprIter(fila);
                eat(FECHA_COLCHETES, fila);
            }
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            // + Exp - Exp OU Exp
            if(token == MAIS) {
                eat(MAIS, fila);
                ExpressaoSimples(fila);
            }
            if(token == MENOS) {
                eat(MENOS, fila);
                ExpressaoSimples(fila);
            }
            if(token == OU) {
                eat(OU, fila);
                ExpressaoSimples(fila);
            }
            break;
        default:
            break;
    }
}

void Termo(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        // -> Fator (tudo)
        case ABRE_PARENTESES:
            eat(ABRE_PARENTESES, fila);
            Expressao(fila);
            eat(FECHA_PARENTESES, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            break;
        case NAO:
            eat(NAO, fila);
            Fator(fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            break;
        case NUMERO_INTEIRO:
            eat(NUMERO_INTEIRO, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            break;
        case NUMERO_REAL:
            eat(NUMERO_REAL, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            break;
        case VERDADEIRO:
            eat(VERDADEIRO, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            break;
        case FALSO:
            eat(FALSO, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            break;
        case STRING:
            eat(STRING, fila);
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            break;
        case IDENTIFICADOR:
            eat(IDENTIFICADOR, fila);
            if (token == ABRE_PARENTESES) {
                eat(ABRE_PARENTESES, fila);
                ExprIter(fila);
                eat(FECHA_PARENTESES, fila);
            }
            if (token == ABRE_COLCHETES) {
                eat(ABRE_COLCHETES, fila);
                ExprIter(fila);
                eat(FECHA_COLCHETES, fila);
            }
            if(token == VEZES) {
                eat(VEZES, fila);
                Termo(fila);
            }
            if(token == DIVISAO) {
                eat(DIVISAO, fila);
                Termo(fila);
            }
            if(token == DIV) {
                eat(DIV, fila);
                Termo(fila);
            }
            if(token == E) {
                eat(E, fila);
                Termo(fila);
            }
            break;
        default:
            break;
    }

}

void Fator(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case ABRE_PARENTESES:
            eat(ABRE_PARENTESES, fila);
            Expressao(fila);
            eat(FECHA_PARENTESES, fila);
            break;
        case NAO:
            eat(NAO, fila);
            Fator(fila);
            break;
        case NUMERO_INTEIRO:
            eat(NUMERO_INTEIRO, fila);
            break;
        case NUMERO_REAL:
            eat(NUMERO_REAL, fila);
            break;
        case VERDADEIRO:
            eat(VERDADEIRO, fila);
            break;
        case FALSO:
            eat(FALSO, fila);
            break;
        case STRING:
            eat(STRING, fila);
            break;
        case IDENTIFICADOR:
            eat(IDENTIFICADOR, fila);
            if (token == ABRE_PARENTESES) {
                eat(ABRE_PARENTESES, fila);
                ExprIter(fila);
                eat(FECHA_PARENTESES, fila);
            }
            if (token == ABRE_COLCHETES) {
                eat(ABRE_COLCHETES, fila);
                ExprIter(fila);
                eat(FECHA_COLCHETES, fila);
            }
            break;
        default:
            printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", getLinhaToken(fila), getColunaInicialToken(fila), getStringToken(fila));
            flagErro = 1;
            exit(0);
    }
}

void Variavel(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    eat(IDENTIFICADOR, fila);
    if(token == ABRE_COLCHETES) {
        eat(ABRE_COLCHETES, fila);
            ExprIter(fila);
            eat(FECHA_COLCHETES, fila);
    }
    /* switch(token) {
        case ABRE_COLCHETES:
            eat(ABRE_COLCHETES, fila);
            ExprIter(fila);
            eat(FECHA_COLCHETES, fila);
            break;
        default:
            if (textoAntes == 0) {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%d'", linha, coluna, token);
                textoAntes = 1;
            } else {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%d'", linha, coluna, token);
            }
            flagErro = 1;
            break;
    } */
}

void ExprIter(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    Expressao(fila);
    if (token == VIRGULA) {
        eat(VIRGULA, fila);
        ExprIter(fila);
    }
}

/* char* printarToken(char* entrada, int colunaInicialToken, int colunaFinalToken) {
    static char stringToken[1000];
    int i;
    colunaInicialToken--;
    colunaFinalToken--;
    for (i=colunaInicialToken; i<=colunaFinalToken; i++) {
        stringToken[i-colunaInicialToken] = entrada[i];
    }
    stringToken[i-colunaInicialToken] = '\0';
    return token;
} */