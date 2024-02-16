%{
    #include <stdio.h>
    #include <string.h>

    extern char* yytext;
    extern int yylex();
    void yyerror(char *s);
    
    // VALORES PADRÃO DAS VARIÁVEIS INTERNAS
    float h_view_lo = -6.500000;
    float h_view_hi = 6.500000;
    float v_view_lo = -3.500000;
    float v_view_hi = 3.500000;
    int float_precision = 6;
    int integral_steps = 1000;
    // ON = 1
    // OFF = 0
    int draw_axis = 1;
    int erase_plot = 1;
    int connect_dots = 0;

    // DECLARAÇÃO DAS FUNÇÕES
    void informacoes_aluno();
    void mostrar_configuracoes();
    void resetar_configuracoes();

%}

%token ABOUT
%token ABS
%token AXIS
%token CONNECT_DOTS
%token COS
%token DETERMINANT
%token E
%token ERASE
%token FLOAT
%token H_VIEW
%token INTEGRAL_STEPS
%token INTEGRATE 
%token LINEAR_SYSTEM
%token MATRIX
%token OFF
%token ON
%token PI 
%token PLOT
%token PRECISION
%token QUIT
%token RESET
%token RPN
%token SEN
%token SET
%token SETTINGS
%token SHOW
%token SOLVE
%token SUM
%token SYMBOLS
%token TAN
%token V_VIEW
%token X
%token ADICAO
%token SUBTRACAO
%token MULTIPLICACAO
%token DIVISAO
%token POTENCIACAO
%token RESTO_DIVISAO
%token ABRE_PARENTESES
%token FECHA_PARENTESES
%token INTERVALO
%token IGUAL
%token ATRIBUICAO
%token ABRE_COLCHETES
%token FECHA_COLCHETES
%token PONTO_VIRGULA
%token VIRGULA
%token NUMERO_REAL
%token NUMERO_INTEIRO
%token IDENTIFICADOR


%start inicio

%%

inicio:
    comando {}
    | expressao {}
;

comando:
    SHOW  p1 {}
    | RESET p2 {}
    | QUIT { return 0; }
    | SET p3 {}
    | PLOT p4 {}
    | INTEGRATE ABRE_PARENTESES valor_float INTERVALO valor_float VIRGULA funcao FECHA_PARENTESES  PONTO_VIRGULA {}
    | SUM ABRE_PARENTESES variavel VIRGULA valor_float INTERVALO valor_float VIRGULA expressao FECHA_PARENTESES PONTO_VIRGULA {}
    | MATRIX IGUAL ABRE_COLCHETES ABRE_COLCHETES valor_float{}
    | SOLVE p5 {}
    | ABOUT PONTO_VIRGULA { informacoes_aluno(); return 1; }
    | RPN ABRE_PARENTESES expressao FECHA_PARENTESES PONTO_VIRGULA {}
    | atribuicao_valores {}
    | atribuicao_matrizes {}
    | mostrando_valor {}
;

variavel: IDENTIFICADOR {}
;

p1:
    SETTINGS PONTO_VIRGULA { mostrar_configuracoes(); return 1; }
    | MATRIX PONTO_VIRGULA {}
    | SYMBOLS PONTO_VIRGULA { /*printa_lista */ }
;

p2:
    SETTINGS PONTO_VIRGULA { resetar_configuracoes(); return 1; }
;

p3:
    H_VIEW valor_float INTERVALO valor_float PONTO_VIRGULA {}
    | V_VIEW valor_float INTERVALO valor_float PONTO_VIRGULA {}
    | AXIS ON PONTO_VIRGULA { draw_axis = 1; return 1;}
    | AXIS OFF PONTO_VIRGULA { draw_axis = 0; return 1; }
    | ERASE PLOT OFF PONTO_VIRGULA {}
    | ERASE PLOT ON PONTO_VIRGULA {}
    | INTEGRAL_STEPS valor_inteiro PONTO_VIRGULA {}
    | FLOAT PRECISION valor_inteiro PONTO_VIRGULA {}
;

p4:
    PONTO_VIRGULA {}
    | ABRE_PARENTESES funcao FECHA_PARENTESES PONTO_VIRGULA {}
;

funcao:
    expressao {}
    | SEN ABRE_PARENTESES funcao FECHA_PARENTESES {}
    | COS ABRE_PARENTESES funcao FECHA_PARENTESES {}
    | TAN ABRE_PARENTESES funcao FECHA_PARENTESES {}
    | ABS ABRE_PARENTESES funcao FECHA_PARENTESES {}
;

p5:
    DETERMINANT PONTO_VIRGULA {}
    | LINEAR_SYSTEM PONTO_VIRGULA {}
;

valor_float: 
    ADICAO NUMERO_REAL {}
    | SUBTRACAO NUMERO_REAL {}
    | NUMERO_REAL {}
    | valor_inteiro {}
;

valor_inteiro:
    ADICAO NUMERO_INTEIRO {}
    | SUBTRACAO NUMERO_INTEIRO {}
    | NUMERO_INTEIRO {}
;

expressao: IDENTIFICADOR {}
;

atribuicao_valores:
    variavel ATRIBUICAO expressao PONTO_VIRGULA {}
;

atribuicao_matrizes: IDENTIFICADOR {}
;

mostrando_valor:
    variavel PONTO_VIRGULA {}
;

%%


int main(int argc, char** argv) {

    int verificador_comandos = 1;

    while (verificador_comandos == 1) {
        printf("\n>");
        verificador_comandos = yyparse();
    }
    return 0;
}

void informacoes_aluno() {
    printf("+--------------------------------------------------------+\n");
    printf("|                                                        |\n");
    printf("|              Beatriz Barrios Caporusso                 |\n");
    printf("|                    202000560034                        |\n");
    printf("|                                                        |\n");
    printf("+--------------------------------------------------------+\n");

}

void mostrar_configuracoes() {
    printf("\nh_view_lo: %.6f", h_view_lo);
    printf("\nh_view_hi: %.6f", h_view_hi);
    printf("\nv_view_lo: %.6f", v_view_lo);
    printf("\nv_view_hi: %.6f", v_view_hi);
    printf("\nfloat precision: %d", float_precision);
    printf("\nintegral_steps: %d\n", integral_steps);
    if(draw_axis = 1)
        printf("\nDraw Axis: ON");
    else
        printf("\nDraw Axis: OFF");
    if(erase_plot = 1)
        printf("\nErase Plot: ON");
    else
        printf("\nConnect Dots: OFF");
}

void resetar_configuracoes() {
    h_view_lo = -6.500000;
    h_view_hi = 6.500000;
    v_view_lo = -3.500000;
    v_view_hi = 3.500000;
    float_precision = 6;
    integral_steps = 1000;
    draw_axis = 1;
    erase_plot = 1;
    connect_dots = 0;
}

void yyerror(char *s){
	int i = 1;
	printf("eba pedro");
}

// todos os comandos possiveis