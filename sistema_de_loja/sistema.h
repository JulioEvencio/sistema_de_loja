#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

/*  Constantes */
//  Produto
#define PRODUTO_QUANTIDADE 100
//  PROGRAMA
#define NOME_TAMANHO 100
#define USUARIO_CAPACIDADE 3

/*  Variaveis */

/*  Structs */
//  Usuario
struct tipo_usuario
{
    char nome[NOME_TAMANHO];
    char login[NOME_TAMANHO];
    char senha[NOME_TAMANHO];
};
typedef struct tipo_usuario Usuario;
Usuario usuario[USUARIO_CAPACIDADE];
//  Produto
struct tipo_produto
{
    int codigo;
    char nome[NOME_TAMANHO];
    float preco;
    float preco_repor;
    int quantidade;
};
typedef struct tipo_produto Produto;
Produto produto[PRODUTO_QUANTIDADE];
//  Historico
typedef struct Tipo_historico
{
    char descricao[NOME_TAMANHO];
    Produto login;
}Historico;
Historico historico;

/*  Funcoes */

#endif // SISTEMA_H_INCLUDED