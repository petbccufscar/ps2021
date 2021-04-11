#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  int C, N, i, j, k;
  while(scanf("%d %d\n", &C, &N) != EOF) {
    if(C < 1 || N < 1) return 0;
    char cifra1[22]; 
    char cifra2[22];
    char cripto[1002];
    fgets(cifra1, 21, stdin);
    fgets(cifra2, 21, stdin);
    for(i = 0; i < N; i++){
      fgets(cripto, 1001, stdin);
      for (j = 0; j < C+1; j++){
        for(k = 0; k < 1001 && cripto[k] != '/n'; k++){
          char aux = cripto[k];
          if (islower(aux))
            aux = toupper(aux);
          if (cifra2[j] == aux){
            if(isalpha(cifra1[j]) && !isupper(cripto[k])) 
              cripto[k] = tolower(cifra1[j]);
            else 
              cripto[k] = cifra1[j];
          }
          else if (cifra1[j] == aux){
            if(isalpha(cifra2[j]) && !isupper(cripto[k]))
              cripto[k] = tolower(cifra2[j]);
            else
              cripto[k] = cifra2[j];  
          }
        }
      }
      printf("%s", cripto);
    }
    printf("\n");
  }
  return 0;
}