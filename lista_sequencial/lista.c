#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

lista *cria_lista (size_t n) {
    lista *L;
    L = (lista *) malloc (sizeof(lista));
    if (L == NULL){
        return NULL;
    }

L->elementos = (int *) malloc(n * sizeof(int));

if (L->elementos == NULL){
    free(L);
    return NULL;
}

L->capacidade = n;
L->ultimo = -1;

return L;

}

int insere_lista(lista *L, int elemento) {
    
    if (L == NULL){
        return 0;
    }

    if (L->ultimo == L->capacidade - 1){
        return 0;
    }

    L->ultimo++;
    L->elementos[L->ultimo] = elemento;

    return 1;
}

int buscar_lista(lista *L, int elemento) {
    if (L == NULL){
        return 0;
    }

    for (int i = 0; i <= L->ultimo; i++){
        if (L->elementos[i] == elemento){
            return 1;
        }
    }
    return -1;
}

int remover_lista(lista *L, int elemento)

