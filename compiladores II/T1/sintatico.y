%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ast.h>

    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);
    TreeNode* AST = NULL;
    
    // VALORES PADRÃO DAS VARIÁVEIS INTERNAS
    float h_view_lo = -6.500000;
    float h_view_hi = 6.500000;
    float v_view_lo = -3.500000;
    float v_view_hi = 3.500000;
    int float_precision = 6;
    int integral_steps = 1000;
    // ON = 1
    // OFF = 0
    int draw_axis = 1;
    int erase_plot = 1;
    int connect_dots = 0;

    // DECLARAÇÃO DAS FUNÇÕES
    void informacoes_aluno();
    void mostrar_configuracoes();
    void resetar_configuracoes();
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
    SHOW p1 EOL {}
    | RESET p2 EOL {}
    | QUIT EOL { return 0; }
    | SET p3 EOL {}
    | PLOT p4 EOL {}
    | INTEGRATE ABRE_PARENTESES valor_float INTERVALO valor_float VIRGULA funcao FECHA_PARENTESES  PONTO_VIRGULA EOL {}
    | MATRIX IGUAL ABRE_COLCHETES ABRE_COLCHETES valor_float EOL {}
    | SOLVE p5 EOL {}
    | ABOUT PONTO_VIRGULA EOL { informacoes_aluno(); return 1; }
    | RPN ABRE_PARENTESES exp FECHA_PARENTESES PONTO_VIRGULA EOL {}
    | SUM ABRE_PARENTESES variavel VIRGULA valor_inteiro INTERVALO valor_inteiro VIRGULA exp FECHA_PARENTESES PONTO_VIRGULA EOL { comando_sum($3, $5, $7, $9); return 1; }
    | exp EOL { 
        /*
        AST = $1;
        if(AST) {
            RPN_Walk(AST);
            Delete_Tree(AST);
        } else {
            printf("AST is NULL\n");
        }
        //return 0;
        */
        printf("%f\n",RPN_Walk($1));
        Delete_Tree($1);
        return 1;
    }
    | atribuicao_valores {}
    | atribuicao_matrizes {}
    | mostrando_valor {}
;


p1:
    SETTINGS PONTO_VIRGULA { mostrar_configuracoes(); return 1; }
    | MATRIX PONTO_VIRGULA {}
    | SYMBOLS PONTO_VIRGULA { /*printa_lista */ }
;

p2:
    SETTINGS PONTO_VIRGULA { resetar_configuracoes(); return 1; }
;

p3:
    H_VIEW valor_float INTERVALO valor_float PONTO_VIRGULA {}
    | V_VIEW valor_float INTERVALO valor_float PONTO_VIRGULA {}
    | AXIS ON PONTO_VIRGULA { draw_axis = 1; return 1;}
    | AXIS OFF PONTO_VIRGULA { draw_axis = 0; return 1; }
    | ERASE PLOT OFF PONTO_VIRGULA { erase_plot = 0; return 1; }
    | ERASE PLOT ON PONTO_VIRGULA { erase_plot = 1; return 1; }
    | INTEGRAL_STEPS valor_inteiro PONTO_VIRGULA {}
    | FLOAT PRECISION valor_inteiro PONTO_VIRGULA {}
;

p4:
    PONTO_VIRGULA {}
    | ABRE_PARENTESES funcao FECHA_PARENTESES PONTO_VIRGULA {}
;

funcao:
    exp {}
    | SEN ABRE_PARENTESES funcao FECHA_PARENTESES {}
    | COS ABRE_PARENTESES funcao FECHA_PARENTESES {}
    | TAN ABRE_PARENTESES funcao FECHA_PARENTESES {}
    | ABS ABRE_PARENTESES funcao FECHA_PARENTESES {}
;

p5:
    DETERMINANT PONTO_VIRGULA {}
    | LINEAR_SYSTEM PONTO_VIRGULA {}
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
;

term: 
    valor_inteiro { $$ = $1; }
    | valor_float { $$ = $1; }
    | variavel { $$ = $1; }
;

variavel: IDENTIFICADOR { TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
        aux->node_type = IDENTIFICADOR;
        strcpy(aux->value_string, $1);
        aux->left = NULL;
        aux->right = NULL;
        $$ = (TreeNode*) aux; 
    }
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
        aux->value_float = $2;
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


atribuicao_valores:
    variavel ATRIBUICAO exp PONTO_VIRGULA {}
;

atribuicao_matrizes: IDENTIFICADOR {}
;

mostrando_valor:
    variavel PONTO_VIRGULA {}
;


%%


int main(int argc, char** argv) {

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

void mostrar_configuracoes() {
    printf("\nh_view_lo: %.6f", h_view_lo);
    printf("\nh_view_hi: %.6f", h_view_hi);
    printf("\nv_view_lo: %.6f", v_view_lo);
    printf("\nv_view_hi: %.6f", v_view_hi);
    printf("\nfloat precision: %d", float_precision);
    printf("\nintegral_steps: %d\n", integral_steps);
    if(draw_axis = 1)
        printf("\nDraw Axis: ON");
    else
        printf("\nDraw Axis: OFF");
    if(erase_plot = 1)
        printf("\nErase Plot: ON");
    else
        printf("\nConnect Dots: OFF");
}

void resetar_configuracoes() {
    h_view_lo = -6.500000;
    h_view_hi = 6.500000;
    v_view_lo = -3.500000;
    v_view_hi = 3.500000;
    float_precision = 6;
    integral_steps = 1000;
    draw_axis = 1;
    erase_plot = 1;
    connect_dots = 0;
}

void comando_sum(TreeNode *variavel, TreeNode *lim_inferior, TreeNode *lim_superior, TreeNode *no_expr) {

    float result_somatorio = 0;
    for (int i=lim_inferior->value_int; i<lim_superior->value_int; i++) {
        result_somatorio += RPN_Walk(no_expr);
    }

    printf("%f", result_somatorio);
}

void yyerror(char *s) {
	int i = 1;
	printf("erro: %s", yytext);
}