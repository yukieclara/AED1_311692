/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Clara Yukie Mimura de Castilho
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 12/09/2026
Objetivo    : Verificar se cada parêntese que abre ( tem um parentese que fecha ).
Dificuldade : Coordenar o int main para deixar tudo certo, errei mais na ideia do 
correto.
Uso de IA   : Usei para corrigir as ideias do int main, pois a compilação deu errado
na primeira, até ela me guiar pelo int correto.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ideia: Quando encontrar ( empilha, e quanto encontrar ) desempilha um ( */

typedef struct cel {
    char item;
    struct cel *seg;
} cel;

typedef struct {
    cel *topo;
} pilha;

cel *cria (int valor) {
    cel *novo;
    
    novo = malloc (sizeof (cel));

    novo -> item = valor;
    novo -> seg = NULL;

    return novo;
}

void inicializa (pilha *p) {
    p -> topo = NULL;
}

int vazio (pilha *p) {
    return p -> topo == NULL;
}

void push (pilha *p, int valor) {
    cel *novo;
    
    novo = cria (valor);

    novo -> seg = p -> topo;
    p -> topo = novo;
}

char pop (pilha *p) {
    int valor;
    cel *aux;

    if (p -> topo == NULL) {
        return -1;
    }

    aux = p -> topo;
    valor = aux -> item;
    p -> topo = p -> topo -> seg;

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

int main () {
    char texto [1001];
    int correto;

    /* ler cada expressao */
    while (scanf ("%s", texto) == 1) {
        pilha p;

        inicializa (&p);
        correto = 1; /* 1 = correta; 0 = incorreta */

        for (int i = 0; i < strlen(texto); i++) {
            if (texto[i] == '(') {
                push (&p, '('); /* empilhou o ( */
            }
            else if (texto [i] == ')'){
                if (vazio (&p)) { /* se tiver um ), mas nao tiver ( = incorreto = 0 */
                    correto = 0;
                    break;
                }
                pop (&p); /* desempilhou o ) */
            }
        }
        if (!vazio (&p)) {
            correto = 0; /* significa que nao tem numero certo de casais (), 
            ou seja, tem algum sobrando sozinho */
        }
        if (correto) {
            printf ("Correct\n");
        }
        else {
            printf ("Incorrect\n");
        }
        libera (&p);
    }
    return 0;
}