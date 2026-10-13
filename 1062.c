/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Clara Yukie Mimura de Castilho
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 27/09/2026
Objetivo    : Verificar se uma sequência de saída dos vagões é possível.
Dificuldade : Fazer diferentes desempilhacoes possiveis de aceitar.
Uso de IA   : Usei pois não sabia como fazer com que desempilhasse antes de
empilhar todos.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int item;
    struct cel *seg;
} cel;

typedef struct {
    cel *topo;
} pilha; 

cel *cria (int valor) { /*usado*/
    cel *novo;
    
    novo = malloc (sizeof(cel));

    novo -> item = valor;
    novo -> seg = NULL;

    return novo;
}

void inicializa (pilha *p) { /*usado*/
    p -> topo = NULL;
}

int vazia (pilha *p) {
    return p -> topo == NULL;
}

void libera (pilha *p) {
    cel *aux;

    while (p -> topo != NULL) {
        aux = p -> topo;
        p -> topo = p -> topo -> seg;
        free (aux);
    }
}

void push (pilha *p, int valor) { 
    cel *novo;
    
    novo = cria (valor);

    novo -> seg = p -> topo;
    p -> topo = novo;
}

int pop (pilha *p) {
    cel *aux;
    int valor;
    
    if (p -> topo == NULL) {
        return -1;
    }

    aux = p -> topo;
    valor = aux -> item;
    p -> topo = p -> topo -> seg;

    free (aux);
    return valor;
}

void Imprime (pilha *p) {
   if (p -> topo == NULL) {
    printf ("vazio\n");
   }
   for (cel *aux = p -> topo; aux != NULL; aux = aux -> seg) {
    printf ("%d", aux -> item);
   }
   printf ("\n");
}

int main() {
    int quantidadeVagoes;

    while (scanf("%d", &quantidadeVagoes) == 1 && quantidadeVagoes != 0) {
        while (1) {
            int ordemSaida[1000];

            scanf("%d", &ordemSaida[0]);

            if (ordemSaida[0] == 0) {
                printf("\n");
                break;
            }

            for (int posicao = 1; posicao < quantidadeVagoes; posicao++) {
                scanf("%d", &ordemSaida[posicao]);
            }

            pilha p;
            inicializa(&p);

            int proximoVagao = 1;
            int possivel = 1;

            for (int posicao = 0; posicao < quantidadeVagoes; posicao++) {
                while ((vazia(&p) || p.topo->item != ordemSaida[posicao]) &&
                       proximoVagao <= quantidadeVagoes) {
                    push(&p, proximoVagao);
                    proximoVagao++;
                }

                if (!vazia(&p) && p.topo->item == ordemSaida[posicao]) {
                    pop(&p);
                } else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            libera(&p);
        }
    }

    return 0;
}