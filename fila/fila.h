#ifndef FILA_H
#define FILA_H

/* A estrutura interna fica escondida em fila.c. */
typedef struct fila Fila;

Fila *criar_fila(void);
/* Retornam 1 em caso de sucesso e 0 em caso de falha. */
int enqueue(Fila *fila, int valor);
/* Retorna 0 se a fila estiver vazia; nao altera valor nesse caso. */
int dequeue(Fila *fila, int *valor);
void liberar_fila(Fila *fila);

#endif
