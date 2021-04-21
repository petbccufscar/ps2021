#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
  
  int linhas, colunas, LinhaOrigem,ColunaOrigem,LinhaDestino,ColunaDestino,dist;
  scanf("%d %d", &linhas,&colunas);		
  int i,j; //Variáveis Auxiliares 
  int **m = (int**)malloc(linhas * sizeof(int*)); //Aloca um Vetor de Ponteiros
 
  for (i = 0; i < linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
       m[i] = (int*) malloc(colunas * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (j = 0; j < colunas; j++){ //Percorre o Vetor de Inteiros atual.
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
