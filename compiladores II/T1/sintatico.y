%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "ast.h"
    #include "hash.h"
    #include "settings.h"

    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);

    // estruturas de dados
    TreeNode* AST = NULL;
    HashTable* hash = NULL;
    Settings* settings = NULL;
    Matriz* matriz = NULL;
    ListaLinhas* lista_matriz = NULL;

    // variaveis globais
    int num_linhas = 1;
    int num_colunas = 0;
    int max_colunas = 0;
    char* string_matriz;
    
    int funcao_inserida = 0;

    // DECLARAÇÃO DAS FUNÇÕES
    void informacoes_aluno();
    void comando_sum(char* variavel, TreeNode *lim_inferior, TreeNode *lim_superior, TreeNode *no_expr, HashTable* hash);
    char* concat_strings(const char* str1, const char* str2);
    char* to_string(float value);

%}

%union {
    TreeNode* ast;
    int integer;
    float flutuante;
    char identifier[1024];
}

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

%token EOL 
%token INVALID_SYMBOL
%token SYNTAX_ERROR

//%type <ast> calc
%type <ast> exp
%type <ast> factor
%type <ast> term
%type <integer> NUMERO_INTEIRO
%type <flutuante> NUMERO_REAL
%type <identifier> IDENTIFICADOR
%type <ast> valor
%type <ast> func_trigonometrica

%start inicio

%%

inicio:
    comando {}
;

comando:
    SHOW p1 { return 1; }
    | RESET SETTINGS PONTO_VIRGULA EOL { set_default_settings(settings); return 1; }
    | QUIT EOL { return 0; }
    | SET p3 { return 1; }
    | PLOT p4 { return 1; }
    | INTEGRATE ABRE_PARENTESES valor INTERVALO valor VIRGULA func_trigonometrica FECHA_PARENTESES  PONTO_VIRGULA EOL { 
        if($3->value_float > $5->value_float) {
            printf("ERROR: lower limit must be smaller than upper limit\n");
            return 1;
        }
        /*comando_integrate($3->value_float, $5->value_float, $7);*/ 
        return 1; 
        }
    | MATRIX IGUAL cria_matriz { 
        printf("\nstring matriz no final: %s\n", string_matriz);
        printf("num linhas: %d\nnum colunas: %d\n\n", num_linhas, max_colunas);
        //liberar_matriz(matriz);

        if(num_linhas > 10 || max_colunas > 10) {
            printf("ERROR: Matrix limits out of boundaries.\n");
            return 1;
        }
        matriz = create_matrix(num_linhas, max_colunas);
        imprimir_matriz(matriz);
        formatar_matriz(matriz, string_matriz, num_linhas, max_colunas);
        //max_colunas=0; num_linhas=1; num_colunas=1; 
        return 1;
    }
    | SOLVE p5 {}
    | ABOUT PONTO_VIRGULA EOL { informacoes_aluno(); return 1; }
    | RPN ABRE_PARENTESES exp FECHA_PARENTESES PONTO_VIRGULA EOL {}
    | SUM ABRE_PARENTESES IDENTIFICADOR VIRGULA valor INTERVALO valor VIRGULA exp FECHA_PARENTESES PONTO_VIRGULA EOL { comando_sum($3, $5, $7, $9, hash); return 1; }
    | IDENTIFICADOR PONTO_VIRGULA EOL {
        int existe;
        //printf("antes do search");
        existe = search_hash(hash, $1);
        if (existe == -1) {
            printf("Undefined symbol\n");
        } else {
            printf("%s = %.f\n", $1, get_value(hash, $1));
        }
        return 1;
    }
    | IDENTIFICADOR ATRIBUICAO valor PONTO_VIRGULA EOL {

        // VERIFICAr se é valor real ou matriz -> valores da matriz na hash
        printf("%.6f\n", (float) $3->value_float);
        inserir_hash(hash, $1, $3->value_float);
        return 1;

    }
    | IDENTIFICADOR ATRIBUICAO exp PONTO_VIRGULA EOL {
        printf("%f\n", RPN_Walk($3, hash));
        inserir_hash(hash, $1, RPN_Walk($3, hash));
        Delete_Tree($3);
        return 1;
    }
    | exp EOL { 
        if (search_hash(hash, $1->value_string) == -1) {
            printf("Undefined symbol [%s]\n", $1->value_string);
        } else {
            float result = RPN_Walk($1, hash); 
            printf("%.*f\n", settings->float_precision, RPN_Walk($1, hash));
        }

        Delete_Tree($1);
        return 1;
    }
