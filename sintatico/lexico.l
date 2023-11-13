%option noyywrap

%{
    #include <sintatico.tab.h>
    #include <string.h>

    int linha=1;
    int coluna=1;
    int qtdeComentarios=0;
    int existePrimeiroToken = 0;
    int abreComentario = 0;

    void warning() {
        int i=0;
        for(i = 0; i < strlen(yytext); i++){
            if(yytext[i]=='\n'){
                linha += 1; 
                coluna = 1;
            }else{
                coluna += 1;
            }
            if(yytext[i]=='/' && i < (strlen(yytext)-1) && i > 0){
                if(yytext[i+1]=='*' && yytext[i+2] != '/')	{
                    printf("warning:%d:%d: \'/*\' within block comment\n", linha, coluna-1);
                }
            }	
        }	
    }

%}

%%

"void" {coluna += strlen(yytext); return VOID; }
"int" {coluna += strlen(yytext); return INT; }
"char" {coluna += strlen(yytext); return CHAR; }
"return" {coluna += strlen(yytext); return RETURN; }
"break" {coluna += strlen(yytext); return BREAK; }
"switch" {coluna += strlen(yytext); return SWITCH; }
"case" {coluna += strlen(yytext); return CASE; }
"default" {coluna += strlen(yytext); return DEFAULT; }
"do" {coluna += strlen(yytext); return DO; }
"while" {coluna += strlen(yytext); return WHILE; }
"for" {coluna += strlen(yytext); return FOR; }
"if" {coluna += strlen(yytext); return IF; }
"else" {coluna += strlen(yytext); return ELSE; }
"typedef" {coluna += strlen(yytext); return TYPEDEF; }
"struct" { coluna += strlen(yytext); return STRUCT; }
"+" {coluna += strlen(yytext); return PLUS; }
"-" {coluna += strlen(yytext); return MINUS; }
"*" {coluna += strlen(yytext); return MULTIPLY; }
"/" {coluna += strlen(yytext); return DIV; }
"%" {coluna += strlen(yytext); return REMAINDER; }
"++" {coluna += strlen(yytext); return INC; }
"--" {coluna += strlen(yytext); return DEC; }
"&" {coluna += strlen(yytext); return BITWISE_AND; }
"|" {coluna += strlen(yytext); return BITWISE_OR; }
"~" {coluna += strlen(yytext); return BITWISE_NOT; }
"^" {coluna += strlen(yytext); return BITWISE_XOR; }
"!" {coluna += strlen(yytext); return NOT; }
"&&" {coluna += strlen(yytext); return LOGICAL_AND; }
"||" {coluna += strlen(yytext); return LOGICAL_OR; }
"==" {coluna += strlen(yytext); return EQUAL; }
"!=" {coluna += strlen(yytext); return NOT_EQUAL; }
"<" {coluna += strlen(yytext); return LESS_THAN; }
">" {coluna += strlen(yytext); return GREATER_THAN; }
"<=" {coluna += strlen(yytext); return LESS_EQUAL; }
">=" {coluna += strlen(yytext); return GREATER_EQUAL; }
">>" {coluna += strlen(yytext); return R_SHIFT; }
"<<" {coluna += strlen(yytext); return L_SHIFT; }
"=" {coluna += strlen(yytext); return ASSIGN; }
"+=" {coluna += strlen(yytext); return ADD_ASSIGN; }
"-=" {coluna += strlen(yytext); return MINUS_ASSIGN; }
";" {coluna += strlen(yytext); return SEMICOLON; }
"," {coluna += strlen(yytext); return COMMA; }
":" {coluna += strlen(yytext); return COLON;}
"(" {coluna += strlen(yytext); return L_PAREN;}
")" {coluna += strlen(yytext); return R_PAREN;}
"{" {coluna += strlen(yytext); return L_CURLY_BRACKET;}
"}" {coluna += strlen(yytext); return R_CURLY_BRACKET;}
"[" {coluna += strlen(yytext); return L_SQUARE_BRACKET;}
"]" {coluna += strlen(yytext); return R_SQUARE_BRACKET;}
"?" {coluna += strlen(yytext); return TERNARY_CONDITIONAL;}
"#" {coluna++; return NUMBER_SIGN;}
"->" {coluna += strlen(yytext); return POINTER;}
"printf" {coluna += strlen(yytext); return PRINTF;}
"scanf" {coluna += strlen(yytext); return SCANF;}
"define" {coluna += strlen(yytext); return DEFINE;}
"exit" {coluna += strlen(yytext); return EXIT;}

[_a-zA-Z][_a-zA-Z0-9]* {if(strlen(yytext)>255){return IDENTIFIER_TOO_LONG;}else{coluna += strlen(yytext);return IDENTIFIER; }}
"0"[1-7][0-7]* {coluna += strlen(yytext);return NUM_OCTAL; }
[0-9]+ { coluna += strlen(yytext);return NUM_INTEGER;}
0[xX][0-9a-fA-F]+ {coluna += strlen(yytext);return NUM_HEXA; }
["]([^"\\\n]|\\.|\\\n)*["] {coluna += strlen(yytext);return STRING;}
"\'""\\"?."\'" {coluna += strlen(yytext); return CHARACTER;}
[\r\t \f] {coluna += 1;}
"//".*[\n] {linha += 1; coluna = 1;}
"//".* {return END_OF_FILE;}
("/*"([^*]|[\n]|("*"+([^*/]|[\n])))*"*/") {warning();}
("/*"([^*]|[\n]|("*"+([^*/]|[\n])))*)	{return  UNTERMINATED_COMMENT;}
[\n] {linha += 1; coluna = 1;}
<<EOF>> {return END_OF_FILE;}
. { coluna += strlen(yytext); return OTHER;}

%%
