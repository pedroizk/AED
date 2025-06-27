
typedef struct {
    int topo; 
    char* pilha;
} Stack;

Stack* inicializar();
char pop(Stack* pilha);
void push(Stack* pilha, char valor);

int maximumGain(char* s, int x, int y) {
    
    Stack* p = inicializar();
    char* tempString = malloc(sizeof(char) * 4 );
    char valor;
    int pontos = 0;

    for(int i = 0; i < strlen(s); i++)
    {
        push(p, s[i]);
    }

    while(p->pilha != NULL)
    {
       for(int i = 0; i < 3; i++)
       {
            tempString[i] = pop(p);
       }
       tempString[3] = '\0';
       
        int v1= tempString[0];
        int v2 = tempString[1];
        int v3 = tempString[2];

       if(x > y) // se ab der mais pontos que ba ---- bab abb baa aba aab 
       {
        // Valores estao invertidos logo meu ab é ba
            if((v1 == 'b' && v2 == 'a'))
            {
                push(p, v3);
                pontos += 5;
                break;
            }
            else if(v3 == 'a' && v2 == 'b')
            {
                push(p, v1);
                pontos += 5;
                
            }
            else if(v3 == 'b'  && v2 == 'a')
            {
                push(p, v1);
                pontos += 4;
                               
            }
           else if(v2 == 'b'  && v1 == 'a')
            {
                push(p, v1);
                pontos += 4;
                               
            }
            
            else {
                push(p,v1);
                push(p, v2);
                push(p, v3);
            }


       }

       else if(y < x)
       {

       }

       else {
            
       }
        
        

    }
    return pontos;
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


void push(Stack* pilha, char valor) {

    pilha->pilha = realloc(pilha->pilha, sizeof(char) * ( pilha->topo + 1));
    pilha->pilha[pilha->topo] = valor;
    pilha->topo += 1;

}


char pop(Stack* pilha) {

    if(pilha->topo == 0)
        return '\0';
    
    char valor_a_retornar =  pilha->pilha[pilha->topo-1];

    pilha->topo -=1;
    pilha->pilha = realloc(pilha->pilha, sizeof(char) * ( pilha->topo));
    

    return valor_a_retornar;

}