%option noyywrap

%%

"if" {printf("%s IF\n", yytext);}
[a-z]+[a-z0-9]* {printf("%s ID\n", yytext);}
" " {printf("white space\n");}
[0-9]+ {printf("%s NUM\n", yytext);}
[0-9]+"."[0-9]* {printf("%s REAL\n", yytext);}
"-""-"[a-z]*"\n" {yytext[strlen(yytext)-1] = ' '; printf("%scomment\n", yytext);}
"."[0-9]+ {printf("%s REAL", yytext);}
. {printf("%s ERRO\n", yytext);}

%%

int main (int argc, char** argv) {
    yylex();
    return 0;
}