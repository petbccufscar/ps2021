/*
	Código criado por Vanderlei Junior para PS2021-PETBCC

	Utilizando o conceito de Programação Dinâmica em C

	Inicialmente, salvavos todos os dados recebidos em um vetor alocado estaticamente,
	após isso, percorremos o vetor em loop, separando em uma tabela de 2 linhas, onde
	cada linha representa uma possível jogada no turno. Assim salvando os valores para
	os próximos turnos, evitando mais cálculos e otimizando o código.

	Abril, 2021
*/
#include <stdio.h>

/*
	Funções de comparação em C, já que não existe na biblioteca padrão:
	Recebe dois valores do tipo "long long int" e faz uma comparação entre eles,
	utilizando o operador ternário, onde caso a comparação seja verdadeira, retorna
	o valor da variável 'x' como resultado. Caso seja falso, retorna o valor da
	variável 'y' como resuldado. A mesma premissa para as duas funções.
*/
long long int minimo(long long int x, long long int y){
	long long int resultado = x < y ? x : y;
	return resultado;
};

long long int maximo(long long int x, long long int y){
	long long int resultado = x > y ? x : y;
	return resultado;
};


int main(){
	/*
		Declaração das variáveis. "qtd" para quantidade de cartões. "loop" é uma variável
		para todos os for, substitui o 'i' que acaba se perdendo visualmente. Um "vetor" de
		10000 posições, para acomodar todos os possíveis valores. Uma "tebela" para guardar
		os cálculos prévios e aplicar o conceito de Programação Dinâmica
	*/
	int qtd, loop;
	int vetor[10001];
	long long int tabela[10001][2] = {0};

	/*
		O programa se mantem em funcionamento até que seja reconhecido EOF, ou seja, "End of
		File", sinalizando que os casos de testes acabaram.
	*/

	while(scanf("%d", &qtd) != EOF){
		/*
			Preenchimento do vetor com todos os valores de cartões recebidos
		*/
		for(loop = 0; loop < qtd; loop++){
			scanf("%d", &vetor[loop]);
		}
		/*
			Preenchimento da primeira linha da tabela, com os valores máximos
			de comparação entre o número atual do loop e o próximo.
		*/
		for(loop = 0; loop < (qtd - 1); loop++){
			tabela[loop][0] = maximo(vetor[loop], vetor[loop + 1]);
		}

		/*
			Como a tabela tem exatamente 2 linhas, os turnos indicam qual linha
			pertence ao turno anterior, assim, os novos cálculos podem usar de base
			os valores obtidos no cálculo anterior
		*/
		int turno = 0;
		int turnoPassado = 1;

		/*
			Aqui está o coração do código, com o preenchimento da tabela. A cada vez
			que uma linha é preenchida, ela elimina a pior das sequências até o presente
			momento, pois, Programação Dinâmica se baseia em encontrar a solução ótima.
			Tendo isso em mente, uma subsolução também deve ser ótima. Por isso, a cada
			turno, a pior solução encontrada é descartada.
		*/
		for(int intervalo = 4; intervalo <= qtd; intervalo += 2){
			turnoPassado = turno;
			turno = !turno;

			/*
				Resumidamente. A cada turno, é feita uma comparação entre o primeiro valor do vetor ainda pertencente somado
				com o menor valor entre as duas próximas posições do vetor do turno anterior e o último valor do vetor atual
				somado com o menor valor entre a posição atual e a próxima posição do vetor do turno anterior. Garantindo assim,
				uma soma máxima, independente da carta retirada pelo segundo jogador (que por acaso, se chama Wanderley).
			*/
			for (int i = intervalo - 1, loop = 0; i < qtd; loop++, i++){
				tabela[loop][turno] = maximo(vetor[loop] + minimo(tabela[loop + 1][turnoPassado], tabela[loop + 2][turnoPassado]), 
										 	 vetor[i] + minimo(tabela[loop][turnoPassado], tabela[loop + 1][turnoPassado]));
			}
		}

		/*
			Print com o resultado do valor máximo de pontos obtidos por Alberto
		*/
		printf("%lld\n", tabela[0][turno]);
	}

	return 0;
}