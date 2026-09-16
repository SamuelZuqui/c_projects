# TAD FILA
Enquanto pilhas usam a política LIFO (last in, first out), as filas seguem o princípio FIFO (first in, first out).
Isso significa que quando retirar-mos um elemento da fila, ele sempre será aquele que está há mais tempo armazenado e é o único que podemos retirar.
Na prática, os elementos são inseridos no final e removidos no início possibilitando que sejam processados na mesma ordem que foram inseridos.

- Operações básicas:
    O princípio FIFO é assegurado por duas operações disponíveis na interface do TAD fila:
    
    1) Uma que insere no final da fila denotada por enqueue.
    
    2) Uma que retira no início da fila, denotadfa por dequeue.

    DEQUEUE <- [ ][ ][ ][ ] <- ENQUEUE
    Front/inicio              rear/fim


-- 
I = INICIO
F = FIM

## (F + x) % capacidade

Exemplo:
     0   1   2
    [4] [2] [3]       --->     (f + 1) % 3 = adiciona no 0    --->   Nesse caso, (F == 2 + 1 = 3) % 3 = 0 (adiciona no 0)
     I       F


     