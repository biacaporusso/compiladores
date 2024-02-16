FLEX=flex
CC=gcc

PROGRAMA = l7e1
LEXICO = l7e1.l

$(PROGRAMA): $(LEXICO)
	$(FLEX) $(LEXICO)
	$(CC) lex.yy.c $(LIBS) -o $(PROGRAMA)

clear:
	rm -f lex.yy.c
	rm -f $(PROGRAMA)