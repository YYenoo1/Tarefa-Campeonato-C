#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "campeonato.h"

/* 1) Aloque com malloc um Campeonato e preencha seus campos:
      - Para a quantidade de times, use o valor do parametro 'quantidade'.
      - Para o vetor de times, aloque dinamicamente um vetor de struct Time com 'quantidade' elementos.
   Copie os dados de timesIniciais (parâmetro da função) para o novo vetor, na mesma ordem.
   Considere que as alocacoes sao bem-sucedidas. */
Campeonato *criarCampeonato(const Time timesIniciais[], int quantidade) {
    Campeonato *campeonato = malloc(sizeof(Campeonato));
    campeonato->quantidade = quantidade;
    campeonato->times = malloc(quantidade * sizeof(Time));
    for (int i = 0; i < quantidade; i++) {
        campeonato->times[i] = timesIniciais[i];
    }
    return campeonato;
}

/* 2) Registre o resultado de uma partida entre dois times.
   'time1' e 'time2' sao indices no vetor de times dado no main.
   Atualize os campos 'golsPro' (gols marcados) e 'golsContra' (gols sofridos) de ambos.
   Atualize o campo 'pontos' de acordo com:
      - Vitoria: +3 pontos ao vencedor; 
      - Empate: +1 ponto para cada;
      - Derrota: 0 ponto. */
void registrarPartida(Campeonato *campeonato, int time1, int time2, int golsTime1, int golsTime2) {
   campeonato->times[time1].golsPro+=golsTime1;
   campeonato->times[time1].golsContra+=golsTime2;
   campeonato->times[time2].golsPro+=golsTime2;
   campeonato->times[time2].golsContra+=golsTime1;
   if (golsTime1>golsTime2){
      campeonato->times[time1].pontos+=3;
   }else if(golsTime2>golsTime1){
      campeonato->times[time2].pontos+=3;
   }else{
      campeonato->times[time1].pontos+=1;
      campeonato->times[time2].pontos+=1;
   }
}

/* 3) Retorne o indice do lider do campeonato (maior numero de pontos).
   Em caso de empate na pontuacao, utilize os seguintes criterios,
   nesta ordem:
   a) maior saldo de gols (golsPro - golsContra);
   b) maior numero de golsPro.
   Se ainda houver empate, mantenha o time que aparece primeiro no vetor. */
int indiceLider(const Campeonato *campeonato) {
   int lider=0;
   for(int i=0;i<campeonato->quantidade;i++){
      int saldoatual=campeonato->times[i].golsPro-campeonato->times[i].golsContra;
      int saldolider=campeonato->times[lider].golsPro-campeonato->times[lider].golsContra;
      if (campeonato->times[i].pontos>campeonato->times[lider].pontos){
         lider=i;
      }else if(campeonato->times[i].pontos==campeonato->times[lider].pontos){
         if (saldoatual>saldolider){
            lider=i;
         }else if(saldoatual==saldolider){
            if(campeonato->times[i].golsPro>campeonato->times[lider].golsContra){
               lider=i;
            }
         }
      }
   }
   return lider;
}
/* 4) Conte quantos times possuem saldo de gols positivo, isto e, golsPro > golsContra. */
int contarSaldoPositivo(const Campeonato *campeonato) {
   int timesPositivos=0;
   for(int i=0;i<campeonato->quantidade;i++){
      if (campeonato->times[i].golsPro>campeonato->times[i].golsContra){
         timesPositivos++;
      }
   }
}
/* 5) Libere o vetor de times e a struct Campeonato.
   Ao final, *campeonato deve ser NULL. */
void liberarCampeonato(Campeonato **campeonato) {
   if(campeonato==NULL|| *campeonato==NULL){
      return;
   }
   free((*campeonato)->times);
   free(*campeonato);
   *campeonato=NULL;
}

/* DESAFIO OPCIONAL: Implemente a mesma contagem da funcao 4,
   mas utilizando recursividade, sem for ou while.

   O parametro quantidade representa o numero de times
   que ainda precisam ser analisados.

   Comece pelo ultimo time do vetor (índice 'quantidade - 1')
   e avance em direcao ao primeiro (índice '0').

   Caso-base: se quantidade == 0, retorne 0.

   Caso recursivo: verifique se o ultimo time possui saldo
   positivo e some esse resultado com a contagem dos times
   anteriores, chamando a funcao com 'quantidade - 1'. */
int contarSaldoPositivoRecursivo(const Campeonato *campeonato, int quantidade) {
   if (quantidade==0){
      return 0;
   }
   int i=quantidade-1;
   int contador=0;
   if (campeonato->times[i].golsPro>campeonato->times[i].golsContra){
      contador+=1;
   }
   return contador+contarSaldoPositivoRecursivo(campeonato, quantidade-1);
}
/*

RESPONDA AS PERGUNTAS ABAIXO, APOS IMPLEMENTAR AS FUNCOES E EXECUTAR O PROGRAMA:

a) Quantos pontos o Santos possui?
Resposta:O santos possui 4 pontos por vencer uma partida e empatar outra.

b) Quantos pontos o lider possui?
Resposta:O líder palmeiras possui 9 pontos (porem n tem mundial).

c) Qual e o time lider do campeonato?
Resposta:Palmeiras.

d) Quantos times possuem saldo de gols positivo?
Resposta:Só um.
*/