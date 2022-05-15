#include<stdio.h>
#include<conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h>

int validador(char var[100]){

  for(int i = 0; i < strlen(var); i++){
  	
  }
  
   
}

int main(int argc,char *argv[]){
  setlocale(LC_ALL, "Portuguese");
  FILE *arqIn;
  FILE *arqOut;
  char linha[100];
  char *result;
  
  arqOut = fopen("saida.txt", "w");
  arqIn  = fopen("entrada.txt", "r");
  
  if (arqIn == NULL)  
  {
     printf("Problemas ao abrir o arquivo de leitura\n");
     exit(0);
  }
  
  if (arqOut == NULL)  
  {
     printf("Problemas ao abrir o arquivo de gravacao\n");
     exit(0);
  }

  while (!feof(arqIn))
  {
      result = fgets(linha, 100, arqIn);  
      if (result)
	  {
	  	
	  	if(int(linha[strlen(linha)-1]) == 10 ){
	  		linha[strlen(linha)-1]='\0';
		}
      	
    	if(validador(linha) == 1){
    		fprintf(arqOut, "%s S\n", linha);
  				printf("\nId valido");
		}else
		{
    		fprintf(arqOut, "%s N\n", linha);
    		printf("\n Id - %s - invalido", linha);
  			printf("\nId invalido");
		}
	  }
  }
  
  printf("\nVerificar arquivo de saida");
  fclose(arqIn);
  fclose(arqOut);
    
  return 0;
}