//Exercício URI 2168
//Pedro Morini da Mota

#include <stdio.h>

int main()
{
    int N, valEsquina, valida = 0, numCamera = 0;
    int i, j;
    
    while(valida == 0){
        
        scanf("%d", &N);
        if(N >= 1 && N <= 100){ valida = 1; }
        
    }
    
    int esquinas[N+1][N+1];
    
    for(i = 0; i <= N; i++){
        
        for(j = 0; j <= N; j++){
            
            scanf("%d", &valEsquina);
            esquinas[i][j] = valEsquina;
            
        }
        
    }
    
    for(i = 0; i <= N; i++){
        
        for(j = 0; j <= N; j++){
            
            if(i < N && j < N){
                
                if(esquinas[i][j] == 1){ numCamera++; }
                if(esquinas[i][j + 1] == 1){ numCamera++; }
                if(esquinas[i + 1][j] == 1){ numCamera++; }
                if(esquinas[i + 1][j + 1] == 1){ numCamera++; }

                if(numCamera >= 2){
                    
                    if(j == N - 1){
                        printf("S\n");
                    }else{
                        printf("S");
                    }
                    
                }else{
                    
                    if(j == N - 1){
                        printf("U\n");
                    }else{
                        printf("U");
                    }
                    
                }
            
                numCamera = 0;
            }
        }
    }

    return 0;
}