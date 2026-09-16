#include "pilha.h"
#include <stdio.h>

int main()
{
    Pilha *p = cria_pilha();
    
    push(&p, 10);
    // push(&p, 2);
    // push(&p, 3);
    printf("%d\n", pop(&p));
    exibe_pilha(p);

    libera_pilha(p);
    
    return 0;
}
