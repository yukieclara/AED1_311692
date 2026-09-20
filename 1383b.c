#include <stdio.h>
#include <stdlib.h>

int verificaLinha (int *m, int linha){
    /* ** = ponteiro p/ ponteiro */
    /* Cada linha contem 1 a 9*/
    int apareceu[10] = {0};
    int x;
    /* vetor auxiliar */
    for (int j = 0; j < 9; j++) {
        x = m[linha * 9 + j];
        /* pula 9 * o i de m[i][j] e adiciona o j pra saber qual a posicao
        ex: m[2][4] = 2 * 9 + 4 = posicao 22 (lembra que primeira linha é linha 0) */
        if (apareceu[x] == 1)
            return 0;
        apareceu[x] = 1;
    }
    return 1;
}
int verificaColuna (int *m, int coluna) {
    int apareceu[10] = {0};
    int x;

    for (int i = 0; i < 9; i++) {
        x = m[i * 9 + coluna];

        if (apareceu[x] == 1)
            return 0;
        apareceu[x] = 1;
    }
    return 1;
}
int verificaRegiao (int *m, int lin, int col) {
    int apareceu [10] = {0};
    int x;
    for (int i = lin; i < lin + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            x = m[i * 9 + j];

            if (apareceu[x] == 1)
                return 0;
            apareceu[x] = 1;
        }
    }
    return 1;
}
int verificaSudoku (int *m) {
    for (int i = 0; i < 9; i++) {
        if (verificaLinha(m, i) == 0)
            return 0;
    }
    for (int i = 0; i < 9; i++) {
        if (verificaColuna(m, i) == 0)
            return 0;
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (verificaRegiao(m,i,j) == 0)
                return 0;
        }
    }
    return 1;
}
int main () {
    int *m;

    /* alocacao dinamica  */
    m = (int *) malloc (9 * 9 * sizeof(int));
    if (m == NULL) {
        printf ("Erro de alocacao\n");
        return 1;
    }
    /* preenchendo a matriz */
    printf ("Digite os valores: ");
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            scanf ("%d", &m[i * 9 + j]);
        }
    }
    if (verificaSudoku(*m) == 0){
        printf ("NAO\n");
    }
    else {
        printf ("SIM\n");
    }
    /* liberando memoria */
    for (int i = 0; i < 9; i++) {
        free (m[i]);
    }
    free (m);

    return 0;
}