// Exercicio feito apenas em aula, não concluido

#include <stdio.h>
#include <string.h>

char nomes[0];
void adicionarNome();
void listarNomes();
void removerNome();

int main() {

    int escolha = 0;
    while(escolha != 4) {
    printf("Escolha uma das opções:  \n 1. Adicionar nome \n 2. Remover nome \n 3. Listar \n 4. Sair \n Escolha: ");
    escolha = 0;
    scanf("%i", &escolha);

    if(escolha == 1)
        adicionarNome();
    else if(escolha == 2)
        removerNome();
    else if(escolha == 3)
        listarNomes();
    else if(escolha == 4)
        printf("Saindo..");
    else
        printf("Não há essa opção");
    
    }
}

// nome[0] = ?
// 
// nome[1] = e
// []

void adicionarNome()
{
    char nomeAdicionar[100];
    printf("Digite o nome: ");
    scanf("%s", nomeAdicionar);
    char *pointer = &nomes[0];

    while(*(pointer) != '\0')
    {
        pointer = pointer + 1;
    }

    for(int i = 0; i < strlen(nomeAdicionar); i++)
    {

        *pointer = nomeAdicionar[i];
        pointer = pointer + 1;

    }
    *(pointer) = '-';
}

void listarNomes()
{
    char *pointer = &nomes[0];
    printf(" - - - - - - - - - - - - - - - - \n");
    for(int i = 1; i<=strlen(pointer); i++) {
        while(*pointer != '-')
        {
            printf("%c", *pointer);
            pointer = pointer + 1;
        }
        pointer = pointer+1;
        printf("\n");
    }
    printf("\n\n");

}

void removerNome()
{
    char nomeInputado[100];
    char nome[100];
    printf("Digite o nome: ");
    scanf("%s", nomeInputado);

    char *pointer = &nomes[0];
    int i = 0;
    while(*pointer != '\0') {
    while(*pointer != '-')
    {
        nome[i] = *pointer;
        pointer = pointer + 1;
        i++;
    }
    if(strcmp(nome, nomeInputado))
    {
        printf("achei");
        break;

    }
    else {
        printf("Não achei");
        break;
    }
}

}





