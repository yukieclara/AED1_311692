#include <stdio.h>
int main () {
    int v[100];
    int maior = 0, posicao = 0;

    for (int i = 0; i < 100; i++) {
        scanf ("%d", &v[i]);

        if (v[i] > maior) {
            maior = v[i];
            posicao = i + 1;
        }
    }
    printf ("Maior valor: %d\n", maior);
    printf ("Posição do maior valor: %d\n", posicao);
    return 0;
}