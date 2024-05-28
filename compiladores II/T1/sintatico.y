%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "ast.h"
    #include "hash.h"
    #include "settings.h"
    #include "pilha.h"

    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);

    // estruturas de dados
    TreeNode* AST = NULL;
    HashTable* hash = NULL;
    Settings* settings = NULL;
    Matriz* matriz = NULL;
    Pilha* pilha_primeirosValores = NULL;
    Pilha* pilha = NULL;
    Matriz* matriz_aux = NULL;

    // variaveis globais
    int num_linhas = 1;
    int num_colunas = 1;
    int max_colunas = 1;
    int matriz_inserida = 0;
    float pi = 3.141593;
    float e = 2.71828182;
    int erro = 0;
    int inseriu = 0;
    int inseriu2 = 0;

    int funcao_inserida = 0;

    extern int erro_eval_exp;

    // DECLARAÇÃO DAS FUNÇÕES
    void informacoes_aluno();
    void comando_sum(char* variavel, TreeNode *lim_inferior, TreeNode *lim_superior, TreeNode *no_expr, HashTable* hash);
    void integrate(float lim_inferior, float lim_superior, TreeNode *no_expr, HashTable* hash);
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
%type <ast> exponenciacao
%type <ast> cria_matriz

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
    | INTEGRATE ABRE_PARENTESES valor INTERVALO valor VIRGULA exp FECHA_PARENTESES  PONTO_VIRGULA EOL { 
        if($3->value_float > $5->value_float) {
            printf("\nERROR: lower limit must be smaller than upper limit\n");
            return 1;
        }
        integrate($3->value_float, $5->value_float, $7, hash);
        return 1; 
        }
    | MATRIX IGUAL cria_matriz { 
        //inseriu = 0;
        clear_matrix(matriz);
        inseriu2 = insert_matrix(matriz, pilha_primeirosValores, pilha, num_linhas, max_colunas);
        num_linhas = 1;
        num_colunas = 1;
        max_colunas = 1;
        clear_stack(pilha_primeirosValores);
        clear_stack(pilha);
        return 1; 
    }
    | SOLVE p5 {}
    | ABOUT PONTO_VIRGULA EOL { informacoes_aluno(); return 1; }
    | RPN ABRE_PARENTESES exp FECHA_PARENTESES PONTO_VIRGULA EOL {
        printf("\nExpression in RPN format:\n\n");
        comando_RPN($3, hash, settings);
        printf("\n");
        return 1;
    }
    | SUM ABRE_PARENTESES IDENTIFICADOR VIRGULA valor INTERVALO valor VIRGULA exp FECHA_PARENTESES PONTO_VIRGULA EOL { comando_sum($3, $5, $7, $9, hash); return 1; }
    | IDENTIFICADOR PONTO_VIRGULA EOL {
        int existe;
        existe = search_hash(hash, $1);
        if (existe == -1) {
            printf("Undefined symbol\n");
        } else {
            int tipo = get_tipo(hash, $1);
            if(tipo == MATRIX) {
                Matriz* matriz_imprimir = get_matriz_hash(hash, $1);
                imprimir_matriz(matriz_imprimir, settings);
            } else {
                printf("%s = %.*f\n", $1, settings->float_precision, get_value(hash, $1));
            }
        }
        return 1;
    }
    | IDENTIFICADOR ATRIBUICAO exp PONTO_VIRGULA EOL {

        erro_eval_exp = 0;
        Result* rpn_id2 = RPN_identifier($3, hash);

        if((int)rpn_id2->value == 0) {

            Result* result = (Result*)malloc(sizeof(Result));
            result = RPN_Walk($3, hash);
            if(result->type == MATRIX) {
                imprimir_matriz(result->matriz, settings);
            } else
                printf("%f\n", result->value);
            //inserir_hash(HashTable, char *key, value, int tipo,    matriz)
            inserir_hash(hash, $1, result->value, result->type, result->matriz);
            free_result(result);
        } 
        Delete_Tree($3);
        erro_eval_exp = 0;
        return 1;
    }
    | IDENTIFICADOR ATRIBUICAO cria_matriz {
        clear_matrix(matriz_aux);
        int inseriu = 0;
        inseriu = insert_matrix(matriz_aux, pilha_primeirosValores, pilha, num_linhas, max_colunas);

        if (inseriu == 1) {
            //void inserir_hash(HashTable *ht, char *key, float value, int tipo, Matriz* matriz);
            inserir_hash(hash, $1, -2, MATRIX, matriz_aux);
            imprimir_matriz(matriz_aux, settings);
            clear_matrix(matriz_aux);
        }

        //Result* result = (Result*)malloc(sizeof(Result));
        //result = RPN_Walk($3, hash);

        num_linhas = 1;
        num_colunas = 1;
        max_colunas = 1;
        clear_stack(pilha_primeirosValores);
        clear_stack(pilha);
        return 1; 
    }
    | exp EOL { 

        Result* rpn_id = RPN_identifier($1, hash);

        if (rpn_id->value == 0.0) { 

            Result* result = RPN_Walk($1, hash);
            if(result->type == MATRIX) {
                imprimir_matriz(result->matriz, settings);
            } 
            else {
                printf("%.*f\n", settings->float_precision, result->value);
            }
            free_result(result);
        }
        Delete_Tree($1);
        return 1;
    }
    | EOL {return 1;}
