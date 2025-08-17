Nome: Pedro Izkovitz
Matrícula: 24100320

Ordenar uma lista simplesmente ligada em ordem crescente.
Regras: O(n log n) no tempo e O(1) extra (tirando a pilha da recursão).  

# Caminho até chegar na resposta correta


## Versão 01 — selection sort durante a aula

    Ideia: achar o menor, tirar da lista, jogar numa nova. Repetir.

    Problemas: problemas de sintaxe e lógica.

    Resultado: erros e saída errada.

## Versão 02 — selection sort (arrumado) 

    Corrigi os ponteiros e o laço.

    Funciona, mas é O(n²) → toma TLE nos casos grandes.

    Moral: corrigir bug ≠ cumprir complexidade.


## Versão 03 — merge sort (final)

- Divide com slow/fast, ordena recursivo e intercala linearmente.
- No merge uso um nó sentinela local chamado temp (variável na stack) para simplificar a montagem.
- Tempo O(n log n), espaço extra O(1) → Accepted.

---

## Passos do merge sort
1. Base: `0` ou `1` nó → retorna.
2. Achar o meio (slow/fast) e cortar (slow->next = NULL).
3. left = sortList(parte1), right = sortList(parte2).
4. Merge de left e right usando o sentinela temp e sempre ligando o menor.

---