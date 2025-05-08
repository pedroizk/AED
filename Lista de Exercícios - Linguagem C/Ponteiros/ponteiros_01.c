/*
1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das vari ´ aveis antes e ap ´ os a ´
modificac¸ao. 
*/

#include <stdio.h>

int main(void) {
    int a = 0;
    char b = '0';
    float c = 0;

    printf("%i\n", a);
    printf("%c\n", b);
    printf("%.2f\n", c);

    int* A;
    char* B;
    float* C;

    A = &a;
    B = &b;
    C = &c;

    *A = 1;
    *B = '1';
    *C = 1;

    printf("%i\n", a);
    printf("%c\n", b);
    printf("%.2f\n", c);

}