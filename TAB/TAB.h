#include <stdio.h>
#include <stdlib.h>

#ifndef TAB_H
#define TAB_H

typedef struct arvBin{
    char info;
    struct arvBin *esq;
    struct arvBin *dir;
}TAB;

#endif

TAB *criarNo(char info);

void printBarra(TAB *arv, int *ind);

TAB *busc_pre_ordem(TAB *arv, char info);

TAB *busc_ord_sim(TAB *arv, char info);

void busc_larg(TAB *arv, char info);

