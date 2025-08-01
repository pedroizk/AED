int dfs(int* nums, int numsSize, int** table);

int numOfWays(int* nums, int numsSize) {
    // Solução pensada após editorial

    // Passo 1: Separar o array em dois vetores, os maiores que o nodo(primeiro
    // numero) e os menores OBS: A ordem não pode ser mudada ao fazer isso

    // OBS: Podemos alterar o index deles desde que não alteremos a ordem dos
    // numeros em um mesmo subgrupo Passo 2: Calcular o número válido de
    // permutações possíveis quantidade de
    //(espaçoes no array - o inicial)! / (quantidade de números - o inicial - a
    // quantidade de números do array em questão)!

    // Passo 3: Montar função recursiva dfs que deve ser utilizado no array da
    // esquerda e direita * a permutação

    // Passo 4: Botar as exceções que serão arrays de tamanho < 3

    // Passo extra: terei que criar uma tabela de pascal para saber a quantidade
    // de combinacoes possiveis para multiplicar os meus arrays

    if (numsSize < 3)
        return 1;


    int** table = (int**)(malloc(sizeof(int*) * numsSize ));
    for(int i = 0; i < numsSize; i++) {
        table[i] = malloc(sizeof(int));
    }
    
    
    for (int i = 0; i < numsSize; ++i) {
        
        table[i][0] = table[i][i] = 1;
    }
    for (int i = 2; i < numsSize; i++) {
        for (int j = 1; j < i; j++) {
            table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]);
        }
    }

    return dfs(nums, numsSize, table);
}

int dfs(int* nums, int numsSize, int** table) {

    if (numsSize < 3)
        return 1;

    int left[numsSize];
    int right[numsSize];
    int cl = 0, cr = 0;

    for (int i = 0; i < numsSize - 1; i++) {

        if (nums[i] > nums[i + 1]) {
            left[cl] = nums[i + 1];
            cl++;
        }

        else {
            right[cr] = nums[i + 1];
            cr++;
        }
    }
    // dfs(left) * dfs(right) * a combinação de possibilidades entre os dois
    return dfs(left, cl, table) * dfs(right, cr, table) * table[numsSize -1][cl-1];
}
