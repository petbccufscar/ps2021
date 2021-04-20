#include <stdio.h>
#include <stdlib.h>

/**
 * função de intercalação
 * dado duas partes ordenadas subsequentes de um array
 * a função ordena o array maior formado pela junção das duas partes 
 * 
 * argumentos:
 *              v -> ponteiro para o array
 *              b -> posição inicial do primeiro sub-array
 *              n -> posição final do primeiro sub-array
 *              m -> posição final do segundo sub-array
 * funcionamento: usando um array auxiliar aux, a função verifica os maiores elementos 
 * dos dois sub-arrays e copia o maior deles pro auxiliar, até terminar de copiar um dos sub-arrays
 * após isso, ele termina de copiar o resto do sub-array faltante.
 * A seguir, ele copiar todos elementos do array auxiliar aux, para o array original v.
 *              
*/
void intercala(int* v, int b, int n, int m){

    //aloca espaço na memoria para um array auxiliar aux
    int *aux = (int*) malloc(sizeof(int)*(m+1-b));

    //idx é a posição atual do array auxiliar
    //i é a posição atual do primeiro sub-array
    //j é a posição atual do segundo sub-array
    int idx = 0, i = b, j = n + 1, k;

    //copia os maiores elementos dos sub-arrays para o array auxiliar
    //até que um dos sub-arrays seja copiado por completo
    while(j <= m && i <= n){
        if(v[i] > v[j]){
            aux[idx] = v[i];
            i++;
        } else{
            aux[idx] = v[j];
            j++;
        }
        idx++;
    }

    //termina de copiar o segundo sub-array, caso tenha copiado o primeiro inteiro
    while (j <= m){
        aux[idx] = v[j];
        j++;
        idx++;
    }

    //termina de copiar o primeiro sub-array, caso tenha copiado o segundo inteiro
    while (i <= n){
        aux[idx] = v[i];
        i++;
        idx++;
    }

    //copia os elementos do array auxiliar para o array original
    for(k = b; k <= m; k++){
        v[k] = aux[k-b];
    }
    //libera a memoria alocada para o array auxiliar
    free (aux);
}

/**
 * função de ordenação: mergesort recursivo
 * argumentos:  
 *              v -> array
 *              b -> posição inicial do array
 *              n -> posição final do array
 * 
 * funcionamento: ele divide o array em arrays menores e
 * quando eles estiverem ordenados, executa a intercalação e 
 * ordena o array maior
*/
void sort(int* v,int b, int n){
    //caso base da recursão:
    //o array tem menos de duas posições é um array ordenado
    if(n-b < 1)
        return;
    
    //calcula a posição do meio do array
    int mid = (b + n)/2; 
    
    //metodo de divisão e conquista
    //divide o array em dois e os ordena
    sort(v, b, mid);
    sort(v, mid + 1, n);

    //ordena o array maior, dado dois arrays menores ordenados
    intercala(v, b, mid, n);
}

int main(){

    int q, n, question, i;
    //escaneia as variaveis n e q pedidas no problema
    while(scanf("%d %d", &n, &q) != EOF){
    
        //aloca espaço para um array para receber as notas
        int *v = (int*) malloc(sizeof(int)*n);
        
        //escaneia as notas colocando-as no array
        for(i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }

        //ordena o array na ordem decrescente
        sort(v, 0, n-1);

        //lê as consultas e já devolve o resultado da pessoa na posição qº
        for(i = 0; i < q; i++){
            scanf("%d", &question);
            printf("%d\n", v[question - 1]);
        }
        //libera a memoria alocada para as notas
        free(v);
    }
    
    //simboliza que tudo ocorreu bem durante o programa
    return 0;
}
