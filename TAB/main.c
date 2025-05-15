#include "TAB.h"

int main(void){
    TAB* raiz;
    raiz = criarNoChar('A');
    raiz->esq = criarNoChar('B');
    raiz->dir = criarNoChar('C');
    raiz->esq->esq = criarNoChar('D');
    raiz->esq->dir = criarNoChar('E');
    // raiz->dir->esq = criarNoChar('F');
    // raiz->dir->dir = criarNoChar('G');

    // raiz = criarNoInt(15);
    // raiz->esq = criarNoInt(5);
    // raiz->dir = criarNoInt(30);
    // raiz->esq->esq = criarNoInt(1);
    // raiz->esq->dir = criarNoInt(10);
    // raiz->dir->esq = criarNoInt(20);
    // raiz->dir->dir = criarNoInt(40);
    // raiz->dir->dir->esq = criarNoInt(12);

    TAB *aux = espelho(raiz);
    printarArvore(raiz, 0);
    printf("============================================================\n");
    printarArvore(aux, 0);
}
