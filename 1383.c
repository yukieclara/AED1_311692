/* Q1: Todas as 9 linhas tem os numeros de 1 a 9? 
Q2: Todas as 9 colunas tem os numeros de 1 a 9? 
Q3: Todos os 9 quadrados 3x3 tem os numeros de 1 a 9? */
#include <stdio.h>
int verificaLinhas (int m[9][9], int linha) {
/* Cada linha contém 1 a 9*/
    int apareceu[10] = {0}; 
    /* {0}: todas as posicoes sao inicializadas com 0 */
    int x; /* x é o numero da posicao m[linha][j]*/
    for (int j = 0; j < 9; j ++) {
        x = m[linha][j];

        if (apareceu[x] == 1) /*. esse numero ja apareceu? SIM */
            return 0; /* se aquele número já apareceu, a linha é inválida. */

        apareceu[x] = 1; /* marca que o numero apareceu*/
    }
    return 1; /* se no final percorreu os 9 números sem encontrar repetição*/
}
int verificaColuna (int m[9][9], int coluna) {
/* Cada coluna contém 1 a 9*/
int apareceu[10] = {0};
int x;
for (int i = 0; i < 9; i++) {
    x = m[i][coluna];

    if (apareceu[x] == 1)
        return 0;
    
    apareceu[x] = 1;
    }
    return 1;
}
int verificaRegião (int m[9][9], int lin, int col) {
/* Cada região 3x3 contém 1 a 9*/
    int apareceu[10] = {0};
    int x;

    for (int i = lin; i < lin + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            x = m[i][j];

            if (apareceu[x] == 1)
            return 0;

            apareceu[x] = 1;
        }
    }
    return 1;
}
int verificaSudoku (int m[9][9]) {
/* usa as outras funções */
    for (int i = 0; i < 9; i++) {
        if (verificaLinhas(m, i) == 0)
            return 0;
    }
    for (int j = 0; j < 9; j++) {
        if (verificaColuna (m, j) == 0)
            return 0;
    }
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++) {
            if (verificaRegião(m,i,j) == 0)
                return 0;
        }
    }
    return 1;
}
int main () {
    int m[9][9];

    printf ("digite a matriz solucao: ");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf ("%d", &m[i][j]);
        }
    }
    if (verificaSudoku(m) == 0)
        printf ("NÃ0\n");
    else 
        printf ("SIM\n");
    return 0; 
}