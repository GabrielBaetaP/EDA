#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>

#ifndef TG_H
#define TG_H

typedef struct funcionario {
    int cod;
    char nome[50];
    double salario;
}TFunc;

typedef struct lse {
    int info;
    struct lse *prox;
}TLSE;

typedef struct vizinho{
    int id_viz;
    struct vizinho *prox;
}TVizinho;

typedef struct grafo{
    int id_vert;
    struct vizinho *prim_viz;
    struct grafo *prox;
}TG;

#endif

TG *inicializa();

void imprimir_viz(TVizinho *v);

void imprimir(TG *g);

void libera_viz(TVizinho *v);

void libera(TG *g);

TG *busca_vert(TG *g, int vert);

TVizinho *busca_viz(TG *g, int vert, int viz);

void insere_vert(TG **g, int id);

void insere_sent(TG **g, int id, int viz);

void insere_arest_ori(TG **g, int id, int viz);

void insere_arest_nori(TG **g, int vert1, int vert2);

void busca_retira(TVizinho **id, int viz);

void retira_sentido(TG **g, int vert);

void retira_vertice(TG **g, int vert);

void retira(TG **g, int vert);

TLSE *todos_caminhos(TG *g, int ini, int fim);
