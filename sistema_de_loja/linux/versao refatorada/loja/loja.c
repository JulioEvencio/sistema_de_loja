#include <stdio.h>
#include <stdlib.h>
#include "../cabecalho.h"
#include "lista.h"
#include "../produto/produto.h"
#include "loja.h"

#define LOJA_CAPITAL_INICIAL 0

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

int loja_cadastrar_produto(Loja **loja) {
    Produto produto;

    system(LIMPAR_TELA);
    puts("========CADASTRAR======== ");

    //  Gerar codigo

    printf("Nome: ");
    ler_stdin(produto.nome, PRODUTO_NOME);

    printf("Preco: ");
    produto.preco = ler_stdin(buffer, BUFFER_TAMANHO);

    produto.quantidade = 0;

    if (lista_adicionar_final(&(*loja)->estoque, &produto)) return LOJA_SEM_MEMORIA;

    puts("Cadastro realizado com sucesso!");
}