
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#ifndef MAX_BUF
#define MAX_BUF 200
#endif


int main(int argc, char* argv[])
{
	FILE *f;
	int n1=0;
	int n2=0;
	char filename[80];
	char buf [MAX_BUF];  
	char palavra;
    int posicaoSinais = 0;
	int posicaoLetraE = 0;
	int posicaoPonto = 0;
	bool valido = true;
	bool acerto = false;

	printf("Indique nome do ficheiro:");
	gets(filename);

	f=fopen(filename,"r");
	if (f==NULL) 
	{
		printf("Erro na abertura do ficheiro");
		return 1;
	}
	while (! feof(f)) 
	{
		
	}
	fclose(f);
	printf("\n\nO ficheiro tem %d linhas, das quais %d com \"printf\"\n",n1,n2);
	return 0;
}