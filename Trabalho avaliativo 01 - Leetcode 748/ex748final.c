#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
============================
ShortestCompletingWord
 Recebe uma placa de carro e retorna a menor palavra da lista que contém todas as letras da placa
============================
*/
char* ShortestCompletingWord( char* licensePlate, char** words, int wordsSize ) {

	char* wordVector = NULL;
	int letterCount = 1;
	int tempCounter[wordsSize];
	char placeholderChar;
	char* tempWord;

	// Extrai as letras da placa, ignorando números e símbolos
	for ( int i = 0; i < strlen( licensePlate ); i++ ) {
		if ( tolower( licensePlate[i] ) >= 'a' && tolower( licensePlate[i] ) <= 'z' ) {
			wordVector = realloc( wordVector, sizeof( char ) * ( letterCount + 1 ) );
			wordVector[letterCount - 1] = tolower( licensePlate[i] );
			wordVector[letterCount] = '\0';
			letterCount++;
		}
	}

	int vectorLength = strlen( wordVector );
	int shortestIndex = 0;
	letterCount = 0;
	bool allMarked = true;
	int shortestLength = 100;

	for ( int i = 0; i < wordsSize; i++ ) {

		allMarked = true;
		char* tempVector = malloc( ( vectorLength + 1 ) * sizeof( char ) );
		strcpy( tempVector, wordVector );

		while ( words[i][letterCount] != '\0' ) {
			for ( int k = 0; k < vectorLength; k++ ) {
				if ( tempVector[k] == words[i][letterCount] ) {
					tempVector[k] = '#';
					break;
				}
			}
			letterCount++;
		}
		letterCount = 0;

		for ( int k = 0; k < vectorLength; k++ ) {
			if ( tempVector[k] != '#' ) {
				allMarked = false;
			}
		}

		if ( allMarked && strlen( words[i] ) < shortestLength ) {
			shortestLength = strlen( words[i] );
			shortestIndex = i;
		}

		free( tempVector );
	}

	free( wordVector );
	
	return words[shortestIndex];
}

/*
============================
main
 Função principal de teste
============================
*/
int main( void ) {

	char* licensePlate = "1s3 PSt";
	char* words[] = { "step", "steps", "stripe", "stepple" };
	int wordsSize = sizeof( words ) / sizeof( words[0] );

	char* result = ShortestCompletingWord( licensePlate, words, wordsSize );
	printf( " %s\n", result );

	return 0;
}
