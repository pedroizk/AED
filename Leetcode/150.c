int pop(int **stack, int *size);
void push(int **stack, int *size, int value);

int evalRPN(char** tokens, int tokensSize) {

    int *pilha = NULL;

    char valor;
    int contador = 0;
    int n1,n2;
    int op;

        for(int i = 0; i < tokensSize; i++)
        {
            valor = *tokens[i];
            if (tokens[i][0] >= '0' || tokens[i][0] == '-' && tokens[i][1] != '\0') {
                push(&pilha, &contador, atoi(tokens[i]));
            }

            else {
                n1 = pop(&pilha, &contador);
                n2 = pop(&pilha, &contador);

                if(valor == '+')
                {
                    op = n1 + n2;
                    push(&pilha, &contador, op);
                }
                else if(valor == '/')
                {
                    op = n2/n1;
                    push(&pilha, &contador,  op);
                }            
                else if(valor == '*') {
                    op = n1 * n2;
                    push(&pilha, &contador, op);
                }   
                else if(valor == '-') {
                    op = n2 - n1;
                    push(&pilha, &contador, op);
                }               
            }


        }


    return *pilha;
}


int pop(int **stack, int *size) {
    if (*size == 0) {
        return -1; 
    }

    int value = (*stack)[*size - 1];  
    (*size)--;                        

    int *tmp = realloc(*stack, (*size) * sizeof(int));
    if (tmp != NULL || *size == 0) { 
        *stack = tmp;
    }

    return value;
}

void push(int **stack, int *size, int value) {
    int *tmp = realloc(*stack, (*size + 1) * sizeof(int));
    if (tmp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    *stack = tmp;
    (*stack)[*size] = value;
    (*size)++;
}



// Basico dos guri
// Vai botando na pilha, se achar da dois pop