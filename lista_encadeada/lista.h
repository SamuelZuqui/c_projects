#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int valor;
    struct no *prox; //aponta para o próximo nó
} Lista;

Lista *criar_lista(void);
Lista *inserir_inicio(Lista *lista, int valor);
void liberar_lista(Lista *lista);

#endif
