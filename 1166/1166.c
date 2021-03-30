#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ehQuadradoPerfeito(int n) {
    int r = (int)sqrt(n);
    return r*r == n;
}

int calculaMaximo(int N) {
    int * varetas = (int *)calloc(N, sizeof(int));
    int max = 1;
    int idx = 0;

    while (idx < N) {
        int estaVazia = varetas[idx] == 0;
        int ehPerfeito = ehQuadradoPerfeito(max + varetas[idx]);
            
        if (estaVazia || ehPerfeito) {
            varetas[idx] = max;
            max++;
            idx = 0;
        } else {
            idx++;
        }
    }

    return max - 1;
}

int main() {
    int T;
    int N;
    int i;
    int maximo;

    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        scanf("%d", &N);

        maximo = calculaMaximo(N);

        printf("%d\n", maximo);
    }

    return 0;
}