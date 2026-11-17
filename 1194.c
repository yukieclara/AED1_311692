/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Clara Yukie Mimura de Castilho
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1194
Data        : 10/11/2026
Objetivo    : Computar a forma posfixa da árvore dados os percursos 
infixo e prefixo
Dificuldade : Perceber o que precisava ser feito, que era algo consideravelmente
simples, mas fiz algo super complicado e complexo. Alem do raciocinio ser dificil
Uso de IA   : usei para corrigir meu primeiro codigo e perceber que errei 
totalmente, ai precisei de uma ajuda para comecar o novo.
-------------------------------------------------------------------------- */
#include <stdio.h>

void posfixa (char prefixa[], char infixa[], int inicio, int fim, int *indice) {
    if (inicio > fim) {
        return;
    }

    /* a raiz e o prox elemento da prefixa */
    char raiz = prefixa[*indice];
    (*indice)++;

    /* encontrar a raiz na infixa */
    int pos = inicio;

    while (infixa[pos] != raiz) {
        pos ++;
    }

    /* percorrer esquerda e direita */
    posfixa (prefixa, infixa, inicio, pos - 1, indice);
    posfixa (prefixa, infixa, pos + 1, fim, indice);

    printf ("%c", raiz);
}

int main () {
    int x, n;

    char prefixa [30], infixa[30];

    scanf ("%d", &x);

    while (x--) {
        scanf ("%d", &n);
        scanf ("%s", &prefixa);
        scanf ("%s", &infixa);

        int indice = 0;

        posfixa(prefixa, infixa, 0, n-1, &indice);

        printf ("\n");
    }
    return 0;
}