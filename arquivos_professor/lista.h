typedef struct lista lista;
typedef struct no no;

lista* criar_lista();
void destruir_lista(lista *l);
int inserir_inicio_lista(lista *l, int valor);
int inserir_fim_lista(lista *l, int valor);
no* buscar_lista(lista *l, int valor);
int remover_lista(lista *l, int valor);
void exibir_lista(lista *l);