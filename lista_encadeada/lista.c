#include "lista.h"

Lista criar() {
    return NULL;
}

Lista inserir_inicio(Lista lista, int valor){
    No *novo = malloc(sizeof(No)); // novo nó

    novo->valor = valor;
    novo->prox =  lista; // apontando para o prox nó

    return novo; 
}
