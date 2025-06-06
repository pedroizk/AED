#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    char data;
    int topo;
    int base;
    int limite;
} *pile;


void initPile(*pile)
{
    pile->data = '';


}



int main(void) {

    pile *pilha;
    initPilha(pilha);
}