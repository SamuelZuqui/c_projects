1) Principal diferença entre uma lista sequencial e uma lista encadeada:
    
    - Lista Sequencial:
    Os elementos ficam em posições sequenciais/contíguas de memória.
    
    EXEMPLO:
    elementos
        ↓
    ┌────┬────┬────┬────┬────┐
    │ 10 │ 20 │ 30 │ 40 │    │
    └────┴────┴────┴────┴────┘
      0    1    2    3    4

     Você acessa discretamente:
        L -> elementos[2] e encontra "30".


    - Lista Encadeada:
    Os elementos ficam dentro de nós, e cada nó possui um ponteiro para outro nó.

    EXEMPLO:
    ┌───────────┐      ┌───────────┐      ┌───────────┐
    │ valor: 10 │      │ valor: 20 │      │ valor: 30 │
    │ prox: ─────────► │ prox: ─────────► │ prox: NULL│
    └───────────┘      └───────────┘      └───────────┘
    Os nós não precisam estar lado a lado na memória.


                                -- TABELA DE DIFERENÇAS --
| Característica                 | Lista Sequencial              | Lista Encadeada                |
|--------------------------------|--------------------------------|-------------------------------|
| Memória                        | Contígua                      | Não precisa ser contígua       |
| Usa vetor                      | Sim                           | Não necessariamente            |
| Usa nós                        | Não                           | Sim                            |
| Usa ponteiros entre elementos  | Não                           | Sim                            |
| Acesso por posição             | Fácil/direto                  | Precisa percorrer              |
| Inserir no meio                | Pode deslocar elementos       | Altera ponteiros               |
| Remover no meio                | Pode deslocar elementos       | Altera ponteiros               |
| Memória extra por elemento     | Menor                         | Maior por causa dos ponteiros  |
| Tamanho                        | Pode ter capacidade definida  | Pode crescer dinamicamente     |
| Último nó aponta para `NULL`   | Não se aplica                 | Sim, na lista simples          |



2) Lista Sequencial:
    typdef struct{
        int tamanho_max;
        int ultimo;
        int *elementos;
    } Lista;

    - Variáveis:
        1) int tamanho_max: 
            Exemplo: tamanho_max = 5;
            Ela possui espaço para: 0 1 2 3 4.
            São 5 elementos, embora o último índice seja 4.

        2) int ultimo:
            Guarda o índice da última posição ocupada.
            Exemplo: 
            [10] [20] [30] [ ] [ ]       -> ultimo = 2
             0    1    2    3   4
            Existem: ultimo + 1 elementos, portanto: 3 elementos

        3) int *elementos:
            É um ponteiro para a área de memória onde os números estão armazenados.
            Depois de algo como: L->elementos = malloc(tamanho_max * sizeof(int));
            Ele aponta para um vetor criado dinamicamente.

3) Lista Vazia:
    Na implementação que estamos estudando, é muito comum começar:
    L->ultimo = -1; Por quê?
    Porque ainda não existe opção ocupada.
    Exemplo: 
        ultimo = -1;
        [ ] [ ] [ ] [ ] [ ]
        Então, em uma condição típica de lista vazia é: L->ultimo == -1;

4) Lista Cheia:
    A lista está cheia quando:
    L->ultimo == L->tamanho_max -1
    Exemplo:
        tamanho_max = 5
        [10] [20] [30] [40] [50]
         0    1    2    3    4
                             ↑
                           ultimo

        Então: ultimo = 4 e tamanho_max -1 (5 - 1 = 4), logo:
        ultimo == tamanho_max -1 (LISTA CHEIA).

5) Inserção no final da lista sequencial:
    Exemplo:
        Antes:
        [10] [20] [ ] [ ]
               ↑
             ultimo = 1

        Executando: L->ultimo++;
        Agora: ultimo = 2.
        Depois: L->elementos[2] = 30;

        Resultado:
        [10] [20] [30] [ ]
                    ↑
                  ultimo = 2

6) Inserção em posição específica:
    Exemplo:
        [10] [20] [30] [40]
        Queremos colocar "15" entre "10" e "20".
        Não podemos simplesmente sobrescrever o "20".
        Precisamos deslocar:
            antes:
            [10] [20] [30] [40]
            para:
            [10] [__] [20] [30] [40]
            e depois:
            [10] [15] [20] [30] [40]
            
            Poranto, em lista sequencial:
                Inserções no meio normalmente exigem deslocamento dos elementos.

7) Remoção na lista sequencial:
    Mesma lógica, só que ao contrário.
    Exemplo:
        [10] [20] [30] [40] [50]
        Remover "30":
        [10] [20] [__] [40] [50]
        Os elementos posteriores precisam andar:
        [10] [20] [40] [50]

        Portanto, em lista sequencial: 
            A remoção de um elemento no meio da lista sequencial pode exigir deslocamento dos elementos posteriores.

8) Busca na lista sequencial:
    Exemplo:
        [34] [72] [15] [91] [20]
        Buscar "91".
        Podemos percorrer:
        34 → não
        72 → não
        15 → não
        91 → achei
        Isso é uma busca seuqencial/linear.
        Se os dados NÃO estiverem ordenados, normalmente pode ser necessário verificar vários elementos.


9) Lista Encadeada:
    Um nó normalmente possui duas coisas:

        typedef struct no{
            int valor;
            struct no *prox;
        } No;

    Visualmente:
    ┌──────────────┐
    │ valor        │
    │ prox         │
    └──────────────┘
    Então:
    int_valor; guarda o dado.
    struct no *prox; guarda o endereço do próximo nó.

