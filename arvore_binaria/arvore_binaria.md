Uma árvore pode ser definida de maneira recursiva da seguinte forma:
1) A árvore pode ser vazia (nula) 
ou
3) Ela contém um nó que possui, no máximo, dois filhos (sub-árvores): um à esquerda e outro à direita

           T
         /   \
        0     O
            /   \
          SAE   SAD      SAD: Sub-árvore direita
                         SAE: Sub-árvore esquerda

Exemplo:
1) 
        T
         \
          O
         / \
        O   O
           /
          O

2) 
        T
         \
          

3) 
        T
         \
          O

4) 
        T
         \
          O
           \
            O
           / \
          O   O

- Elementos da árvore binária 
                         T
                      [RAIZ]
                       /   \
                      /     \
               [INTERNO]   [INTERNO]
                  /          /     \
                 /          /       \
           [INTERNO]   [INTERNO]   [FOLHA]
               \          /   \
                \        /     \
              [FOLHA] [FOLHA] [FOLHA]

[RAIZ]: Primeiro nó (pai de todos)
[INTERNO]: Nós que possuem "filhos" mas não são o Nó [RAIZ]
[FOLHA]: Nós que não possuem filhos
Obs.: O nó [RAIZ] pode também ser um nó [FOLHA], basta ele não ter filhos

- Altura de um nó 
1) Caminho: Uma sequência de nós onde cada nó, exceto o primeiro, é filho do anterior.
Ex.:
                      [Nó_1]
                       /   \
                  [Nó_2]   [Nó_3]
                  /    \        \
             [Nó_4]   [Nó_5]   [Nó_6]

Exemplos de caminhos:
<2,5> ✅
<4,2,5> ❌
<1,3,6> ✅
<4,6> ❌
<1,2,3> ❌
<1,6,3> ❌

2) Longitude: É a quantidade de relações pai-filho que existe no caminho. Pode ser calculada pela expressão
#<> = N -1 , onde 'N' é a quantidade de Nós que formam o caminho.
Ex.1: #<2,5> = 2-1 = 1
Ex.2: #<1,3,6> = 3-1 - 2

3) Altura: A altura 'h' de um nó é definida como sendo a maior longitude dos caminhos entre o nó e suas folhas.
Ex.:  
                      [Nó_1]
                       /   \
                  [Nó_2]   [Nó_3]
                  /    \        \
             [Nó_4]   [Nó_5]   [Nó_6]
                      /        /    \
                 [Nó_7]    [Nó_8]   [Nó_9]
                                         \
                                         [Nó_10]

Calcule:
1) h5 = MAX(#<5,7>)
   h5 = 1

2) h6 = MAX(#<6,8>, #<6,9,10>)
   h6 = MAX(1,2) = 2

3) h4 = MAX(#<4>)
   h4 = 0

4) (ALTURA DA ÁRVORE)
   h = MAX(#<1,2,4>, #<1,2,5,7>, #<1,3,6,8>, #<1,3,6,9,10>)
   h = 4

4) Árvore completa:
    - Todos os nós da árvore possuem NENHUM ou DOIS filhos
    Ex.1:
                      [Nó_1]
                       /   \
                  [Nó_2]   [Nó_3]         -> [COMPLETA]
                                \
                               [Nó_4]

    Ex.2:
                      [Nó_1]
                       /   \
                  [Nó_2]   [Nó_3]         -> [NÃO_COMPLETA]
                  /             \
             [Nó_4]              [Nó_5]

5) Árvore cheia:
 - Uma árvore cheia é quando é COMPLETA e todas as folhas estiverem no mesmo NÍVEL
Ex.1:
                   [Nó_1]
                   /     \
              [Nó_2]     [Nó_3]          -> [CHEIA]
            /    \       /     \ 
        [Nó_4]  [Nó_5] [Nó_6]   [Nó_7]

Ex.2:
                   [Nó_1]
                   /     \
              [Nó_2]     [Nó_3]          -> [COMPLETA] [NÃO_CHEIA]
             /     \       
        [Nó_4]     [Nó_5] 

Ex.3:
                   [Nó_1]
                   /     \
             [Nó_2]       [Nó_3]          -> [QUASE_CHEIA]
            /     \       /
       [Nó_4]    [Nó_5] [Nó_6]


