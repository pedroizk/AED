#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
//====================================================================
// Funções da agenda usando apenas pBuffer e realloc, sem variáveis extras
//====================================================================
=======
void AdicionarPessoa( void **pBuffer);
void LerTudo( void **pBuffer);
void RemoverPessoa( void **pBuffer, int *qPalavras, int *tamanho );
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67

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

<<<<<<< HEAD
    // Loop principal: recalcule ponteiros antes de cada uso
    for (;;)
    {
        int *tamanhoBuffer = (int *)pBuffer;
        int *escolha = (int *)(pBuffer + sizeof(int));
        int *qPalavras = (int *)(pBuffer + sizeof(int) * 2);

        
=======
    *tamanhoBuffer = sizeof( int ) * 3; // Atualizei o tamanho e setei a quantidade de pessoas para zero
    *qPalavras = 0;
    *escolha = 0;
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67

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

<<<<<<< HEAD
        // Se escolha for 5, sai
        if (*escolha == 5)
        {
            printf("Sair\n");
            break;
=======
    while ( *escolha != 5 ) {
        printf( "\nEscolha uma das opções a seguir:\n 01: Adicionar uma pessoa\n 02: Remover pessoa\n 03: Buscar pessoa\n 04: Listar todos\n 05: Sair\n Escolha sua opção: " );
        scanf( "%d", escolha );

        if ( *escolha == 1 ) {
            AdicionarPessoa( &pBuffer );

            // Atualização necessária após realloc dentro da função
            tamanhoBuffer = (int *)pBuffer;
            qPalavras = (int *)( pBuffer + sizeof( int ) * 2 );
            escolha = (int *)( pBuffer + sizeof( int ) );

        } else if ( *escolha == 2 ) {
            RemoverPessoa( &pBuffer, qPalavras, tamanhoBuffer );


        // OBS: Essa atualização manual do segundo espaço de memória foi necessário, porque no meio do códig ele estava sendo sobrescrito
        } else if ( *escolha == 3 ) {
            int *ponteiro_auxiliar = (int *)( pBuffer + sizeof( int ) );
            *ponteiro_auxiliar = 3;
            RemoverPessoa( &pBuffer, qPalavras, tamanhoBuffer );
            *ponteiro_auxiliar = 0;

        } else if ( *escolha == 4 ) {
            LerTudo( &pBuffer);

        } else if ( *escolha == 5 ) {
            break;

        } else {
            printf( "Escolha inválida\n" );
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67
        }
    }

    
    free(pBuffer);
    return 0;
}

<<<<<<< HEAD
//=============================================================================
// AdicionarPessoa: realoca pBuffer, lê nome, idade, email e atualiza contador
//=============================================================================
void AdicionarPessoa(void **pBuffer, int *tamanhoPbuffer, int *qPalavras)
=======



/*
====================
AdicionarPessoa
 Adiciona uma nova pessoa na memória dinâmica. 
====================
*/
void AdicionarPessoa( void **pBuffer)
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67
{
    *pBuffer = realloc(*pBuffer, *tamanhoPbuffer + 50 + sizeof(int) + 50);

<<<<<<< HEAD
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
    *pBuffer = realloc(*pBuffer, *tamanhoPbuffer);

    // Recalcula de novo e incrementa contador
    tamanhoPbuffer = (int *)(*pBuffer);
    qPalavras = (int *)(*pBuffer + sizeof(int) * 2);
    *qPalavras += 1;
}

//=============================================================================
// LerTudo: lista todos os contatos, usando realloc para auxiliar no laço
//=============================================================================
void LerTudo(void **pBuffer, int *qPalavras, int *tamanho)
=======
    // Lógica básica:
    // Cria espaço de memória para uma pessoa máxima ->
    // Recebe os valores ->
    // Descobre o tamanho ->
    // Aumenta o tamanho da variável tamanho (variável de tamannho total do pBuffer) ->
    // Por fim, dá um realloc final para cortar o espaço extra desnecessário

    int * tamanhoPbuffer = (int*)(*pBuffer); // Pego o valor, do primeiro espaço de memória
    int * qPalavras = (int*)(*pBuffer + sizeof(int) * 2); // Agora do segundo para a quantidade de palavras

    *pBuffer = realloc( *pBuffer, *tamanhoPbuffer + 50 + sizeof(int) + 50 );

    // Atualizei os ponteiros depois do realloc
    tamanhoPbuffer = (int*)(*pBuffer);
    qPalavras = (int*)(*pBuffer + sizeof(int) * 2);

    printf( "============== \n Insira seu nome: " );
    scanf( " %49s", (char *)(*pBuffer + *tamanhoPbuffer) );
    *tamanhoPbuffer += strlen((char *)(*pBuffer + *tamanhoPbuffer)) + 1; 

    printf( "============== \n Insira sua idade: " );
    scanf( "%d", (int *)(*pBuffer + *tamanhoPbuffer) );
    *tamanhoPbuffer += sizeof( int );

    printf( "============== \n Insira seu email: " );
    scanf( " %49s", (char *)(*pBuffer + *tamanhoPbuffer) );
    *tamanhoPbuffer += strlen((char *)(*pBuffer + *tamanhoPbuffer)) + 1;

    *pBuffer = realloc( *pBuffer, *tamanhoPbuffer );

    // Atualizei os ponteiros depois do realloc final
    qPalavras = (int*)(*pBuffer + sizeof(int) * 2);
    *qPalavras += 1;
}





