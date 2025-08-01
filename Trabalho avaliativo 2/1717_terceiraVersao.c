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
int counterAB(char* s, int x, Stack* p);
int counterBA(char* s, int x, Stack* p);

int maximumGain(char* s, int x, int y) {

    Stack* p = inicializar();
    Stack* p2 = inicializar();
    char* aux1 = s;
    char* aux2 = NULL;
    char* stringAux = malloc(strlen(s) + 1);

    if (strlen(s) > 1)
        aux2 = s + 1;

    int t = strlen(s);
    char valor;
    int pontos = 0;

    if (x > y) {
        pontos += counterAB(s, x, p);
        int j = 0;
        while (p->topo != 0) {
            stringAux[j] = pop(p);
            j++;
        }
        stringAux[j] = '\0';
        printf("%s", stringAux);
        pontos += counterAB(stringAux, y, p2);
    }

    else {
        pontos += counterBA(s, y, p);
        int j = 0;
        while (p->topo != 0) {
            stringAux[j] = pop(p);
            j++;
        }
        stringAux[j] = '\0';
        printf("%s", stringAux);
        pontos += counterBA(stringAux, x, p2);
    }

    return pontos;
}

int counterAB(char* s, int x, Stack* p) {
    int pontos = 0;


    int t = strlen(s);

    for (int i = 0; i < (t); i++) {

        if (i + 1 < t && s[i] == 'a' && s[i + 1] == 'b') {
            i++;
            pontos += x;

        }
        
         else if (s[i] == 'b' && p->topo > 0 &&
                   p->pilha[p->topo - 1] == 'a') {
            pop(p);
            pontos += x;
        } 
        
        else {
            push(p, s[i]);
        }

    }

    return pontos;
}

int counterBA(char* s, int x, Stack* p) {
    int pontos = 0;
    // qaawbbbwc

    int t = strlen(s);


    for (int i = 0; i < (t); i++) {

        if (i + 1 < t && s[i] == 'b' && s[i + 1] == 'a') {
            i++;
            pontos += x;

        } else if (s[i] == 'a' && p->topo > 0 &&
                   p->pilha[p->topo - 1] == 'b') {
            pop(p);
            pontos += x;
        }  else {
            push(p, s[i]);
        }

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