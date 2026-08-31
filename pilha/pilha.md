# PILHA
Estrutura de dados linear onde o último elemento inserido é o primeiro a ser removido.
O primeiro elemento inserido é chamado de base da pilha e o último de topo.
Uma pilha pode ter tamanho fixo ou variável

# OPERAÇÕES
1) push: insere no topo
2) pop: remove o topo
3) peek: consulta o topo
4) pilha_vazia: retorna se a pilha está vazia 

Todas opreações "push", "pop" e "peek" tem complexidade O(1)

# IMPLEMENTAÇÕES
- Pilha sequencial:
    Alocação semelhante a uma lista sequencial utilizando um array para armazenar seus valores.

- Pilha dinâmica:
    Alocada em tempo de execução, semelhante à implementação de listas encadeadas.