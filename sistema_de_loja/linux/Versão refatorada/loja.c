#include <stdio.h>
#include <stdlib.h>
#include "loja.h"

#define LOJA_PRODUTO_NOME 31

struct Produto {
    int codigo;
    char nome[LOJA_PRODUTO_NOME];
    float preco;
    float preco_repor;
    int quantidade;
};
typedef struct Produto Produto;

struct Loja {
    // Lista de produtos
    // Usuario
    float capital;
};