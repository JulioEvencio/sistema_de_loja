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
    
    system(LIMPAR_TELA);
    puts("======== Inicializando Loja ========");
    
    printf("Nome da loja: ");
    ler_stdin((*loja)->nome, LOJA_NOME_TAMANHO);

    estoque_inicializar(&(*loja)->estoque);

    return LOJA_SUCESSO;
}

void loja_liberar(Loja **loja) {
    estoque_liberar(&(*loja)->estoque);
    free(*loja);
}

int loja_cadastrar_produto(Loja **loja) {
    Produto produto;

    system(LIMPAR_TELA);
    puts("======== Cadastrar Produto ========");

    printf("Codigo: ");
    produto.codigo = (int) ler_stdin(buffer, BUFFER_TAMANHO);

    if (produto.codigo == -1) {
        puts("Codigo invalido!");
        return LOJA_CODIGO_INVALIDO;
    }

    printf("Nome: ");
    ler_stdin(produto.nome, ESTOQUE_PRODUTO_NOME);

    printf("Preco: ");
    produto.preco = ler_stdin(buffer, BUFFER_TAMANHO);

    produto.quantidade = 0;

    if (estoque_adicionar_final(&(*loja)->estoque, &produto)) {
        return LOJA_SEM_MEMORIA;
    }

    puts("Produto cadastrado com sucesso!");

    return LOJA_SUCESSO;
}