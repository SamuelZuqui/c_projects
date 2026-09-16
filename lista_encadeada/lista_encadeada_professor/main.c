#include "lista.h"
#include <stdio.h>

int main()
{
    lista *l = criar_lista();
    inserir_inicio_lista(l, 3);
    inserir_fim_lista(l, 4);
    inserir_inicio_lista(l, 30);
    inserir_fim_lista(l, 40);
    exibir_lista(l);
    destruir_lista(l);

    return 0;
}
