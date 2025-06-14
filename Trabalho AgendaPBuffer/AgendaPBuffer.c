#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AdicionarPessoa( void **pBuffer, int *tamanhoPbuffer, int *qPalavras );
void LerTudo( void **pBuffer);
void RemoverPessoa( void **pBuffer, int *qPalavras, int *tamanho );


/*
====================
main
 Menu principal da agenda com controle via pBuffer
====================
*/

int main( void )
{
    // Iniciei o pBuffer com 03 espaços de memória padrão 
    // [0] tamanho total do pBuffer
    // [1] escolha do menu
    // [2] quantidade de pessoas cadastradas
    
    void *pBuffer = malloc( sizeof( int ) * 3 );

    int *tamanhoBuffer = (int *)pBuffer; // Espaço para guardar o tamanho do pBuffer em bytes
    int *escolha = (int *)( pBuffer + sizeof( int ) ); // Espaço pra saber qual é a escolha do usuário, uso para outras coisas depois
    int *qPalavras = (int *)( pBuffer + sizeof( int ) * 2 ); // Espaço para guardar a quantidade de pessoas na agenda

    // ==========================================================

    *tamanhoBuffer = sizeof( int ) * 3; // Atualizei o tamanho e setei a quantidade de pessoas para zero
    *qPalavras = 0;

    // ==========================================================

    // Loop para escolha de próxima ação

    while ( *escolha != 5 ) {
        printf( "\nEscolha uma das opções a seguir:\n 01: Adicionar uma pessoa\n 02: Remover pessoa\n 03: Buscar pessoa\n 04: Listar todos\n 05: Sair\n Escolha sua opção: " );
        scanf( "%d", escolha );

        if ( *escolha == 1 ) {
            AdicionarPessoa( &pBuffer, tamanhoBuffer, qPalavras );

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
            printf( "Sair\n" );

        } else {
            printf( "Escolha inválida\n" );
        }
    }

    free( pBuffer );
    return 0;
}



/*
====================
AdicionarPessoa
 Adiciona uma nova pessoa na memória dinâmica. 
====================
*/
void AdicionarPessoa( void **pBuffer, int *tamanhoPbuffer, int *qPalavras )
{

    // Lógica básica: 
    // Cria espaço de memória para uma pessoa máxima -> 
    // Recebe os valores -> 
    // descobre o tamanho -> 
    // Aumenta o tamanho da variável tamanho (variável de tamannho total do pBuffer) ->
    // Por fim, da um realloc final para cortar o espaço extra desnecessário

    *pBuffer = realloc( *pBuffer, *tamanhoPbuffer + 50 + sizeof( int ) + 50 );
    char *base = (char *)( *pBuffer ); // Ponteiro que aponta para o primeiro endereço de memória do pBuffer.
    char *nome = base + *tamanhoPbuffer; // Isso aponta pro final do meu tamanho anterior, indepente do qual for

    printf( "============== \n Insira seu nome: " );
    scanf( " %49s", nome );
    *tamanhoPbuffer += strlen( nome ) + 1;

    int *idade = (int *)( base + *tamanhoPbuffer );
    printf( "============== \n Insira sua idade: " );
    scanf( "%d", idade );
    *tamanhoPbuffer += sizeof( int );

    char *email = base + *tamanhoPbuffer;
    printf( "============== \n Insira seu email: " );
    scanf( " %49s", email );
    *tamanhoPbuffer += strlen( email ) + 1;

    *pBuffer = realloc( *pBuffer, *tamanhoPbuffer );
    *qPalavras += 1; // Atualiza a quantidade de pessoas;
}

/*
====================
LerTudo
 Lista todas as pessoas cadastradas.
====================
*/
void LerTudo( void **pBuffer)
{

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

    printf( "\n========== Listagem de contatos ==========\n\n" );

    for ( *auxiliar = 0; *auxiliar < *(int*)(*pBuffer + sizeof(int) * 2); ( *auxiliar )++ ) {
        printf( "=======================\n" );
        printf( "Contato %d\n\n", *auxiliar + 1 );
        printf( "Nome: %s\n", base );
        base += strlen( base ) + 1;

        printf( "Idade: %d\n", *(int *)base );
        base += sizeof( int );

        printf( "Email: %s\n", base );
        base += strlen( base ) + 1;
        printf( "=======================\n\n" );
    }

    *auxiliar = 4;
    return;
}

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
    
    *pBuffer = realloc( *pBuffer, *tamanho + sizeof( int ) + 50 ); // Espaço para adicionar o nome da pessoa que vai ser removida e para o contador (memsa coisa que o auxliar na última função)
    char *base = (char *)( *pBuffer ); // De novo um ponteiro para apontar para o endereço inicial de memória

    int *contador = (int *)( base + *tamanho ); // Contador igual ao da função ler tudo
    char *nomeRemover = (char *)( base + *tamanho + sizeof( int ) ); // Nome para comparar

    base += sizeof( int ) * 3; // Pula os 3 espaços padrão
    int *ponteiro_auxiliar = (int *)( base - ( sizeof( int ) * 2 ) ); // "Roubo" o valor inicial da variável de escolha

    if ( *ponteiro_auxiliar != 3 ) {
        *ponteiro_auxiliar = 2; // Gambiarra que tive que criar para que minha comparação final funcionasse
    }

    printf( "Nome da pessoa: " );
    scanf( " %49s", nomeRemover );

    for ( *contador = 0; *contador < *qPalavras; ( *contador )++ ) {
        if ( strcmp( base, nomeRemover ) == 0 ) {

            if ( *ponteiro_auxiliar == 3 ) {
                printf( "\n ====================== \n A pessoa %s foi achada na agenda! \n ======================\n", base );

                base += strlen( base ) + 1;
                printf( "Idade: %d \n", *(int *)base );

                base += sizeof( int );
                printf( "Email: %s \n", base );

                printf( "================================================================== \n" );
                *ponteiro_auxiliar = 1;
                break; // Sai do for e não exclui a pessoa.
            }

            *ponteiro_auxiliar = strlen( base ) + 1;
            base += *ponteiro_auxiliar;

            *ponteiro_auxiliar += sizeof( int );
            base += sizeof( int );

            *ponteiro_auxiliar += strlen( base ) + 1;
            base += strlen( base ) + 1;

            memmove( base - *ponteiro_auxiliar, base, *tamanho - ( base - (char *)( *pBuffer ) ) );
            *tamanho -= *ponteiro_auxiliar;
            *pBuffer = realloc( *pBuffer, *tamanho );
            *qPalavras -= 1;

            break;
        }

        base += strlen( base ) + 1;
        base += sizeof( int );
        base += strlen( base ) + 1;
    }

    if ( *ponteiro_auxiliar == 2 || *ponteiro_auxiliar == 3 ) {
        printf( "\n==============\nEssa pessoa não existe na agenda\n==============\n" );
    }

    *pBuffer = realloc( *pBuffer, *tamanho ); // Se removeu a pessoa atualiza o valor do endereco de memoria para o valor novo, se não removeu não muda nada
    *ponteiro_auxiliar = 2;
}


