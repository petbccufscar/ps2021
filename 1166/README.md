# Problema:

No problema original da Torre de Hanoi existem 3 hastes e N discos, todos os discos estão encaixados em uma das hastes de modo que um disco maior nunca fica em cima de um disco menor. Neste problema existe uma Torre de Hanoi modificada, em vez de discos temos bolas mágicas numeradas 1, 2, 3... Por serem mágicas as bolas se repelem, a menos que a soma de duas bolas consecutivas em uma haste seja um quadrado perfeito. Cabe a você dizer qual o número máximo de bolas que podem ser colocadas em N hastes.

###### Problema completo: https://www.urionlinejudge.com.br/judge/pt/problems/view/1166

# Resolução:

Visando separar o problema original em problemas menores, vamos criar duas funções.

A primeira verifica se um número é um quadrado perfeito:

```c
        int ehQuadradoPerfeito(int n) {
            int r = (int)sqrt(n);
            return r*r == n;
        }
```

Primeiro calculamos a parte inteira da raiz de *n*:

```c
        int r = (int)sqrt(n);
```

Então elevamos a raiz ao quadrado e comparamos com *n*, se os valores forem iguais, *n* é um quadrado perfeito:

```c
        return r*r == n;
```

A segunda é quem faz o trabalho duro, calculando o número máximo para *N* hastes:

```c
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
```

Começamos alocando um vetor de tamanho *N* para guardar os valores no topo de cada haste, como todas as hastes vão começar vazias, usamos calloc para que o vetor comece zerado:

```c
        int * varetas = (int *)calloc(N, sizeof(int));
```

As variáveis *max* e *idx* são respectivamente o próximo número que vamos tentar por em uma haste e o índice da haste que vamos usar:

```c
        int max = 1;
        int idx = 0;
```

Enquanto não precisarmos de um número maior de hastes do que o que temos, continuamos colocando números:

```c
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
```

Um número pode ser colocado em uma haste se esta estiver vazia ou possuir um número que quando somado com o novo gera um quadrado perfeito:

```c
        int estaVazia = varetas[idx] == 0;
        int ehPerfeito = ehQuadradoPerfeito(max + varetas[idx]);
```

Se for possível colocar o número na haste em questão basta salvarmos seu valor no vetor, incrementar *max* e resetar o índice da haste para 0. Caso contrário incrementamos o índice da haste, mantendo *max*.

```c
        if (estaVazia || ehPerfeito) {
            varetas[idx] = max;
            max++;
            idx = 0;
        } else {
            idx++;
        }
```

A função termina quando saímos do loop por precisar de mais hastes do que temos. O valor em *max* indica o próximo número que seria testado, portanto *max - 1* é o último número que conseguimos colocar na torre.

```c
        return max - 1;
```

Como o problema possui vários casos de teste, na *main* temos que ler o número de casos e resolver cada um:

```c
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
```

Vamos declarar 4 variáveis, *T* para o número de testes, *N* para receber o número de hastes, *i* como auxiliar para o loop, e *maximo* para receber a resposta:
```c
        int T;
        int N;
        int i;
        int maximo;
```

Então lemos *T*:
```c
        scanf("%d", &T);
```

E iteramos, lendo e resolvendo cada caso:
```c
        for (i = 0; i < T; i++) {
            scanf("%d", &N);

            maximo = calculaMaximo(N);

            printf("%d\n", maximo);
        }
```

Lemos o número de hastes do caso:
```c
        scanf("%d", &N);
```

Calculamos usando a função previamente declarada:
```c
        maximo = calculaMaximo(N);
```

E exibimos o resultado:
```c
        printf("%d\n", maximo);
```

Caso tenha alguma dúvida sobre este problema ou sobre a resolução, entre em contato com o PET-BCC pelo nosso
[Facebook](https://www.facebook.com/petbcc/),
[Instagram](https://www.instagram.com/petbcc.ufscar/)
ou nos mande um e-mail com o assunto "URI" para  petbcc.ufscar@gmail.com

