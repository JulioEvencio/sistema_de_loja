#include <stdlib.h>
#include "estoque.h"

#define ESTOQUE_INICIO 1

typedef struct Estoque Nodo;
struct Estoque {
    Produto produto;
    Nodo *proximo;
};

void estoque_inicializar(Estoque **estoque) {
    *estoque = NULL;
}

void estoque_liberar(Estoque **estoque) {
    Nodo *nodo = NULL;

    while (*estoque != NULL) {
        nodo = *estoque;
        *estoque = (*estoque)->proximo;
        free(nodo);
    }
}

int estoque_tamanho(Estoque **estoque) {
    int tamanho = 0;
    Nodo *nodo = *estoque;

    while (nodo != NULL) {
        nodo = nodo->proximo;
        tamanho++;
    }

    return tamanho;
}

int estoque_vazio(Estoque **estoque) {
    return *estoque == NULL;
}

int estoque_adicionar_inicio(Estoque **estoque, Produto *produto) {
    Nodo *nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return ESTOQUE_SEM_MEMORIA;

    nodo->produto = *produto;
    nodo->proximo = *estoque;
    *estoque = nodo;

    return ESTOQUE_SUCESSO;
}

int estoque_adicionar_posicao(Estoque **estoque, Produto *produto, int posicao) {
    Nodo *nodo = NULL;

    if (posicao < ESTOQUE_INICIO || posicao > estoque_tamanho(estoque)) {
        return ESTOQUE_POSICAO_INEXISTENTE;
    }

    nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return ESTOQUE_SEM_MEMORIA;

    nodo->produto = *produto;

    if (posicao == ESTOQUE_INICIO) {
        nodo->proximo = *estoque;
        *estoque = nodo;
    } else {
        Nodo *nodo_anterior = NULL, *nodo_atual = *estoque;

        for (int i = ESTOQUE_INICIO; i <= posicao; i++) {
            nodo_anterior = nodo_atual;
            nodo_atual = nodo_atual->proximo;
        }

        nodo_anterior->proximo = nodo;
        nodo->proximo = nodo_atual;
    }

    return ESTOQUE_SUCESSO;
}

int estoque_adicionar_final(Estoque **estoque, Produto *produto) {
    Nodo *nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return ESTOQUE_SEM_MEMORIA;

    nodo->produto = *produto;

    if (*estoque == NULL) {
        nodo->proximo = *estoque;
        *estoque = nodo;
    } else {
        Nodo *auxiliar = *estoque;

        while (auxiliar->proximo != NULL) {
            auxiliar = auxiliar->proximo;
        }

        nodo->proximo = auxiliar->proximo;
        auxiliar->proximo = nodo;
    }

    return ESTOQUE_SUCESSO;
}

int estoque_remover_inicio(Estoque **estoque) {
    Nodo *nodo = *estoque;

    if (nodo == NULL) return estoque_vazio;

    *estoque = (*estoque)->proximo;
    free(nodo);

    return ESTOQUE_SUCESSO;
}

int estoque_remover_posicao(Estoque **estoque, int posicao) {
    Nodo *nodo = *estoque;

    if (nodo == NULL) return estoque_vazio;

    if (posicao < ESTOQUE_INICIO || posicao > estoque_tamanho(estoque)) {
        return ESTOQUE_POSICAO_INEXISTENTE;
    }

    if (posicao == ESTOQUE_INICIO) {
        *estoque = (*estoque)->proximo;
        free(nodo);
    } else {
        Nodo *auxiliar = NULL;

        for (int i = ESTOQUE_INICIO; i <= posicao; i++) {
            auxiliar = nodo;
            nodo = nodo->proximo;
        }

        auxiliar->proximo = nodo->proximo;
        free(nodo);
    }

    return ESTOQUE_SUCESSO;
}

int estoque_remover_final(Estoque **estoque) {
    Nodo *nodo = *estoque;

    if (nodo == NULL) estoque_vazio;

    if ((*estoque)->proximo == NULL) {
        *estoque = (*estoque)->proximo;
        free(nodo);
    } else {
        Nodo *auxiliar = NULL;

        while (nodo->proximo != NULL) {
            auxiliar = nodo;
            nodo = nodo->proximo;
        }

        auxiliar->proximo = nodo->proximo;
        free(nodo);
    }

    return ESTOQUE_SUCESSO;
}

int estoque_alterar_inicio(Estoque **estoque, Produto *produto) {
    if (*estoque == NULL) return estoque_vazio;

    (*estoque)->produto = *produto;

    return ESTOQUE_SUCESSO;
}

int estoque_alterar_posicao(Estoque **estoque, Produto *produto, int posicao) {
    Nodo *nodo = *estoque;

    if (nodo == NULL) return estoque_vazio;

    if (posicao < ESTOQUE_INICIO || posicao > estoque_tamanho(estoque)) {
        return ESTOQUE_POSICAO_INEXISTENTE;
    }

    for (int i = ESTOQUE_INICIO; i <= posicao; i++) {
        nodo = nodo->proximo;
    }

    nodo->produto = *produto;

    return ESTOQUE_SUCESSO;
}

int estoque_alterar_final(Estoque **estoque, Produto *produto) {
    Nodo *nodo = *estoque;

    if (nodo == NULL) return estoque_vazio;

    while (nodo->proximo != NULL) {
        nodo = nodo->proximo;
    }

    nodo->produto = *produto;

    return ESTOQUE_SUCESSO;
}

int estoque_obter_inicio(Estoque **estoque, Produto *produto) {
    if (*estoque == NULL) return estoque_vazio;

    *produto = (*estoque)->produto;

    return ESTOQUE_SUCESSO;
}

int estoque_obter_posicao(Estoque **estoque, Produto *produto, int posicao) {
    Nodo *nodo = *estoque;

    if (nodo == NULL) return estoque_vazio;

    if (posicao < ESTOQUE_INICIO || posicao > estoque_tamanho(estoque)) {
        return ESTOQUE_POSICAO_INEXISTENTE;
    }

    for (int i = ESTOQUE_INICIO; i <= posicao; i++) {
        nodo = nodo->proximo;
    }

    *produto = nodo->produto;

    return ESTOQUE_SUCESSO;
}

int estoque_obter_final(Estoque **estoque, Produto *produto) {
    Nodo *nodo = *estoque;

    if (nodo == NULL) return estoque_vazio;

    while (nodo->proximo != NULL) {
        nodo = nodo->proximo;
    }

    *produto = nodo->produto;

    return ESTOQUE_SUCESSO;
}