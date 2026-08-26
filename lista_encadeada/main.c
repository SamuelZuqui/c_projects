#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista *lista = criar_lista();

    lista = inserir_inicio(lista, 10);
    lista = inserir_inicio(lista, 20);
    lista = inserir_inicio(lista, 30);

    for (Lista *atual = lista; atual != NULL; atual = atual->prox) {
        printf("%d\n", atual->valor);
    }

    liberar_lista(lista);

    return 0;
}
