/*
Solução para o problema TwoSum em C

63 / 63 test cases passed.
Status: Accepted
Runtime: 207 ms
Memory Usage: 8.7 MB
Submitted: 1 day ago (06/05/2025)
Author: pedroizkovitz

*/
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int* result = (int*) malloc(2 * sizeof(int));

    for(int i = 0; i < numsSize; i++)
    {
        for(int j = 0; j < numsSize; j++ )
        {
            if((nums[i] + nums[j]) == target && i != j)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return NULL;

}

// Para testes 


int main(void) {
    int a[3] = {1,2,3};
    int t = 3;
    int *b;
    int *resultado;
    resultado = (twoSum(a, 3, t, b));

    if (*b == 2) {
        printf("[%i, %i]\n", resultado[0], resultado[1]);
        free(resultado);
    } else {
        printf("Nenhum par\n");
    }

}
