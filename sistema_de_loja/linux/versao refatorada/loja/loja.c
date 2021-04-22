#include <stdio.h>
#include <stdlib.h>
#include "../cabecalho.h"
#include "loja.h"
#include "estoque.h"

#define LOJA_CAPITAL_INICIAL 0

struct Loja {
    float capital;
    char nome[LOJA_NOME_TAMANHO];
    Estoque *estoque;
};

int loja_inicializar(Loja **loja) {
    *loja = malloc(sizeof **loja);

    if (*loja == NULL) return LOJA_SEM_MEMORIA;

    (*loja)->capital = LOJA_CAPITAL_INICIAL;
    
    printf("Nome da loja: ");
    ler_stdin((*loja)->nome, LOJA_NOME_TAMANHO);

    estoque_inicializar(&(*loja)->estoque);

    return LOJA_SUCESSO;
}

void loja_liberar(Loja **loja) {
    estoque_liberar(&(*loja)->estoque);
    free(*loja);
}