#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define MOD 1000000007 // Para o cálculo do módulo, necessário para não estourar o long long
#define MAXN 1001 // Necessário para o alocar o espaço máximo para o triângulo de pascal

long long pascalTable[MAXN][MAXN];

void construirPascal(int n);
long long calculoCombinacoes(int *nums, int numsSize);

// ==============================================================================
// FUNÇÃO: numOfWays
// OBJETIVO:
//     Função principal chamada pelo sistema.
// ==============================================================================
int numOfWays(int *nums, int numsSize)
{
    if (numsSize < 3)
    {
        return 0; // Nenhuma permutação adicional possível
    }

    construirPascal(numsSize);

    long long ways = calculoCombinacoes(nums, numsSize);

    // Subtrai a permutação original e aplica módulo para evitar valor negativo
    long long result = (ways - 1 + MOD) % MOD;

    return (int)result;
}

// ==============================================================================
// FUNÇÃO: construirPascal
// OBJETIVO:
//     Construir tabela de combinações C(n, k) usando Triângulo de Pascal.
// DETALHES:
//     - Cada linha i contém i+1 elementos.
//     - Elementos extremos sempre valem 1.
//     - Demais valores são soma dos dois elementos acima.
//     - Todos os cálculos são feitos módulo MOD para evitar overflow.
// ==============================================================================
void construirPascal(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        pascalTable[i][0] = pascalTable[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            pascalTable[i][j] = (pascalTable[i - 1][j - 1] + pascalTable[i - 1][j]) % MOD;
        }
    }
}

// ===============================================,===============================
// FUNÇÃO: calculoCombinacoes
// OBJETIVO:
//     Recursivamente calcula o número de maneiras de gerar a mesma BST.
// DETALHES:
//     - Separa os elementos em dois grupos: menores e maiores que a raiz.
//     - Aplica recursão para os dois grupos separadamente.
//     - Usa a tabela de Pascal para contar as formas de intercalar os grupos.
//     - Combinação total: combinações possíveis * formas do lado esquerdo * formas do lado direito.
//     - Todos os resultados são calculados módulo MOD.
// ==============================================================================
long long calculoCombinacoes(int *nums, int numsSize)
{
    if (numsSize < 3)
    {
        return 1; // Árvores com menos de 3 elementos só têm uma estrutura possível
    }

    int left[MAXN], right[MAXN]; // Vetores fixos no stack
    int cl = 0, cr = 0;

    // Particionamento do array em dois subgrupos mantendo ordem relativa
    for (int i = 1; i < numsSize; ++i)
    {
        if (nums[i] < nums[0])
        {
            left[cl++] = nums[i];
        }
        else
        {
            right[cr++] = nums[i];
        }
    }

    // Recursão para os dois lados
    long long leftWays = calculoCombinacoes(left, cl);
    long long rightWays = calculoCombinacoes(right, cr);

    // Número de formas de intercalar left e right sem mudar a ordem relativa
    long long comb = pascalTable[cl + cr][cl];

    // Total de formas (modularizado para evitar estouro)
    long long totalWays = ((comb * leftWays) % MOD * rightWays) % MOD;

    return totalWays;
}

// ==============================================================================
// FUNÇÃO: main
// ==============================================================================
int main()
{
    // Exemplo de teste: [3, 1, 2, 5, 4, 6]
    int nums[] = {3, 1, 2, 5, 4, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = numOfWays(nums, numsSize);

    printf("Número de formas diferentes (excluindo a original): %d\n", result);

    return 0;
}
