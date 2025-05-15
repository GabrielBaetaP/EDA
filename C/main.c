#include "TABB.h"

int main() {
    TABB *arv = NULL;

    insere(&arv, 10);
    insere(&arv, 5);
    insere(&arv, 9);
    insere(&arv, 2);
    insere(&arv, 7);
    insere(&arv, 12);
    insere(&arv, 18);

    //printarArvore(arv, 0);

    int qtd = qtdArv(arv) - 1;

    int *vet = buscOrdCre(arv);

    TABB *nova = NULL;
    nova = arvore_balanceada(nova, vet, 0, qtd);

    printarArvore(nova, 1);


    return 0;
}