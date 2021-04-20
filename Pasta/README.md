# Entendendo o [Problema](https://www.urionlinejudge.com.br/judge/pt/problems/view/2534)
### Resumo extremamente básico
O problema consiste simplesmente em um problema de ordenação.
### Sobre a História
A história do problema é sobre cidadãos da Nlogonia que fizeram a prova nacional de matemática, e devem ser  ranqueadas de acordo com sua nota (da nota mais alta até a nota mais baixa), quanto melhor a sua posição no ranking, mais descontos eles ganharão nos impostos.
O papel do programador nesse problema é substituir a função que normalmente seria atribuída  a uma pessoa que foi hospitalizada.

# Sobre a Resolução

### Entradas
Cada caso teste para o programa é um conjunto de “entradas”, cada entrada tem o número de notas, o número de consultas, a seguir, tem as notas e as consultas a serem feitas, o programa deverá parar de ler as entradas quando chegar no fim do arquivo (EOF).

### Saídas
O programa deverá mostrar a nota da pessoa que ficou na posição consultada, ou seja, caso a consulta for “1”, o programa deverá mostrar a nota que ficou em primeiro lugar na classificação.

### Ordenação
O algoritmo de ordenação utilizado é o [merge sort](https://en.wikipedia.org/wiki/Merge_sort), consiste em uma ordenação recursiva baseada no conceito de divisão e conquista. 
Basicamente com a ideia de que tendo duas listas já ordenadas, é fácil as intercalar e fazer uma lista maior ordenada. 
Com isso, o algoritmo divide um “vetor” maior em vetores menores, e vai dividindo os vetores menores até chegar num caso base (o vetor ter um ou zero elementos, ou seja, um vetor ordenado), e assim, os vetores menores já compostos são ordenados intercalando seus sub-vetores, assim, após certo tempo, o vetor maior estará ordenado.


