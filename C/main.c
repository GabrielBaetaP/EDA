#include "TABB.h"

int main() {
    TABB *arv = NULL;

    insere(&arv, 10);
    insere(&arv, 5);
    insere(&arv, 15);
    insere(&arv, 2);
    insere(&arv, 7);
    insere(&arv, 12);
    insere(&arv, 18);

    printarArvore(arv, 0);

    printf("\n\n%d\n\n", qtdArv(arv));

    int * vet = buscOrdCre(arv);

    for (int i = 0; i < qtdArv(arv); i++) printf("%d ", vet[i]);



    return 0;
}