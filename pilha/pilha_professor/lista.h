#ifndef LISTA_H
#define LISTA_H
typedef struct no Lista;

Lista* cria_lista();
void destroi_lista(Lista *l);

void insere_lista(Lista **l, int valor);
void remove_lista(Lista **l);
int primeiro_lista(Lista *l);
void exibe_lista(Lista *l);
#endif