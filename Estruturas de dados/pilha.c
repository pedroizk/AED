// Testo no qual vou me basear

/*
Pilhas
    A operação INSERT em uma pilha é frequentemente denominada PUSH, e a operação DELETE, que não toma um
    argumento de elemento, é frequentemente denominada POP. Esses nomes são alusões a pilhas físicas, como as pilhas de
    pratos acionadas por molas usadas em restaurantes. A ordem em que os pratos são retirados da pilha é o inverso da
    ordem em que foram colocados na pilha, já que apenas o prato do topo está acessível.
    Como mostra a Figura 10.1, podemos implementar uma pilha de no máximo n elementos com um arranjo S[1.. n].
    O arranjo tem um atributo S.topo que indexa o elemento mais recentemente inserido. A pilha consiste nos elementos S[1
    .. S.topo], onde S[1] é o elemento na parte inferior da pilha e S[S.topo] é o elemento na parte superior.
    Quando S.topo = 0, a pilha não contém nenhum elemento e está vazia. Podemos testar se a pilha está vazia pela
    operação de consulta STACK-EMPTY. Se tentarmos extrair algo de uma pilha vazia, dizemos que a pilha tem estouro
    negativo, que é normalmente um erro. Se S.topo exceder n, a pilha tem um estouro. (Em nossa implementação de
    pseudocódigo, não nos preocuparemos com estouro de pilha.)
    Podemos implementar cada uma das operações em pilhas com apenas algumas linhas de código.

*/

// Estrutura básica que penso inicialmente. Fazer uma struct, ela irá conter: topo e o array iniciado em zero
// Topo será o valor de items na pilha

// Consegui fazer a pilha! Maiores problemas foram de sintexe, a lógica da estrutura é bem simples

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int topo;
    int* pilha;
} Pilha; 

void push(int valor, Pilha* end_pilha);
Pilha *inicializar();
int pop(Pilha* p);

int main(void) {

    Pilha* p = inicializar(); // Tive que criar por ser dinâmico na memória

    push(4, p);
    push(5, p);
    push(6, p);
    push(7, p);
    push(8, p);
    push(9, p);
    push(1, p);
    
    printf("=====\n Pilha:\n");
    for(int i = 0; i < p->topo; i++)
    {
        printf("Item %i: %i\n", i, p->pilha[i]);
    }
    printf("=====\n");

    int valor = pop(p);
    printf("%i\n", valor);

    printf("=====\n Pilha:\n");
    for(int i = 0; i < p->topo; i++)
    {
        printf("Item %i: %i\n", i, p->pilha[i]);
    }
    printf("=====\n");

    free(p->pilha);
    free(p);
}

Pilha *inicializar() {

   Pilha* nova_pilha = malloc(sizeof(Pilha));
    nova_pilha->topo = 0;
    nova_pilha->pilha = malloc(sizeof(int));
    return nova_pilha;
} 


void push(int valor, Pilha* end_pilha) {

    end_pilha->topo+= 1; // aumenta o topo em 1
    end_pilha->pilha = realloc(end_pilha->pilha, sizeof(int) * (end_pilha->topo)); // realloca o valor baseado em quantos itens tem na pilha

    end_pilha->pilha[end_pilha->topo - 1] = valor; // bota no ultimo indice o valor


}

int pop(Pilha* p) {

    if(p->topo != 0)
        p->topo -= 1;

    int valor_a_retornar = p->pilha[p->topo];

    p->pilha = realloc(p->pilha, sizeof(int) * p->topo);
    return valor_a_retornar;
    

}


