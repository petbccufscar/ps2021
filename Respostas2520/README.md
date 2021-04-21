# Explicação Exercício 2520
## Matheus Paladini 769111

##  Enunciado do Exercício 
Analógimôn Go! é um jogo bastante popular. Em sua jornada, o jogador percorre diversas cidades capturando pequenos monstrinhos virtuais, chamados analógimôns. Você acabou de chegar em uma cidade que contém o último analógimôn que falta para sua coleção!

A cidade pode ser descrita como um grid de N linhas e M colunas. Você está em uma dada posição da cidade, enquanto o último analógimôn está em outra posição da mesma cidade. A cada segundo, você pode se mover (exatamente) uma posição ao norte, ao sul, a leste ou a oeste. Considerando que o analógimôn não se move, sua tarefa é determinar o menor tempo necessário para ir até a posição do monstrinho.

A figura abaixo descreve o exemplo da entrada, e apresenta um caminho percorrido em 5 segundos. Outros caminhos percorridos no mesmo tempo são possíveis, mas não há outro caminho que pode ser percorrido em um tempo menor.

![Bilby Stampede](https://www.urionlinejudge.com.br/gallery/images/problems/UOJ_2520.png)

## Considerações Iniciais
Antes de se iniciar a explicação sobre o programa, é necessário evidenciar a estratégia usada para a resolução
do problema. Ao se falar sobre a menor distância entre 2 quadrantes de uma matriz, sempre será necessário o 
mesmo número de deslocamentos verticais e horizontais, por exemplo: vamos supor que o destino esteja a 2 casas 
a direita e 3 acima do nosso local de início, para chegar ao destino não importa a ordem das ações, você pode 
inicialmete realizar ações para a direita ou para cima, ou até mesclalas (variar entre ações para a direita e 
para cima), contanto que não sejam realizadas ações contra o destino (nesse caso para baixo ou para a esquerda),
o número de movimentos para o destino é sempre o mesmo. É possível checar isso na imagem acima, deslocando o 
personagem inicialmente 3 vezes para cima e 2 vezes para a esquerda atingindo o destino na mesma quantidade 
de movimentos, porém em uma rota diferente.   

## Identificação de Problemas

Ao se ler o enunciado é possível identificar os principais pontos que necessitariam de uma explicação em especial.
- Criação de uma matriz com valores mutaveis de linha e coluna.
- A identificaação da coordenadas de início e destino (dado que não existe campo específico para isso na
entrada do programa).
- A operação matemática correta entre as coordenadas para que o cálculo do tempo seja correto.


## Código 
Iremos separá-lo em seções para termos uma explicação mais dealhada.


```sh
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
  
  int linhas, colunas, LinhaOrigem,ColunaOrigem,LinhaDestino,ColunaDestino,dist;
  scanf("%d %d", &linhas,&colunas);		
  int i,j; 
  int **m = (int**)malloc(linhas * sizeof(int*)); 
 
  for (i = 0; i < linhas; i++){ 
       m[i] = (int*) malloc(colunas * sizeof(int)); 
       for (j = 0; j < colunas; j++){ 
            scanf("%d", &m[i][j]);
       }
	}
	for (i = 0; i < linhas; i++){
       for (j = 0; j < colunas; j++){ 
	       	if(m[i][j]==1){
	       		LinhaOrigem=i;
	       		ColunaOrigem=j;
			}
			else if(m[i][j]==2){
				LinhaDestino=i;
				ColunaDestino=j;
			}
			
       }   
	}
	dist=abs(LinhaDestino-LinhaOrigem) + abs(ColunaDestino-ColunaOrigem);
	printf("O tempo para tingir será: %d segundos", dist);
	return 0;
}
```

## Variáveis 
Foram declaradas todas as variáveis necessárias para o programa, sendo elas para determinar a quantidade de linhas e  colunas(linhas, colunas), as coordenadas de início e de destino (LinhaOrigem,ColunaOrigem,LinhaDestino,ColunaDestino), a distância (dist)  e as variáveis para os loops utilizados (i,j).
```sh
  int linhas, colunas, LinhaOrigem,ColunaOrigem,LinhaDestino,ColunaDestino,dist;
  scanf("%d %d", &linhas,&colunas);	//Leitura do tamanho da matriz
  int i,j; //Variáveis Auxiliares 
```

## Alocação dinámica de matriz
De maniera similar a uma alocação dinâmica normal, a primeira linha aloca um número X de variáveis (no caso o número de linhas), mas ao invés de se alocar uma variável convencional, são alocados ponteiros, desse modo criando um vetor de ponteiros.
Após isso, na linha 3, é aberto um For que vai percorer o vetor de ponteiros recém criado na linha 1, e para cada ponteiro será alocado um numero de varivéis (nesse caso o número de colunas). Em síntese a primeira linha cria um vetor, em seguida, o loop cria um vetor para cada elemento do vetor inicial, logo, se froma uma matriz.
Após isso, o valor é atribuido para cada elemnto da matriz utilizando um scanf comum. 
```sh
  int **m = (int**)malloc(linhas * sizeof(int*)); //Aloca um Vetor de Ponteiros
 
  for (i = 0; i < linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
       m[i] = (int*) malloc(colunas * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de 
       Ponteiros.
       for (j = 0; j < colunas; j++){ //Percorre o Vetor de Inteiros atual.
            scanf("%d", &m[i][j]);
       }
    }
```
## Identificação do Início e do destino
Como nossa entrada do exercício apenas nos permite inserir as dimensões da matriz e seus elementos em ordem de aparição (não necessáriamente destacando as coordenadas do início e do destino) é preciso formular um mecanismo para a identificação. 
Nesse caso, a abordagem foi criar um loop que percorre totalmete a matriz procurando pelos valores 1 e 2 (início e destino respectivamente). Ao encontrá-los, as coordenadas que estão nos 2 loops serão armazenados em variáveis auxiliares especícas para cada um dos elementos.
```sh

for (i = 0; i < linhas; i++){ //Loop que percorre os valores de linha da matriz
       for (j = 0; j < colunas; j++){ //Loop que percorre os valores de coluna da matriz
            if(m[i][j]==1){ //Identificador da coordenada de origem
                LinhaOrigem=i; //Atribui o valor das coordenadas nas variáveis específicas
                ColunaOrigem=j;
            }
            else if(m[i][j]==2){ //Identificador da coordenada de destino
                LinhaDestino=i;
                ColunaDestino=j;
            }
            
       }   
    }
```
## Definição da distância
Como dito no início da explicação, ao se buscar o menor caminho, se os movimentos forem sempre em favor do destino, todas as rotas vão realizar a mesma quantidade de movimetos. A quantidade de movimentos pode ser descobeta pela soma dos modulos das subtrações das coordenadas da origem e do destino 
Distância=|(LinhaDestino-LinhaOrigem)| + |(ColunaDestino-ColunaOrigem)|
É importante lembrar que a operação de módulo em C se da a partir da função abs().
Mas atenção, o módulo deve ser aplicado individualmente entre as subtrações e não em toda operação, pois em uma situação onde a origem possua um valor mais alto de linha e um valor mais baixo de coluna em relação ao destino pode gerar um erro na conta. Por exemplo: em um caso onde a origem estaria na coordenada (1,4) e o destino estaria na coordenada (3,2), ao não se aplicado o módulo individualmente a conta seria |(3-1)+(2-4)| o resultado é 0, o que está errado. Aplicando a fórmula correta |(3-1)|+|(2-4)|, chegamos ao valor 4, o resultado correto.
Como o personagem pode se movimentar 1 unidade de distância a cada segundo, o valor da distãncia passa a ser o mesmo tempo em segundos, nos permitindo dar a resposta a partir daí.

```sh
dist=abs(LinhaDestino-LinhaOrigem) + abs(ColunaDestino-ColunaOrigem); //Fórmula da menor disância entre elemnetos
de uma matriz
    printf("O tempo para tingir será: %d segundos", dist);
```


