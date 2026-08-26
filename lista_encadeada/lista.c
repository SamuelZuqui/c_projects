#include <stdlib.h>
#include "lista.h"

Lista *criar_lista(void) {
    return NULL;
}

Lista *inserir_inicio(Lista *lista, int valor) {
    Lista *novo = malloc(sizeof *novo);

    if (novo == NULL) {
        return lista;
    }

    novo->valor = valor;
    novo->prox = lista;

    return novo;
}

void liberar_lista(Lista *lista) {
    while (lista != NULL) {
        Lista *proximo = lista->prox;
        free(lista);
        lista = proximo;
    }
}
