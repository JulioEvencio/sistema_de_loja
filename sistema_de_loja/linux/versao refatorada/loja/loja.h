#ifndef LOJA_H_INCLUDED
#define LOJA_H_INCLDUED

#define LOJA_NOME_TAMANHO 21

#include "../produto/produto.h"

struct Loja {
    float capital;
    char nome[LOJA_NOME_TAMANHO];
    Produto produto;
};
typedef struct Loja Loja;

#endif