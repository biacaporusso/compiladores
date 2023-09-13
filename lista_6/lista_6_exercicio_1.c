#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_STATES 22
#define NUM_SYMBOLS 20
#define NUM_ESTADOSFINAIS 12

int percorreVetor(char caractere);
bool ehEstadoFinal(int estadoDepois);
void simboloReconhecido(int i_recon, char caractere);
void limpaReconhecida();
char reconhecida[200] = "";

int edges[NUM_STATES][NUM_SYMBOLS] = {
        //              a  c  e  h  i  r  s  t  0  1  2  3  4  5  6  7  8  9  +  -
        /* state 0 */  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 1 */  {0,11, 0, 2, 0, 0, 4, 0,19,19,19,19,19,19,19,19,19,19,17,18},
        /* state 2 */  {0, 0, 3, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 3 */  {0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 4 */  {0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 5 */  {0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 6 */  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 7 */  {0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 8 */  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 9 */  {0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 10 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 11 */ {12,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 12 */ {0, 0, 0, 0, 0,14, 0,13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 13 */ {0, 0, 0, 0, 0, 0,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 14 */ {0, 0, 0, 0, 0, 0,16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 15 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 16 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 17 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 18 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 19 */ {0, 0, 0, 0, 0, 0, 0, 0,19,19,19,19,19,19,19,19,19,19, 0, 0},
        /* state 20 */ {0, 0, 0, 0, 0, 0, 0, 0,22,22,22,22,22,22,22,22,22,22,21,21},
        /* state 21 */ {0, 0, 0, 0, 0, 0, 0, 0,22,22,22,22,22,22,22,22,22,22, 0, 0},
        /* state 22 */ {0, 0, 0, 0, 0, 0, 0, 0,22,22,22,22,22,22,22,22,22,22, 0, 0},
        
    };

int estadosFinais[NUM_ESTADOSFINAIS] = {3, 6, 8, 10, 13, 14, 15, 16, 17, 18, 19, 22};


void main () {

    

    int final_states[5] = {2,3,4,5,8};
    char entrada[200];

    int current_state = 1;
    int estadoDepois = 0;
    int last_final = 0;

    int i_recon = 0;
    int control = 0;

    //fgets(entrada, 200, stdin);
    //scanf("%[^\n]", entrada);
    int i, size;

    // loop percorrer string de entrada
    while (fgets(entrada, 200, stdin) != NULL) {
        entrada[strcspn(entrada, "\n")] = 0;  // removes the \n from the input
        i = 0;
        size = strlen(entrada);
        while (i < size) {
            int colunaSimbolo = percorreVetor(entrada[i]); // 
        
            // se existir o simbolo
            if (colunaSimbolo >= 0) {

                estadoDepois = edges[current_state][colunaSimbolo];

                // se a transição existir
                if (estadoDepois > 0) {
                    // printf("\nA letra '%c' no estado %d, leva para o estado %d\n",entrada[i], current_state, estadoDepois);
                    current_state = estadoDepois;
                    simboloReconhecido(i_recon, entrada[i]);
                    i_recon++;
                    i++;
                    if (ehEstadoFinal(estadoDepois)) {
                        last_final = estadoDepois;
                    } 
                    control = 1;
                } else {
                    current_state = 1;
                    last_final = 0;
                    if (control == 1) {
                        strcat(reconhecida, "\n");
                        i_recon++;
                    }
                    control = 1;
                }

            } else {
                i++;
                if (control == 1) {
                    strcat(reconhecida, "\n");
                    i_recon++;
                }
                control = 1;
                strcat(reconhecida, "ERRO");
                i_recon = i_recon+4;
                current_state = 1;
                last_final = 0;
            }
            
        } 
        printf("\n%s", reconhecida);
        limpaReconhecida();
    }
}

int percorreVetor(char caractere) {
    char vetorCaracteres[38] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's','t', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '+'};

    for (int i = 0; i < 38; i++){
        if(vetorCaracteres[i] == caractere)
            return i;
    }
    return -1;
}

bool ehEstadoFinal(int estadoDepois) {

    for (int i=0; i<NUM_ESTADOSFINAIS; i++) {
        if (estadoDepois == estadosFinais[i]) {
            return true;
        } 
    }
    return false;
}

void simboloReconhecido(int i_recon, char caractere) {

    reconhecida[i_recon] = caractere;
}

void limpaReconhecida() {
    for (int i=0; i<strlen(reconhecida); i++) {
        reconhecida[i] = '\0';
    }
}
