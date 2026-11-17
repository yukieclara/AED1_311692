/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Clara Yukie Mimura de Castilho
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 22/10/2026
Objetivo    : Montar uma árvore binária de busca com os números recebidos e 
imprimir os valores por nível, da raiz até as folhas, da esquerda pra direta. 
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

struct cel {
    int item;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel no;

no *cria (int valor) {
    no *novo = malloc (sizeof (no));

    novo -> item = valor;
    novo -> esq = NULL;
    novo -> dir = NULL;

    return novo;
}

no *insere (no *raiz, int valor) {
    if (raiz == NULL) {
        return cria (valor);
    }
    if (valor < raiz -> item) {
        raiz -> esq = insere (raiz -> esq, valor);
    }
    else {
        raiz -> dir = insere (raiz -> dir, valor);
    }
    return raiz;
}

/* percurso por nível usando fila */
void nivel (no *raiz, int n) {
    no **fila = malloc (n * sizeof(no*));

    int inicio = 0;
    int fim = 0;
    int primeiro = 1;

    fila [fim++] = raiz;

    while (inicio < fim) {
        no *atual = fila [inicio ++];

        if (!primeiro) {
            printf (" ");
        }
        printf ("%d", atual -> item);
        primeiro = 0;

        if (atual -> esq != NULL) {
            fila [fim++] = atual -> esq;
        }
        if (atual -> dir != NULL) {
            fila[fim++] = atual -> dir;
        }
    }
    printf ("\n");
    free (fila);
}

void liberar (no *raiz){
    if (raiz != NULL) {
        liberar (raiz -> esq);
        liberar (raiz -> dir);
        free (raiz);
    }
}

int main () {
    int x, n, valor;

    scanf ("%d", &x); /* numero de casos */

    for (int i = 1; i <= x; i++) {
        scanf ("%d", &n);
        
        no *raiz = NULL;

        for (int j = 0; j < n; j++) {
            scanf ("%d", &valor);
            raiz = insere (raiz , valor);
        }
        printf ("Case %d:\n", i);
        nivel (raiz, n);
        printf ("\n");
        liberar (raiz);
    }
    return 0;
}