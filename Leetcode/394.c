#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* pop(char** pilha, int* tamanho) {
    if (*tamanho == 0)
        return NULL;

    (*tamanho)--;
    char* topo = (pilha)[*tamanho];
    *pilha = realloc(pilha, sizeof(char*) * (*tamanho));
    return topo;
}


void push(char** pilha, int* tamanho, const char* novaString) {
    *pilha = realloc(*pilha, sizeof(char*) * (*tamanho + 1));
    (*pilha)[*tamanho] = malloc(strlen(novaString) + 1);
    strcpy((*pilha)[*tamanho], novaString);
    (*tamanho)++;
}


char* decodeString(char* s) {
    char** pilha = NULL;
    int tamanho = 0;


    for(int i = 0; i<strlen(s); i++)
    {

        push(pilha,&tamanho, s[i]);
        printf("%c", *pilha[i]);
    }
}


int main(void) {

    char* string = decodeString("3[a]2[bc]");
}