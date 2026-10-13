/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Clara Yukie Mimura de Castilho
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 01/09/2026
Objetivo    : Há uma pilha de cartas (Max 50). Deve-se descartar a primeira e mover
 a nova primeira para o final da fila repetidas vezes. Fazer esse procedimento até 
 haver apenas 1 carta na pilha. deve-se imprimir as cartas descartadas em ordem e 
 a última carta restante no baralho.
Dificuldade : Organizar a parte do "int main" para que todas as ações do enunciado
acontecessem corretamente.
Uso de IA: Falhei ao fazer a parte do int main e ela me corrigiu, além de me explicar
um jeito que deu certo.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int item;
    struct cel *seg;
} cel;

typedef struct {
    cel *frente;
    cel *fim;
} fila;

cel *cria (int valor) {
    cel *novo;

    novo = malloc (sizeof (cel));

    novo -> item = valor;
    novo -> seg = NULL;

    return novo;
}

void inicializa (fila *f) {
    f -> frente = NULL;
    f -> fim = NULL;
}

int vazio (fila *f) {
    return f -> frente == NULL;
}

void libera (fila *f) {
    cel *p;

    while (f -> frente != NULL) {
        p = f -> frente;
        f -> frente = f -> frente -> seg;
        free (p);
    }
}

int retira (fila *f) {
    cel *p;
    int valor;

    if (f -> frente == NULL) {
        return -1;
    }
    p = f -> frente;
    valor = p -> item;

    f -> frente = f -> frente -> seg;

    if (f -> frente == NULL) {
        f -> fim = NULL;
    }

    free (p);
    return valor;
}

void insere (fila *f, int valor) {
    cel *novo;

    novo = cria (valor);

    if (f -> frente == NULL) {
        f -> frente = novo;
        f -> fim = novo;
    }
    else {
        f -> fim -> seg = novo;
        f -> fim = novo;
    }
}


int main () {
    fila f;
    int n, descartada, i, primeiro, carta;

    /* Lendo o número de cartas */
    while (scanf("%d", &n) == 1 && n != 0) {
        inicializa (&f);

        /* Inserindo todas as cartas */
        for (i = 1; i <= n; i++) {
            insere (&f, i);
        }

        printf ("Descarded Cards: ");

        primeiro = 1; /* serve para organizar as virgulas, comeca em 1 porque 
        ainda nao imprimimos nenhuma carta */

        /* Repete enquanto houver mais de uma carta */
        while (f.frente != f.fim) {

            /* Descarta a primeira carta */
            descartada = retira (&f);
            
            if (primeiro == 0) {
                printf (",");
            }
            printf (" %d", descartada);
            primeiro = 0;

            carta = retira (&f);
            insere (&f, carta);
        }
        printf ("\nRemaining cards: %d\n", f.frente -> item);
        libera (&f);
    }
    return 0;
}