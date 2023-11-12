%{
    /* definitions */
%}

%union {
    int num;
    char sym;
}

%token EOL
%token<num> NUMBER
%type<num> exp
%token PLUS MINUS MULTIPLY

%%

input:
|   line input
;

line: 
    exp EOL { printf("%d\n", $1); }
|   EOL;

exp:  
    NUMBER { $$ = $1; }
|   exp MULTIPLY exp { $$ = $1 * $3; }
|   exp PLUS exp { $$ = $1 + $3; }
|   exp MINUS exp { $$ = $1 - $3; }

%%

int main() {
    yyparse();

    return 0;
}

int yyerror(char* s) {
    printf("ERROR: %s\n", s);
    return 0;
}