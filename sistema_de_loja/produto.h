#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

/*  Constantes */
#define PRODUTO_QUANTIDADE 100
#define PRODUTO_NOME 50

/*  Variaveis */

/*  Structs */
struct tipo_produto
{
    int codigo;
    char nome[PRODUTO_NOME];
    float preco;
    float preco_repor;
    int quantidade;
};
typedef struct tipo_produto Produto;

/*  Funcoes */

#endif // PRODUTO_H_INCLUDED