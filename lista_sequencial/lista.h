#ifndef LISTA_H
#define LISTA_H

#include <stddef.h>

typedef struct {
    size_t capacidade;
    int ultimo;
    int *elementos;
} lista;

lista* cria_lista(size_t n);

void destroi_lista (lista *L);

int insere_lista(lista *L, int elemento);

int remover_lista(lista *L, int elemento);

int buscar_lista(lista *L, int elemento);

#endif

