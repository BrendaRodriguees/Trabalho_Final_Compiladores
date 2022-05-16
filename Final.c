#include <stdio.h>
#include <curses.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

#define VALID_CHARACTERS (const char[]) {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'E', '.', '+', '-'}

char * validateAutomaton(char line[100]);
bool isValidCharacter(char character);
	
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	FILE *inputFile;
	FILE *outputFile;

	char *buffer;
	char line[100];
	
	inputFile  = fopen("input.txt", "r");
	outputFile = fopen("output.txt", "w");
	
	if (inputFile == NULL) {
		printf("Erro ao abrir o aqruivo de leitura.\n");
		exit(0);
	}
	
	if (outputFile == NULL) {
		printf("Erro ao abrir o aqruivo de escrita.\n");
		exit(0);
	}

	while (!feof(inputFile)) {
		buffer = fgets(line, 100, inputFile);
		
		fprintf(outputFile, "%s - %s\n", validateAutomaton(line), line);
	}

	printf("\nVerificar arquivo de saida");
	fclose(inputFile);
	fclose(outputFile);	
				
	return 0;
	 
}

char * validateAutomaton(char line[100]) {
	int i;
	int countDot = 0;
	int countLetterE = 0;
	int countMoreOrLess = 0;
	
	for (i = 0; i < strlen(line) - 1; i++) {
		// Verifica se todos os caracteres são válidos
		if (!isValidCharacter(line[i])) {
			return "Inválido";	
		} 
		
		// Verifica se tem no máximo um "."
		if (line[i] == '.') {
			countDot++;
			
			if (countDot > 1) {
				return "Inválido";
			}
			
			// Verifica se antes e depois do "." existem apenas números
			if ((isdigit(line[i - 1]) <= 0 && line[i - 1] != 'E') || isdigit(line[i + 1]) <= 0) {
				return "Inválido";
			}
		}
		
		// Verifica se tem no máximo um "E"
		if (line[i] == 'E') {
			countLetterE++;
			
			if (countLetterE > 1) {
				return "Inválido";
			}
			
			// Verifica se depois do "E" é numero ou "+" ou "-"
			if (!(line[i + 1] == '+' || line[i + 1] == '-' || isdigit(line[i + 1]))) {
				return "Inválido";
			}
			
			// Verifica se antes do "E" existem apenas números
			if (isdigit(line[i - 1]) <= 0) {
				return "Inválido";
			}
		}
		
		// Verifica se o "+" ou "-" está depois do "E" e se existe apenas uma incidencia na entrada
		if (line[i] == '+' || line[i] == '-') {
			countMoreOrLess++;
			
			if (line[i - 1] != 'E') {
				return "Inválido";
			}
			
			if (countMoreOrLess > 1) {
				return "Inválido";
			}
		}	
	}
	
	// Verifica se começa com um número
	if (isdigit(line[0]) <= 0) {
		return "Inválido";
	}
	
	return "Válido";
}

bool isValidCharacter(char character) {
	int i;
	
	for (i = 0; i < strlen(VALID_CHARACTERS); i++) {
		if (character == VALID_CHARACTERS[i]) {
			return true;
		}
	}
	
	return false;
}
