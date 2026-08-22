#include <stdlib.h>
#include "lista.h"

Lista *criar_lista(int quantidade_max){
    Lista *l;

    l = malloc(sizeof(Lista));

    if (l == NULL){
        return NULL;
    }

    l->quantidade_max = quantidade_max; 

    l->ultimo = -1;

    l->elementos = malloc(quantidade_max * sizeof(int));

    if (l->elementos == NULL){
        free(l);
        return NULL;
    }

    return l;
}

void destruir_lista(Lista *l){
    if (l == NULL){
        return;
    }

    free(l->elementos);
    free(l);
}

int inserir_lista(Lista *l, int numero){
    int posicao;
    int i;

    if (l == NULL){
        return 0;
    }   

    if (l->ultimo == l->quantidade_max -1){
        return 0;
    }

    posicao = 0;

}
