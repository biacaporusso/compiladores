FLEX=flex
CC=gcc

PROGRAMA = l7e3
LEXICO = l7e3.l

$(PROGRAMA): $(LEXICO)
	$(FLEX) $(LEXICO)
	$(CC) lex.yy.c $(LIBS) -o $(PROGRAMA)

clear:
	rm -f lex.yy.c
	rm -f $(PROGRAMA)