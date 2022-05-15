#define VALID_CHARACTERS {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'E', '.', '+', '-'}

int main(int argc, char* argv[]) {
	// deve começar com numero
	// deve ter no maximo um .
	// deve ter no maximo uma letra E
	// depois do E deve ter [+, -, numero]
	// antes do E deve ser um numero

	setlocale(LC_ALL, "Portuguese");
	FILE *inputFile;
	FILE *outputFile;

	char line[100];
	char *buffer;
	
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

		fprintf(outputFile, "%s N\n", line);
		
		// if (buffer) {
		// 	if (int(line[strlen(line)-1]) == 10 ) {
		// 		linha[strlen(linha)-1]='\0';
		// 	}
			
		// 	if (validador(linha) == 1) {
		// 		fprintf(arqOut, "%s S\n", linha);
		// 			printf("\nId valido");
		// 	} else
		// 	{
		// 		fprintf(arqOut, "%s N\n", linha);
		// 		printf("\n Id - %s - invalido", linha);
		// 		printf("\nId invalido");
		// 	}
		// }
	}
	
	printf("\nVerificar arquivo de saida");
	fclose(inputFile);
	fclose(outputFile);
		
	return 0;

//   while (!feof(arq))
//   {
// 	// Lê uma linha (inclusive com o '\n')
//       result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
//       if (result)  // Se foi possível ler
// 	  printf("Linha %d : %s",i,Linha);
//       i++;
//   }
//   fclose(arq);


    // char palavra[];

    // char[] alfabeto = { 'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
	// 			'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '*', '#', '$', '@', '!', '%', '_', ';', '(', ')', '<', '>', ':', ',',
	// 			'}', '{' };

    // char[] alfabeto_valido = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'E', '.', '+', '-' };

    // int posicaoSinais = 0;
	// int posicaoLetraE = 0;
	// int posicaoPonto = 0;

    // bool valido = true;
    // bool acerto = false;

    // while (!acerto) {
    //     printf("Digite a palavra: ");
    //     palavra = scanner.nextLine();
    //     acerto = automato(palavra, alfabeto, alfabeto_valido, posicaoSinais, posicaoLetraE, posicaoPonto, valido);

    // }
}





// public class FINAL {

//     p

// 	public static void main(String[] args) {
// 		//String palavra;

// 		char[] alfabeto = { 'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
// 				'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '*', '#', '$', '@', '!', '%', '_', ';', '(', ')', '<', '>', ':', ',',
// 				'}', '{' };

// 		char[] alfabeto_valido = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'E', '.', '+', '-' };

// 		int posicaoSinais = 0;
// 		int posicaoLetraE = 0;
// 		int posicaoPonto = 0;

// 		boolean valido = true;

// 		@SuppressWarnings("resource")
// 		Scanner scanner = new Scanner(System.in);
// 		boolean acerto = false;
		
// 		while (!acerto) {
// 			System.out.print("Digite a palavra: ");
// 			palavra = scanner.nextLine();
// 			acerto = automato(palavra, alfabeto, alfabeto_valido, posicaoSinais, posicaoLetraE, posicaoPonto, valido);

// 		}

// 	}

// 	public static boolean automato(String palavra, char[] alfabeto, char[] alfabeto_valido, int posicaoSinais,
// 			int posicaoLetraE, int posicaoPonto, boolean valido) {
		
// 		for (int i = 0; i < palavra.length(); i++) {
// 			for (int j = 0; j < alfabeto_valido.length; j++) {
// 				if (!(palavra.charAt(i) == alfabeto_valido[i]) && palavra.charAt(i) == ' ') { // Verifica se h� espa�os na palavra
// 					valido = false;
// 					break;
// 				}
// 			}
// 		}

// 		try {
// 			if (Character.isDigit(palavra.charAt(0))) { // Verifica se s�o n�meros na primeira posicao da palavra
				
// 				for (int i = 0; i < palavra.length(); i++) {// Repeticao para percorrer a palavra
// 					for (int y = 0; y < alfabeto.length; y++) {// repeticao para calcular cada letra da palavra com o
// 																// alfabeto
// 						if (palavra.charAt(i) == alfabeto[y] && Character.isLowerCase(palavra.charAt(i))) {// verifica se h� letras min�sculas
// 							System.out.println("A palavra possui letras min�sculas");
// 							valido = false;
// 							break;
// 						} else {
// 							if (palavra.charAt(i) == '.') {
// 								posicaoPonto = i;
								
// 								if (!Character.isDigit(palavra.charAt(i + 1)) || palavra.charAt(i + 1) == 'E') {// verifica se o caractere na posicao � uma letra e se o proximo caractere � a letra E
// 									valido = false;
// 									break;
// 								}

// 							}

// 							if (palavra.charAt(i) == 'E') {// verifica se o caractere � a letra E
// 								posicaoLetraE = i;

// 								if ((palavra.charAt(i + 1) == '+' && Character.isDigit(palavra.charAt(i + 2))
// 										|| ((palavra.charAt(i + 1) == '-' && Character.isDigit(palavra.charAt(i + 2)))
// 												|| Character.isDigit(palavra.charAt(i + 1))))) {
// 									posicaoSinais = i;
// 									valido = true;
// 								} else {
// 									valido = false;
// 									break;
// 								}

// 							}
							
// 							if (palavra.charAt(i) == '+' && palavra.charAt(i - 1) != 'E'  //valida se o caractere � '+' e o caractere anterior n�o � 'E' 
// 									|| palavra.charAt(i) == '-' && palavra.charAt(i - 1) != 'E') {//valida se o caractere � '-' e o caractere anterior n�o � 'E' 
// 								valido = false;
// 								break;
// 							}

// 						}
// 					}

// 				}
// 			} else {
// 				valido = false;
// 			}
// 		} catch (Exception e) {
// 			valido = false;
// 		}

// 		for (int i = posicaoPonto - 1; i >= 0; i--) { // verifica se possui mais de um '.' na palavra
// 			if (palavra.charAt(i) == '.') {
// 				valido = false;
// 				break;
// 			}
// 		}
// 		for (int i = posicaoLetraE - 1; i >= 0; i--) { // verifica se possui dois caracteres 'E'
// 			if (palavra.charAt(i) == 'E') {
// 				valido = false;
// 				break;
// 			}
// 		}
// 		for (int i = posicaoSinais - 1; i >= 0; i--) {
// 			if (palavra.charAt(i) == '+' || palavra.charAt(i) == '-') { //verifica se na palavra contem sinal '+' e '-' repetido
// 				valido = false;
// 				break;
// 			}
// 		}
// 		if (valido) {
// 			System.out.println("Palavra V�lida");
// 			return true;
// 		} else {
// 			System.out.println("Palavra Inv�lida");
// 			return false;
// 		}

// 	}
// }