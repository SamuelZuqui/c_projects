#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int valor;
    struct no *prox; // apontando para o prox nó
} No;

typedef No* Lista; // Lista lista

Lista criar();

Lista inserir_inicio(Lista lista, int valor);

#endif