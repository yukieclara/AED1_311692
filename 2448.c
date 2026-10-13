/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Clara Yukie Mimura de Castilho
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 23/09/2026
Objetivo    : Descobrir quanto tempo o carteiro leva para entregar todas as 
encomendas em ordem de chegada.
Dificuldade : Entender a lógica por traz do int main.
Uso de IA   : Para correção do meu int main
-------------------------------------------------------------------------- */
#include <stdio.h>

int BuscaBinaria (int v[], int x, int n) {
    int inicio = 0; 
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (v[meio] == x) {
            return meio;
        } 
        if (x > v[meio]) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main () {
    int n, m, i;

    scanf ("%d %d", &n, &m);
    
    int casas[n];

    for (i = 0; i < n; i++) {
        scanf ("%d", &casas[i]);
    }

    int atual = 0; /* comeca na primeira casa */
    long long tempo = 0;

    for (int i = 0; i < m; i++) {
        int encomenda;
        scanf ("%d", &encomenda); 

        int posicao = BuscaBinaria (casas, encomenda, n);

        if (posicao > atual) {
            tempo += posicao - atual;
        }
        else {
            tempo += atual - posicao;
        }
        atual = posicao;
    }
    printf ("%lld\n", tempo);
    return 0;
}