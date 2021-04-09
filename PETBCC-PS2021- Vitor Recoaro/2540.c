/*
Autor: Vitor de Almeida Recoaro - Email: vitordearec@gmail.com - Data: 08/04/2021

Primeira etapa processo seletivo PETBCC-UFSCar - 2021

Resolução do problema nº 2540 (https://www.urionlinejudge.com.br/judge/pt/problems/view/2540)

Breve descrição:
Em um jogo popular há 3 equipes e um líder para cada equipe. O time que o usuário participa
está sendo acusado de infringir algumas regras do jogo e alguns membros do time estão querendo o impeachment
do líder, enquanto outros membros não querem o afastamento do líder.

Intuito do código:
Fazer um sistema em que recebe o número de membros de um time e o próximo dado será o voto de cada membro 
sendo 0 para não é a favor do impeachment, 1 é a favor do impeachment. E a saída deverá ser "Impeachment",
caso o números de votos a favor passe de dois terços do tamanho do time, ou "acusacao arquivada" caso contrário.
*/

#include<stdio.h>

int main(){
   int numMembros, voto, i,aux;
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
    return 0; 
}