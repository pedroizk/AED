/*
Filas
Designamos a operação INSERT em uma fila por ENQUEUE (ENFILEIRAR) e a operação DELETE por DEQUEUE (DESINFILEIRAR);
assim como a operação em pilhas POP , DEQUEUE não adota nenhum argumento de elemento. A propriedade FIFO de uma
fila faz com que ela funcione como uma fileira de pessoas em uma caixa registradora. A fila tem um início (ou cabeça) e
um fim (ou cauda). Quando um elemento é inserido na fila, ocupa seu lugar no fim da fila, exatamente como um cliente
que acabou de chegar ocupa um lugar no final da fileira. O elemento retirado da fila é sempre aquele que está no início
da fila, como o cliente que está no início da fileira e esperou por mais tempo.
*/


// Teoricamente, agora vou precisar guardar dois ponteiros, um para o inicio da fila e outro para o fim.
// Entretanto, ao remover um elemento da fila preciso mover todos os outros valores

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int inicio;
    int fim;

    int* fila;
} Fila;


Fila* inicializar();
void enqueue(Fila* fila, int valor);
int dequeue(Fila* fila);
void printarFila(Fila* fila);

int main(void) {
    Fila* fila;

    fila = inicializar();

    enqueue(fila, 6);
    enqueue(fila, 5);
    enqueue(fila, 9);
    enqueue(fila, 10);
    enqueue(fila, 25);

    int a = dequeue(fila);
    printf("tirei: %i \n", a);

    printarFila(fila);

    a = dequeue(fila);
    printf("tirei: %i \n", a);

    printarFila(fila);
    a = dequeue(fila);
    a = dequeue(fila);
    a = dequeue(fila);

    printarFila(fila);


    
}

Fila* inicializar() {
    Fila* fila = malloc(sizeof(Fila));
    fila->fila = malloc(sizeof(int));
    fila->fim = 0;
    fila->inicio = 0;
    return fila;
}

void enqueue(Fila* fila, int valor) {

    fila->fim += 1;
    fila->fila = realloc(fila->fila, sizeof(int) * fila->fim);
    fila->fila[fila->fim - 1] = valor;

}

int dequeue(Fila * fila) {

    if(fila->fim == 0) {
        printf("\nFila esta vazia\n");
        return 0;
    }

    fila->fim -= 1;
    int valor_a_retornar = fila->fila[fila->inicio];
    memmove(&fila->fila[fila->inicio], &fila->fila[fila->inicio + 1], sizeof(int) * fila->fim);
    return valor_a_retornar;

}


void printarFila(Fila* fila) {

    printf("===== Valores da fila ===== \n");
    for(int i = 0; i < fila->fim; i++)
    {
        printf("%i: %i \n", i+1, fila->fila[i]);
    }
    printf("\n ========= \n");

}