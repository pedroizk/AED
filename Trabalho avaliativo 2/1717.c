
typedef struct {
    int topo; 
    char* pilha;
} Stack;

Stack* inicializar();
char pop(Stack* pilha);
void push(Stack* pilha, char valor);

int maximumGain(char* s, int x, int y) {
    
    Stack* p = inicializar();

    
}

// Ou, empilho tudo, quando terminar de empilhar, vou tirando de 3 em 3
// cdbcbbaaabab -> bab -> se eu escolho um deles o outro vai de volta para a pilha
// cdbcbbaaa -> bab -> cdbcbbaaab -> aab -> ab -> cdbcbbaa -> aab 


Stack* inicializar() {

    Stack* nova_pilha = malloc(sizeof(Stack));
    nova_pilha->topo = 0;
    nova_pilha->pilha = malloc(sizeof(char));
    return nova_pilha;

}

Stack