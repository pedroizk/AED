#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
====================
Definição da struct pilha
*/
typedef struct { 

    int topo; 
    char* pilha;
    int capacidade;

} Stack;

// Funções
Stack* inicializar(int capacidade); // Inicializa a struct, capacidade = strlen(string)
char pop(Stack* pilha); // Retira o último char da pilha e retorna-o 
void push(Stack* pilha, char valor); // Insere um valor no primeiro espaço vazio da pilha
int counterAB(char* s, int x, Stack* p); // Retira ab`s da pilha e retorna a quantidade de pontos
int counterBA(char* s, int x, Stack* p); // Retira ba`s da pilha e retorna a quantidade de pontos

/*
====================
maximumGain: retorna a quantidade maxima de pontos de uma string qualquer.
*/
int maximumGain( char* s, int x, int y ) {

    // Inicialização das pilhas
    int capacidade = strlen( s );
    Stack* p = inicializar( capacidade );
    Stack* p2 = inicializar( capacidade );
    int pontos = 0;

    // Cria uma string auxiliar
    char * stringAux = malloc( strlen( s ) + 1 );

    // Calcula os pontos quando ab vale mais que ba
    if ( x > y ) {

        // Primeiro calcula os pontos de ab
        pontos += counterAB( s, x, p );
        int j = 0;
        // agora os valores são retirados da pilha e para uma string, acontece a inversão dos elementos
        while ( p->topo != 0 ) {
            stringAux[j] = pop( p );
            j++;
        }
        stringAux[j] = '\0';
        printf( "%s", stringAux );

        // Mesma função é ativa, isso acontece porqu a funcão foi invertida
        pontos += counterAB( stringAux, y, p2 );
        
    }

    else {

        pontos += counterBA( s, y, p );
        int j = 0;
        while (p->topo != 0) {
            stringAux[j] = pop( p );
            j++;
        }
        stringAux[j] = '\0';
        printf( "%s", stringAux );
        pontos += counterBA( stringAux, x, p2 );
         
    }

    free( stringAux );
    free( p->pilha );
    free( p );
    free( p2->pilha );
    free( p2 );

    return pontos;
}

/*
====================
counterAB: recebe uma string, o valor dos pontos e uma pilha. Retira os ab's da string, coloca o resto dos valores na pilha e retorna a quantidade de pontos
*/
int counterAB( char* s, int x, Stack* p ) {
    
    int pontos = 0;
    int t = strlen(s);

    for ( int i = 0; i < (t); i++ ) {

        if ( i + 1 < t && s[i] == 'a' && s[i + 1] == 'b' ) {
            i++;
            pontos += x;

        }
        
         else if ( s[i] == 'b' && p->topo > 0 &&
                   p->pilha[p->topo - 1] == 'a' ) {
            pop( p );
            pontos += x;
        } 
        
        else {
            push(p, s[i]);
        }
    }

    return pontos;

}

/*
====================
counterBA: recebe uma string, o valor dos pontos e uma pilha. Retira os ba's da string, coloca o resto dos valores na pilha e retorna a quantidade de pontos
*/
int counterBA(char* s, int x, Stack* p) {
    int pontos = 0;

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

/*
====================
inicializar: Inicia a pilha e seta a capacidade máxima dela
*/
Stack* inicializar( int capacidade ) {

    Stack* nova_pilha = malloc( sizeof( Stack ) );
    nova_pilha->topo = 0;
    nova_pilha->pilha = malloc( sizeof( char ) * capacidade );
    return nova_pilha;

}

/*
====================
push: Bota um valor na pilha e aumenta seu topo em 1
*/
void push( Stack* pilha, char valor ) {

    pilha->pilha[pilha->topo] = valor;
    pilha->topo += 1;

}

/*
====================
pop: Retira o último elemento da pilha, diminui o topo em 1 e retorna o valor retirado.
*/
char pop(Stack* pilha) {
    if (pilha->topo == 0)
        return '\0';

    char valor_a_retornar = pilha->pilha[pilha->topo - 1];
    pilha->topo -= 1;
    return valor_a_retornar;
}