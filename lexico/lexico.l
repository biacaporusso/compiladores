%option noyywrap

%{

int linha=1;
int coluna=1;
int qtdeComentarios=0;
int existePrimeiroToken = 0;
int abreComentario = 0;

void printarErro(int linha, int coluna, char* erro) {
    if (existePrimeiroToken == 0) {
        printf("error:lexical:%d:%d: %s", linha, coluna, erro);
        existePrimeiroToken = 1;
    } else {
        printf("\nerror:lexical:%d:%d: %s", linha, coluna, erro);
    }
}
void printarErroLongo(int linha, int coluna) {
    if (existePrimeiroToken == 0) {
        printf("error:lexical:%d:%d: identifier too long", linha, coluna);
        existePrimeiroToken = 1;
    } else {
        printf("\nerror:lexical:%d:%d: identifier too long", linha, coluna);
    }
}
void printarToken(char* token) {
    if (existePrimeiroToken == 0) {
        printf("%s", token); // não tem token ainda, é o primeiro token, então não pula linha 
        existePrimeiroToken = 1; // atualiza o verificador indicando que já existe um primeiro token
    } else { 
        printf("\n%s", token); // não é o primeiro token então imprime o \n antes
    }
}
void printarStringSemAspasDuplas(char* token) {
    printf("(");
    for (int i=1; i < strlen(token) -1; i++) {
        printf("%c", token[i]);
    }
    printf(")");
}
void printarUnterminatedComment(int linha, int coluna) {
    if (existePrimeiroToken == 0) {
        printf("error:lexical:%d:%d: unterminated comment", linha, coluna); 
        existePrimeiroToken = 1; // atualiza o verificador indicando que já existe um primeiro token
    } else { 
        printf("\nerror:lexical:%d:%d: unterminated comment", linha, coluna);
    }
}

void verificaWarnings(char* yytext, int linha, int coluna) {

    for(int i=2; i<strlen(yytext); i++) {

        if(yytext[i] == '/') {
            if (yytext[i+1] == '*') {
                if (yytext[i+2] != '/') {
                    printf("\nwarning:%d:%d: '/*' within block comment", linha, coluna);
                    coluna++;
                }
            } else {
                coluna++;
            }
        } else {
            coluna++;
        }
        if (yytext[i] == '\n') {
            coluna = 1;
            linha++;
        }
    }
}

void printarWarning(int linha, int coluna) {
    if (existePrimeiroToken == 0) {
        printf("warning:%d:%d: '/*' within block comment", linha, coluna);
        existePrimeiroToken = 1;
    } else {
        printf("\nwarning:%d:%d: '/*' within block comment", linha, coluna);
    }
}

%}

%%

