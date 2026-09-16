#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no{
    int valor;
    No *prox;
};

Lista* cria_lista(){
    return NULL;
}

void destroi_lista(Lista *l){
    No *aux;
    while (l){
        aux = l;
        l = l->prox;
        free(aux);
    }
}

void insere_lista(Lista **l, int valor){
    No *novo_no = malloc(sizeof(No));
    
    novo_no->valor = valor;
    novo_no->prox = *l;
    *l = novo_no;
}

void remove_lista(Lista **l){
    No *aux = *l;
    if (*l){
        *l = (*l)->prox;
        free(aux);
    }
}

int primeiro_lista(Lista *l){
    return l->valor;
}

void exibe_lista(Lista *l){
    No *aux = l;
    while (aux){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}



