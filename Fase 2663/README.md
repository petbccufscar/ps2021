
### URI - Fase 2663

#### Entendendo o problema 
Primeiramente, o exercício nos apresenta uma competição em uma olímpiada em que participarão até 1000 candidatos (N), tendo entre estes um certo número de aprovados (K) para a próxima etapa. Entretando, caso haja mais candidatos com a mesma nota do último classificado, ocorrendo assim um empate, todos com essa mesma nota passão também para a próxima etapa, mesmo que ultrapasse a quantidade de aprovados estimada anteriormente (K). O algoritmo ao final terá como saída o número de classificados para a próxima etapa.

#### Entradas 
Como os dados de entrada serão lidos na sequência: N, K e nota de cada um dos candidatos participantes. Serão primeiramente declaradas as variáveis inteiras 'n' (Número de Candidatos), 'k' (quantidade de aprovados para a próxima etapa) e um vetor 'n_vetor[1000]' de 1001 posições, pois terão até 1000 particiantes (N), que armazenará cada nota individual de todos os candidatos; e a variável 'i' que será nosso contador.

```{r, attr.source='.numberLines'}
int n, k, n_vetor[1000], i;
```
#### Leitura das Entradas

As leituras de N, K e as notas indivudias de cada cadidato serão feitas pela função "scanf" da linguagem C, seguindo suas respectivas ordens de leitura. Entretanto, para a leitura das notas individuais será utilizado também um loop com o "for" de 0 até 'n', em que a cada ciclo do loop será feita a leitura da nota de um candidato e armazenado seu valor na posição correspondente do vetor 'n_vetor[i]'.  Note que é feito a variável 'i', sendo nosso contador, a cada loop do ciclo é incrementado em 1 seu valor, e também corresponde a posição em que será armazenado a nota do participante.

```{r, attr.source='.numberLines'}
 scanf("%d", &n);
 scanf("%d", &k);

 for (int i=0; i<n; i++) {
     scanf("%d", &n_vetor[i]);
 }
```

#### Ordenação do vetor
Agora com todas a entradas lidas, vamos ordenar o vetor com as notas de cada candidado em ordem decresente, pois assim, após a ordenação saberemos que na posição do vetor "n_vetor[k-1]" teremos exatante a nota do último participante classificado!  Portanto, para a ordenação temos:

 ```{r, attr.source='.numberLines'}
int armazena;
 
for(int j=0; j<n; j++) {
    for (i = j+1; i<n; i++) {

        if (n_vetor[j] <  n_vetor[i]) {
            
            armazena = n_vetor[j];
            n_vetor[j] = n_vetor[i];
            n_vetor[i] = armazena;
        }
    }
}
```
Primeiramente é declarado a variável inteira 'armazena' que simplesmente nos servirá como um auxiliar, e também a variável 'j' que será nosso contador do primeiro laço. O primeiro loop inicia com o contador 'j = 0', e o fluxo seguirá para o segundo loop com o contador 'i' sendo iniciada como ' i = j + 1', essa escolha é proposital, pois como ambos os contadores indicam a posição do vetor, a seguinte comparação "(n_vetor[j] <  n_vetor[i])" sempre se dará entre a posição 'j' do vetor com sua posição seguinte 'j + 1'. Portanto, o primeiro loop acontecera da comparação da posição 'n_vetor[j]' com todas as posições subsequentes do vetor 'n_vetor[i], com 'i' iniciado em 'j + 1' até 'n' (segundo loop). Assim, a cada comparação feita entre a posição 'j' e 'i' no segundo loop, caso o valor armazenado na posição 'n_veto[i]' seja maior que o armazenado na posição 'n_vetor[j]' :

 ```{r, attr.source='.numberLines'}
        if (n_vetor[j] <  n_vetor[i])
```

 O valor da posição 'n_vetor[j]' será armazenado no auxiliar 'armazena':
 
  ```{r, attr.source='.numberLines'}
        if (n_vetor[j] <  n_vetor[i]) {
        
             armazena = n_vetor[j];
        }
```

 E em seguida trocado de lugar com o valor da posição 'n_vetor[i]' (posição com maior valor):
 
   ```{r, attr.source='.numberLines'}
        if (n_vetor[j] <  n_vetor[i]) {
        
             armazena = n_vetor[j];
             n_vetor[j] = n_vetor[i];
        }
```
 
 E por fim o valor guardado no auxiliar 'armazena' (valor da posição 'n_vetor[j]', menor valor) vai para a posição 'n_vetor[i]':
 
   ```{r, attr.source='.numberLines'}
    if (n_vetor[j] <  n_vetor[i]) {
            
            armazena = n_vetor[j];
            n_vetor[j] = n_vetor[i];
            n_vetor[i] = armazena;
        }
```

Assim, ao final de ambos os loops, teremos o vetor ordenado, pois foram feitas as comparações entre todas as posições do vetor, e colocado sempre o maior valor na posição 'j' do vetor a cada loop. Tendo ao fim nosso vetor ordenado em ordem decrescente de notas dos candidatos.

### Encontrado quantos participantes irão para a próxima fase

Bom, como agora temos nosso vetor em ordem decrescente, sabemos que serão aprovados para a próxima etapa 'k' participantes, sendo que, caso haja mais candidados com a mesma nota do último classificado 'n_vetor[k-1]', todos com essa mesma nota trambém passarão.  Então, primeiramente criamos a variável 'classificados' sendo igual a 'k', pois essa será o número de classificados para o final (output):

   ```{r, attr.source='.numberLines'}
int classificados = k;
```

 Agora, vamos verificar no vertor se há mais candidadtos com a mesma nota do último classificado 'n_vetor[k-1]'. Portanto criamos o loop coma função 'while', que sempre realizará  a comparação ao inicio do laço, e inicializamos o contador 'i = 1'. A comparação é feita pelo '(n_vetor[k-1] == n_vetor[k-1+i])', em que compara a cada laço se há notas iguais ao do último colocado 'n_vetor[k-1]' com os os classificados nas próximas posições 'n_vetor[k-1+i]'. Como 'i' inicializa em 1, já no primeiro loop comparamos a nota do último classificado com a do particiante seguinte no vertor 'n_vetor[k-1+1]', assim a cada laço, caso haja mais candidatos com essa mesma nota, incrementeamos 1 à variável 'classificados', com 'classificados++', somando assim em 1 o número total de participantes para a próxima etapa. E também incrementamos em 1 o contador 'i', para ser realizado a comparação com a próxima posição do vetor 'n_vetor[k-1+i}', assim enquanto houver notas iguais a do último classificado loop continua, sendo interrompido quando não houver mais notas iguais. Temos:

   ```{r, attr.source='.numberLines'}
int classificados = k;
i=1;

while(n_vetor[k-1] == n_vetor[k-1+i]) {
	
	classificados++;
	i++;
}
```

#### Output

 Portanto, ao final temos na variável 'classificados' com o número exato de participantes classificados para a próxima etapa, respeitando a ordem de empate do último classificado. Retornando assim seu valor como *output* utilizando a função 'printf':

   ```{r, attr.source='.numberLines'}
printf("%d\n", classificados);
```
