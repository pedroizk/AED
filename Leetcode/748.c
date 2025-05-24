 #include <ctype.h>

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {

    char* wordVector = NULL;
    int contador = 1;
    int contador2[wordsSize];
    char a;
    char *temp;
    
     for(int i = 0; i < strlen(licensePlate); i++)
     {
        
        if(tolower(licensePlate[i]) >= 'a' && tolower(licensePlate[i]) <= 'z')
        {
            wordVector = realloc(wordVector, sizeof(char) * (contador + 1));
            wordVector[contador-1] = tolower(licensePlate[i]);
            wordVector[contador] = '\0';
            contador++;
            
        }
    }

    int tamanhoVetor = strlen(wordVector);
    int indiceMenor = 0;
    contador = 0;
    bool tudoHash = true;
    int tamanhoMenor = 100;

    for(int i = 0; i < wordsSize; i++)
    {
        tudoHash = true;
        char* vetorTemp = malloc((tamanhoVetor + 1) * sizeof(char));
        strcpy(vetorTemp, wordVector);
        while(words[i][contador] != '\0') 
        {
            for(int k = 0; k < tamanhoVetor; k++) 
            {
                if(vetorTemp[k] == words[i][contador])
                {
                    vetorTemp[k] = '#';
                    break;
                }
            }
            contador++;
        } 
        contador = 0;

        for(int k = 0; k < tamanhoVetor; k++)
        {
            if(vetorTemp[k] != '#')
            {
                tudoHash = false;
            }
        }

        if(tudoHash && strlen(words[i]) < tamanhoMenor)
        {   
            tamanhoMenor = strlen(words[i]);
            indiceMenor = i;
        }
        free(vetorTemp);
    }

    return words[indiceMenor];
}