;

p1:
    SETTINGS PONTO_VIRGULA EOL { show_settings(settings); return 1; }
    | MATRIX PONTO_VIRGULA EOL { 
        if (!matriz) {
            printf("\nNo Matrix defined!\n");
            return 1;
        } else {
            imprimir_matriz(matriz, settings);
        }
    }
    | SYMBOLS PONTO_VIRGULA EOL { printar_hash(hash); }
;

p3:
    H_VIEW valor INTERVALO valor PONTO_VIRGULA EOL { 
        if ($2->value_float < $4->value_float) {
            settings->h_view_lo = $2->value_float; settings->h_view_hi = $4->value_float; 
        }
        else {
            printf("\nERROR: h_view_lo must be smaller than h_view_hi\n");
        }
        return 1;
    }
    | V_VIEW valor INTERVALO valor PONTO_VIRGULA EOL { 
        if ($2->value_float < $4->value_float) {
            settings->v_view_lo = $2->value_float; settings->v_view_hi = $4->value_float; 
        } else {
            printf("\nERROR: v_view_lo must be smaller than v_view_hi\n");
        }
        return 1;
    }
    | AXIS ON PONTO_VIRGULA EOL { settings->draw_axis = 1; }
    | AXIS OFF PONTO_VIRGULA EOL { settings->draw_axis = 0; }
    | ERASE PLOT OFF PONTO_VIRGULA EOL { settings->erase_plot = 0; }
    | ERASE PLOT ON PONTO_VIRGULA EOL { settings->erase_plot = 1; }
    | INTEGRAL_STEPS valor PONTO_VIRGULA EOL { 
        if ($2->value_float > 0)
            settings->integral_steps = $2->value_int; 
        else {
            printf("\nERROR: integral_steps must be a positive non-zero integer\n");
        }
        return 1;
    }
    | FLOAT PRECISION valor PONTO_VIRGULA EOL { 
        if ($3->value_int < 0 || $3->value_int > 8)
            printf("\nERROR: float precision must be from 0 to 8\n");
        else
            settings->float_precision = $3->value_int; 

        return 1;
    }
;

p4:
    PONTO_VIRGULA EOL {
        if(funcao_inserida == 0) {
            printf("\nNo Function defined!\n\n");
        } else {
            plot(AST, settings, hash);
        }
        return 1;
    }
    | ABRE_PARENTESES exp FECHA_PARENTESES PONTO_VIRGULA EOL {

        AST = $2;
        funcao_inserida = 1;
        if(AST) {
            plot(AST, settings, hash);
        }
    }
;

p5:
    DETERMINANT PONTO_VIRGULA EOL {
        if (!matriz) {
            printf("No Matrix defined!\n");
            return 1;
        } else {
            if(matriz->linhas == matriz->colunas) {
                float det = calculo_determinante(matriz);
                printf("\n%f\n", det);
                clear_matrix(matriz);
                return 1;
            } else {
                printf("\nMatrix format incorrect!\n");
                return 1;
            }
        }
    }
    | LINEAR_SYSTEM PONTO_VIRGULA EOL {

        if (!matriz) {
            printf("No Matrix defined!\n");
            return 1;
        }
        
        int ls = calculo_sistema_linear(matriz);
        if (ls == 1) {
            printf("\nMatrix format incorrect!\n");
        }
        return 1;
    }
;


