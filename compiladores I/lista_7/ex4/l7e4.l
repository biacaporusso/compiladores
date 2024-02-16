%option noyywrap

%{
int linhas = 1;
int linhas_branco = 0;
int linhas_coment = 0; // seja comentarios com // ou /* */
int linhas_normal = 0; // normal = linhas que nao estao em branco e nao possuem comentarios
int pv = 0; // ponto e virgula
int diretivas = 0; // #include e #define
int is_linha_branco = 0;

int total_linhas = 0;
int total_linhas_branco = 0;
int total_linhas_coment = 0;
int total_linhas_normal = 0; // normal = linhas que nao estao em branco e nao possuem comentarios
int total_pv = 0; // ponto e virgula
int total_diretivas = 0;
%}

%%
";" {pv++;}


"//" {linhas_coment++;}
"/*" {linhas_coment++;}
"*/" {linhas_coment++;}
"#"("include"|"define") {diretivas++;}

"\n" { linhas++;
    if (is_linha_branco) {
        linhas_branco++;
    }
    is_linha_branco = 1;
    } 
    . {is_linha_branco=0;}
%%

int main(int argc, char** argv)
{
    int i;
    printf("total linhas  linhas em branco  linhas com coments  linhas nbc  ponto-virgula  diretivas\n");
    if(argc < 2) { /* just read stdin */
        yylex();
        return 0;
    }
    for(i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");

        if(!f) {
            perror(argv[i]);
            return (1);
        }
        linhas_normal = linhas - linhas_branco - linhas_coment;
        yyrestart(f);
        yylex();
        fclose(f);
        printf("%8d%16d%16d%16d%16d%16d        %s\n", linhas, linhas_branco, linhas_coment, linhas_normal, pv, diretivas, argv[i]);
        total_linhas += linhas; linhas = 1;
        total_linhas_branco += linhas_branco; linhas_branco = 0;
        total_linhas_coment += linhas_coment; linhas_coment = 0;
        total_pv += pv; pv = 0;
        total_diretivas += diretivas; diretivas = 0;
        total_linhas_normal += linhas_normal; 
    }

    if(argc > 1) /* print total if more than one file */
        printf("%8d%16d%16d%16d%16d%16d        total\n", total_linhas, total_linhas_branco,total_linhas_coment, linhas_normal, total_pv, total_diretivas);
    return 0;
}
