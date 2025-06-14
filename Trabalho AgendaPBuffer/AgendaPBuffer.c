#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//====================================================================
// Funções da agenda usando apenas pBuffer e realloc, sem variáveis extras
//====================================================================

void AdicionarPessoa(void **pBuffer, int *tamanhoPbuffer, int *qPalavras);
void LerTudo(void **pBuffer, int *qPalavras, int *tamanho);
void RemoverPessoa(void **pBuffer, int *qPalavras, int *tamanho);

int main(void)
{
    // Aloca espaço inicial para [tamanhoBuffer, escolha, qPalavras]
    void *pBuffer = malloc(sizeof(int) * 3);
    if (!pBuffer)
    {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Inicializa valores no buffer
    *(int *)pBuffer = sizeof(int) * 3;       // tamanho total do bloco
    *(int *)(pBuffer + sizeof(int)) = 0;     // escolha do menu
    *(int *)(pBuffer + sizeof(int) * 2) = 0; // quantidade de pessoas

    // Loop principal: recalcule ponteiros antes de cada uso
    for (;;)
    {
        int *tamanhoBuffer = (int *)pBuffer;
        int *escolha = (int *)(pBuffer + sizeof(int));
        int *qPalavras = (int *)(pBuffer + sizeof(int) * 2);

        

        // Exibe menu e lê opção
        printf("\nEscolha uma das opções a seguir:\n"
               " 01: Adicionar uma pessoa\n"
               " 02: Remover pessoa\n"
               " 03: Buscar pessoa\n"
               " 04: Listar todos\n"
               " 05: Sair\n"
               "Escolha sua opção: ");
        scanf("%d", escolha);

        // Redireciona ação
        if (*escolha == 1)
        {
            AdicionarPessoa(&pBuffer, tamanhoBuffer, qPalavras);
        }
        else if (*escolha == 2)
        {
            RemoverPessoa(&pBuffer, qPalavras, tamanhoBuffer);
        }
        else if (*escolha == 3)
        { 
            RemoverPessoa(&pBuffer, qPalavras, tamanhoBuffer);
        }
        else if (*escolha == 4)
        {
            LerTudo(&pBuffer, qPalavras, tamanhoBuffer);
        }

        // Se escolha for 5, sai
        if (*escolha == 5)
        {
            printf("Sair\n");
            break;
        }
    }

    
    free(pBuffer);
    return 0;
}

//=============================================================================
// AdicionarPessoa: realoca pBuffer, lê nome, idade, email e atualiza contador
//=============================================================================
void AdicionarPessoa(void **pBuffer, int *tamanhoPbuffer, int *qPalavras)
{
    void *tmp = realloc(*pBuffer, *tamanhoPbuffer + 50 + sizeof(int) + 50);
    if (!tmp)
    {
        printf("Erro ao realocar memória!\n");
        return;
    }
    *pBuffer = tmp;

    // Recalcula ponteiros no novo bloco
    tamanhoPbuffer = (int *)(*pBuffer);
    qPalavras = (int *)(*pBuffer + sizeof(int) * 2);

    // base aponta ao início do bloco, nome ao fim do usado
    char *base = (char *)(*pBuffer);
    char *nome = base + *tamanhoPbuffer;

    printf("Insira seu nome: ");
    scanf(" %49s", nome);
    *tamanhoPbuffer += strlen(nome) + 1;

    // Idade logo após o nome
    int *idade = (int *)(base + *tamanhoPbuffer);
    printf("Insira sua idade: ");
    scanf("%d", idade);
    *tamanhoPbuffer += sizeof(int);

    // Email em sequência
    char *email = base + *tamanhoPbuffer;
    printf("Insira seu email: ");
    scanf(" %49s", email);
    *tamanhoPbuffer += strlen(email) + 1;

    // 2º realloc: ajusta bloco ao tamanho exato de dados
    tmp = realloc(*pBuffer, *tamanhoPbuffer);
    if (!tmp)
    {
        printf("Erro ao realocar memória!\n");
        return;
    }
    *pBuffer = tmp;

    // Recalcula de novo e incrementa contador
    tamanhoPbuffer = (int *)(*pBuffer);
    qPalavras = (int *)(*pBuffer + sizeof(int) * 2);
    *qPalavras += 1;
}

//=============================================================================
// LerTudo: lista todos os contatos, usando realloc para auxiliar no laço
//=============================================================================
void LerTudo(void **pBuffer, int *qPalavras, int *tamanho)
{
    // Recalcula ponteiros antes de usar
    tamanho = (int *)(*pBuffer);
    qPalavras = (int *)(*pBuffer + sizeof(int) * 2);

    if (*qPalavras == 0)
    {
        printf("\n==============\nNenhuma pessoa na agenda\n==============\n");
        return;
    }

    // Expande para inserir contador auxiliar ao final
    void *tmp = realloc(*pBuffer, *tamanho + sizeof(int));
    if (!tmp)
    {
        printf("Erro ao realocar memória!\n");
        return;
    }
    *pBuffer = tmp;

    // Recalcula ponteiros após realloc
    tamanho = (int *)(*pBuffer);
    qPalavras = (int *)(*pBuffer + sizeof(int) * 2);

    char *base = (char *)(*pBuffer) + sizeof(int) * 3;
    int *auxiliar = (int *)((char *)(*pBuffer) + *tamanho);

    printf("\n========== Listagem de contatos ==========");
    for (*auxiliar = 0; *auxiliar < *qPalavras; (*auxiliar)++)
    {
        printf("\n-----------------------");
        printf("\nContato %d", *auxiliar + 1);
        printf("\n Nome: %s", base);
        base += strlen(base) + 1;
        printf("\n Idade: %d", *(int *)base);
        base += sizeof(int);
        printf("\n Email: %s", base);
        base += strlen(base) + 1;
    }
    printf("\n-----------------------\n");

    // Remove espaço do auxiliar
    tmp = realloc(*pBuffer, *tamanho);
    if (!tmp)
    {
        printf("Erro ao realocar memória!\n");
        return;
    }
    *pBuffer = tmp;
}

//=============================================================================
// RemoverPessoa: busca ou remove pessoas da agenda
//=============================================================================
void RemoverPessoa(void **pBuffer, int *qPalavras, int *tamanho)
{
    // Recalcula ponteiros iniciais
    tamanho = (int *)(*pBuffer);
    qPalavras = (int *)(*pBuffer + sizeof(int) * 2);

    // 1º realloc: espaço p/ contador e nome temporário
    void *tmp = realloc(*pBuffer, *tamanho + sizeof(int) + 50);
    if (!tmp)
    {
        printf("Erro ao realocar memória!\n");
        return;
    }
    *pBuffer = tmp;

    // Recalcula após realloc
    tamanho = (int *)(*pBuffer);
    qPalavras = (int *)(*pBuffer + sizeof(int) * 2);

    char *base = (char *)(*pBuffer) + sizeof(int) * 3;
    int *auxiliarContador = (int *)((char *)(*pBuffer) + *tamanho);
    int *flagBusca = (int *)((char *)(*pBuffer) + sizeof(int));
    char *nomeRemover = (char *)(*pBuffer) + *tamanho + sizeof(int);

    if (*flagBusca != 3)
        *flagBusca = 2;

    printf("Nome da pessoa: ");
    scanf(" %49s", nomeRemover);

    for (*auxiliarContador = 0; *auxiliarContador < *qPalavras; (*auxiliarContador)++)
    {
        if (strcmp(base, nomeRemover) == 0)
        {
            if (*flagBusca == 3)
            {
                // Só pesquisa
                printf("\n========================");
                printf("\nEncontrou: %s", base);
                base += strlen(base) + 1;
                printf("\nIdade: %d", *(int *)base);
                base += sizeof(int);
                printf("\nEmail: %s\n========================\n", base);
                *flagBusca = 1;
                return;
            }
            // Remove registro nome+idade+email inline
            memmove(
                base,
                base + (strlen(base) + 1 + sizeof(int) + strlen(base + (strlen(base) + 1) + sizeof(int)) + 1),
                *tamanho - ((base + (strlen(base) + 1 + sizeof(int) + strlen(base + (strlen(base) + 1) + sizeof(int)) + 1)) - (char *)(*pBuffer)));
            // Ajusta tamanho total e decrementa contador
            *tamanho -= (strlen(base) + 1 + sizeof(int) + strlen(base + (strlen(base) + 1) + sizeof(int)) + 1);
            *qPalavras -= 1;

            // 2º realloc: reduz bloco
            tmp = realloc(*pBuffer, *tamanho);
            if (!tmp)
            {
                printf("Erro ao realocar memória!\n");
                return;
            }
            *pBuffer = tmp;

            // Recalcula ponteiros depois do realloc
            tamanho = (int *)(*pBuffer);
            qPalavras = (int *)(*pBuffer + sizeof(int) * 2);
            return;
        }
        // Avança para próximo registro
        base += strlen(base) + 1;
        base += sizeof(int);
        base += strlen(base) + 1;
    }

    printf("\n==============\nPessoa não encontrada\n==============\n");
}
