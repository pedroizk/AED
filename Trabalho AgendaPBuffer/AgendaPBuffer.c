// Básico inicial 
// Definir o main que terá o PBuffer, inicialmente um ponteiro null.
// No main terá o loop while que chamará as funções básicas

#include <stdio.h>
#include <stdlib.h>



int main(void) {

    // DELIMITANDO PBUFFER E 03 ESPACOES INICIAIS
    void* pBuffer = malloc(sizeof(int) * 2 + sizeof(char));
    
    int* tamanhoBuffer = (int*)pBuffer;
    *tamanhoBuffer = sizeof(int) * 2 + sizeof(char);
    
    int* escolha = (int*)(pBuffer + sizeof(int));
    char* final = (char*)(pBuffer + (sizeof(int) * 2));


    
    // while(*escolha != 5)
    // {

    //     if(*escolha) {
    //         printf("Escolha uma das opções a seguir: \n 01: Adicionar uma pessoa \n 02: Remover pessoa \n 03: Buscar pessoa \n 04: Listar todos \n 05: Sair \n Escolha sua opção: ");
    //         scanf("%i", escolha);

    //     }

    //     if(*escolha == 1)
    //         printf("Adicionar pessoa\n");
    //     else if(*escolha == 2)
    //         printf("Remover pessoa\n");
    //     else if(*escolha == 3)
    //         printf("Buscar pessoa\n");
    //     else if(*escolha == 4)
    //         listarAgenda(tamanhoBuffer);
    //     else if(*escolha == 5)
    //         printf("Sair\n");
        
    //     else {
    //         printf("Escolha invalida");
    //     }

        
    // }
    

}


