#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    no *prox;
};

struct lista {
    int quantidade;
    no *primeiro, *ultimo;
};

lista* criar_lista(){
    lista *l = NULL;
    l = malloc(sizeof(lista));
    
    if (l) {
        l->quantidade = 0;
        l->primeiro = l->ultimo = NULL;s
    }
    
    return l;
}

void destruir_lista(lista *l) {
    no *p = l->primeiro;
    
    while (p) {
        p = p->prox;
        free(l->primeiro);
        l->primeiro = p;
    }
    
    free(l);
}

int inserir_inicio_lista(lista *l, int valor){
    no *novo_no = malloc(sizeof(no));
    
    if(novo_no) {
        novo_no->valor = valor;
        novo_no->prox = l->primeiro;
        
        if (l->primeiro == NULL)
            l->ultimo = novo_no;

        l->primeiro = novo_no;
        l->quantidade++;
    }
}

int inserir_fim_lista(lista *l, int valor) {
    no *novo_no = malloc(sizeof(no));
    no *p = l->ultimo;
    
    if(novo_no) {
        novo_no->valor = valor;
        novo_no->prox = NULL;
        
        if (l->ultimo == NULL)
            l->primeiro = novo_no;
        else
            l->ultimo->prox = novo_no;

        l->ultimo = novo_no;
        l->quantidade++;
    }
}

no* buscar_lista(lista *l, int valor){
    no *p;
    
    for(p = l->primeiro; p && p->valor != valor; p=p->prox){}
        
    return p;
}

int remover_lista(lista *l, int valor){
    //Implementar
    return 0;
}

void exibir_lista(lista *l){
    for(no *p = l->primeiro; p; p=p->prox)
        printf("%d ", p->valor);
}



