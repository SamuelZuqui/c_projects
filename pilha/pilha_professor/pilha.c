#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "lista.h"


Pilha* cria_pilha(){
    return cria_lista();
}

void libera_pilha(Pilha *p){
    destroi_lista(p);
}

void push(Pilha **p, int valor){
    insere_lista(p, valor);
}

int pop(Pilha **p){
    if (!vazia(*p)){
        int topo = primeiro_lista(*p);
        remove_lista(p);
        return topo;
    }
}

int vazia(Pilha *p){
    return p == NULL;
}

void exibe_pilha(Pilha *p){
    exibe_lista(p);
}