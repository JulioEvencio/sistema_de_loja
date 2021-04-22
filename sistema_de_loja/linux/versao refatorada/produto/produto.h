#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

#define PRODUTO_NOME_TAMANHO 31

struct Produto {
    int codigo;
    char nome[PRODUTO_NOME_TAMANHO];
    float preco;
    int quantidade;
};
typedef struct Produto Produto;

#endif