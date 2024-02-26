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
    HashTable* HT = NULL;
    Settings* settings = NULL;

    // variaveis globais
    int num_linhas = 1;
    int num_colunas = 1;
    int max_colunas = 0;

    // DECLARAÇÃO DAS FUNÇÕES
    void informacoes_aluno();
    void comando_sum(TreeNode *variavel, TreeNode *lim_inferior, TreeNode *lim_superior, TreeNode *no_expr);

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
%type <ast> valor_float
%type <ast> valor_inteiro
%type <ast> variavel

%start inicio

%%

inicio:
    comando {}
;

comando:
    SHOW p1 {}
    | RESET SETTINGS PONTO_VIRGULA EOL { set_default_settings(settings); return 1; }
    | QUIT EOL { return 0; }
    | SET p3 {}
    | PLOT p4 PONTO_VIRGULA EOL {}
    | INTEGRATE ABRE_PARENTESES valor_float INTERVALO valor_float VIRGULA funcao FECHA_PARENTESES  PONTO_VIRGULA EOL {}
    | MATRIX IGUAL cria_matriz { max_colunas=0; num_linhas=1; num_colunas=1; return 1;}
    | SOLVE p5 PONTO_VIRGULA EOL {}
    | ABOUT PONTO_VIRGULA EOL { informacoes_aluno(); return 1; }
    | RPN ABRE_PARENTESES exp FECHA_PARENTESES PONTO_VIRGULA EOL {}
    | SUM ABRE_PARENTESES variavel VIRGULA valor_inteiro INTERVALO valor_inteiro VIRGULA exp FECHA_PARENTESES PONTO_VIRGULA EOL { comando_sum($3, $5, $7, $9); return 1; }
    //| atribuicao_valores {}
    | IDENTIFICADOR PONTO_VIRGULA EOL {
        int existe;
        printf("antes do search");
        existe = search_hash(HT, $1);
        if (existe == -1) {
            printf("undefined SYMBOOOL\n");
        } else {
            printf("existe na hash");
            //printf("%s = %f", $1, HT->value);
        }
    }
    | IDENTIFICADOR ATRIBUICAO valor_inteiro PONTO_VIRGULA EOL {
        printf("atribuicao\n");
        inserir_hash(HT, $1, $3->value_int);
        printf("passou\n");
    }
    | exp EOL { 
        printf("entrou no exp");
        printf("%f\n", RPN_Walk($1));
        Delete_Tree($1);
        return 1;
    }
    | atribuicao_matrizes {}
    | mostrando_valor {}
;

//  { , valor }∗                                ** numero de colunas
zero_ou_mais_valores_interno:                   
    VIRGULA valor_inteiro zero_ou_mais_valores_interno { num_colunas++; }
    | {}
;

//   { , [ valor { , valor }∗ ] }∗              ** zero ou mais linhas
zero_ou_mais_valores_externo:
    VIRGULA ABRE_COLCHETES valor_inteiro contador_colunas FECHA_COLCHETES zero_ou_mais_valores_externo { num_linhas++; } 
    | {}
;

contador_colunas: zero_ou_mais_valores_interno { 
    if (num_colunas > max_colunas) 
        max_colunas = num_colunas;
    num_colunas = 1;
    
}

cria_matriz: //  [ [ valor zero_ou_mais_valores_interno ] {,[ valor zero_ou_mais_valores_interno ] }∗ ];
    ABRE_COLCHETES ABRE_COLCHETES valor_inteiro contador_colunas FECHA_COLCHETES zero_ou_mais_valores_externo FECHA_COLCHETES PONTO_VIRGULA EOL { 
        printf("matriz com %d linhas e %d colunas", num_linhas, max_colunas);
    }
;

p1:
    SETTINGS PONTO_VIRGULA EOL { show_settings(settings); return 1; }
    | MATRIX {}
    | SYMBOLS { /*printa_lista */ }
;

p3:
    H_VIEW valor_float INTERVALO valor_float PONTO_VIRGULA EOL { settings->h_view_lo = $2->value_float; settings->h_view_hi = $4->value_float; return 1; }
    | V_VIEW valor_float INTERVALO valor_float PONTO_VIRGULA EOL { settings->v_view_lo = $2->value_float; settings->v_view_hi = $4->value_float; return 1; }
    | AXIS ON PONTO_VIRGULA EOL { settings->draw_axis = 1; return 1; }
    | AXIS OFF PONTO_VIRGULA EOL { settings->draw_axis = 0; return 1; }
    | ERASE PLOT OFF PONTO_VIRGULA EOL { settings->erase_plot = 0; return 1; }
    | ERASE PLOT ON PONTO_VIRGULA EOL { settings->erase_plot = 1; return 1; }
    | INTEGRAL_STEPS valor_inteiro PONTO_VIRGULA EOL { settings->integral_steps = $2->value_int; return 1; }
    | FLOAT PRECISION valor_inteiro PONTO_VIRGULA EOL { settings->float_precision = $3->value_int; return 1; }
;

p4:
    PONTO_VIRGULA {}
    | ABRE_PARENTESES funcao FECHA_PARENTESES {}
;

funcao:
    exp {}
    | SEN ABRE_PARENTESES funcao FECHA_PARENTESES {}
    | COS ABRE_PARENTESES funcao FECHA_PARENTESES {}
    | TAN ABRE_PARENTESES funcao FECHA_PARENTESES {}
    | ABS ABRE_PARENTESES funcao FECHA_PARENTESES {}
;

p5:
    DETERMINANT {}
    | LINEAR_SYSTEM {}
;


