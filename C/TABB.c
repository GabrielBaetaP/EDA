#include "TABB.h"

void insere(TABB **arv, int elem){
    if(!*arv){
        *arv = (TABB *)malloc(sizeof(TABB));
        (*arv)->info = elem;
        (*arv)->esq = NULL;
        (*arv)->dir = NULL;
        return;
    }
    if((*arv)->info > elem){
        return insere(&(*arv)->esq, elem);
    }
    return insere(&(*arv)->dir, elem);
}

TABB *buscaNo(TABB *arv, int elem){
     if(!arv) return NULL;
     else if(arv->info == elem) return arv;
     else if(arv->info < elem) return buscaNo(arv->esq, elem);
     return buscaNo(arv->dir, elem);
}

void printarArvore(TABB *arv, int espaco){
    if(!arv) return;

    int incremento = 10;
    espaco += incremento;

    printarArvore(arv->dir, espaco);
    for(int i = 0; i<espaco; i++) printf(" ");
    printf("%d\n", arv->info);

    printarArvore(arv->esq, espaco);
}

int qtdArv(TABB *arv) {
    if (!arv) return 0;
    return 1 + qtdArv(arv->esq) + qtdArv(arv->dir);
}

void auxVet(TABB *arv, int *vet, int *ind) {
    if (!arv) return;
    auxVet(arv->esq, vet, ind);
    vet[(*ind)++] = arv->info;
    auxVet(arv->dir, vet, ind);
}

int *buscOrdCre(TABB *arv) {
    if (!arv) return NULL;
    int *vet = malloc(sizeof(int)*qtdArv(arv));
    int indice = 0;
    auxVet(arv, vet, &indice);
    return vet;
}

TABB *arvore_balanceada(TABB *arv, int vet[], int ini, int fim){
	if(ini <= fim){
    	int meio = (ini+fim)/2;
        insere(&arv, vet[meio]);
        arvore_balanceada(arv,vet,ini,meio-1);
        arvore_balanceada(arv,vet,meio+1,fim);
    }
    return arv;
}














