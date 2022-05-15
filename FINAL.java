import java.util.Scanner;

public class FINAL {

	public static void main(String[] args) {
		String palavra;
		char[] alfabeto = { 'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
				'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '*', '#', '$', '@', '!', '%', '_', ';', '(', ')', '<', '>', ':', ',',
				'}', '{' };
		char[] alfabeto_valido = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'E', '.', '+', '-' };
		int posicaoSinais = 0;
		int posicaoLetraE = 0;
		int posicaoPonto = 0;
		boolean valido = true;
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		boolean acerto = false;
		
		while (!acerto) {
			System.out.print("Digite a palavra: ");
			palavra = scanner.nextLine();
			acerto = automato(palavra, alfabeto, alfabeto_valido, posicaoSinais, posicaoLetraE, posicaoPonto, valido);

		}

	}

	public static boolean automato(String palavra, char[] alfabeto, char[] alfabeto_valido, int posicaoSinais,
			int posicaoLetraE, int posicaoPonto, boolean valido) {
		for (int i = 0; i < palavra.length(); i++) {
			for (int j = 0; j < alfabeto_valido.length; j++) {
				if (!(palavra.charAt(i) == alfabeto_valido[i]) && palavra.charAt(i) == ' ') { // Verifica se há espaços na palavra
					valido = false;
					break;
				}
			}
		}
		try {
			if (Character.isDigit(palavra.charAt(0))) { // Verifica se são números na primeira posicao da palavra
				for (int i = 0; i < palavra.length(); i++) {// Repeticao para percorrer a palavra
					for (int y = 0; y < alfabeto.length; y++) {// repeticao para calcular cada letra da palavra com o
																// alfabeto
						if (palavra.charAt(i) == alfabeto[y] && Character.isLowerCase(palavra.charAt(i))) {// verifica se há letras minúsculas
							System.out.println("A palavra possui letras minúsculas");
							valido = false;
							break;
						} else {
							if (palavra.charAt(i) == '.') {
								posicaoPonto = i;
								if (!Character.isDigit(palavra.charAt(i + 1)) || palavra.charAt(i + 1) == 'E') {// verifica se o caractere na posicao é uma letra e se o proximo caractere é a letra E
									valido = false;
									break;
								}

							}
							if (palavra.charAt(i) == 'E') {// verifica se o caractere é a letra E
								posicaoLetraE = i;
								if ((palavra.charAt(i + 1) == '+' && Character.isDigit(palavra.charAt(i + 2))
										|| ((palavra.charAt(i + 1) == '-' && Character.isDigit(palavra.charAt(i + 2)))
												|| Character.isDigit(palavra.charAt(i + 1))))) {
									posicaoSinais = i;
									valido = true;
								} else {
									valido = false;
									break;
								}

							}
							if (palavra.charAt(i) == '+' && palavra.charAt(i - 1) != 'E'  //valida se o caractere é '+' e o caractere anterior não é 'E' 
									|| palavra.charAt(i) == '-' && palavra.charAt(i - 1) != 'E') {//valida se o caractere é '-' e o caractere anterior não é 'E' 
								valido = false;
								break;
							}

						}
					}

				}
			} else {
				valido = false;
			}
		} catch (Exception e) {
			valido = false;
		}
		for (int i = posicaoPonto - 1; i >= 0; i--) { // verifica se possui mais de um '.' na palavra
			if (palavra.charAt(i) == '.') {
				valido = false;
				break;
			}
		}
		for (int i = posicaoLetraE - 1; i >= 0; i--) { // verifica se possui dois caracteres 'E'
			if (palavra.charAt(i) == 'E') {
				valido = false;
				break;
			}
		}
		for (int i = posicaoSinais - 1; i >= 0; i--) {
			if (palavra.charAt(i) == '+' || palavra.charAt(i) == '-') { //verifica se na palavra contem sinal '+' e '-' repetido
				valido = false;
				break;
			}
		}
		if (valido) {
			System.out.println("Palavra Válida");
			return true;
		} else {
			System.out.println("Palavra Inválida");
			return false;
		}

	}
}