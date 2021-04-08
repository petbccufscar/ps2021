/* Autor: Yuri Said Sunbali
 * Data: 8 de Abril de 2021
 *
 * Objetivos: Escrever um programa que seja capaz
 * de receber na entrada principal um número N,
 * referente a quantidade de participantes em uma
 * competição, um número K, referente ao número
 * de vagas para a próxima etapa da competição,
 * e N valores referentes as notas dos participantes,
 * assim, sendo possível classificá-los e determinar
 * quantos deles passarão para a próxima fase.
 * Considera-se que todos aqueles que empatarem com
 * o último colocado, dentre os aprovados, também será
 * aprovado, ou seja, o número de aprovados será maior
 * ou igual a K, a depender das notas informadas. */

/* Inclui o arquivo de cabeçalho
 * responsável por funções de I/O */
#include <stdio.h>


/* Escrita da função main */
int main() {
	/* Declaração de variáveis*/
	int i, j; /* Variáveis para controle de laço */
	int numeroParticipantes, vagasProxFase,
	    notaDeCorte; /* Variáveis base para a resolução do problema */

	int numeroAprovados = 0;

	/* Inicialização dos valores do número de participantes
	 * e da quantidade de vagas para a próxima fase */
	scanf("%d", &numeroParticipantes);
	scanf("%d", &vagasProxFase);

	/* Declaração e inicialização do array de notas
	 * dos candidatos */
	int notas[numeroParticipantes];
	for (i = 0; i < numeroParticipantes; ++i)
		scanf("%d", &notas[i]);

	/* Ordenação das notas em ordem decrescente */
	for (i = 0; i < numeroParticipantes; ++i) {
		for (j = 0; j < numeroParticipantes - 1; ++j) {
			if (notas[j] < notas[j + 1]) {
				int aux = notas[j];
				notas[j] = notas[j+1];
				notas[j + 1] = aux;
			}
		}
	}

	/* Contabilização do número de aprovados
	 * para a próxima fase */
	for (i = 0; i < numeroParticipantes; ++i) {
		if (numeroAprovados < vagasProxFase) {
			++numeroAprovados;
			notaDeCorte = notas[i];
		} else if (notas[i] == notaDeCorte)
			++numeroAprovados;
		else
			i = numeroParticipantes;
	}

	/* Impressão do resultado do número de aprovados */
	printf("%d\n", numeroAprovados);

	/* Fim do programa principal */
	return 0;
}