10) O que significa "prox":
    Imagine: 
        ┌──────┐     ┌──────┐     ┌──────┐
        │  10  │ ──► │  20  │ ──► │  30  │
        └──────┘     └──────┘     └──────┘
        O primeiro nó não precisa saber onde todos os outros estão.
        Ele só sabe:
            Onde está o próximo.
        O segundo sabe onde está o terceiro. E assim por diante.
        Isso cria o ENCADEAMENTO.

11) E o último nó?:
    O último nó aponta para: NULL
    Assim: 
        10 -> 20 -> 30 -> NULL
        
        Então, em uma lista simplesmente encadeada, o ponteiro "prox" do último elemento normalmente aponta para NULL.

12) O primeiro nó:
    Normalmente existe um ponteiro que indica onde a lista começa.
    Pode receber nomes como: inicio; primeiro; cabeca; ou até L;
    Imagine:
        inicio
           │
           ▼
         10 → 20 → 30 → NULL
         Sem saber onde está o primeiro nó, você não consegue começar a percorrer a lista.

13) Lista encadeada vazia:
    Em uma implementação comum:
    inicio == NULL   significa: lista vazia
    Visualmente: 
        inicio
          │
          ▼
         NULL

14) Inserir no começo da encadeada:
    Imagine:
        inicio
        ↓
        10 → 20 → 30 → NULL
        Quer inserir "5".
        Primeiro o novo nó aponta para o antigo primeiro:
        5 ─────► 10 → 20→ 30
        Depois o inicio passa a apontar para o "5".
        inicio
        ↓
        5 → 10 → 20 → 30 → NULL
        Não precisamos mover o "10", "20", "30" fisicamente na memória.
        Essa é a vantagem das listas encadeadas.

15) Remover da lista encadeada:
    Imagine:
        10 → 20 → 30 → 40 → NULL
        Queremos remover o "30".
        Precisamos fazer:
        20 ─────────► 40
        Então: 
        10 → 20 → 40 → NULL
        E a nenporia do nó "30" normalmente precisa ser liberada:
        free(...);

        OBS: Retirar o nó do encadeamento não significa automaticamente liberar a memória.
        Se usou malloc, normalmente depois precisa usar free.

16) malloc e free:

    - malloc: Reserva memória dinamicamente.
      Exemplo: 
        No *novo = malloc(sizeof(No));

    - free: Libera memória que foi reservada.
      Exemplo:
        free(novo);
    
    Se você usa malloc várias vezes e nunca libera memória, pode ocorrer:
    >   Memory leak / vazamento de memória.

17) NULL:
    
    NULL significa basicamente:
    >   O ponteiro está apontando para um endereço válido de objeto.
    Por isso verificamos:
        if (novo == NULL)  depois de um malloc.
    Significa que a alocação falhou.

18) "." versus "->":

    Se eu tenho uma variável normal:
        Lista L;
    uso: L.ultimo
    Mas se eu tenho ponteiro:
        Lista *L;
    uso: L->ultimo

19) Possível pegadinha sobre acesso:

    - Lista Sequencial:
        [5] [8] [2] [7] [9]
        Quero a posição 4. Consigo acessar diretamente:
        elementos[4]

    - Lista Encadeada:
        5 → 8 → 2 → 7 → 9
        Para chegar no "9", normalmente faço:
        5
        ↓
        8
        ↓
        2
        ↓
        7
        ↓
        9
        Ou seja:
        >   Lista encadeada não oferece acesso aleatório direto como um vetor.

20) Complexidade:

    STAND BY

21) Vantagens e desvantagens:

    - Lista Sequencial - vantagens:
        1) Acesso rápido por índice.
        2) Mais simples.
        3) Boa utilização de cache / memória.
        4) Menos memória adicional por elemento.

    - Lista Sequencial - desvantagens:
        1) Inserções e remoções no meio podem exigit deslocamentos.
        2) Pode existir uma capacidade máxima previamente definida.

    - Lista Encadeada - vantagens:
        1) Não precisa guardar os nós juntos na memória.
        2) Inserções e remoções podem ser eficientes quando já sabemos onde alternar.
        3) Pode crescer dinamicamente.

    - Lista Encadeada - desvantagens: 
        1) Precisa guardar ponteiros.
        2) Consome memória adicional.
        3) Nçao possui acesso direto como "vetor[i]".
        4) Pode precisar percorrer vários nós.

22) Lista simplesmente encadeada:
        10 → 20 → 30 → NULL
        Cada nó conhece apenas o próximo.

23) Lista duplamente encadeada:
        anterior ← nó → próximo
        Exemplo:
            NULL ← 10 ⇄ 20 ⇄ 30 → NULL
        struct no *ant;
        struct no *prox;
        - Vantagens:
            1) pode percorrer nos dois sentidos.
            2) Desvantagem:
            3) gasta mais memória porque possui mais um ponteiro.
        - Desvantagens:
            1) Gasta mais memória porque possui mais um ponteiro. 

24) Inserção ordenada: 
    Imagine:
        10 → 20 → 40 → 50
    Inserir: "30":
    Você procura a posição correta: 
        10 → 20 → 30 → 40 → 50
    A ideia é preservar a propriedade: menor → maior
    > Em uma lista ordenada, a posição de inserção deve ser determinada de forma a preservar a ordenação.
