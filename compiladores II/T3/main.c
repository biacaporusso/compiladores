#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


/*  




INCOMPLETO PRA CRL !!!!!!!!!! FALTA TUDO DE SPILL MAS NAO SOBROU TEMPO IRMÃO




*/


Lista* vetor_ativos = NULL;
Lista* lista_registradores = NULL;

// retorna o valor de k
int build(Lista* lista_registradores) {

    char linha[2500];
    char s[7];
    int k;      // tamanho do vetor de "memoria"

    fgets(linha, sizeof(linha), stdin);
    char *kStr;
    kStr = strtok(linha, "=");
    kStr = strtok(NULL, "=");
    k = atoi(kStr);

    //printf("valor de k: %d\n", k);

    int id_reg = 1;
    int tempo_inicio = 0, tempo_fim = 0;
    char *token;

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        //printf("linha: %s", linha);
        token = strstr(linha, "-->");
        if (token != NULL) {
            if (sscanf(token, "--> %d %d", &tempo_inicio, &tempo_fim) == 2) {
                //printf("Valores numericos: %d %d\n", tempo_inicio, tempo_fim);
                Node* registrador = novoNo(id_reg, tempo_inicio, tempo_fim);
                inserir(lista_registradores, registrador);
                id_reg++;
            }
        }
    }

    return k;
}

void linear_scan(int k, Lista* lista_registradores) {

    int vetor_memoria[k];
    int i = 0; // para o vetor de memoria
    int j = 0; // para a lista de registradores

    for (i = 0; i < k; i++) {
        vetor_memoria[i] = -999;
    }

    Node* reg_atual = lista_registradores->inicio;
    printf("K = %d\n\n", k);
    for(i = 0; i < lista_registradores->tamanho; i++) { // posição da memoria

        int registrador_alocado = 0;

        for (j=0; j<k; j++) { // registrador atual
            //printf("\ni = %d\nj = %d\n", i, j);
            if (vetor_memoria[j] == -999) {
                vetor_memoria[j] = reg_atual->id;
                printf("vr%d: %d\n", i+1, j);
                reg_atual = reg_atual->prox;
                break;
            } else {
                //printf("\nposição memoria %d registrador %d\n", i, j+1);
                //printf("id do alocado: %d\n", i);
                Node* reg_alocado = getNode(lista_registradores, vetor_memoria[j]); 
                //printf("id alocado: %d, %d <= %d ?\n", reg_alocado->id, reg_alocado->tempo_fim, reg_atual->tempo_inicio);
                if (reg_alocado->tempo_fim <= reg_atual->tempo_inicio) {
                    vetor_memoria[j] = reg_atual->id;
                    printf("vr%d: %d\n", i+1, j);
                    reg_atual = reg_atual->prox;
                    break;
                } 
            }
        }
    }

}

void main() {

    lista_registradores = criarLista();
    int k = build(lista_registradores);
    int sucessful_alocation[k-1];
    int i;

    for (i = 0; i < k-1; i++) {
        sucessful_alocation[i] = 0;
    }

    for(i=k; i>=2; i--) {
        linear_scan(i, lista_registradores);
        printf("----------------------------------------\n");
    }

    printf("----------------------------------------");
    int j = 0;
    for(i=k; i>=2; i--) {
        //printf("successful_alocation[%d] = %d\n",i, sucessful_alocation[j]);
        if(sucessful_alocation[j] == 0) {
            printf("\nK = %d: Successful Allocation", i);
        } else {
            printf("SPILL\n");
        }
        j++;
    }


}