// hash - só os valores que eu atribuo (ex: bia := 4) só quando atribuir um valor
exp: 
    factor { $$ = $1; }
    | exp ADICAO factor { 
        //           create_ast_node(node_type,int,float,string, left, right);
        TreeNode* aux = create_ast_node(ADICAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
    | exp SUBTRACAO factor { 
        TreeNode* aux = create_ast_node(SUBTRACAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
;

factor: 
    exponenciacao { $$ = $1; }
    | factor MULTIPLICACAO exponenciacao { 
        //  create_ast_node(node_type, value_int, value_float, value_string, left, right);
        TreeNode* aux = create_ast_node(MULTIPLICACAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
    | factor DIVISAO exponenciacao { 
        TreeNode* aux = create_ast_node(DIVISAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
    | factor RESTO_DIVISAO exponenciacao { 
        TreeNode* aux = create_ast_node(RESTO_DIVISAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
;

exponenciacao:
    func_trigonometrica { $$ = $1; }
    | func_trigonometrica POTENCIACAO exponenciacao { 
        TreeNode* aux = create_ast_node(POTENCIACAO, -2, -2, NULL, $1, $3);
        $$ = aux;
    }
    
;

func_trigonometrica:

    term { $$ = $1; }
    | SEN ABRE_PARENTESES exp FECHA_PARENTESES {
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
    | X {
        TreeNode* aux = create_ast_node(X, -2, -2, NULL, NULL, NULL);
        $$ = aux;
    }

    | ABRE_PARENTESES exp FECHA_PARENTESES {
        $$ = $2;
    }
;

valor:
    ADICAO NUMERO_REAL { 
        //               create_ast_node(node_type,  int, float,string, matriz, left, right);
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
    | PI { 
        TreeNode* aux = create_ast_node(NUMERO_REAL, 3, 3.14159265, NULL, NULL, NULL);
        $$ = aux;
    }
    | E {
        TreeNode* aux = create_ast_node(NUMERO_REAL, 2, 2.71828182, NULL, NULL, NULL);
        $$ = aux;
    }
;

contador_colunas:
    zero_ou_mais_colunas { 
        if (num_colunas > max_colunas) 
            max_colunas = num_colunas;
        num_colunas = 1;
        insert_info(pilha, 0.0, '|'); // | = fim da linha

    }
; 

//  { , valor }∗                                ** numero de colunas
zero_ou_mais_colunas:
    VIRGULA valor zero_ou_mais_colunas {
        insert_info(pilha, $2->value_float, '&'); // & = representa que é número
        num_colunas++;
    }
    | { }

;

//   { ∗ ] }∗  , [ valor { , valor }            ** zero ou mais linhas
zero_ou_mais_linhas: 
    VIRGULA ABRE_COLCHETES valor contador_colunas FECHA_COLCHETES zero_ou_mais_linhas { 
        insert_info(pilha_primeirosValores, $3->value_float, '@'); // @ = fim da coluna
        num_linhas++;
    }
    | { }
;

cria_matriz: //  [ [ valor zero_ou_mais_valores_interno ] {,[ valor zero_ou_mais_valores_interno ] }∗ ];
    ABRE_COLCHETES ABRE_COLCHETES valor contador_colunas FECHA_COLCHETES zero_ou_mais_linhas FECHA_COLCHETES  PONTO_VIRGULA EOL { 
        insert_info(pilha_primeirosValores, $3->value_float, '@'); // @ = fim da coluna
        //TreeNode* aux = create_ast_node(MATRIX, -2, -2, NULL, NULL, NULL);
        //$$ = aux;
    }
;

%%

void informacoes_aluno() {
    printf("\n+--------------------------------------------------------+\n");
    printf("|                                                        |\n");
    printf("|              Beatriz Barrios Caporusso                 |\n");
    printf("|                    202000560034                        |\n");
    printf("|                                                        |\n");
    printf("+--------------------------------------------------------+\n");

}

void comando_sum(char* variavel, TreeNode *lim_inferior, TreeNode *lim_superior, TreeNode *no_expr, HashTable* hash) {

    Result* result = (Result*)malloc(sizeof(Result));
    result->value = 0;
    result->matriz = NULL;

    float aux_value = 0.0;
    
    inserir_hash(hash, variavel, lim_inferior->value_int, NUMERO_REAL, NULL);
    Result* rpn_id = RPN_identifier(no_expr, hash);
    if((int)rpn_id->value == 0) {
        for (int i=lim_inferior->value_int; i<=lim_superior->value_int; i++) {
            inserir_hash(hash, variavel, i, NUMERO_REAL, NULL);
            //result->value += RPN_Walk(no_expr, hash);
            result = RPN_Walk(no_expr, hash);

            result->type = NUMERO_REAL;
            aux_value += result->value;
        }

        printf("\n%f\n", aux_value);
    } 
    free_result(result);
    free_result(rpn_id);
}

void integrate(float lower_limit, float upper_limit, TreeNode *no_expr, HashTable* hash) {

    float dx = (upper_limit - lower_limit) / settings->integral_steps;
    float sum = 0.0;
    float x;

    Result* result = (Result*)malloc(sizeof(Result));
    result->value = 0;

    // Soma de Riemman
    for (int i = 0; i < settings->integral_steps; i++) {
        x = i * dx; 
        set_X(x);
        result = RPN_Walk(no_expr, hash);
        sum += result->value;
    }

    result->value = sum* dx;

    printf("\n%f\n", result->value);
    free_result(result);
}

int main(int argc, char** argv) {

    settings = create_settings();
    hash = create_hash_table();
    pilha_primeirosValores = create_pilha();
    pilha = create_pilha();
    matriz = create_matrix();
    matriz_aux = create_matrix();

    int verificador_comandos = 1;

    while (verificador_comandos == 1) {
        printf("\n>");
        verificador_comandos = yyparse();
    }

    free(settings);
    free_hash(hash);
    free_pilha(pilha_primeirosValores);
    free_pilha(pilha);
    free_matriz(matriz);
    free_matriz(matriz_aux);

    return 0;
}

void yyerror(char *s) {
	
    //verificar se ja houve erro
    if(erro == 1) 
        return;
    switch(yychar) {
        case INVALID_SYMBOL:
            printf("\nInvalid Symbol: %s\n", yytext);
            //erro = 1;
            break;
        case EOL:
            printf("\nSYNTAX ERROR: Incomplete Command\n");
            //erro = 1;
            break;
        default:
            if(!strcmp(s, "syntax error"))
                printf("\nSYNTAX ERROR: [%s]\n\n",yytext);
            else
                printf("\n%s\n\n", s);
            //erro = 1;
            break;
    }

    // frees
}