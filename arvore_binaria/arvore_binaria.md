# Árvores binárias e árvores AVL

## 1. Definição de árvore binária

Uma árvore pode ser definida de maneira recursiva:

1. A árvore pode ser vazia (nula); ou
2. Ela contém um nó que possui, no máximo, dois filhos (subárvores): um à esquerda e outro à direita.

```text
           T
         /   \
        O     O
             / \
           SAE SAD
```

- **SAE:** subárvore esquerda.
- **SAD:** subárvore direita.

### Exemplos

**Exemplo 1**

```text
        T
         \
          O
         / \
        O   O
           /
          O
```

**Exemplo 2**

```text
        T
         \
```

**Exemplo 3**

```text
        T
         \
          O
```

**Exemplo 4**

```text
        T
         \
          O
           \
            O
           / \
          O   O
```

## 2. Elementos da árvore binária

```text
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
```

- **Raiz:** primeiro nó (pai de todos).
- **Nó interno:** nó que possui filhos, mas não é a raiz.
- **Folha:** nó que não possui filhos.

> A raiz também pode ser uma folha, caso não tenha filhos.

## 3. Caminho, longitude e altura

### 3.1. Caminho

Um **caminho** é uma sequência de nós em que cada nó, exceto o primeiro, é filho do anterior.

```text
                      [Nó_1]
                       /   \
                  [Nó_2]   [Nó_3]
                  /    \        \
             [Nó_4]   [Nó_5]   [Nó_6]
```

Exemplos de caminhos:

| Sequência | É um caminho? |
|---|---|
| ⟨2, 5⟩ | ✅ |
| ⟨4, 2, 5⟩ | ❌ |
| ⟨1, 3, 6⟩ | ✅ |
| ⟨4, 6⟩ | ❌ |
| ⟨1, 2, 3⟩ | ❌ |
| ⟨1, 6, 3⟩ | ❌ |

### 3.2. Longitude

A **longitude** é a quantidade de relações pai–filho existentes no caminho. Se \(N\) é a quantidade de nós que formam o caminho:

$$
\#\langle\text{caminho}\rangle = N - 1
$$

Exemplos:

$$
\#\langle 2,5\rangle = 2 - 1 = 1
$$

$$
\#\langle 1,3,6\rangle = 3 - 1 = 2
$$

### 3.3. Altura

A altura \(h\) de um nó é a maior longitude entre os caminhos que vão desse nó até suas folhas.

```text
                      [Nó_1]
                       /   \
                  [Nó_2]   [Nó_3]
                  /    \        \
             [Nó_4]   [Nó_5]   [Nó_6]
                      /        /    \
                 [Nó_7]    [Nó_8]   [Nó_9]
                                         \
                                        [Nó_10]
```

**Altura do nó 5:**

