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

    printarArvore(arv, 0);

    printf("\n================================================\n");

    remover(&arv, 18);

    printarArvore(arv, 0);

    printf("\n================================================\n");

    remover(&arv, 5);

    printarArvore(arv, 0);

    printf("\n================================================\n");

    return 0;
}