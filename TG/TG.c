#include "TG.h"

TLSE *remove_fim(TLSE *l) {
    if (!l) return NULL;
    if (!l->prox) {
        free(l);
        return NULL;
    }
    TLSE *ant = l;
    TLSE *atual = l->prox;
    while (atual->prox) {
        ant = atual;
        atual = atual->prox;
    }
    free(atual);
    ant->prox = NULL;
    return l;
}

void ins_fim(TLSE **l, int info) {
    if (!*l) {
        *l = (TLSE *)malloc(sizeof(TLSE));
        (*l)->info = info;
        (*l)->prox = NULL;
        return;
    }
    ins_fim(&(*l)->prox, info);
}

TG *inicializa(){
    return NULL;
}

void imprimir_viz(TVizinho *v){
    if(!v) return;
    printf(" %d", v->id_viz);
    imprimir_viz(v->prox);
}

void imprimir(TG *g){
    if(!g) return;
    printf("%d ->", g->id_vert);
    imprimir_viz(g->prim_viz);
    printf("\n");
    imprimir(g->prox);
}

void libera_viz(TVizinho *v){
    if (!v) return;
    TVizinho *aux = v->prox;
    free(v);
    libera_viz(aux);
}

void libera(TG *g) {
    if (!g) return;
    libera_viz(g->prim_viz);
    TG *aux = g->prox;
    free(g);
    libera(aux);
}

TG *busca_vert(TG *g, int vert) {
    if (!g) return NULL;
    if (g->id_vert == vert) return g;
    return busca_vert(g->prox, vert);
}

TVizinho *busca_viz(TG *g, int vert, int viz) {
    if (!g) return NULL;
    TG *v1 = busca_vert(g, vert);
    if (!v1) return NULL;
    TVizinho *aux = v1->prim_viz;
    while (aux) {
        if (aux->id_viz == viz) return aux;
        aux = aux->prox;
    }
    return NULL;
}

void insere_vert(TG **g, int id) {
    TG *novo = (TG *)malloc(sizeof(TG));
    novo->id_vert = id;
    novo->prim_viz = NULL;
    novo->prox = *g;
    *g = novo;
}

void insere_sent(TG **g, int id, int viz) {
    if (!*g) return;
    TG *vert1 = busca_vert(*g,id);
    TG *vert2 = busca_vert(*g, viz);
    if (!vert1 || !vert2) return;
    TVizinho *novo = (TVizinho *)malloc(sizeof(TVizinho));
    novo->id_viz = viz;
    novo->prox = vert1->prim_viz;
    vert1->prim_viz = novo;
}

void insere_arest_ori(TG **g, int id, int viz) {
    TVizinho *verif = busca_viz(*g, id, viz);
    if (!*g) return;
    if (!verif) insere_sent(g, id, viz);
}

void insere_arest_nori(TG **g, int vert1, int vert2){
    TVizinho *verif = busca_viz(*g, vert1, vert2);
    if (!*g) return;
    if (!verif) {
        insere_sent(g, vert1, vert2);
        insere_sent(g, vert2, vert1);
    }
}

void busca_retira(TVizinho **id, int viz) {
    if (!*id) return;
    if ((*id)->id_viz == viz) {
        TVizinho *aux = *id;
        *id = (*id)->prox;
        free(aux);
        return;
    }
    busca_retira(&(*id)->prox, viz);
}

void retira_sentido(TG **g, int vert) {
    if (!*g) return;
    busca_retira(&(*g)->prim_viz, vert);
    retira_sentido(&(*g)->prox, vert);
}

void retira_vertice(TG **g, int vert) {
    if (!*g) return;
    if ((*g)->id_vert == vert) {
        TG *aux = *g;
        *g = (*g)->prox;
        libera_viz(aux->prim_viz);
        free(aux);
        return;
    }
    retira_vertice(&(*g)->prox, vert);
}

void retira(TG **g, int vert) {
    if (!*g) return;
    retira_sentido(g, vert);
    retira_vertice(g, vert);
}

void busca_maior(TG *g, int *maior) {
    if (!g) return;
    if (g->id_vert > *maior) *maior = g->id_vert;
    busca_maior(g->prox, maior);
}

void dfs(TG *g, int id, int alvo, int *visitados, TLSE **caminho, TLSE *caminho_atual) {
    TG * atual = busca_vert(g, id);
    if (!atual) return;

    visitados[id] = 1;
    ins_fim(&caminho_atual, atual->id_vert);

    if (atual->id_vert == alvo) {
        for (TLSE *temp = caminho_atual; temp; temp = temp->prox) {
            ins_fim(caminho, temp->info);
        }
        ins_fim(caminho, -1);
    }
    else {
        for (TVizinho *viz = atual->prim_viz; viz; viz = viz->prox) {
            if (!visitados[viz->id_viz]) dfs(g, viz->id_viz, alvo, visitados, caminho, caminho_atual);
        }
    }

    visitados[atual->id_vert] = 0;
    caminho_atual = remove_fim(caminho_atual);
}

TLSE *todos_caminhos(TG *g, int ini, int fim) {
    if (!g) return NULL;

    int maior = 0;
    busca_maior(g, &maior);

    int *visitados = calloc(maior + 1, sizeof(int));
    TLSE *caminho_atual = NULL;
    TLSE *caminho = NULL;

    dfs(g, ini, fim, visitados, &caminho, caminho_atual);

    printf("\n===================================================\n");

    free(visitados);
    return caminho;
}




// int *menor_caminho(TG *g, int ini, int fim) {
//     if (!g) return;
//     TVizinho *caso1 = busca_viz(g,ini,fim);
//     if (caso1) {
//         int vet[2] = {ini, fim};
//         return vet;
//     }
//
//
// }





