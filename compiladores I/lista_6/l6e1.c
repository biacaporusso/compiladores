#include <stdio.h>
#include <string.h>

#define ESTADOS 22

int getIndice(char character);

void imprimir_token(int ultimoEstadoFinal) {
	if(ultimoEstadoFinal == 3){
         printf("ELE");
    }
	else if(ultimoEstadoFinal == 6) {
        printf("ELA");
    }else if(ultimoEstadoFinal == 8) {
        printf("DELE");
    }else if(ultimoEstadoFinal == 10){
        printf("DELA");
    }else if(ultimoEstadoFinal == 13){
        printf("GATO");
    }else if(ultimoEstadoFinal == 14){
        printf("CARRO");
    }else if(ultimoEstadoFinal == 15){
        printf("GATOS");
    }else if(ultimoEstadoFinal == 16){
        printf("CARROS");
    }else if(ultimoEstadoFinal == 17){
        printf("MAIS");
    }else if(ultimoEstadoFinal == 18){
        printf("MENOS");
    }else if(ultimoEstadoFinal == 19){
        printf("INTEIRO ");
    }else if(ultimoEstadoFinal == 22){
        printf("REAL ");
    } 
}

int getIndice(char character) {
	if(character == 10) return 0;
	else if(character == 32) return 1;
	else if(character == 43) return 2;
	else if(character == 45) return 3;
	else if(character >= 48 && character <= 57) return character-44;
	else if(character >= 97 && character <= 122) return character-83;
	else return 40;
}




int main() {
	int edges[][128] = {
	/*		\n,  , +, -, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, OTHER*/
	/*00*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*01*/	{0, 0, 17, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 0, 0, 11, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
	/*02*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*03*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*04*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*05*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*06*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*07*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
	/*08*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*09*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0},
	/*10*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*11*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*12*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 13, 0, 0, 0, 0, 0, 0, 0},
	/*13*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0},
	/*14*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0},
	/*15*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*16*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*17*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*18*/	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*19*/	{0, 0, 0, 0, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*20*/	{0, 0, 21, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*21*/	{0, 0, 0, 0, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/*22*/	{0, 0, 0, 0, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

	int estadosFinais[ESTADOS+1] = {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1};
	int estadoInicial = 1;
	int tamanhoEntrada;
	int i;

	char entrada[2048];

	int estadoAtual;
	int inicioCadeia;
	int cursorUltimoFinal;
	int ultimoEstadoFinal;
	int cursorAtual;
	int erroImpresso;

	while(fgets(entrada, sizeof(entrada), stdin)) {
		tamanhoEntrada = strlen(entrada);
		estadoAtual = 1;
		inicioCadeia = 0;
		ultimoEstadoFinal = 0;
		cursorUltimoFinal = 0;
		cursorAtual = -1;

		while(cursorAtual <= tamanhoEntrada) {
			cursorAtual++;
			estadoAtual = edges[estadoAtual][getIndice(entrada[cursorAtual])];

			if(estadoAtual == 0) {
				if(ultimoEstadoFinal == 0) {
					erroImpresso = 0;
					if(entrada[cursorAtual] != 10 && entrada[cursorAtual] != 32) {
						printf("ERRO");
						erroImpresso = 1;
					}
					else if (cursorAtual != inicioCadeia) {
						printf("ERRO");
						erroImpresso = 1;
					}
					if(cursorAtual != inicioCadeia) {
						cursorAtual = inicioCadeia;
						inicioCadeia++;
					}
					else {
						inicioCadeia++;
					}
					estadoAtual = estadoInicial;

					if(erroImpresso && inicioCadeia != tamanhoEntrada) {
						printf("\n");
					}
				}

				else {
					imprimir_token(ultimoEstadoFinal);

					if(ultimoEstadoFinal == 19 || ultimoEstadoFinal == 22 ) {
						for(i = inicioCadeia; i <= cursorUltimoFinal; i++) {
							printf("%c", entrada[i]);
						}
					}

					inicioCadeia = cursorUltimoFinal+1;
					cursorAtual = cursorUltimoFinal;
					estadoAtual = estadoInicial;
					ultimoEstadoFinal = 0;

					if(inicioCadeia != tamanhoEntrada) {
						printf("\n");
					}
				}
			}

			if(estadosFinais[estadoAtual]) {
				ultimoEstadoFinal = estadoAtual;
				cursorUltimoFinal = cursorAtual;
			}

			if(inicioCadeia == tamanhoEntrada) {;
				break;
			}
		}
	}

	return 0;
}



