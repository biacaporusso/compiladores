
# Nome do executável
PROJ_NAME=regalloc
 
# arquivos .c
C_SOURCE=$(wildcard *.c)
 
# arquivos .h
H_SOURCE=$(wildcard *.h)
 
# arquivos .o
OBJ=$(C_SOURCE:.c=.o)
 
# compilador
CC=gcc
 
# Flags
CC_FLAGS=-c         \
		 -g         \
		 -w         \
         -W         \
         -Wall      \
	 -std=c99	\
	 -fstack-protector-all
 
#
# Compila e linka os arquivos
#
all: $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ -lm -std=c99 -fstack-protector-all 
 
%.o: %.c %.h

	$(CC) -o $@ $< $(CC_FLAGS)
 
main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)
 
clean:
	rm -rf *.o $(PROJ_NAME) *~