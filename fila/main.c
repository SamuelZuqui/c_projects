#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void) {
    Fila *fila = criar_fila();
    if (fila == NULL) {
        fprintf(stderr, "Nao foi possivel criar a fila.\n");
        return EXIT_FAILURE;
    }

    /* enqueue insere no FIM. */
    if (!enqueue(fila, 10) || !enqueue(fila, 20) || !enqueue(fila, 30)) {
        fprintf(stderr, "Memoria insuficiente para inserir.\n");
        liberar_fila(fila);
        return EXIT_FAILURE;
    }
    printf("Inseridos: 10 20 30\n");

    /* dequeue remove do INICIO: quem entrou primeiro sai primeiro. */
    int valor;
    while (dequeue(fila, &valor)) {
        printf("Removido: %d\n", valor);
    }
    printf("Fila vazia!\n");

    liberar_fila(fila);
    return EXIT_SUCCESS;
}
