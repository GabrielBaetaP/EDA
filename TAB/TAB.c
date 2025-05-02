#include "TAB.h"

TAB *criarNo(char info){
    TAB *novo = (TAB *)malloc(sizeof(TAB));
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void printBarra(TAB *arv, int * ind){
    for (int i = 0; i < *ind; i++) printf("--");

    if (!arv) {
        printf("vazio\n");
        return;
    }

    printf("%c\n", arv->info);
    (*ind)++;
    printBarra(arv->esq, ind);
    printBarra(arv->dir, ind);
    (*ind)--;
}

TAB *busc_pre_ordem(TAB *arv, char info) {
    if (!arv) return NULL;

    if (arv->info == info) return arv;

    TAB *aux = busc_pre_ordem(arv->esq, info);
    if (aux) return aux;

    return busc_pre_ordem(arv->dir, info);
}

TAB *busc_ord_sim(TAB *arv, char info) {
    if (!arv) return NULL;

    TAB *aux = busc_ord_sim(arv->esq, info);
    if (aux) return aux;

    if (arv->info == info) return arv;

    return busc_ord_sim(arv->dir, info);
}

void aux_busc_larg(TAB *arv, char info) {
    if (!arv) return;
    printf("%c", arv->info);
}

void busc_larg(TAB *arv, char info) {
    if (!arv) return;

}



