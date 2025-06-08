// Básico inicial 
// Definir o main que terá o PBuffer, inicialmente um ponteiro null.
// No main terá o loop while que chamará as funções básicas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  AdicionarPessoa(void** pBuffer, int* tamanhoPbuffer);
void * LerTudo(void* pBuffer, char* ponteiroDeAjuda);

int main(void) {

    // DELIMITANDO PBUFFER E 03 ESPACOES INICIAIS
    void* pBuffer = malloc(sizeof(int) * 2 + sizeof(char));
    
    int* tamanhoBuffer = (int*)pBuffer;
    *tamanhoBuffer = sizeof(int) * 2 + sizeof(char);
    
    int* escolha = (int*)(pBuffer + sizeof(int));
    char* final = (char*)(pBuffer + (sizeof(int) * 2));
    *final = '\0';

    
    
    while(*escolha != 5)
    {

        if(*escolha) {
            printf("Escolha uma das opções a seguir: \n 01: Adicionar uma pessoa \n 02: Remover pessoa \n 03: Buscar pessoa \n 04: Listar todos \n 05: Sair \n Escolha sua opção: ");
            scanf("%i", escolha);

        }

        if(*escolha == 1)
            AdicionarPessoa(&pBuffer, tamanhoBuffer); // CORRIGIDO: passa referência de pBuffer
        else if(*escolha == 2)
            printf("Remover pessoa\n");
        else if(*escolha == 3)
            printf("Buscar pessoa\n");
        else if(*escolha == 4)
            LerTudo(pBuffer, (char*)pBuffer + sizeof(int) * 2);
        else if(*escolha == 5)
            printf("Sair\n");
        
        else {
            printf("Escolha invalida");
        }

        
    }

    free(pBuffer);
    return 0;
}


void  AdicionarPessoa(void** pBuffer, int* tamanhoPbuffer)
{

    // Criar espaco maximo padrao
    *pBuffer = realloc(*pBuffer, *tamanhoPbuffer + sizeof(char) + sizeof(char) * 50 + sizeof(char) * 50 + sizeof(int) + sizeof(char) * 2);

    // Preciso agora alocar colocar o { e ja exclui o \0
    char* base = (char*)(*pBuffer);
    char* delimitador = base + *tamanhoPbuffer;
    *delimitador = '{';
    *tamanhoPbuffer += sizeof(char);

    // Agora inserir nome
    char* nome = base + *tamanhoPbuffer;
    printf("============== \n Insira seu nome: ");
    scanf("%49s", nome); // limitar tamanho do nome 
    *tamanhoPbuffer += strlen(nome);

    // inserir ,
    char* virgula = base + *tamanhoPbuffer;
    *virgula = ',';
    *tamanhoPbuffer += sizeof(char);

    // Inserir idade 
    int* idade = (int*)(base + *tamanhoPbuffer);
    printf("============== \n Insira sua idade: ");
    scanf("%i", idade);
    *tamanhoPbuffer += sizeof(int);

    // Inserir ,
    char* virgula2 = base + *tamanhoPbuffer;
    *virgula2 = ',';
    *tamanhoPbuffer += sizeof(char);

    char* email = base + *tamanhoPbuffer;
    printf("============== \n Insira seu email: ");
    scanf("%49s", email); // mesma coisa para o emial
    *tamanhoPbuffer += strlen(email);

    char* delimitador2 = base + *tamanhoPbuffer;
    *delimitador2 = '}';
    *tamanhoPbuffer += sizeof(char);

    char* finaliza = base + *tamanhoPbuffer;
    *finaliza = '\0';

    // Realoca o espaco apenas para o necessario 
    *pBuffer = realloc(*pBuffer, *tamanhoPbuffer + 1); // inclui o \0 final
}



void * LerTudo(void* pBuffer, char* ponteiroDeAjuda)
{
    ponteiroDeAjuda = pBuffer;

    while(*ponteiroDeAjuda != '\0')
    {
        printf("%c",*ponteiroDeAjuda);
        ponteiroDeAjuda += 1;
    }

}
