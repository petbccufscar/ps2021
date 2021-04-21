#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
  
  int linhas, colunas,dist,aux,linCord[2],colCord[2];
  int i,j; //Variáveis Auxiliares 
  while (scanf("%d %d", &linhas,&colunas) != EOF){
  		aux=0;
  		int **m = (int**)malloc(linhas * sizeof(int*)); //Aloca um Vetor de Ponteiros
  		for (i = 0; i < linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
        	m[i] = (int*) malloc(colunas * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
      		for (j = 0; j < colunas; j++){ //Percorre o Vetor de Inteiros atual.
            	scanf("%d", &m[i][j]);
            		if(m[i][j]!=0){
		       		linCord[aux]=i;
		       		colCord[aux]=j;
		       		aux++;
					}
       		}
		}
		dist=abs(linCord[0]-linCord[1]) + abs(colCord[0]-colCord[1]);
		printf("%d\n", dist);
	}
	return 0;
}
