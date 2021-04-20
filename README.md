## EXERCÍCIO URI 3168

### PROBLEMA:
Serão instaladas câmeras nas esquinas das ruas do centro de _Portland_, devido a invasão de vampiros e lobisomens. Teremos que a partir do mapa disponibilizado pela prefeitura,
onde nos dirá em quais esquinas foram instalada as câmeras definir se a quadra está segura(S) ou se não está segura(U), levando em consideração que uma quadra só estará segura
quando houver 2 ou mais câmeras nela instaladas.

### -CÓDIGO

####    -ENTRADAS:
São declaradas 3 variáveis, n, irá definir quantas quadras temos, se n = 1, teremos 1 quadra, se n = 2, teremos 4 quadras, se n = 3, serão 9 quadras, ou seja, o número de quadras, é definido por n². As variáveis i e j, auxiliaram na montagem do mapa. Posteriormente lê-se o valor de n.
```
int n, i, j; 
```
#### Parte 1:

```
scanf("%d", &n);
    int rua[n+1][n+1];
    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            scanf("%d", &rua[i][j]);
```
