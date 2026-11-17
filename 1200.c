/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Clara Yukie Mimura de Castilho
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 10/11/2026
Objetivo    : Construir uma arvore binaria de busca em que a pessoa possa
inserir, procurar e listar os elementos nas ordens infixa, pos fixa e prefixa.
Dificuldade : Criar o int main
Uso de IA   : Usei so pra corrigir.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel {
    int item;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel no;

no *cria (int valor) {
    no *novo = malloc (sizeof(no));

    novo -> item == valor;
    novo -> esq == NULL;
    novo -> dir == NULL;

    return novo;
}

no *insere (int valor, no *raiz) {
    no *novo = cria (valor);

    if (raiz == NULL) {
        return novo;
    }
    if (valor < raiz -> item) {
        raiz -> esq = insere (valor, raiz -> esq);
    }
    else {
        raiz -> dir = insere (valor, raiz -> dir);
    }
    return raiz;
}

void prefixo (no *raiz) { 
    if (raiz != NULL) {
        printf (" %d", raiz -> item);
        prefixo (raiz -> esq);
        prefixo (raiz -> dir);
    }
}

void infixo (no *raiz) { 
    if (raiz != NULL) {
        infixo (raiz -> esq);
        printf (" %d", raiz -> item);
        infixo (raiz -> dir);
    }
}

void sufixo (no *raiz) { 
    if (raiz != NULL) {
        sufixo (raiz -> esq);
        sufixo (raiz -> dir);
        printf (" %d", raiz -> item);
    }
}

void liberar (no *raiz) {
    if (raiz != NULL){
        liberar (raiz -> esq);
        liberar (raiz -> dir);
        free (raiz);
    }
}

no *busca (no *raiz, char valor) {
    if (raiz -> item == NULL) {
        return;
    }
    if (raiz -> item == valor) {
        return raiz;
    }
    if (valor < raiz -> item) {
        return busca (raiz -> esq, valor);
    }
    else {
        return busca (raiz -> dir, valor);
    }
}

int main () {
    no *raiz = NULL;
    char comando[10];
    char letra;
    scanf ("%s", comando);
    while (scanf ("%s", comando) != EOF){
        if (strcmp (comando, "I") == 0){
            scanf (" %c", &letra);
            insere (raiz, letra); 
        }
        else if (strcmp (comando, "P") == 0) {
            scanf (" %c", &letra);

            if (busca (raiz, letra)) {
                printf ("%c existe\n", letra);
            }
            else {
                printf ("%c não existe\n", letra);
            }
        }
        else if (strcmp (comando, "INFIXA") == 0) {
            infixo (raiz);
            printf ("\n");
        }
        else if (strcmp (comando, "PREFIXA") == 0) {
            prefixo (raiz);
            printf ("\n");
        }
        else if (strcmp (comando, "SUFIXA") == 0) {
            sufixo (raiz);
            printf ("\n");
        }
    }
    liberar (raiz);
    return 0;
}