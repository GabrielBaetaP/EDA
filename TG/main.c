#include "TG.h"

int tamanho_registro() {
    return sizeof(TFunc);
}

int tamanho_arq(FILE *arq) {
    fseek(arq, 0, SEEK_END);
    long tam_bytes = ftell(arq);
    rewind(arq);
    return tam_bytes / tamanho_registro();
}

void salva(TFunc *func, FILE *out) {
    fwrite(&func->cod, sizeof(int), 1, out);

    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);

    fwrite(&func->salario, sizeof(double), 1, out);
}

TFunc *leitura(FILE *in) {
    TFunc *func = (TFunc *)malloc(sizeof(TFunc));

    if (0 >= fread(&func->cod, sizeof(int), 1, in)) {
        free(func);
        return NULL;
    }

    fread(func->nome, sizeof(char), sizeof(func->nome), in);

    fread(&func->salario, sizeof(double), 1, in);

    return func;
}

TFunc *aux_busc_bin(int cod, FILE *arq, int tam, int tam_reg) {
    int inicio = 0, fim = tam - 1;
    
    while (inicio <= fim) {
        int meio = (inicio+fim)/2;

        long pos = meio * tam_reg;

        fseek(arq, pos, SEEK_SET);

        TFunc *func = leitura(arq);

        if (!func) return NULL;

        if (func->cod == cod) {
            return func;
        }

        if (func->cod < cod) {
            free(func);
            inicio = meio  + 1;
        }
        else {
            free(func);
            fim = meio - 1;
        }
    }
    return NULL;
}

TFunc *busc_bin(int cod, FILE *arq, int tam) {
    int tam_reg = tamanho_registro();
    return aux_busc_bin(cod, arq, tam, tam_reg);
}


int main(){

}