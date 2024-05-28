#include <string.h>
#include "lexico.h"
#include "util.h"
#include "pilha.h"
#include "list.h"
#include "sintatico.h"

int main() {
    FILE *entry = stdin;
    Stack *stack = criaPilha();
    List *list = criaLista();

    int input_token;
    int linha = 1;
    int coluna = 1;
    int flag = 1;
    char *word = NULL;

    input_token = advance(1, entry, list, &linha, &coluna, &word);
    inserePilha(stack, START_NT);

    while (input_token!= END_OF_FILE){
        int stack_token = pop(stack);
        if (stack_token < comeco_nao_terminais && stack_token > comeco_terminais){
            if(input_token == stack_token){
                input_token = advance(1, entry, list, &linha, &coluna, &word); // implementar advance
            }else{
                printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> \'%s\'", linha, coluna - strlen(word), word);
                flag = 0;
                break;
            }


        }else if (stack_token > comeco_nao_terminais && stack_token < fim_nao_terminais){
            if (!parser(input_token, stack_token, stack)){ 
                printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> \'%s\'", linha, coluna - strlen(word), word);
                flag = 0;
                break;
            }
        }
        if(input_token == ERRO){
            printf("ERRO LEXICO. Linha: %d Coluna: %d -> \'%s\'", linha, coluna - strlen(word), word);
            flag = 0;
            break;
        }
    }

    if(flag){
        printf("PROGRAMA CORRETO.");
    }

    stack_free(stack);

    return 0;

}
