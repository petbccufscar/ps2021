#include <stdio.h>

int main () {
 
 int n, k, n_vetor[1000], i;

 scanf("%d", &n);
 scanf("%d", &k);
 

 for (i=0; i<n; i++) {

     scanf("%d", &n_vetor[i]);

 }
 
int armazena, j;
 
for(j=0; j<n; j++) {
    for (i = j+1; i<n; i++) {

        if (n_vetor[j] <  n_vetor[i]) {
            
            armazena = n_vetor[j];
            n_vetor[j] = n_vetor[i];
            n_vetor[i] = armazena;
        }
     
    }
}

int classificados = k;
i=1;

while(n_vetor[k-1] == n_vetor[k-1+i]) {
	
	classificados++;
	i++;
}

printf("%d\n", classificados);

return 0;

}
