#include <stdio.h>
#include "campeonato.h"

int main(void) {
    /* Dados ficticios: campeonato com quatro clubes paulistas. */
    Time timesIniciais[4] = {
        {"Palmeiras",   0, 0, 0},
        {"Corinthians", 0, 0, 0},
        {"Sao Paulo",   0, 0, 0},
        {"Santos",      0, 0, 0}
    };

    Campeonato *campeonato = criarCampeonato(timesIniciais, 4);

    /* Indices dos times: 0=Palmeiras, 1=Corinthians,
       2=Sao Paulo, 3=Santos. Os resultados sao ficticios. */
    registrarPartida(campeonato, 0, 1, 2, 0); /* Palmeiras 2 x 0 Corinthians */
    registrarPartida(campeonato, 2, 3, 1, 1); /* Sao Paulo 1 x 1 Santos */
    registrarPartida(campeonato, 1, 3, 0, 2); /* Corinthians 0 x 2 Santos */
    registrarPartida(campeonato, 0, 2, 2, 0); /* Palmeiras 2 x 0 Sao Paulo */
    registrarPartida(campeonato, 3, 0, 0, 3); /* Santos 0 x 3 Palmeiras */

    printf("CLASSIFICACAO (na ordem do vetor):\n");
    for (int i = 0; i < campeonato->quantidade; i++) {
        Time t = campeonato->times[i];
        printf("%s: %d pontos | GP: %d | GC: %d | Saldo: %d\n",
               t.nome, t.pontos, t.golsPro, t.golsContra,
               t.golsPro - t.golsContra);
    }

    int lider = indiceLider(campeonato);
    printf("Lider: %s\n", campeonato->times[lider].nome);

    printf("Times com saldo positivo: %d\n",
           contarSaldoPositivo(campeonato));

    /* DESAFIO OPCIONAL: descomente somente apos implementar a funcao.
    printf("Saldo positivo (recursivo): %d\n",
           contarSaldoPositivoRecursivo(campeonato, campeonato->quantidade));
    */

    liberarCampeonato(&campeonato);

    printf("Estrutura liberada: %s\n",
           campeonato == NULL ? "sim" : "nao");

    return 0;
}