;

p1:
    SETTINGS PONTO_VIRGULA EOL { show_settings(settings); return 1; }
    | MATRIX PONTO_VIRGULA EOL { imprimir_matriz(matriz); }
    | SYMBOLS PONTO_VIRGULA EOL { printar_hash(hash); }
;

p3:
    H_VIEW valor INTERVALO valor PONTO_VIRGULA EOL { 
        if ($2->value_float < $4->value_float) {
            settings->h_view_lo = $2->value_float; settings->h_view_hi = $4->value_float; 
        } else {
            printf("ERROR: h_view_lo must be smaller than h_view_hi\n");
            return 1;
        }
    }
    | V_VIEW valor INTERVALO valor PONTO_VIRGULA EOL { 
        if ($2->value_float < $4->value_float) {
            settings->v_view_lo = $2->value_float; settings->v_view_hi = $4->value_float; 
        } else {
            printf("ERROR: v_view_lo must be smaller than v_view_hi\n");
            return 1;
        }
    }
    | AXIS ON PONTO_VIRGULA EOL { settings->draw_axis = 1; }
    | AXIS OFF PONTO_VIRGULA EOL { settings->draw_axis = 0; }
    | ERASE PLOT OFF PONTO_VIRGULA EOL { settings->erase_plot = 0; }
    | ERASE PLOT ON PONTO_VIRGULA EOL { settings->erase_plot = 1; }
    | INTEGRAL_STEPS valor PONTO_VIRGULA EOL { 
        if ($2->value_float > 0)
            settings->integral_steps = $2->value_int; 
        else {
            printf("ERROR: integral_steps must be a positive non-zero integer\n");
            return 1;
        }
    }
    | FLOAT PRECISION valor PONTO_VIRGULA EOL { settings->float_precision = $3->value_int; }
;

p4:
    PONTO_VIRGULA EOL {
        if(funcao_inserida == 0) {
            printf("\nNo Function defined!\n\n");
            //return 0;
        } else {
            //plot(AST, settings, hash);
            printf("plot");
        }
    }
    | ABRE_PARENTESES func_trigonometrica FECHA_PARENTESES PONTO_VIRGULA EOL {}
;

p5:
    DETERMINANT PONTO_VIRGULA EOL {
        if (matriz->linhas != matriz->colunas) {
            printf("Matrix format incorrect!\n");
            return 1;
        }
    }
    | LINEAR_SYSTEM PONTO_VIRGULA EOL {
        if (matriz->linhas != matriz->colunas + 1) {
            printf("Matrix format incorrect!\n");
            return 1;
        }
    }
;


