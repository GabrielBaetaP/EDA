#include <stdio.h>
#include <stdlib.h>

#ifndef TABB_H
#define TABB_H

typedef struct arvBinBusc{
    int info;
    struct arvBinBusc *esq, *dir;
}TABB;

typedef struct lse {
    int info;
    struct lse *prox;
};

#endif

void insere(TABB **arv, int elem);

TABB *buscaNo(TABB *arv, int elem);

void printarArvore(TABB *arv, int espaco);

int qtdArv(TABB *arv);

void auxVet(TABB *arv, int *vet, int *ind);

int *buscOrdCre(TABB *arv);





