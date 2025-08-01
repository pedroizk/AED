#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int topo;
    char* pilha;
} Stack;

Stack* inicializar();
char pop(Stack* pilha);
void push(Stack* pilha, char valor);

int maximumGain(char* s, int x, int y) {

    Stack* p = inicializar();
    char* aux1 = s;
    char* aux2 = NULL;

    if (strlen(s) > 1)
        aux2 = s + 1;

    int t = strlen(s);
    char valor;
    int pontos = 0;

    for (int i = 0; i < (t - 1); i++) {
        if (x > y) {

            if (*aux1 == 'a' && *aux2 == 'b') {
                pontos += x;

            } else if (*aux1 == 'a' && p->topo > 0 &&
                       p->pilha[p->topo - 1] == 'b') {
                pop(p);
                pontos += x;
            } else if (i > 0 && *(aux1 - 1) == 'a' && *aux1 == 'b') {

            } else {
                push(p, s[i]);
            }

        }

        else {

            if (*aux1 == 'b' && *aux2 == 'a') {
                pontos += y;

            } else if (*aux1 == 'b' && p->topo > 0 &&
                       p->pilha[p->topo - 1] == 'a') {
                pop(p);
                pontos += y;
            } else if (i > 0 && *(aux1 - 1) == 'b' && *aux1 == 'a') {

            } else {
                push(p, s[i]);
            }
        }
        aux1++;
        aux2++;
    }

      

    return pontos;
}

Stack* inicializar() {
    Stack* nova_pilha = malloc(sizeof(Stack));
    nova_pilha->topo = 0;
    nova_pilha->pilha = malloc(sizeof(char));
    return nova_pilha;
}

void push(Stack* pilha, char valor) {
    pilha->pilha = realloc(pilha->pilha, sizeof(char) * (pilha->topo + 1));
    pilha->pilha[pilha->topo] = valor;
    pilha->topo += 1;
}

char pop(Stack* pilha) {
    if (pilha->topo == 0)
        return '\0';

    char valor_a_retornar = pilha->pilha[pilha->topo - 1];
    pilha->topo -= 1;
    pilha->pilha = realloc(pilha->pilha, sizeof(char) * pilha->topo);
    return valor_a_retornar;
}
