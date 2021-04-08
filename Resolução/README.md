## Resolução Passo a Passo do Problema 2663 do Site URI

**Autor: Yuri Said Sunbali**

**Data: 8 de Abril de 2021**

### Visão Geral do Problema
Inicialmente, o problema solicita que seja escrito um
programa que receba na entrada principal quantos participantes
estiveram em uma determinada competição e a quantidade de
vagas disponíveis para a próxima etapa. Em seguida, o programa
deverá receber, linha a linha, a nota de cada um dos
participantes presentes e, a partir deste conjunto de
informações, deve-se indicar quantos participantes foram 
aprovados para a fase seguinte.

### Etapa 0: Identificação do Padrão
Inicialmente, é de vital importância identificar qual os
requisitos para que um competidor esteja apto para ser
aprovado para a próxima etapa. Afinal, a finalidade do
código é contabilizar quantos participantes foram aprovados
e entregar esse resultado, a fim de que o problema seja
resolvido. Intuitivamente, pensa-se que basta aprovar aqueles
com maiores notas até que não restem mais vagas para a
próxima etapa. De fato, **mas e a nota daqueles que empataram**
**com o último lugar dentre os aprovados?**
Atentando-se ao enunciado da questão, é possível notar que,
nos casos em que há empate, **aprova-se mais do que a**
**quantidade de vagas disponíveis**. Ou seja, **aqueles**
**que empatarem com o último colocado, dentre os aprovados,**
**também será aprovado para a próxima fase.** Portanto
não há critério de desempate, e, portanto, aprova-se
uma quantidade de candidatos maior ou igual ao número
de vagas disponíveis para a fase seguinte.

### Etapa 1: Inicializar os Valores Base da Solução
Assim, conhecendo-se qual o padrão do problema, resta
solucioná-lo. Inicia-se com a inicialização das variáveis
que irão armazenar a quantidade de participantes, e a
quantidade de vagas para a segunda fase, ou seja,
`int numeroParticipantes, vagasProxFase;`,
respectivamente. Dessa forma, é possível prosseguir com a
resolução, uma vez que os valores dessas variáveis irão guiar
o restante do código, dado que a quantidade de notas a serem
lidas se baseiam no número de participantes, e a quantidade
de aprovados tem como base a quantidade de vagas para a próxima fase.

### Etapa 2: Inicializar as Notas dos Participantes e Ordená-las
Conhecendo-se a quantidade de participantes, o próximo passo é tomar
conhecimento de quais são as notas desses participantes.
Para isso, será necessário armazenar esses valores para posterior análise,
afinal, adiante, será preciso ordenar as notas e verificar quais
são as maiores notas e comparar quantas notas empatam com a última
posição dos classificados. Portanto, cria-se o
array `int notas[numeroParticipantes]`. Observe que este é um
array de número inteiros com a mesma quantidade de posições que
o número de participantes, isso, pois, cada participante terá uma
nota correspondente ao seu desempenho. Após isso, ordena-se o array
das notas (na presente solução, optou-se por ordenar em
ordem decrescente). Dessa forma, será possível prosseguir para
as etapas finais, na qual, apenas resta contabilizar os
aprovados e imprimir este valor.

### Etapa 3: Contabilização dos Aprovados
Por fim, conhecendo-se quantas vagas existem para a fase seguinte
e as notas dos candidatos, contabiliza-se quantos deles serão
aprovados. Portanto, mais uma variável entrará em cena e ela irá
coordenar quando o programa deve parar de incrementar o número de
candidatos aprovados, ou seja, `int notaDeCorte = 0;`.
Assim, a partir do array ordenado em ordem decrescente,
adota-se a seguinte estratégia:
cria-se um laço de repetição que irá percorrer os valores no array
de notas, até que não existam mais vagas disponíveis para a etapa
seguinte **E** que não existam mais candidatos que empatam com o último
dos aprovados. Ou seja
```
for (i = 0; i < numeroParticipantes; ++i) {
		if (numeroAprovados < vagasProxFase) {
			++numeroAprovados;
			notaDeCorte = notas[i];
		} else if (notas[i] == notaDeCorte)
			++numeroAprovados;
		else
			i = numeroParticipantes;
	}
```
para cada elemento no array de notas, que tem tamanho igual
ao número de participantes, o programa verifica se o número
de aprovados (que, inicialmente, é zero) é inferior ao número
de vagas disponíves, em caso positivo, ele incrementa em 1
o número de aprovados e atualiza a nota de corte com a nota
que está sendo analisada afinal, ela será menor ou igual a
nota analisada na iteração anterior. Em caso negativo, ou seja,
alcançou-se o limite de vagas, o programa continuará contabilizando
aprovados em caso das notas dos candidatos seguintes no array
ser igual ao valor da nota de corte, ou seja da nota do último
colocado dentre os aprovados.
Devido ao fato de o array estar ordenado em ordem decrescente,
um elemento `notas[i]` será sempre
**maior ou igual** a `notas[i + 1]`, i >= 0.
Assim, na situação em o programa localiza uma nota
menor que a nota de corte, ele imediatamente atualiza o valor
da variável responsável pelo laço de repetição, de forma a
encerrar a execução da análise, uma vez que todas as outras
notas serão menores que a nota de corte.

### Etapa Final: Entrega do Resultado
Uma vez que conhece-se a quantidade de aprovados,
com base nos dados informados na entrada principal,
basta informar qual a quantidade de aprovados:

```
printf("%d\n", numeroAprovados);
```

Assim, completa-se os requisitos solicitados pelo
problema e finaliza-se a escrita do programa,
restando apenas compilá-lo e executá-lo (uma vez que
a linguagem utilizada, para solucionar a questão,
foi a linguagem C).

**Fim da explicação da resolução.**
