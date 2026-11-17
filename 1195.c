/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Clara Yukie Mimura de Castilho
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 10/11/2026
Objetivo    : Contruir uma árvore binária de busca com os números fornecidos e,
depois, imprimir os elementos. em três formas diferentes de percurso.
Dificuldade : Não sabia como fazer os 3 percursos diferentes, muito menos como
imprimi-los no int main.
Uso de IA   : Usei para entender o enunciado 4e para criar as 3 funcoes.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

struct cel {
    int valor;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel no; 

no *criar (int valor) {
    no *novo = malloc (sizeof (no));

    novo -> valor = valor;
    novo -> esq = NULL;
    novo -> dir == NULL;

    return novo;
}

no *inserir (no *raiz, int valor) {
    if (raiz == NULL) {
        return criar (valor);
    }
    if (valor < raiz -> valor){
        raiz -> esq = inserir (raiz -> esq, valor);
    }
    else {
        raiz -> dir = inserir (raiz -> dir, valor);
    }
    return raiz;
}

void preorder (no *raiz) {
    if (raiz != NULL) {
        printf (" %d", raiz -> valor);
        preorder (raiz -> esq);
        preorder (raiz -> dir);
    }
}

void inorder (no *raiz) {
    if (raiz != NULL){
        inorder (raiz -> esq);
        printf (" %d", raiz -> valor);
        inorder (raiz -> dir);
    }
}

void postorder (no *raiz){
    if (raiz != NULL) {
        postorder (raiz -> esq);
        postorder (raiz -> dir);
        printf (" %d", raiz -> valor);
    }
}

void liberar (no *raiz) {
    if (raiz != NULL) {
        liberar (raiz -> esq);
        liberar (raiz -> dir);
        free (raiz);
    }
}

int main () {
    int x, n, valor;

    scanf ("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf ("%d",  &x);

        no *raiz = NULL;

        for (int j = 0; j < x; j++) {
            scanf ("%d", &valor);
            raiz = inserir (raiz, valor);
        }

        printf ("Case: %d\n", i);

        printf ("Pre:");
        preorder(raiz);
        printf ("\n");

        printf ("In:");
        inorder (raiz);
        printf ("\n");

        printf ("Post:");
        postorder (raiz);
        printf ("\n");

        printf ("\n");

        liberar (raiz);
    }
    return 0;
}