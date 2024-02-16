%option noyywrap

%{

#include <sintatico.tab.h>
#include <stdio.h>

void numeroReal() {
    printf("numero real\n");
}

void numeroInteiro() {
    printf("numero inteiro\n");
}

void identificador() {
    printf("identificador\n");
}

void teste() {
    printf("testeAAAAAAAA\n");
}

%}

%%

"about" { return ABOUT; }
"abs" { return ABS; }
"axis" { return AXIS; }
"connect_dots" { return CONNECT_DOTS; }
"cos" { return COS; }
"determinant" { return DETERMINANT; }
[Ee] { return E; }
"erase" { return ERASE; }
"float" { return FLOAT; }
"h_view" { return H_VIEW; }
"integral_steps" { return INTEGRAL_STEPS; }
"integrate" { return INTEGRATE; }
"linear_system" { return LINEAR_SYSTEM; }
"matrix" { return MATRIX; }
"off" { return OFF; }
"on" { return ON; }
[Pp][Ii] { return PI; }
"plot" { return PLOT; }
"precision" { return PRECISION; }
"quit" { return QUIT; }
"reset" { return RESET; }
"rpn" { return RPN; }
"sen" { return SEN; }
"set" { return SET; }
"settings" { return SETTINGS; }
"show" { return SHOW; }
"solve" { return SOLVE; }
"sum" { return SUM; }
"symbols" { return SYMBOLS; }
"tan" { return TAN; }
"v_view" { return V_VIEW; }
[Xx] { return X; }
"+" { return ADICAO; }
"-" { return SUBTRACAO; }
"*" { return MULTIPLICACAO; }
"/" { return DIVISAO; }
"^" { return POTENCIACAO; }
"%" { return RESTO_DIVISAO; }
"(" { return ABRE_PARENTESES; }
")" { return FECHA_PARENTESES; }
":" { return INTERVALO; }
"=" { return IGUAL; }
":=" { return ATRIBUICAO; }
"[" { return ABRE_COLCHETES; }
"]" { return FECHA_COLCHETES; }
";" { return PONTO_VIRGULA; }
"," { return VIRGULA; }

[0-9]+"."[0-9]+ {return NUMERO_REAL;}
[0-9]+ {return NUMERO_INTEIRO;}
[a-zA-Z]+[_0-9a-zA-Z]* {return IDENTIFICADOR;}


%%