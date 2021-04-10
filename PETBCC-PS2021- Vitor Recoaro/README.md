## **Resolução do problema ["Impeachment do Líder" - URI 2540](https://www.urionlinejudge.com.br/judge/pt/problems/view/2540)**

### **Breve descrição:**

- Em um jogo popular chamado *Analógimôn Go!* Há 3 equipes e um líder para cada equipe. O time que o usuário participa está sendo acusado de infringir algumas regras do jogo e alguns membros do time estão querendo o impeachment do líder, enquanto outros membros não querem o afastamento do líder.

### Proposta **do código:**

- Fazer um sistema em que recebe na primeira linha o número de membros de um time e as próximas *N* linhas serão o voto de cada membro, sendo 0 para não é a favor do impeachment, 1 é a favor do impeachment. E a saída deverá ser "impeachment", caso o números de votos a favor seja maior ou igual a dois terços *N*, ou "acusacao arquivada" caso contrário. Isso repetidamente até encontrar o EOF.

### **Análise do problema e desenvolvimento do código:**

- De acordo com a proposta do código, necessitaremos de variáveis que guardem o número de pessoas de um time, uma para guardar o voto de cada pessoa e uma auxiliar para computar cada voto. Assim declaramos as variáveis:

    ```c
    int numMembros, voto, aux, i; // A variável 'i' será usada para manipulação do laço de repetição 'for' mais adiante.
    ```

    - Após a declaração de nossas variáveis, deveremos nos atentar a obtenção de dados, pode parecer complicado, mas as entradas de dados seguem o seguinte padrão:
        1. Um número positivo que representa o número de pessoas que votarão.
        2. Diversas linhas de zeros e uns, sendo o total de linhas o número de pessoas que estão para votar.
- Assim precisaremos da leitura do primeiro número que é o tamanho da equipe. E a partir deste número faremos um laço de repetição que receberá os votos dos participantes.

```c
scanf(" %d",&numMembros);//Recebe o número de pessoas que irão votar
for(i=0;i<numMembros;i++){
	scanf(" %d",&voto);
}
```

- Ao fazer a obtenção do voto, precisamos fazer a contagem de quantos são a favor e quantos são contra. Como os valores de votos são "0" ou "1", podemos inicializar a variável "aux" como zero e somar todos os votos obtidos, como o valor de favorável é "1" o "aux" sempre aumentará a cada voto a favor, e não será mudado quando o voto é contra, pois o seu valor é "0". E deste jeito ficará ao implementar a variável "aux":

```c
scanf(" %d",&numMembros);//Recebe o número de pessoas que irão votar
        aux = 0;
        for(i=0;i<numMembros;i++){
            scanf(" %d",&voto);
            aux = aux + voto;
        }
```

- A partir deste momento nós possuímos os valores de pessoas que são favoráveis ao impeachment na variável "aux", e assim precisamos fazer um teste para o dado de saída do programa, sendo a saída como "impeachment", caso o "aux" seja maior ou igual a dois terços do número de votos, e o programa deve mostrar "acusacao arquivada" caso "aux" seja menor. E  assim podemos gerar a seguinte parte do código:

```c
if(aux>=(numMembros*(float)2/3)){ // É necessário usar o 'cast' de float, pois caso faça a divisão inteira de 2/3, o valor resultante é 0 e desse jeito o 'aux' sempre vai ser maior que 0.
	printf("impeachment\n");
}
else{
	printf("acusacao arquivada\n");
}
```

- Após todo o desenvolvimento do corpo do programa, será necessário apenas um pequeno detalhe, que este código inteiro deve ser repetido até que o valor de "numMembros" lido for "EOF". Então usaremos o laço de repetição while, sendo a condição o valor lido for diferente de "EOF".

```c
while(scanf(" %d",&numMembros)!=EOF){
        aux = 0;
        for(i=0;i<numMembros;i++){
            scanf(" %d",&voto);
            aux = aux + voto;
        }
        if(aux>=(numMembros*(float)2/3)){
            printf("impeachment\n");
        }
        else{
            printf("acusacao arquivada\n");
        }
    }
```

- Deste jeito, ele conseguirá ler várias votações até o usuário querer finalizar o programa, terminando o desenvolvimento do código.
