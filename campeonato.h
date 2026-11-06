#ifndef CAMPEONATO_H
#define CAMPEONATO_H

/* Estruturas fornecidas: nao alterar. */
typedef struct Time {
    char nome[30];
    int pontos;           
    int golsPro;          /* Gols marcados pelo time */
    int golsContra;       /* Gols sofridos pelo time */
} Time;

typedef struct Campeonato {
    Time *times;          /* vetor alocado dinamicamente */
    int quantidade;       /* quantidade de times participantes */
} Campeonato;

/* Cinco funcoes obrigatorias: implementar em campeonato.c. */
Campeonato *criarCampeonato(const Time timesIniciais[], int quantidade);
void registrarPartida(Campeonato *campeonato, int time1, int time2, int golsTime1, int golsTime2);
int indiceLider(const Campeonato *campeonato);
int contarSaldoPositivo(const Campeonato *campeonato);
void liberarCampeonato(Campeonato **campeonato);

/* DESAFIO OPCIONAL: mesma contagem, agora com recursividade. */
int contarSaldoPositivoRecursivo(const Campeonato *campeonato, int quantidade);

#endif