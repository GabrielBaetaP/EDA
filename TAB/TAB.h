#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TAB_H
#define TAB_H

typedef struct arvBin{
    int info;
    struct arvBin *esq;
    struct arvBin *dir;
}TAB;

typedef struct fila {
    TAB *no;
    struct fila *prox;
}TF;

#endif

TF *inicializar();

TF *push(TF *l, TAB *arv);

TF* pop(TF *l, TAB **arv);

TAB *criarNoChar(char info);

TAB *criarNoInt(int info);

void printBarra(TAB *arv, int *ind);

TAB *busc_pre_ordem(TAB *arv, char info);

TAB *busc_ord_sim(TAB *arv, char info);

TAB *busc_larg(TAB *arv, int info);

TAB *busc_pos_ord(TAB *arv, char info);

void aux_nivel(TAB *arv, int * maior, int *indice);

int qtd_nivel(TAB *arv);

int est_bin(TAB *arv);

void aux_bin_com(TAB *arv, int qtd, int * indice, int * verif);

int bin_com(TAB *arv);

void aux_bin_che(TAB *arv, int qtd, int *indice, int *verif);

int bin_che(TAB *arv);

int altura(TAB *arv);

int qtd_elem(TAB *arv);

void elem_nivel(TAB *arv, int *aux);

void preencher_vet_aux(TAB *arv, int *vet, int * indice);

void preencher_matriz(TAB *arv, int **mat, int *vet, int *vet_val, int qtd);

int **matriz(TAB *arv);

void printarArvore(TAB *arv, int espaco);

TAB *espelho(TAB *arv);



