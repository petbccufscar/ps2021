# Processo Seletivo - PET BCC 2021

## Exercício [URI 1224](https://www.urionlinejudge.com.br/judge/pt/problems/view/1224)

### Descrição do Problema
Ajudar Alberto vencer Wanderley em um simples jogo de cartas, onde uma sequencia de cartas é disposta sobre a mesa, de valores variáveis. Alberto deve fazer o maior número de pontos, pegando para si uma carta por vez e apenas das extremidades. Wanderley, por sua vez, deve impedir que Alberto faça o maior número de pontos possíveis, seguindo a mesma premissa, só podendo retirar as cartas das extremidades.

#### Problemas
Por se tratar de um problema de decisão, visto que o último caso de teste exemplificado pelo próprio exercício, foge totalmente de uma solução trivial, a alternativa foi a utilização de _Programação Dinâmica_, para só assim conseguir resolver o problema em tempo hábil. Visto que não é uma matéria muito abrangente na faculdade, foi um bom exercício de pesquisa fora dela.

#### Resolução
Todo o código está comentado, e creio que seja mais fácil assimilar o que está acontecendo com o código visível, porém, para dar uma boa simplificada em como a resposta foi atingida, podemos começar explicando o conceito de Programação Dinâmica, a qual é a forma de otimizar cálculos recursivos e ainda, facilitar tomada de decisões, principalmente as que dependem de informação já obtidas em algum momento da execução do programa. Esse nome se dá justamente por isso, é um método de programação que vai se adequando e tornando mais rápido conforme ele se auto completa com valores obtidos.

Após toda a primeira linha da tabela estar preenchida, a função pode se chamar recursivamente, ou dentro de um ```for``` ou ```while```, assim preenchendo as próximas linhas. Neste caso em específico, apenas duas linhas são utilizadas, assim, são sempre alternadas a cada turno passado, visto que, os pontos do segundo jogador não são necessários para a resolução do problema.