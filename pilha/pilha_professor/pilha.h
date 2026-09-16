#include "lista.h"
typedef Lista Pilha;

Pilha* cria_pilha();
void libera_pilha(Pilha *p);
void push(Pilha **p, int valor);
int pop(Pilha **p);
int vazia(Pilha *p);

void exibe_pilha(Pilha *p);
