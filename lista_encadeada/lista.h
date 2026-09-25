#ifndef LISTA_H
#define LISTA_H

typedef struct no{
    int valor;
    struct no *proximo;
} no;

typedef struct lista{
    int quantidade;
    no *primeiro;
    no *ultimo;
} lista;

lista *criar_lista(void);

void destruir_lista(lista *l);

int inserir_inicio(lista *l, int valor);

int inserir_fim(lista *l, int valor);

no *buscar_lista(lista *l, int valor);

int remover_lista(lista *l, int valor);

void exibir_lista(lista *l);


#endif
