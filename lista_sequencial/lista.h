#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int quantidade_max;
    int ultimo;
    int *elementos;
} Lista;

Lista *criar_lista(int quantidade_max);

int remover_lista(Lista *l, int posicao);

int inserir_lista(Lista *l, int numero);

int buscar_lista(Lista *l, int numero);

void destruir_lista(Lista *l);

#endif 