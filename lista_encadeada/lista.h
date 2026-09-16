#ifndef LISTA_H
#define LISTA_H

typedef struct lista lista;
typedef struct no no;

lista *criar_lista(void);
void destruir_lista(lista *l);

int inserir_inicio_lista(lista *l, int valor);






#endif