/*
====================
LerTudo
 Lista todas as pessoas cadastradas.
====================
*/
void LerTudo( void **pBuffer)
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67
{
    // Recalcula ponteiros antes de usar
    tamanho = (int *)(*pBuffer);
    qPalavras = (int *)(*pBuffer + sizeof(int) * 2);

<<<<<<< HEAD
    if (*qPalavras == 0)
    {
        printf("\n==============\nNenhuma pessoa na agenda\n==============\n");
        return;
    }

    // Expande para inserir contador auxiliar ao final
   *pBuffer = realloc(*pBuffer, *tamanho + sizeof(int));
=======
    // Lógica básica:
    // Inicialmente verifica se a quantidade de pessoas é zero (se for já sai da função) ->
    // Depois cria váriavel auxiliar zerada ->
    // Loopa no e vai escrevendo as pessoas -> 
    // No final um realloc para tirar aquela váriavel auxiliar do pBuffer

    if ( *(int*)(*pBuffer + sizeof(int) * 2) == 0 ) {
        printf( "\n==============\nNenhuma pessoa na agenda\n==============\n" );
        return;
    }


    // Inicio do pBuffer tirando os 3 blocos de memória padrão
    char *base = (char *)( *pBuffer ) + sizeof( int ) * 3;

    // Variável auxiliar que vai pro final do pBuffer, serve para que o loop funcione
    int *auxiliar = (int *)( (char *)( *pBuffer ) + sizeof(int) );
    *auxiliar = 0;
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67


<<<<<<< HEAD
    // Recalcula ponteiros após realloc
    tamanho = (int *)(*pBuffer);
    qPalavras = (int *)(*pBuffer + sizeof(int) * 2);
=======
    for ( *auxiliar = 0; *auxiliar < *(int*)(*pBuffer + sizeof(int) * 2); ( *auxiliar )++ ) {
        printf( "=======================\n" );
        printf( "Contato %d\n\n", *auxiliar + 1 );
        printf( "Nome: %s\n", base );
        base += strlen( base ) + 1;
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67

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
   *pBuffer  = realloc(*pBuffer, *tamanho);

<<<<<<< HEAD
=======
    *auxiliar = 4;
    return;
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67
}
   



<<<<<<< HEAD
//=============================================================================
// RemoverPessoa: busca ou remove pessoas da agenda
//=============================================================================
void RemoverPessoa(void **pBuffer, int *qPalavras, int *tamanho)
{
    // Recalcula ponteiros iniciais
    tamanho = (int *)(*pBuffer);
    qPalavras = (int *)(*pBuffer + sizeof(int) * 2);
=======
/*
====================
RemoverPessoa
 Remove uma pessoa ou busca ela, dependendo da escolha inicial
====================
*/

// OBS: Essa função eu criei sem lembrar da buscar pessoa, então adaptei ela depois de pronta


void RemoverPessoa( void **pBuffer, int *qPalavras, int *tamanho )
{
    // Lógica básica:
    // Insiro as variáveis que vou precisar para essa função no pBuffer ->
    // Roubo a função do segundo espaço de memória que era da escolha para me ajudar a excluir a palavra ->
    // Verifico o valor da escolha ->
    // Se for remover entro utilizo a lógica de remoção, se for buscar eu apenas printo o valor no console.

    *pBuffer = realloc( *pBuffer, *tamanho + sizeof( int ) + 50 ); // Espaço para adicionar o nome da pessoa que vai ser removida e para o contador (mesma coisa que o auxiliar na última função)
    char *base = (char *)( *pBuffer ); // De novo um ponteiro para apontar para o endereço inicial de memória
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67

    // 1º realloc: espaço p/ contador e nome temporário
    *pBuffer = realloc(*pBuffer, *tamanho + sizeof(int) + 50);

<<<<<<< HEAD
    // Recalcula após realloc
    tamanho = (int *)(*pBuffer);
    qPalavras = (int *)(*pBuffer + sizeof(int) * 2);
=======
    base += sizeof( int ) * 3; // Pula os 3 espaços padrão
    int *ponteiro_auxiliar = (int *)( *pBuffer + sizeof(int) ); // atualizado após realloc
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67

    char *base = (char *)(*pBuffer) + sizeof(int) * 3;
    int *auxiliarContador = (int *)((char *)(*pBuffer) + *tamanho);
    int *flagBusca = (int *)((char *)(*pBuffer) + sizeof(int));
    char *nomeRemover = (char *)(*pBuffer) + *tamanho + sizeof(int);

    if (*flagBusca != 3)
        *flagBusca = 2;

<<<<<<< HEAD
    printf("Nome da pessoa: ");
    scanf(" %49s", nomeRemover);
=======
    char *inicioBase = base;

    for ( *contador = 0; *contador < *qPalavras; ( *contador )++ ) {
        if ( strcmp( base, nomeRemover ) == 0 ) {
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67

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
<<<<<<< HEAD
            // Remove registro nome+idade+email inline
            memmove(
                base,
                base + (strlen(base) + 1 + sizeof(int) + strlen(base + (strlen(base) + 1) + sizeof(int)) + 1),
                *tamanho - ((base + (strlen(base) + 1 + sizeof(int) + strlen(base + (strlen(base) + 1) + sizeof(int)) + 1)) - (char *)(*pBuffer)));
            // Ajusta tamanho total e decrementa contador
            *tamanho -= (strlen(base) + 1 + sizeof(int) + strlen(base + (strlen(base) + 1) + sizeof(int)) + 1);
=======

            int offset = 0;
            offset += strlen( base ) + 1;
            base += strlen( base ) + 1;

            offset += sizeof( int );
            base += sizeof( int );

            offset += strlen( base ) + 1;
            base += strlen( base ) + 1;

            memmove( base - offset, base, *tamanho - ( base - (char *)( *pBuffer ) ) );
            *tamanho -= offset;
            *pBuffer = realloc( *pBuffer, *tamanho );
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67
            *qPalavras -= 1;

            // 2º realloc: reduz bloco
             *pBuffer = realloc(*pBuffer, *tamanho);

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

<<<<<<< HEAD
    printf("\n==============\nPessoa não encontrada\n==============\n");
}
=======
    if ( *ponteiro_auxiliar == 2 || *ponteiro_auxiliar == 3 ) {
        printf( "\n==============\nEssa pessoa não existe na agenda\n==============\n" );
    }

    *pBuffer = realloc( *pBuffer, *tamanho ); // Se removeu a pessoa atualiza o valor do endereco de memoria para o valor novo, se não removeu não muda nada
    ponteiro_auxiliar = (int *)( *pBuffer + sizeof(int) ); // atualizado após realloc final
    *ponteiro_auxiliar = 2;
}
>>>>>>> 9b02cd0f2e242149b11492adf5a60d36a52b1e67
