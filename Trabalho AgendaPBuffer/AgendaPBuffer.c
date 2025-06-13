// Básico inicial 
// Definir o main que terá o PBuffer, inicialmente um ponteiro null.
// No main terá o loop while que chamará as funções básicas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  AdicionarPessoa(void** pBuffer, int* tamanhoPbuffer, int* qPalavras);
void  LerTudo(void** pBuffer, int* qPalavras, int*tamanho);
void RemoverPessoa(void** pBuffer, int* qPalavras, int* tamanho);


int main(void) {

    // DELIMITANDO PBUFFER E 03 ESPACOES INICIAIS
    void* pBuffer = malloc(sizeof(int) * 3);
    
    int* tamanhoBuffer = (int*)pBuffer;
    int* escolha = (int*)(pBuffer + sizeof(int));
    int* qPalavras = (int*)(pBuffer + sizeof(int) * 2);

    *tamanhoBuffer = sizeof(int) * 3;
    *qPalavras = 0;    
    
    
    
    while(*escolha != 5)
    {

        
        printf("Escolha uma das opções a seguir: \n 01: Adicionar uma pessoa \n 02: Remover pessoa \n 03: Buscar pessoa \n 04: Listar todos \n 05: Sair \n Escolha sua opção: ");
        scanf("%i", escolha);

        

        if(*escolha == 1)
            AdicionarPessoa(&pBuffer, tamanhoBuffer, qPalavras); 
        else if(*escolha == 2)
            RemoverPessoa(&pBuffer, tamanhoBuffer, qPalavras); 
        else if(*escolha == 3)
            printf("Buscar pessoa\n");
        else if(*escolha == 4)
            LerTudo(&pBuffer, qPalavras, tamanhoBuffer);
        else if(*escolha == 5)
            printf("Sair\n");
        
        else {
            printf("Escolha invalida");
        }

        
    }

    free(pBuffer);
    return 0;
}


void  AdicionarPessoa(void** pBuffer, int* tamanhoPbuffer, int* qPalavras)
{

    // Criar espaco maximo padrao
    *pBuffer = realloc(*pBuffer, *tamanhoPbuffer + sizeof(char) * 50 + sizeof(char) * 50 + sizeof(int) + sizeof(char) * 1);


    // Agora inserir nome
    char* base = (char*)(*pBuffer); // base aponta para o primeiro espaco de memoria de pBuffer, serve para somarmos com o valor de tamanhoPbuffer
    char* nome = base + *tamanhoPbuffer;
    printf("============== \n Insira seu nome: ");
    scanf("%49s", nome); // limitar tamanho do nome 
    *tamanhoPbuffer += strlen(nome) + 1;

    // Inserir idade 
    int* idade = (int*)(base + *tamanhoPbuffer);
    printf("============== \n Insira sua idade: ");
    scanf("%i", idade);
    *tamanhoPbuffer += sizeof(int);

    // Por fim inserir o email
    char* email = base + *tamanhoPbuffer;
    printf("============== \n Insira seu email: ");
    scanf("%49s", email); // mesma coisa para o emial
    *tamanhoPbuffer += strlen(email)+1;



    // Realoca o espaco apenas para o necessario 
    *pBuffer = realloc(*pBuffer, *tamanhoPbuffer); // inclui o \0 final
    *base = *tamanhoPbuffer;
    *qPalavras += 1;
}



void  LerTudo(void** pBuffer, int* qPalavras, int* tamanho)
{
    char* base = (char*)(*pBuffer); // Acessando o espaço de memória de tamanhoPbuffer;
    *pBuffer = realloc(*pBuffer, *tamanho + sizeof(int));
    int* auxiliar = (int*)(base+*tamanho);

    base += sizeof(int) * 3; // pula os 3 ints iniciais, agora aponta para primeira palavra
    
    printf("========== Listagem de contatos ========== \n\n");
    for(*auxiliar = 0; *auxiliar < *qPalavras; (*auxiliar)++)
    {
        printf("=======================\n");
        printf("Contato %i\n\n", *auxiliar + 1);
        printf("Nome: ");
        printf("%s \n", base);
        base += strlen(base) + 1;
        printf("Idade: %i\n", *(int*)base);
        base += sizeof(int);
        printf("Email: ");
        printf("%s \n", base);
        base += strlen(base) + 1;
        printf("=======================\n\n");

    }
    printf("========================================= \n");

    *pBuffer = realloc(*pBuffer, *tamanho);
    
}
 
void RemoverPessoa(void** pBuffer, int* qPalavras, int* tamanho) {

    *pBuffer = realloc(*pBuffer, *tamanho + sizeof(int) + sizeof(char) * 50);
    char* base = (char*)(*pBuffer); 
    int* contadorAuxiliar = (int*)(base+*tamanho);
    char* nomeASerRemovido = (char*)(base+*tamanho+sizeof(int));

    base += sizeof(int) * 3; 
    int*ponteiro_auxiliar = (int*)(base - sizeof(int));

    printf("Nome da pessoa a ser removida: ");
    scanf("%s", nomeASerRemovido);


    for(*contadorAuxiliar = 0; *contadorAuxiliar < *qPalavras; (*contadorAuxiliar)++)
    {
        if(strcmp(base, nomeASerRemovido) == 0)
        {
            *ponteiro_auxiliar = *ponteiro_auxiliar = strlen(base) + 1                            
                            + sizeof(int)                                     
                            + strlen(base + strlen(base) + 1 + sizeof(int)) + 1;

            memmove(base, base + *ponteiro_auxiliar, *tamanho - (*ponteiro_auxiliar));
            *pBuffer = realloc(*pBuffer, *tamanho -  (*ponteiro_auxiliar));

            *qPalavras -= 1;
            break;
        }
        base += strlen(base) + 1;
        base += sizeof(int);
        base += strlen(base) + 1;
    }

    *pBuffer = realloc(*pBuffer, *tamanho - *ponteiro_auxiliar);
    *ponteiro_auxiliar = 2;


}
