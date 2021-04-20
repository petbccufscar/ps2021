## EXERCÍCIO URI 3168

### PROBLEMA:
Serão instaladas câmeras nas esquinas das ruas do centro de _Portland_, devido a invasão de vampiros e lobisomens. Teremos que a partir do mapa disponibilizado pela prefeitura,
onde nos dirá em quais esquinas foram instalada as câmeras definir se a quadra está segura(S) ou se não está segura(U), levando em consideração que uma quadra só estará segura
quando houver 2 ou mais câmeras nela instaladas.

### CÓDIGO

#### ENTRADAS:
São declaradas 3 variáveis, n, irá definir quantas quadras temos, se n = 1, teremos 1 quadra, se n = 2, teremos 4 quadras, se n = 3, serão 9 quadras, ou seja, o número de quadras, é definido por n². As variáveis i e j, auxiliaram na montagem do mapa.
```
int n, i, j; 
```

#### PARTE 1:
Primeiramente, lê-se o valor de n, posteriormente, declara-se o array `int rua[n+1][n+1]` ,em seguida dentro de um laço "for" é preenchido os valores dos endereços do array, o qual irá mapear onde estão instaladas as câmeras.
```
scanf("%d", &n);
    int rua[n+1][n+1];
    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            scanf("%d", &rua[i][j]);
```
#### PARTE 2:
Após mapeado a posição das câmeras, o código testará se a quadra está segura ou não, dentro de uma laço "for" e com o comando if é lido quatro posições do array(as quais indicam as quatro esquinas da quadra), se a condição `rua[i][j]+rua[i][j+1]+rua[i+1][j]+rua[i+1][j+1]` é menor que 2, ou seja, testa-se se há menos de 2 câmeras em cada quadra, então imprime-se na tela "U", o que indica que a quadra não está segura, se falso a condição, imprime-se "S", indicando que a quadra está segura.
```
for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(rua[i][j]+rua[i][j+1]+rua[i+1][j]+rua[i+1][j+1] < 2)
              printf("U");
            else printf("S");
```
Exemplo de quadra __segura__:
0 | 1
---|---
1 | 0

Exemplo de quadra __não segura__:
1 | 0    
---|---  
0 | 0
