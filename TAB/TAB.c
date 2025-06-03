#include "TAB.h"

TF *inicializar() {
    return NULL;
}

TF* push(TF *f, TAB *arv) {
    TF *novo = (TF *)malloc(sizeof(TF));
    if (!novo) return f;
    novo->no = arv;
    novo->prox = NULL;

    if (!f) return novo;

    TF *aux = f;
    while (aux->prox) aux = aux->prox;
    aux->prox = novo;
    return f;
}

TF* pop(TF *f, TAB **arv) {
    if (!f) return NULL;

    *arv = f->no;
    TF *temp = f;
    f = f->prox;
    free(temp);
    return f;
}

TAB *criarNoChar(char info){
    TAB *novo = (TAB *)malloc(sizeof(TAB));
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

TAB *criarNoInt(int info){
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

TAB *busc_larg(TAB *arv, int info) {
    if (!arv) return NULL;
    TF *f = inicializar();
    f = push(f, arv);
    while (f) {
        TAB *tmp;
        f = pop(f,&tmp);
        if (tmp -> info == info) return tmp;
        if (arv->esq) f = push(f, tmp->esq);
        if (arv->dir) f = push(f, tmp->dir);
    }
    return NULL;
}

TAB *busc_pos_ord(TAB *arv, char info) {
    if (!arv) return NULL   ;

    busc_pos_ord(arv->esq, info);
    busc_pos_ord(arv->dir, info);

    if (arv->info == info) return arv;
}

void aux_nivel(TAB *arv, int * maior, int *indice) {
    if (!arv) return;
    if (*indice > *maior) *maior = *indice;
    (*indice)++;
    aux_nivel(arv->esq, maior, indice);
    aux_nivel(arv->dir, maior, indice);
    (*indice)--;
}

int qtd_nivel(TAB *arv){
    if (!arv) return 0;
    int maior = 0, indice = 0;
    aux_nivel(arv, &maior, &indice);
    return maior;
}

int est_bin(TAB *arv) {
    if (!arv) return 1;
    if ((arv->esq && arv->dir) || (!arv->esq && !arv->dir)) return est_bin(arv->esq) && est_bin(arv->dir);
    return 0;
}

void aux_bin_com(TAB *arv, int qtd, int * indice, int * verif) {
    if (!arv) return;
    if (*indice < qtd-1){
        if (!arv->esq && !arv->dir) (*verif)++;
        (*indice)++;
        aux_bin_com(arv->esq, qtd, indice, verif);
        aux_bin_com(arv->dir, qtd, indice, verif);
        (*indice)--;
    }
}

int bin_com(TAB *arv) {
    if (!arv) return 0;
    int qtd = qtd_nivel(arv), indice = 0, verif = 0, aux = est_bin(arv);
    aux_bin_com(arv, qtd, &indice, &verif);
    return aux != 0 ? aux : verif;
}

void aux_bin_che(TAB *arv, int qtd, int *indice, int *verif) {
    if (!arv) return;
    if (*indice == qtd-1){
        if (!(arv->esq && arv->dir)) (*verif)++;
    }
    (*indice)++;
    aux_bin_che(arv->esq, qtd, indice, verif);
    aux_bin_che(arv->dir, qtd, indice, verif);
    (*indice)--;
}

int bin_che(TAB *arv) {
    if (!arv) return 0;
    int qtd = qtd_nivel(arv), indice = 0, verif = 0, aux = est_bin(arv);
    aux_bin_che(arv, qtd, &indice, &verif);
    return aux != 0 ? aux : verif;
}

int zz(TAB *arv) {
    if (!arv) return 1;
    if (!arv->esq && !arv->dir) return 1;
    if ((arv->esq && !arv->dir) || (!arv->esq && arv->dir)) return zz(arv->esq) && zz(arv->dir);
    return 0;
}

int altura(TAB *arv) {
    if (!arv) return -1;
    int esq = altura(arv->esq);
    int dir = altura(arv->dir);
    return esq > dir ? 1 + esq : 1 + dir;
}

int qtd_elem(TAB *arv) {
    if (!arv) return 0;
    return 1 + qtd_elem(arv->esq) + qtd_elem(arv->dir);
}

void elem_nivel(TAB *arv, int *aux) {
    if (!arv) return;
    TF *f = inicializar();
    int cont = 0;
    f = push(f, arv);
    while (f) {
        TAB *tmp;
        f = pop(f, &tmp);
        aux[cont] = tmp->info;
        if (tmp->esq) f = push(f, tmp->esq);
        if (tmp->dir) f = push(f, tmp->dir);
        cont++;
    }
}

void preencher_vet_aux(TAB *arv, int *vet, int * indice) {
    if (!arv || !vet) return;
    vet[*indice]++;
    (*indice)++;
    preencher_vet_aux(arv->esq, vet, indice);
    preencher_vet_aux(arv->dir, vet, indice);
    (*indice)--;
}

// void preencher_vet_aux(TAB *arv, int *vet, int nivel) {
//     if (!arv || !vet) return;
//     vet[nivel]++;
//     preencher_vet_aux(arv->esq, vet, nivel+1);
//     preencher_vet_aux(arv->dir, vet, nivel+1);
// }

void preencher_matriz(int **mat, int *vet, int *vet_val, int qtd) {
    if (!mat || !vet || !vet_val) return;
    int cont = 0;
    for (int i = 0; i < qtd; i++) {
        for (int j = 0; j < vet[i]; j++) {
            mat[i][j] = vet_val[cont++];
        }
    }
}

int **matriz(TAB *arv) {
    if (!arv) return NULL;
    int alt = altura(arv) + 1, indice = 0;
    int **mat = malloc(alt*sizeof(int*));
    int *vet_aux = calloc(alt, sizeof(int));
    preencher_vet_aux(arv, vet_aux, &indice);

    for (int i = 0; i < alt; i++) {
        mat[i] = malloc(vet_aux[i] * sizeof(int));
    }

    int *vet_val = calloc(qtd_elem(arv),sizeof(int));
    elem_nivel(arv, vet_val);
    preencher_matriz(mat, vet_aux, vet_val, alt);

    for (int i = 0; i < alt; i++) {
        for (int j = 0; j < vet_aux[i]; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return mat;
}

void printarArvore(TAB *arv, int espaco){
    if(!arv) return;

    int incremento = 10;
    espaco += incremento;

    printarArvore(arv->dir, espaco);
    for(int i = 0; i<espaco; i++) printf(" ");
    printf("%c\n", arv->info);

    printarArvore(arv->esq, espaco);
}

TAB *espelho(TAB *arv) {
    if (!arv) return;
    TAB *res = (TAB *)malloc(sizeof(TAB));
    res->info = arv->info;
    res->esq, res->dir = NULL;
    res->dir = espelho(arv->esq);
    res->esq = espelho(arv->dir);
    return res;
}






