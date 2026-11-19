/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Clara Yukie Mimura de Castilho
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 22/10/2026
Objetivo    : Encontrar quantos componentes conexos existem em um grafo e listar
os vertices de cada componente.
Dificuldade : Entender a questao e raciocina-la.
Uso de IA   : Usei para entender e ajudar a fazer o exercicio inteiro.
-------------------------------------------------------------------------- */

#include <stdio.h>

int grafo[26][26];
int visitado[26];
char componente[26];
int cont;

void dfs(int v) {
    visitado[v] = 1;

    componente[cont] = v + 'a';
    cont++;

    for (int i = 0; i < 26; i++) {
        if (grafo[v][i] == 1 && visitado[i] == 0) {
            dfs(i);
        }
    }
}

void ordenar() {
    for (int i = 0; i < cont - 1; i++) {
        for (int j = i + 1; j < cont; j++) {
            if (componente[i] > componente[j]) {
                char aux = componente[i];
                componente[i] = componente[j];
                componente[j] = aux;
            }
        }
    }
}

int main() {
    int T, V, E;
    char a, b;

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {

        scanf("%d %d", &V, &E);

        for (int i = 0; i < 26; i++) {
            visitado[i] = 0;

            for (int j = 0; j < 26; j++) {
                grafo[i][j] = 0;
            }
        }

        for (int i = 0; i < E; i++) {
            scanf(" %c %c", &a, &b);

            int u = a - 'a';
            int v = b - 'a';

            grafo[u][v] = 1;
            grafo[v][u] = 1;
        }

        int total = 0;

        printf("Case #%d:\n", t);

        for (int i = 0; i < V; i++) {

            if (visitado[i] == 0) {

                cont = 0;

                dfs(i);

                ordenar();

                for (int j = 0; j < cont; j++) {
                    printf("%c,", componente[j]);
                }

                printf("\n");

                total++;
            }
        }

        printf("%d connected components\n\n", total);
    }

    return 0;
}
