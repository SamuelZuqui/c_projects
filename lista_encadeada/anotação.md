Listas encadeadas:

São diferentes das sequenciais porque seus NÓS (elementos) não são alocados de forma contígua na memória.
Essa característica torna impossível acessar diretamente um elemento sem passar pelos elementos anteriores.

Um NÓ da lista é formado por um espaço de memória que contém o valor armazenado e por um ou mais espaços que armazenam (apontam) o endereço do próximo nó.

- Alguns tipos de listas:

    1) Simplesmente Encadeada:
        struct no{
            <tipo> valor;         /       typdef struct no Lista;
            struct no *prox;
        };


    2) Duplamente Encadeada:
        struct no{
            <tipo> valor;            /    typedef struct no lista;
            struct no *prox, *ant;
        }

    * Diferentemente da anterior, permite navegação bidirecional pela lista.

    3) Circular:
        Pode ser simples ou dupla.
        Em amobos, o último nó aponta para o primeiro. No caso de ser dupla o primeiro aponta para o último.


- Operações em uma lista:

    1) Criar: Aloca uma lista vazia e retorna o endereço da lista.
    2) Destruir: Desaloca uma lista já alocada.
    3) Inserir: Dado uma lista e um elemento do tipo da lista, insere o elemento na lista. Retorna a lista com o novo elemento.
    4) Remover: Dado uma lista e a posição (ou o elemento) retorna a lista sem o elemento.
    5) Buscar: Dada uma lista e o valor a ser procurado, retorna o elemento. Se o valor procurnão existe, retorna NULL.

- Uso de cabeçalho:
    Cabeçalhos são geralmente utilizados para armazenar informações sobre a lista. Também o utilizamos para reduzir a complexidade de algumas operações.

    Por exemplo:
        inserir_no_fim(...) numa lista simples encadeada. Tem complexidade O(n).
        Se usarmos um cabeçalho que guarda o endereço do último elemento, podemos inserir com complexidade O(1).

**EXERCÍCIO**
    implemente o TAD lista de inteiros para cada tipo (sem e com cabeçalho)