$$
h_5 = \max\bigl(\#\langle 5,7\rangle\bigr) = 1
$$

**Altura do nó 6:**

$$
h_6 = \max\bigl(\#\langle 6,8\rangle,\ \#\langle 6,9,10\rangle\bigr)
     = \max(1,2) = 2
$$

**Altura do nó 4:**

$$
h_4 = \max\bigl(\#\langle 4\rangle\bigr) = 0
$$

**Altura da árvore:**

$$
\begin{aligned}
h = \max\bigl(
&\#\langle 1,2,4\rangle,\\
&\#\langle 1,2,5,7\rangle,\\
&\#\langle 1,3,6,8\rangle,\\
&\#\langle 1,3,6,9,10\rangle
\bigr) = 4
\end{aligned}
$$

## 4. Árvore completa

Todos os nós da árvore possuem **nenhum ou dois filhos**.

**Exemplo 1 — [COMPLETA]**

```text
                      [Nó_1]
                       /   \
                  [Nó_2]   [Nó_3]
                                \
                               [Nó_4]
```

**Exemplo 2 — [NÃO_COMPLETA]**

```text
                      [Nó_1]
                       /   \
                  [Nó_2]   [Nó_3]
                  /             \
             [Nó_4]           [Nó_5]
```

## 5. Árvore cheia

Uma árvore é **cheia** quando é completa e todas as folhas estão no mesmo nível.

**Exemplo 1 — [CHEIA]**

```text
                   [Nó_1]
                   /     \
              [Nó_2]     [Nó_3]
              /   \       /   \
         [Nó_4] [Nó_5] [Nó_6] [Nó_7]
```

**Exemplo 2 — [COMPLETA] [NÃO_CHEIA]**

```text
                   [Nó_1]
                   /     \
              [Nó_2]     [Nó_3]
              /   \
         [Nó_4] [Nó_5]
```

**Exemplo 3 — [QUASE_CHEIA] (tende à esquerda)**

```text
                   [Nó_1]
                   /     \
              [Nó_2]     [Nó_3]
              /   \       /
         [Nó_4] [Nó_5] [Nó_6]
```

## 6. Caminhamento em árvore

### 6.1. Caminhamento em profundidade

Passa por cada caminho na vertical.

- **Pré-ordem — RED:** raiz → esquerda → direita.
- **Em-ordem — ERD:** esquerda → raiz → direita.
- **Pós-ordem — EDR:** esquerda → direita → raiz.

> A raiz é o elemento que muda de posição entre as três ordens.

```text
                   [a]
                  /   \
               [b]    [c]
              /   \     \
           [d]    [e]    [h]
                  /  \
                [f]  [g]
```

| Ordem | Sequência |
|---|---|
| Pré-ordem | a, b, d, e, f, g, c, h |
| Em-ordem | d, b, f, e, g, a, c, h |
| Pós-ordem | d, f, g, e, b, h, c, a |

**Em-ordem:** com pilha.

### 6.2. Caminhamento em largura

- **Em-nível:** com fila.

```text
                   [a]
                  /   \
               [b]    [c]
              /   \     \
           [d]    [e]    [h]
                  / \
                [f] [g]
```

**Sequência em nível:** a, b, c, d, e, h, f, g.

## 7. Árvore binária de busca (ABB)

```text
          T
           \
           (R)
          /   \
         O     O
        SAE   SAD
```

Uma árvore binária é uma **árvore binária de busca (ABB)** se todo nó da SAE for menor que a raiz e todo nó da SAD for maior que a raiz.

**Exemplo:**

```text
          [5]
         /   \
       [3]   [10]
      /   \
    [1]   [4]
```

### 7.1. Inserção

Ao inserir um elemento, ele é colocado em uma posição **NULL**. A consulta determina onde adicioná-lo:

- Se for menor que o valor do nó atual, vá para a esquerda.
- Se for maior, vá para a direita.

**Exemplo — inserir o número 19:**

```text
         [10]
        /    \
      [5]    [15]
     /   \   /   \
   [3]  [8] [14] [NOVO_NÓ_19]
```

Caminho: **10 → 15** (direita do 10) **→ NULL** (direita do 15).

### 7.2. Remoção

Para remover um nó, deve-se trocar o nó desejado por uma folha, para não perder seus filhos, já que folhas não possuem filhos.

Pode-se escolher pela direita ou pela esquerda, usando o sucessor ou o antecessor:

- **Sucessor:** o menor número entre os maiores.
- **Antecessor:** o maior número entre os menores.

## 8. Implementação de uma árvore

### Estrutura do nó

```c
struct noarbin {
    <tipo> chave;
    struct noarbin *esq, *dir;
};

typedef struct noarbin arbin;
```

### Criação da árvore

```c
arbin *t;

t = cria_arbin();

arbin *cria_arbin() {
    return NULL;
}
```

**Encaminhamento:** pegar matéria.

## 9. Árvore AVL

Uma **árvore AVL** é uma ABB autobalanceada que visa garantir complexidade assintótica logarítmica para as operações de inserção, remoção e busca.

### 9.1. Fator de balanceamento

O **fator de balanceamento (FB)** de um nó é a diferença entre a altura da subárvore esquerda e a altura da subárvore direita:

$$
FB = H_{\mathrm{SAE}} - H_{\mathrm{SAD}}
$$

**Exemplo:**

```text
                [4]
               /   \
            [2]    [7]
              \    /
              [3] [6]
                  /  \
                [5]  [8]
```

$$
\begin{aligned}
FB(3) &= 0 - 0 = 0\\
FB(2) &= 0 - 1 = -1\\  
FB(7) &= 2 - 1 = 1\\
FB(4) &= 2 - 3 = -1
\end{aligned}
$$

Um nó está balanceado quando seu fator de balanceamento é \(-1\), \(0\) ou \(1\):

$$
\left|H_{\mathrm{SAE}} - H_{\mathrm{SAD}}\right| \leq 1
$$

Uma AVL está balanceada quando **todos os nós** estão balanceados:

$$
-1 \leq H_{\mathrm{SAE}} - H_{\mathrm{SAD}} \leq 1
$$


 