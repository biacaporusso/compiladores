%option noyywrap

%%

"+" {printf("+\n");}
"-" {printf("-\n");}
[a-z]+[a-z0-9]* {printf("%s\n", yytext);}
[0-9]+ {printf("%s\n", yytext);}
[0-9]+"e"("+"[0-9]+|"-"[0-9]+|[0-9]+) { printf("%s\n", yytext); }
. {printf("ERRO\n");}

%%

int main (int argc, char** argv) {
    yylex();
    return 0;
}