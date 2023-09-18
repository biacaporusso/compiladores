%option noyywrap

%{

int linha=1;
int coluna=0;

void printarErro(int linha, int coluna, char* erro) {
    printf("error:lexical:%d:%d: %s\n", linha, coluna, erro);
}
void printarErroLongo(int linha, int coluna) {
    printf("error:lexical:%d:%d: identifier too long\n", linha, coluna);
}
%}

%%

"void" {printf("VOID\n"), coluna += strlen(yytext);}
"int" {printf("INT\n"), coluna += strlen(yytext);}
"char" {printf("CHAR\n"), coluna += strlen(yytext);}
"return" {printf("RETURN\n"), coluna += strlen(yytext);}
"break" {printf("BREAK\n"), coluna += strlen(yytext);}
"switch" {printf("SWITCH\n"), coluna += strlen(yytext);}
"case" {printf("CASE\n"), coluna += strlen(yytext);}
"default" {printf("DEFAULT\n"), coluna += strlen(yytext);}
"do" {printf("DO\n"), coluna += strlen(yytext);}
"while" {printf("WHILE\n"), coluna += strlen(yytext);}
"for" {printf("FOR\n"), coluna += strlen(yytext);}
"if" {printf("IF\n"), coluna += strlen(yytext);}
"else" {printf("ELSE\n"), coluna += strlen(yytext);}
"typedef" {printf("TYPEDEF\n"), coluna += strlen(yytext);}
"struct" {printf("STRUCT\n"), coluna += strlen(yytext);}
"+" {printf("PLUS\n"), coluna += strlen(yytext);}
"-" {printf("MINUS\n"), coluna += strlen(yytext);}
"*" {printf("MULTIPLY\n"), coluna += strlen(yytext);}
"/" {printf("DIV\n"), coluna += strlen(yytext);}
"%" {printf("REMAINDER\n"), coluna += strlen(yytext);}
"++" {printf("INC\n"), coluna += strlen(yytext);}
"--" {printf("DEC\n"), coluna += strlen(yytext);}
"&" {printf("BITWISE_AND\n"), coluna += strlen(yytext);}
"|" {printf("BITWISE_OR\n"), coluna += strlen(yytext);}
"~" {printf("BITWISE_NOT\n"), coluna += strlen(yytext);}
"^" {printf("BITWISE_XOR\n"), coluna += strlen(yytext);}
"!" {printf("NOT\n"), coluna += strlen(yytext);}
"&&" {printf("LOGICAL_AND\n"), coluna += strlen(yytext);}
"||" {printf("LOGICAL_OR\n"), coluna += strlen(yytext);}
"==" {printf("EQUAL"), coluna += strlen(yytext);}
"!=" {printf("NOT_EQUAL\n"), coluna += strlen(yytext);}
"<" {printf("LESS_THAN\n"), coluna += strlen(yytext);}
">" {printf("GREATER_THAN\n"), coluna += strlen(yytext);}
"<=" {printf("LESS_EQUAL\n"), coluna += strlen(yytext);}
">=" {printf("GREATER_EQUAL\n"), coluna += strlen(yytext);}
">>" {printf("R_SHIFT\n"), coluna += strlen(yytext);}
"<<" {printf("L_SHIFT\n"), coluna += strlen(yytext);}
"=" {printf("ASSIGN\n"), coluna += strlen(yytext);}
"+=" {printf("ADD_ASIGN\n"), coluna += strlen(yytext);}
"-=" {printf("MINUS_ASSIGN\n"), coluna += strlen(yytext);}
";" {printf("SEMICOLON\n"), coluna += strlen(yytext);}
"," {printf("COMMA\n"), coluna += strlen(yytext);}
":" {printf("COLON\n"), coluna += strlen(yytext);}
"(" {printf("L_PAREN\n"), coluna += strlen(yytext);}
")" {printf("R_PAREN\n"), coluna += strlen(yytext);}
"{" {printf("L_CURLY_BRACKET\n"), coluna += strlen(yytext);}
"}" {printf("R_CURLY_BRACKET\n"), coluna += strlen(yytext);}
"[" {printf("L_SQUARE_BRACKET\n"), coluna += strlen(yytext);}
"]" {printf("R_SQUARE_BRACKET\n"), coluna += strlen(yytext);}
"?" {printf("TERNARY_CONDITIONAL\n"), coluna += strlen(yytext);}
"#" {printf("NUMBER_SIGN\n"), coluna++;}
"->" {printf("POINTER\n"), coluna += strlen(yytext);}
"printf" {printf("PRINTF\n"), coluna += strlen(yytext);}
"scanf" {printf("SCANF\n"), coluna += strlen(yytext);}
"define" {printf("DEFINE\n"), coluna += strlen(yytext);}
"exit" {printf("EXIT\n"), coluna += strlen(yytext);}

0[x|X][0-9|a-f|A-F]+ {printf("NUM_HEXA(%s)\n", yytext), coluna += strlen(yytext);}
0[1-7]+[0-7]+ {printf("NUM_OCTAL(%s)\n", yytext), coluna += strlen(yytext);}
[0-9]+ {printf("NUM_INTEGER(%s)\n", yytext), coluna += strlen(yytext);}
[a-z|A-Z|_]+[0-9|a-z|A-Z|_]* {
    if (strlen(yytext) !=0) {
        printf("IDENTIFIER(%s)\n", yytext);
        coluna += strlen(yytext);
    } else {
        printarErroLongo(linha, coluna);
    }
}
\"[^\"\n]\" {printf("CHARACTER(%s)\n", yytext), coluna += strlen(yytext);}
\"[^\"\n]+\" {printf("STRING(%s)\n", yytext), coluna += strlen(yytext);}
"\n" {linha++, coluna=0;}
" " {coluna++;}
. {printarErro(linha, coluna, yytext), coluna += strlen(yytext);}

%%

int main (int argc, char** argv) {
    yylex();
    return 0;
}