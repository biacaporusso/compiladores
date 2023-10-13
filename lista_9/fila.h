#ifndef fila_h
#define fila_h 

typedef void* Queue;
typedef void* Cell;

Queue criaFila();  
void inserirFila(Queue Q, int info);    // insere um elemento no fim da fila
void removeElemento(Queue Q);            // remove a primeira celula da lisa
int getToken(Queue Q);                    // retorna o primeiro item da fila
void liberaFila(Queue fila);           // percorre toda a fila e libera todas as células e, ao fim, a fila

#endif