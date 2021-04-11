# PROCESSO SELETIVO PET BCC 2021
## URI 2502

[LINK DO EXERCÍCIO](https://www.urionlinejudge.com.br/judge/pt/problems/view/2502)

### Definindo o problema
Como explicado na descrição do próprio exercício, nosso objetivo aqui é partir de uma entrada "criptografada" junto com a suas regras (esse é um ponto importante, mesmo que a cifra de César seja simples de decifrar, outras regras para criptografia podem ser *impossíveis*), para que possamos gerar na saída a mensagem descriptografada.
### Desmembrando o problema
#####  Cada caso de teste começa com uma linha indicando dois números inteiros. C e N.
Onde _C_ (um número inteiro entre 0 e 21) indica quantos caracteres da primeira linha serão trocados por caracteres da segunda linha e vice versa. Já _N_ (um número inteiro entre 0 e 100) representa quantas linhas de teste serão usadas naquele teste. A ordem desses caracteres no código da solução __importa__!
Dessa forma, podemos começar fazendo a leitura desses dois números, já que são inseridos na primeira linha da entrada :3 vamos nos referir a eles daqui para frente com _C_ e _N_).
Como o código é executado até ter uma entrada vazia ou fora das especificações, colocamos essa leitura em um _loop_ para que múltiplas entradas possam ser testadas até que a função de leitura retorne ```EOF``` ou seja, a função ```scanf``` não conseguiu ler nada.
A partir de agora, todo nossa solução ocorrerá dentro do loop supracitado
Dentro deles podemos colocar uma função ```if``` que retorna 0 (zero) para caso nosso _C_  ou _N_ seja menores que 1. (Opcional no URI, mas prever que o usuário pode colocar entradas erradas é uma parte importante da programação).
#####  Leitura da cifra e das linhas
A leitura da cifra e das linhas é feita com o uso do ```fgets``` pela generalidade da função, entanto, poderia ser feito com o uso do ```scanf``` para mais detalhes sobre como as funções diferem acesse o [link](https://www.ti-enxame.com/pt/c/diferenca-entre-scanf-e-fgets/967414216/).
Como mais de uma linha pode fazer parte de um caso de teste, um loop determinado (```for```) foi usado.
##### A solução de fato :-)
Vamos entender o centro da nossa resolução para esse problema, primeira vamos pensar em um algoritmo escrito em língua natural para que se fosse necessário resolver esse problema à mão o que fariámos: 
1. Olhar a primeira letra da frase a ser analisada;
2. Procurar por ela entre na primeira e na segunda linha de codificação. (ZENIT e POLAR, do exemplo do URI);
3. Se achamos, trocar por sua correspondente na outra linha (se acha na primeira troque pela letra correspondente na segunda);
4. Passar para a letra seguinte da frase analisada.

Esse é um bom começo para a resolução, indica que precisaremos iterar pelo texto criptografado e também pelas linhas de codificação (procurando por um caracter _n_) além de fazer a troca das letras. 
Porém, não podemos contar apenas com isso, uma vez que se a letra for minúscula no texto criptografado, ela não será tida como igual à das linhas de codificação (Computadores inteligentes? Discordo!), assim é possível criar uma __variável auxiliar__ que vai guardar nosso valor à ser comparado como letra maiúscula.
Para essa solução foi usada uma biblioteca da linguagem C chamada ```<ctype.h>``` que permite o uso das funções ```toupper``` e ```islower``` para deixar um caractere maiúsculo e verificar se um caracter é minúsculo, respectivamente. Mais detalhes da biblioteca e das funções usadas para resolução estão disponíveis [aqui](https://www.ime.usp.br/~pf/algoritmos/apend/ctype.h.html).
Abaixo é possível conferir o fragmento do código onde aplicamos o processo descrito nesse tópico:
```for (j = 0; j < C+1; j++){
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
```
Esse fragmento faz exatamente o foi aqui descrito (com detalhes de implementação, _neah_). Assim iteramos pela nossa frase, definimos um auxiliar (```aux```) para o caractere selecionado na iteração (ou caractere ```k```), auxiliar esse que é convertido para maiúsculo, caso necessário. A seguir comparamos o ```aux``` com o primeiro caractere das cifras de cima e de baixo (no código denominadas ```cifra1``` e ```cifra2```), se for igual, o caractere na frase criptografada é trocado. 
Isso feito, o segundo caracter será comparado da mesma forma, com o primeiro elemento de ambas as "cifras" e assim por diante, até que todos os caracteres da frase criptografada sejam avaliados e, se necessário, trocados. Daí o mesmo processo é feito para a segunda letra das cifras e assim por diante.
Perceba, nosso _loop_ mais externo é o que itera sobre os elementos de ```cifra1``` e ```cifra2``` e o mais interno o que itera pelos elementos da frase criptografada, mas isso poderia facilmente ser invertido.
##### Os finalmentes
Com tudo feito, garantimos que nossa saída será como a desejada no problema e imprimos na tela a frase descriptografada e o processo é feito para as outras que constem naquele caso de teste :) retornamos 0 (zero) no final do código para que o compilador do URI saiba que a execução acabou e não entre em _loop_. 
