#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_STATES 28
#define NUM_SYMBOLS 27
#define NUM_ESTADOSFINAIS 9

int edges[NUM_STATES][NUM_SYMBOLS] = {
        //               b  d  e  f  g  h  i  l  n  p  r  s  t  0  1  2  3  4  5  6  7  8  9  -  +  ;  =
        /* state 0 */  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 1 */  {14, 0, 8, 0, 0, 0, 2, 0, 0,19, 0, 0, 4,26,26,26,26,26,26,26,26,26,26,25,25,24,27},
        /* state 2 */  { 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 3 */  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 4 */  { 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 5 */  { 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 6 */  { 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 7 */  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 8 */  { 0, 0, 0, 0, 0, 0, 0, 9,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 9 */  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 10 */ { 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 11 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 12 */ { 0,13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 13 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 14 */ { 0, 0,15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 15 */ { 0, 0, 0, 0,16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 16 */ { 0, 0, 0, 0, 0, 0,17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 17 */ { 0, 0, 0, 0, 0, 0, 0, 0,18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 18 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 19 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 20 */ { 0, 0, 0, 0, 0, 0,21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 21 */ { 0, 0, 0, 0, 0, 0, 0, 0,22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 22 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 23 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 24 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /* state 25 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,26,26,26,26,26,26,26,26,26,26, 0, 0, 0, 0},
        /* state 26 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,26,26,26,26,26,26,26,26,26,26, 0, 0, 0, 0},
        /* state 27 */ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        //               b  d  e  f  g  h  i  l  n  p  r  s  t  0  1  2  3  4  5  6  7  8  9  -  +  ;  =

    };

int estadosFinais[NUM_ESTADOSFINAIS] = {3, 7, 11, 13, 18, 23, 24, 26, 27};
char reconhecida[200] = "";

int percorreVetor(char caractere);
bool ehEstadoFinal(int estadoDepois);
void simboloReconhecido(int i_recon, char caractere);
void limpaReconhecida();

void main () {

    char entrada[200];

    int current_state = 1;
    int estadoDepois = 0;
    int last_final = 0;

    int i_recon = 0;
    int control = 0;

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
    char vetorCaracteres[NUM_SYMBOLS] = {'b', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'n', 'p', 'r', 's', 't', 
                                        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '+', ';', '='};

    for (int i = 0; i < NUM_SYMBOLS; i++){
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
