#include "sintatico.h"

#define IF 3
#define THEN 7
#define ELSE 11
#define BEGIN 18
#define END 13
#define PRINT 23
#define SEMI 24
#define NUM 26
#define EQ 27

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

void S(Queue fila) {
    if (flagErro == 1) {
        return;
    }
    //printf("token %d\n", token);
    switch(token) {
        case IF:
            eat(IF, fila); 
            E(fila); 
            eat(THEN, fila); 
            S(fila); 
            eat(ELSE, fila); 
            S(fila); 
            break;
        case BEGIN:
            eat(BEGIN, fila); 
            S(fila); 
            L(fila); 
            break;
        case PRINT:
            eat(PRINT, fila); 
            E(fila); 
            break;
        default:
            char esperado[20] = "if, begin, print";
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