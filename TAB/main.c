#include "TAB.h"

int main(void){
    TAB* raiz;
    raiz = criarNo('A');
    raiz->esq = criarNo('B');
    raiz->dir = criarNo('C');
    raiz->esq->esq = criarNo('D');
    raiz->esq->dir = criarNo('E');
    raiz->dir->esq = criarNo('F');
    raiz->dir->dir = criarNo('G');
    int ind = 0;
    printBarra(raiz,&ind);
    TAB *ajuda = busc_ord_sim(raiz, 'D');
    //TAB *aux = busc_pre_ordem(raiz, 'B');
    printf("%c", ajuda->info);
};