"void" {printarToken("VOID"), coluna += strlen(yytext);}
"int" {printarToken("INT"), coluna += strlen(yytext);}
"char" {printarToken("CHAR"), coluna += strlen(yytext);}
"return" {printarToken("RETURN"), coluna += strlen(yytext);}
"break" {printarToken("BREAK"), coluna += strlen(yytext);}
"switch" {printarToken("SWITCH"), coluna += strlen(yytext);}
"case" {printarToken("CASE"), coluna += strlen(yytext);}
"default" {printarToken("DEFAULT"), coluna += strlen(yytext);}
"do" {printarToken("DO"), coluna += strlen(yytext);}
"while" {printarToken("WHILE"), coluna += strlen(yytext);}
"for" {printarToken("FOR"), coluna += strlen(yytext);}
"if" {printarToken("IF"), coluna += strlen(yytext);}
"else" {printarToken("ELSE"), coluna += strlen(yytext);}
"typedef" {printarToken("TYPEDEF"), coluna += strlen(yytext);}
"struct" {printarToken("STRUCT"), coluna += strlen(yytext);}
"+" {printarToken("PLUS"), coluna += strlen(yytext);}
"-" {printarToken("MINUS"), coluna += strlen(yytext);}
"*" {printarToken("MULTIPLY"), coluna += strlen(yytext);}
"/" {printarToken("DIV"), coluna += strlen(yytext);}
"%" {printarToken("REMAINDER"), coluna += strlen(yytext);}
"++" {printarToken("INC"), coluna += strlen(yytext);}
"--" {printarToken("DEC"), coluna += strlen(yytext);}
"&" {printarToken("BITWISE_AND"), coluna += strlen(yytext);}
"|" {printarToken("BITWISE_OR"), coluna += strlen(yytext);}
"~" {printarToken("BITWISE_NOT"), coluna += strlen(yytext);}
"^" {printarToken("BITWISE_XOR"), coluna += strlen(yytext);}
"!" {printarToken("NOT"), coluna += strlen(yytext);}
"&&" {printarToken("LOGICAL_AND"), coluna += strlen(yytext);}
"||" {printarToken("LOGICAL_OR"), coluna += strlen(yytext);}
"==" {printarToken("EQUAL"), coluna += strlen(yytext);}
"!=" {printarToken("NOT_EQUAL"), coluna += strlen(yytext);}
"<" {printarToken("LESS_THAN"), coluna += strlen(yytext);}
">" {printarToken("GREATER_THAN"), coluna += strlen(yytext);}
"<=" {printarToken("LESS_EQUAL"), coluna += strlen(yytext);}
">=" {printarToken("GREATER_EQUAL"), coluna += strlen(yytext);}
">>" {printarToken("R_SHIFT"), coluna += strlen(yytext);}
"<<" {printarToken("L_SHIFT"), coluna += strlen(yytext);}
"=" {printarToken("ASSIGN"), coluna += strlen(yytext);}
"+=" {printarToken("ADD_ASSIGN"), coluna += strlen(yytext);}
"-=" {printarToken("MINUS_ASSIGN"), coluna += strlen(yytext);}
";" {printarToken("SEMICOLON"), coluna += strlen(yytext);}
"," {printarToken("COMMA"), coluna += strlen(yytext);}
":" {printarToken("COLON"), coluna += strlen(yytext);}
"(" {printarToken("L_PAREN"), coluna += strlen(yytext);}
")" {printarToken("R_PAREN"), coluna += strlen(yytext);}
"{" {printarToken("L_CURLY_BRACKET"), coluna += strlen(yytext);}
"}" {printarToken("R_CURLY_BRACKET"), coluna += strlen(yytext);}
"[" {printarToken("L_SQUARE_BRACKET"), coluna += strlen(yytext);}
"]" {printarToken("R_SQUARE_BRACKET"), coluna += strlen(yytext);}
"?" {printarToken("TERNARY_CONDITIONAL"), coluna += strlen(yytext);}
"#" {printarToken("NUMBER_SIGN"), coluna++;}
"->" {printarToken("POINTER"), coluna += strlen(yytext);}
"printf" {printarToken("PRINTF"), coluna += strlen(yytext);}
"scanf" {printarToken("SCANF"), coluna += strlen(yytext);}
"define" {printarToken("DEFINE"), coluna += strlen(yytext);}
"exit" {printarToken("EXIT"), coluna += strlen(yytext);}

0[x|X][0-9|a-f|A-F]+ {printarToken("NUM_HEXA"); printf("(%s)", yytext); coluna += strlen(yytext);}
0[1-7][0-7]* {printarToken("NUM_OCTAL"); printf("(%s)", yytext); coluna += strlen(yytext);}
[0-9]+ {printarToken("NUM_INTEGER"); printf("(%s)", yytext); coluna += strlen(yytext);}


[a-z|A-Z|_]+[0-9|a-z|A-Z|_]* {
    if (strlen(yytext) <= 255) {
        printarToken("IDENTIFIER"); printf("(%s)", yytext);
        coluna += strlen(yytext);
    } else {
        printarErroLongo(linha, coluna);
    }
}
"\'""\\"?."\'"  {printarToken("CHARACTER"); printarStringSemAspasDuplas(yytext); coluna += strlen(yytext);}
\"[^\"\n]*\" {printarToken("STRING"); printarStringSemAspasDuplas(yytext); coluna += strlen(yytext);}
"\n" {linha++, coluna=1;}
" " {coluna++;}

"//".* {coluna += strlen(yytext);}

("/*"([^*]|[\n]|("*"+([^*/]|[\n])))*"*/") {verificaWarnings(yytext, linha, coluna);}

("/*"([^*]|[\n]|("*"+([^*/]|[\n])))*) {printarUnterminatedComment(linha, coluna);}


"\\" {coluna += strlen(yytext);}
"\'" {coluna += strlen(yytext);}
"\"" {coluna += strlen(yytext);}

"\0" {coluna += strlen(yytext);}

. {printarErro(linha, coluna, yytext), coluna += strlen(yytext);}

%%

int main (int argc, char** argv) {
    yylex();
    return 0;
}