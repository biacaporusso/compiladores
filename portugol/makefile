CC = gcc 
CFLAGS = -std=c99

obj = lexico.o list.o main.o pilha.o sintatico.o 

portugol: $(obj)
	$(CC) $(CFLAGS) $(obj) -o portugol -lm

lexico.o: lexico.c  
	$(CC) $(CFLAGS) -c lexico.c

list.o: list.c
	$(CC) $(CFLAGS) -c list.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c
	
pilha.o: pilha.c  
	$(CC) $(CFLAGS) -c pilha.c

sintatico.o: sintatico.c  
	$(CC) $(CFLAGS) -c sintatico.c




