#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int topo;
    char* pilha;
    int capacidade;
} Stack;

Stack* inicializar(int capacidade);
char pop(Stack* pilha);
void push(Stack* pilha, char valor);
int counterAB(char* s, int x, Stack* p);
int counterBA(char* s, int x, Stack* p);

int maximumGain(char* s, int x, int y) {

    int capacidade = strlen(s);
    Stack* p = inicializar(capacidade);
    Stack* p2 = inicializar(capacidade);

    int pontos = 0;
    char* stringAux = malloc(strlen(s) + 1);

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

    free(stringAux);
    free(p->pilha);
    free(p);
    free(p2->pilha);
    free(p2);

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

Stack* inicializar(int capacidade) {
    Stack* nova_pilha = malloc(sizeof(Stack));
    nova_pilha->topo = 0;
    nova_pilha->pilha = malloc(sizeof(char) * capacidade);
    return nova_pilha;
}

void push(Stack* pilha, char valor) {
    pilha->pilha[pilha->topo] = valor;
    pilha->topo += 1;
}

char pop(Stack* pilha) {
    if (pilha->topo == 0)
        return '\0';

    char valor_a_retornar = pilha->pilha[pilha->topo - 1];
    pilha->topo -= 1;
    return valor_a_retornar;
}


int main() {
    char s1[] = "cdbcbbaaabab";
    int x1 = 4, y1 = 5;
    printf("String: %s, x: %d, y: %d -> Pontos: %d\n", s1, x1, y1, maximumGain(s1, x1, y1));

    char s2[] = "ababaaab";
    int x2 = 5, y2 = 3;
    printf("String: %s, x: %d, y: %d -> Pontos: %d\n", s2, x2, y2, maximumGain(s2, x2, y2));

    char s3[] = "aabbaaxybbaabb";
    int x3 = 10, y3 = 5;
    printf("String: %s, x: %d, y: %d -> Pontos: %d\n", s3, x3, y3, maximumGain(s3, x3, y3));

    char s4[] = "";
    int x4 = 10, y4 = 5;
    printf("String: %s, x: %d, y: %d -> Pontos: %d\n", s4, x4, y4, maximumGain(s4, x4, y4));

    char s5[] = "aaaaa";
    int x5 = 10, y5 = 5;
    printf("String: %s, x: %d, y: %d -> Pontos: %d\n", s5, x5, y5, maximumGain(s5, x5, y5));

    char s6[] = "bbbbb";
    int x6 = 10, y6 = 5;
    printf("String: %s, x: %d, y: %d -> Pontos: %d\n", s6, x6, y6, maximumGain(s6, x6, y6));
    
    return 0;
}