// hash - só os valores que eu atribuo (ex: bia := 4) só quando atribuir um valor
exp: 
    factor { $$ = $1; }
    | exp ADICAO factor { 
        //  create_ast_node(node_type, value_int, value_float, value_string, left, right);
        TreeNode* aux = create_ast_node(ADICAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
    | exp SUBTRACAO factor { 
        TreeNode* aux = create_ast_node(SUBTRACAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
;

factor: 
    term { $$ = $1; }
    | factor MULTIPLICACAO term { 
        //  create_ast_node(node_type, value_int, value_float, value_string, left, right);
        TreeNode* aux = create_ast_node(MULTIPLICACAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
    | factor DIVISAO term { 
        TreeNode* aux = create_ast_node(DIVISAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
    | factor POTENCIACAO term { 
        TreeNode* aux = create_ast_node(POTENCIACAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
    | factor RESTO_DIVISAO term { 
        TreeNode* aux = create_ast_node(RESTO_DIVISAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
    | func_trigonometrica { $$ = $1; }
;

func_trigonometrica:

     SEN ABRE_PARENTESES exp FECHA_PARENTESES {
        TreeNode* aux = create_ast_node(SEN, -2,-2, NULL, $3, NULL);
        $$ = aux;
    }
    |  COS ABRE_PARENTESES exp FECHA_PARENTESES {
        TreeNode* aux = create_ast_node(COS, -2, -2, NULL, $3, NULL);
        $$ = aux;
    }
    |  TAN ABRE_PARENTESES exp FECHA_PARENTESES {
        TreeNode* aux = create_ast_node(TAN, -2, -2, NULL, $3, NULL);
        $$ = aux;
    }
    |  ABS ABRE_PARENTESES exp FECHA_PARENTESES {
        TreeNode* aux = create_ast_node(ABS, $3->value_int, $3->value_float, NULL, $3, NULL);
        $$ = aux;
    } 
    
;

term: 
    valor { $$ = $1; }
    | IDENTIFICADOR { 
        //  create_ast_node(node_type, value_int, value_float, value_string, left, right);
        TreeNode* aux = create_ast_node(IDENTIFICADOR, -2, -2, $1, NULL, NULL);
        $$ = aux;
    }

    | ABRE_PARENTESES exp FECHA_PARENTESES {
        $$ = $2;
    } 

;

valor:
    ADICAO NUMERO_REAL { 
        //  create_ast_node(node_type, value_int, value_float, value_string, left, right);
        TreeNode* aux = create_ast_node(NUMERO_REAL, (int)$2, $2, NULL, NULL, NULL);
        $$ = aux;
    }
    | SUBTRACAO NUMERO_REAL { 
        TreeNode* aux = create_ast_node(NUMERO_REAL, (int)-$2, -$2, NULL, NULL, NULL);
        $$ = aux;
    }
    | NUMERO_REAL {
        TreeNode* aux = create_ast_node(NUMERO_REAL, (int)$1, $1, NULL, NULL, NULL);
        $$ = aux; 
    }
    | ADICAO NUMERO_INTEIRO {
        TreeNode* aux = create_ast_node(NUMERO_INTEIRO, $2, (float)$2, NULL, NULL, NULL);
        $$ = aux;
    }
    | SUBTRACAO NUMERO_INTEIRO {
        TreeNode* aux = create_ast_node(NUMERO_INTEIRO, -$2, (float)-$2, NULL, NULL, NULL);
        $$ = aux;
    }
    | NUMERO_INTEIRO { 
        TreeNode* aux = create_ast_node(NUMERO_INTEIRO, $1, (float)$1, NULL, NULL, NULL);
        $$ = aux; 
    }
;

//  { , valor }∗                                ** numero de colunas
zero_ou_mais_colunas:
    valores_matriz {
        //verificar se qtde de colunas atuais é maior q qtde de colunas 
        if (num_colunas > max_colunas)
            max_colunas = num_colunas;
        num_colunas = 0;
        // resetar qtde de colunas atuais pra 0
    }
;

valores_matriz:
    VIRGULA valor {
        char valor_em_string[20];
        strcpy(valor_em_string, to_string($2->value_float));
        //printf("valor em string1: %s\n", valor_em_string);
        string_matriz = concat_strings(string_matriz, valor_em_string);
        num_colunas++;
    }
    | valores_matriz VIRGULA valor {
        char valor_em_string2[20];
        strcpy(valor_em_string2, to_string($3->value_float));
        string_matriz = concat_strings(string_matriz, valor_em_string2);
        num_colunas++;
    }
    | valor {
        char valor_em_string3[20];
        strcpy(valor_em_string3, to_string($1->value_float));
        string_matriz = concat_strings(string_matriz, valor_em_string3);
        num_colunas++;
    }


//   { ∗ ] }∗  , [ valor { , valor }            ** zero ou mais linhas
zero_ou_mais_linhas:  { strcat(string_matriz, " "); strcat(string_matriz, "|"); }
    VIRGULA ABRE_COLCHETES zero_ou_mais_colunas FECHA_COLCHETES { 
        strcat(string_matriz, "|");
        strcat(string_matriz, " ");
        //strcat(string_matriz, " ");
        num_linhas++; } 
    | zero_ou_mais_linhas VIRGULA ABRE_COLCHETES zero_ou_mais_colunas FECHA_COLCHETES {
        strcat(string_matriz, "|");
        strcat(string_matriz, " ");
        //strcat(string_matriz, " ");
        num_linhas++; 
    }
;

cria_matriz: //  [ [ valor zero_ou_mais_valores_interno ] {,[ valor zero_ou_mais_valores_interno ] }∗ ];
    ABRE_COLCHETES ABRE_COLCHETES zero_ou_mais_colunas FECHA_COLCHETES zero_ou_mais_linhas FECHA_COLCHETES PONTO_VIRGULA EOL { 
        if (num_colunas > max_colunas) 
            max_colunas = num_colunas;
        
        printf("matriz com %d linhas e %d colunas\n", num_linhas, max_colunas);
    }
    | ABRE_COLCHETES ABRE_COLCHETES zero_ou_mais_colunas FECHA_COLCHETES FECHA_COLCHETES PONTO_VIRGULA EOL {
        if (num_colunas > max_colunas) 
            max_colunas = num_colunas;
        printf("matriz com %d linhas e %d colunas\n", num_linhas, max_colunas);
    }
;

%%

char* to_string(float value) {     
    // Determine the maximum size needed for the string     
    int size = snprintf(NULL, 0, "%f", value);      
    // Allocate memory for the string     
    char* result = (char*)malloc(size + 1);  // +1 for the null terminator      
    // Convert float to string     
    snprintf(result, size + 1, "%f", value);      
    return result; 
}  
    
char* concat_strings(const char* str1, const char* str2) {      
    int size = strlen(str1) + strlen(str2) + 2;      
    char* result = (char*)malloc(size);     
    if (!result) {         // Tratamento de erro se a alocação falhar         
        printf("erro alocação\n");     
    }      
    strcpy(result, str1);    
    strcat(result, " ");// space between str1 and str2     
    strcat(result, str2);      
    return result; 
}

void informacoes_aluno() {
    printf("+--------------------------------------------------------+\n");
    printf("|                                                        |\n");
    printf("|              Beatriz Barrios Caporusso                 |\n");
    printf("|                    202000560034                        |\n");
    printf("|                                                        |\n");
    printf("+--------------------------------------------------------+\n");

}

void comando_sum(char* variavel, TreeNode *lim_inferior, TreeNode *lim_superior, TreeNode *no_expr, HashTable* hash) {

    float result_somatorio = 0;

    for (int i=lim_inferior->value_int; i<=lim_superior->value_int; i++) {
         inserir_hash(hash, variavel, i);
        result_somatorio += RPN_Walk(no_expr, hash);
    }

    printf("%f", result_somatorio);
}

int main(int argc, char** argv) {

    settings = create_settings();
    hash = create_hash_table();
    //matriz = create_matrix(10, 10);
    string_matriz = malloc(sizeof(char*));
    lista_matriz = newNode_listaExterna();

    int verificador_comandos = 1;

    while (verificador_comandos == 1) {
        printf("\n>");
        verificador_comandos = yyparse();
        //free(string_matriz);
    }
    return 0;
}

void yyerror(char *s) {
	
    switch(yychar) {
        case INVALID_SYMBOL:
            printf("Invalid Symbol: %s\n", yytext);
            break;
        case SYNTAX_ERROR:
            printf("SYNTAX ERROR: [%s]\n", yytext);
            break;
        default:
            printf("SYNTAX ERROR: Incomplete Command\n");
            break;
    }
}