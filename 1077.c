/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Clara Yukie Mimura de Castilho
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 23/09/2026
Objetivo    : Transformar uma expressão matemática infixa para pós-fixa.
Dificuldade : Construir a lógica do int main.
Uso de IA   : Usei muito pra construir o int main pois não consegui pensar em nada
-------------------------------------------------------------------------- */
/* Infixa: a+b ; Pós-fixa : ab+ */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct cel {
    char item;
    struct cel *seg;
} cel;

typedef struct {
    cel *topo;
} pilha;

cel *cria (char valor) {
    cel *novo;

    novo = malloc (sizeof (cel));

    novo -> item = valor;
    novo -> seg = NULL;

    return novo;
}

void inicializa (pilha *p) {
    p -> topo = NULL;
}

int vazia (pilha *p) {
    return p -> topo == NULL;
}

void push (pilha *p, char valor) {
    cel *novo;

    novo = cria (valor);

    novo -> seg = p -> topo;
    p -> topo = novo;
}

char pop (pilha *p) {
    cel *aux;
    char valor;

    aux = p -> topo;
    valor = aux -> item;

    p -> topo = aux -> seg;

    free (aux);
    return valor;
}

void libera (pilha *p) {
    cel *aux;
    while (p -> topo != NULL) {
        aux = p -> topo;
        p -> topo = p -> topo -> seg;
        free (aux);
    }
}

int prioridade (char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '^') {
        return 3;
    }
    return 0;
}

int main () {
    pilha p;
    int n, j;
    char texto [301];

    scanf ("%d", &n); /* qtde de caracteres */

    while (n --) {
        scanf ("%s", texto);

        inicializa (&p);

        for (j = 0; j < strlen(texto); j++) {
            char c = texto [j];

            if (isalnum((unsigned char)c)) {
                printf ("%c", c);
            }
            else if (c == '(') {
                push (&p, c);
            }
            else if (c == ')') {
                while (!vazia (&p) && p.topo -> item != '(') {
                    printf ("%c", pop (&p));
                }
                if (!vazia(&p)) {
                    pop (&p);
                }
            }
            else {
                while (!vazia(&p) && p.topo -> item != '(' && (prioridade (p.topo -> item) > prioridade (c) || (prioridade (p.topo -> item) == prioridade (c) && c != '^'))) {
                    printf ("%c", pop (&p));
                }
                push (&p, c);
            }
        }
        while (!vazia(&p)) {
            printf ("%c", pop (&p));
        }
        printf ("\n");
        libera (&p);
    }
    return 0;
}