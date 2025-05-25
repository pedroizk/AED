#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {

    char* wordVector = NULL;
    int contador = 1;
    int contador2[wordsSize];
    char a;
    char *temp;
    
    for(int i = 0; i < (int)strlen(licensePlate); i++) {
        if(tolower((unsigned char)licensePlate[i]) >= 'a' &&
           tolower((unsigned char)licensePlate[i]) <= 'z') {
            wordVector = realloc(wordVector, sizeof(char) * (contador + 1));
            wordVector[contador - 1] = tolower((unsigned char)licensePlate[i]);
            wordVector[contador] = '\0';
            contador++;
        }
    }

    int tamanhoLetras = sizeof(wordVector) / wordVector[0];
    int maior = 0;
    int indiceMaior = 0;
    int contador4 = 0;

    for(int i = 0; i < wordsSize; i++) {
        int contador3 = 0;
        contador4 = 0;
        for(int j = 0; j < tamanhoLetras; j++) {
            while(words[i][contador4] != '\0') {
                if(tolower((unsigned char)words[i][contador4]) == wordVector[j]) {
                    contador3++;
                }
                contador4++;
            }
        }
        if(contador3 > maior) {
            maior = contador3;
            indiceMaior = i;
        }
    }
    return words[indiceMaior];
}




int main() {
    char* licensePlate = "1s3 PSt";
    char* words[] = {"step", "steps", "stripe", "stepple"};
    int wordsSize = sizeof(words) / sizeof(words[0]);

    char* resultado = shortestCompletingWord(licensePlate, words, wordsSize);
    printf("Palavra encontrada: %s\n", resultado);

    return 0;
}
