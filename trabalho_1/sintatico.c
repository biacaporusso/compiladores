#include "sintatico.h"

int token;
int flagErro = 0;
int textoAntes = 0;
int linha=0, coluna=0;

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
    if (flagErro == 1) {
        return;
    }
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
            break; // transição vazia -> não dá erro
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
            if (textoAntes == 0) {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
                textoAntes = 1;
            } else {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
            }
            flagErro = 1;
            break;
    }
}

// verificar -> talvez precise de if antes do switch
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
            if (textoAntes == 0) {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
                textoAntes = 1;
            } else {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
            }
            flagErro = 1;
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
            if (textoAntes == 0) {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
                textoAntes = 1;
            } else {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
            }
            flagErro = 1;
            break;
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
        if (textoAntes == 0) {
            printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
                textoAntes = 1;
        } else {
            printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
        }
        flagErro = 1;
        break;
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
            if (textoAntes == 0) {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
                textoAntes = 1;
            } else {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
            }
            flagErro = 1;
            break;
    }
}

void BlocoComandos(Queue fila) {
    eat(INICIO, fila);
    ListaComandos(fila);
    eat(FIM, fila);
} 

void Comandos(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case IDENTIFICADOR:
            eat(IDENTIFICADOR, fila);
            // verificar
            eat(ABRE_PARENTESES, fila);
            ExprIter(fila);
            eat(FECHA_PARENTESES, fila);
            break;
        case SE:
            eat(SE, fila);
            Expressao(fila);
            eat(ENTAO, fila);
            ListaComandos(fila);
            // verificar
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
            // verificar
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
            if (textoAntes == 0) {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
                textoAntes = 1;
            } else {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
            }
            flagErro = 1;
            break;
    }
}

void ExpressaoSimples(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    switch(token) {
        case MAIS:
            eat(MAIS, fila);
            Termo(fila);
        case MENOS:
            eat(MENOS, fila);
            Termo(fila);
        default:
            if (textoAntes == 0) {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
                textoAntes = 1;
            } else {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
            }
            flagErro = 1;
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
            eat(ABRE_PARENTESES, fila);
            ExprIter(fila);
            eat(FECHA_PARENTESES, fila);
            break;
        default:
            if (textoAntes == 0) {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
                textoAntes = 1;
            } else {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
            }
            flagErro = 1;
            break;
    }
}

void Variavel(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    eat(IDENTIFICADOR, fila);
    // verificar se precisa de if
    switch(token) {
        case ABRE_COLCHETES:
            eat(ABRE_COLCHETES, fila);
            ExprIter(fila);
            eat(FECHA_COLCHETES, fila);
            break;
        default:
            if (textoAntes == 0) {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
                textoAntes = 1;
            } else {
                printf("\nERRO DE SINTAXE. Linha: %d Coluna: %d -> '%s'", linha, coluna, token);
            }
            flagErro = 1;
            break;
    }
}

