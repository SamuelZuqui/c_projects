#include <stdlib.h>
#include "fila.h"

typedef struct no {
    int valor;
    struct no *prox;
} No;

struct fila {
    No *inicio;
    No *fim;
};

Fila *criar_fila(void) {
    Fila *fila = malloc(sizeof *fila);
    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}

int enqueue(Fila *fila, int valor) {
    if (fila == NULL) {
        return 0;
    }

    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return 0;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novo; /* Primeiro elemento da fila. */
    } else {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
    return 1;
}

int dequeue(Fila *fila, int *valor) {
    if (fila == NULL || valor == NULL || fila->inicio == NULL) {
        return 0;
    }

    No *removido = fila->inicio;
    *valor = removido->valor;
    fila->inicio = removido->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL; /* O ultimo elemento foi removido. */
    }

    free(removido);
    return 1;
}

void liberar_fila(Fila *fila) {
    if (fila == NULL) {
        return;
    }

    while (fila->inicio != NULL) {
        No *removido = fila->inicio;
        fila->inicio = removido->prox;
        free(removido);
    }
    free(fila);
}
