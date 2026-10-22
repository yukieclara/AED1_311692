/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Clara Yukie Mimura de Castilho
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1094
Data        : 22/10/2026
Objetivo    : Calcular o total de animais utilizados nos experimentos e a 
quantidade e porcentagem de coelhos, ratos e sapos.
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h> 

int main () {
    int n, i, qtd;
    int total = 0, coelhos = 0, ratos = 0, sapos = 0; 
    float pC = 0, pR = 0, pS = 0;
    char c;

    scanf ("%d", &n); /* total de experimentos */

    for (i = 0; i < n; i++) {
        scanf ("%d %c", &qtd, &c);

        total += qtd;

        if (c == 'C') {
            coelhos += qtd;
        }
        if (c == 'R') {
            ratos += qtd;
        }
        else if (c == 'S') {
            sapos += qtd;
        }
    }
    pC = ((float) coelhos * 100) / total;
    pR = ((float) ratos * 100) / total;
    pS = ((float) sapos * 100) / total;

    printf ("Total: %d cobaias\n", total);
    printf ("Total de coelhos: %d\n", coelhos);
    printf ("Total de ratos: %d\n", ratos);
    printf ("Total de sapos: %d\n", sapos);
    printf ("Percentagem de coelhos: %.2f %%\n", pC);
    printf ("Percentual de ratos: %.2f %%\n", pR);
    printf ("Percentual de sapos: %.2f %%\n", pS);
    return 0;
}