// hash - só os valores que eu atribuo (ex: bia := 4) só quando atribuir um valor
exp: 
    factor { $$ = $1; }
    | exp ADICAO factor { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = ADICAO;
        aux->left = $1;
        aux->right = $3;
        $$ = (TreeNode*) aux; 
    }
    | exp SUBTRACAO factor { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = SUBTRACAO;
        aux->left = $1;
        aux->right = $3;
        $$ = (TreeNode*) aux; 
    }
;

factor: 
    term { $$ = $1; }
    | factor MULTIPLICACAO term { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = MULTIPLICACAO;
        aux->left = $1;
        aux->right = $3;
        $$ = (TreeNode*) aux; 
    }
    | factor DIVISAO term { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = DIVISAO;
        aux->left = $1;
        aux->right = $3;
        $$ = (TreeNode*) aux; 
    }
    | factor POTENCIACAO term { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = POTENCIACAO;
        aux->left = $1;
        aux->right = $3;
        $$ = (TreeNode*) aux; 
    }
    | factor RESTO_DIVISAO term { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = RESTO_DIVISAO;
        aux->left = $1;
        aux->right = $3;
        $$ = (TreeNode*) aux; 
    }
;

term: 
    valor_inteiro { $$ = $1; }
    | valor_float { $$ = $1; }
    | variavel { 
        // procurar se a variavel existe na hash
        // se existir, atribui o valor 
        // senão, undefined symbol

        //char string[1024];
        //TreeNode* no_variavel = $1->value_string;
        //strcpy(string, $1->value_string);
        if(search_hash(HT, $1->value_string) == -1) {
            printf("Undefined symbol [%s]", $1->value_string);
        } else {
            printf("nao sei"); // fix
        }

        $$ = $1; 
    }
;

variavel: 
    IDENTIFICADOR { printf("aqui"); TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = IDENTIFICADOR;
        strcpy(aux->value_string, $1);
        aux->left = NULL;
        aux->right = NULL;
        $$ = (TreeNode*) aux; 
    }
    | IDENTIFICADOR ATRIBUICAO valor_float { printf("aqui2"); TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = IDENTIFICADOR;
        strcpy(aux->value_string, $1);
        aux->left = NULL;
        aux->right = NULL;
        $$ = (TreeNode*) aux; 

        // inserir na hash (somente quando tem valor atribuido)
        inserir_hash(HT, aux->value_string, 0);  // fix valor 0
    }
    | IDENTIFICADOR ATRIBUICAO valor_inteiro { printf("aqui3"); TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = IDENTIFICADOR;
        strcpy(aux->value_string, $1);
        aux->left = NULL;
        aux->right = NULL;
        $$ = (TreeNode*) aux; 

        // inserir na hash (somente quando tem valor atribuido)
        inserir_hash(HT, aux->value_string, 0);  // fix valor 0
    }
    /*
    | SEN ABRE_PARENTESES exp FECHA_PARENTESES {

    }
    | COS ABRE_PARENTESES exp FECHA_PARENTESES {

    }
    | TAN ABRE_PARENTESES exp FECHA_PARENTESES {

    }
    | ABS ABRE_PARENTESES exp FECHA_PARENTESES {

    } */

;

valor_float: 
    ADICAO NUMERO_REAL { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = NUMERO_REAL;
        aux->value_float = $2;
        aux->left = NULL;
        aux->right = NULL;
        $$ = (TreeNode*) aux;
    }
    | SUBTRACAO NUMERO_REAL { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = NUMERO_REAL;
        aux->value_float = -$2;
        aux->left = NULL;
        aux->right = NULL;
        $$ = (TreeNode*) aux;
    }
    | NUMERO_REAL { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = NUMERO_REAL;
        aux->value_float = $1;
        aux->left = NULL;
        aux->right = NULL;
        $$ = (TreeNode*) aux; 
    }
    | valor_inteiro { $$ = $1; }
;

valor_inteiro:
    ADICAO NUMERO_INTEIRO { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = NUMERO_INTEIRO;
        aux->value_int = $2;
        aux->left = NULL;
        aux->right = NULL;
        $$ = (TreeNode*) aux;
    }
    | SUBTRACAO NUMERO_INTEIRO { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = NUMERO_INTEIRO;
        aux->value_int = -$2;
        aux->left = NULL;
        aux->right = NULL;
        $$ = (TreeNode*) aux;
    }
    | NUMERO_INTEIRO { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = NUMERO_INTEIRO;
        aux->value_int = $1;
        aux->left = NULL;
        aux->right = NULL;
        $$ = (TreeNode*) aux;
    }
;


/* atribuicao_valores:
    IDENTIFICADOR ATRIBUICAO exp PONTO_VIRGULA {

        char ident[1024];
        printf("oi");
        strcpy(ident, $1);
        float valor = RPN_Walk($3);
        printf("tchau");
        // inserir hash
        inserir_hash(HT, ident, valor);

    }
; */

atribuicao_matrizes: IDENTIFICADOR {}
;

mostrando_valor:
    variavel PONTO_VIRGULA {}
;


%%


int main(int argc, char** argv) {

    settings = create_settings();
    HT = create_hash_table();

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

void comando_sum(TreeNode *variavel, TreeNode *lim_inferior, TreeNode *lim_superior, TreeNode *no_expr) {

    float result_somatorio = 0;
    for (int i=lim_inferior->value_int; i<lim_superior->value_int; i++) {
        result_somatorio += RPN_Walk(no_expr);
    }

    printf("%f", result_somatorio);
}

void yyerror(char *s) {
	
    switch(yychar) {
        case INVALID_SYMBOL:
            printf("\nInvalid Symbol: %s", yytext);
            break;
        case SYNTAX_ERROR:
            printf("\nSYNTAX ERROR: [%s]", yytext);
            break;
        default:
            printf("\nSYNTAX ERROR: Incomplete Command.");
            break;
    }
}