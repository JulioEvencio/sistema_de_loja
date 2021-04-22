#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "produto.h"
#include "loja.h"

#define LOJA_CAPITAL_INICIAL 0

struct Loja {
    float capital;
    Lista *estoque;
    //  Usuario
};

int loja_criar(Loja **loja) {
    *loja = malloc(sizeof **loja);

    if (*loja == NULL) return LOJA_SEM_MEMORIA;

    (*loja)->capital = LOJA_CAPITAL_INICIAL;
    lista_inicializar(&(*loja)->estoque);

    return LOJA_SUCESSO;
}

void loja_liberar(Loja **loja) {
    lista_liberar(&(*loja)->estoque);
    free(*loja);
}