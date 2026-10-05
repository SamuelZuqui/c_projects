#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

lista *criar_lista(void){
    lista *l = malloc(sizeof(lista));

    if (l == NULL){
        return NULL;
    }
     
    l->quantidade = 0;
    l->primeiro = NULL;
    l->ultimo = NULL;

    return l;
}

void destruir_lista(lista *l){
    if (l == NULL){
        return;
    }

    no *p = l->primeiro;

    while (p != NULL){
        no *proximo = p->proximo;
        free(p);
        p = proximo;
    }

    free(l);

}

int inserir_inicio(lista *l, int valor){
    if (l == NULL){
        return 0;
    }

    no *novo = malloc(sizeof(no));

    if (novo == NULL){
        return 0;
    }

    novo->valor = valor;
    novo->proximo = l->primeiro;

}