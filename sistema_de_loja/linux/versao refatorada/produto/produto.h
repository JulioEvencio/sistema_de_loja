#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

#define PRODUTO_NOME 31

struct Produto {
    int codigo;
    char nome[PRODUTO_NOME];
    float preco;
    int quantidade;
};
typedef struct Produto Produto;
typedef struct Produto Elemento;

#endif