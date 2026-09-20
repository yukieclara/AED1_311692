#include <stdio.h>
#include <stdlib.h>

int main () {
    int *v; /* endereco do vetor */
    int maior, posicao;

    /* alocacao dinamica */
    v = (int *) malloc(100 * sizeof(int));
    /* total = reserve um espaco para um vetor e faca v apontar para esse espaco
    malloc = reserve esse espaço 
    sizeof = calcula o espaco necessario: numero de elementos * espaco de 1 */
    if (v == NULL) {
        printf ("Erro de alocação\n");
        /* caso o malloc falhe */
        return 1; /* encerra */
    }
    /* preenchendo o vetor */
    printf ("Digite os valores: ");
    for (int i = 0; i < 100; i++) {
        scanf ("%d", &v[i]);
    }
    maior = v[0]; 
    posicao = 0;

    for(int i = 0; i < 100; i++) {
        if (v[i] > maior) {
            maior = v[i];
            posicao = i + 1;
        }
    }
    /* exibindo dados */
    printf ("Maior valor: %d\n", maior);
    printf ("Posicao do maior valor: %d\n", posicao);

    /* Liberando memória */
    free(v);

    return 0;
}