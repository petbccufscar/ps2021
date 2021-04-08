### Explicação do Exercício 2168
######Pedro Morini da Mota

Começo declarando as variáveis que vou usar.

    int N, esquina, valida = 0, numCamera = 0;
    int i, j;

+ **N**: é o inteiro positivo da primeira linha de entrada.
+ **valEsquina**: é o valor que vai será lido de cada esquina.
+ **valida**: variável para validar a saída de um loop.
+ **numCamera**: variável para contar o número de câmeras que há em cada quadra.
+ **i e j**: índices para a matriz que armazenará os valores de cada esquina.


    while(valida == 0){

        scanf("%d", &N);
        if(N >= 1 && N <= 100){ valida = 1; }

    };

<p>O comando `scanf()` lê o valor inteiro positivo da primeira entrada, o comando `while()` mantém a leitura em um loop até a variável **_valida_** ser alterada, essa alteração só ocorrerá se o valor lido estiver de acordo com a condição no comando `if()`.<br>
Após o valor validado, declaro uma matriz para guradar os valores de cada esquina, com os valores dos índices sendo **_N + 1_** como estabelecido pelo exercício.<br>
Uso então o comando `for` para atribuir a cada espaço da matriz o valor de uma das esquinas.</p>

    int esquinas[N+1][N+1];

    for(i = 0; i <= N; i++){

        for(j = 0; j <= N; j++){

            scanf("%d", &valEsquina);
            esquinas[i][j] = valEsquina;

        }
    }

<p>Após, uso o comando for novamente para varrer os valores da matriz e crio uma condição para não considerar os valores da última coluna da linha com os valores da primeira coluna da próxima linha.</p>

    for(i = 0; i <= N; i++){

        for(j = 0; j <= N; j++){

            if(i < N && j < N){

<p>Comandos `if()` que contam a quantidade de câmeras nas esquinas para cada um dos 4 casos possíveis de formação de uma quadra.</p>


    			if(esquinas[i][j] == 1){ numCamera++; }
    			if(esquinas[i][j + 1] == 1){ numCamera++; }
    			if(esquinas[i + 1][j] == 1){ numCamera++; }
    			if(esquinas[i + 1][j + 1] == 1){ numCamera++; }

<p>Por fim, no caso da quadra ter 2 ou mais câmeras a saída é o caracter S, caso contrário a saída é U. Há ainda outra condicional para pular a linha quando a  quantidade de valores de saída imprimidos for igual ao valor de N, depois da saída do caracter, a variável contadora da quantidade de câmeras é zerada para fazer a contagem da próxima quadra.</p>

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