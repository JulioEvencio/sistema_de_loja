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

int loja_relatorio(Loja **loja) {
    if (*loja == NULL) return -1;
    
    system(LIMPAR_TELA);
    puts("======== Relatorio ========");

    printf("Nome da loja: %s \n", (*loja)->nome);
    printf("Capital: %.2f \n", (*loja)->capital);

    return 0;
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
    produto.preco = (float) ler_stdin(buffer, BUFFER_TAMANHO);

    produto.quantidade = 0;

    if (estoque_adicionar_final(&(*loja)->estoque, &produto)) {
        return LOJA_SEM_MEMORIA;
    }

    puts("Produto cadastrado com sucesso!");

    return LOJA_SUCESSO;
}

int loja_listar_produtos(Loja **loja) {
    system(LIMPAR_TELA);
    puts("======== Listar Produtos ========");

    if (estoque_vazio(&(*loja)->estoque)) {
        puts("Estoque vazio!");
    } else {
        int erro;
        int tamanho = estoque_tamanho(&(*loja)->estoque);
        Produto produto;

        for (int i = 1; i <= tamanho; i++) {
            erro = estoque_obter_posicao(&(*loja)->estoque, &produto, i);

            if (erro == ESTOQUE_POSICAO_INEXISTENTE) {
                puts("Posicao nao existe");
                pausar_tela();
            }

            puts("=================================");
            printf("Codigo: %d \n", produto.codigo);
            printf("Nome: %s \n", produto.nome);
            printf("Preco: %.2f \n", produto.preco);
            printf("Quantidade: %d \n", produto.quantidade);
            puts("=================================");
        }
    }

    return LOJA_SUCESSO;
}

int loja_alterar_produto(Loja **loja) {
    system(LIMPAR_TELA);
    puts("======== Alterar Produto ========");

    if (estoque_vazio(&(*loja)->estoque)) {
        puts("Estoque vazio!");
    } else {
        int codigo;
        int tamanho = estoque_tamanho(&(*loja)->estoque);
        Produto produto;

        printf("Codigo: ");
        codigo = (int) ler_stdin(buffer, BUFFER_TAMANHO);

        for (int i = 1; i <= tamanho; i++) {
            if (estoque_obter_posicao(&(*loja)->estoque, &produto, i)) return -1;

            if (codigo == produto.codigo) {
                printf("Novo nome: ");
                ler_stdin(produto.nome, ESTOQUE_PRODUTO_NOME);

                printf("Novo preco: ");
                produto.preco = (float) ler_stdin(buffer, BUFFER_TAMANHO);

                if (estoque_alterar_posicao(&(*loja)->estoque, &produto, i)) return -1;

                puts("Produto alterado com sucesso!");
                return LOJA_SUCESSO;
            }
        }

        puts("Produto nao encontrado");
    }

    return LOJA_SUCESSO;
}

int loja_remover_produto(Loja **loja) {
    system(LIMPAR_TELA);
    puts("======== Remover Produto ========");

    if (estoque_vazio(&(*loja)->estoque)) {
        puts("Estoque vazio!");
    } else {
        int codigo;
        int tamanho = estoque_tamanho(&(*loja)->estoque);
        Produto produto;

        printf("Codigo: ");
        codigo = (int) ler_stdin(buffer, BUFFER_TAMANHO);

        for (int i = 1; i <= tamanho; i++) {
            if (estoque_obter_posicao(&(*loja)->estoque, &produto, i)) return -1;

            if (codigo == produto.codigo) {
                if (estoque_remover_posicao(&(*loja)->estoque, i)) return -1;

                puts("Produto removido com sucesso!");
                return LOJA_SUCESSO;
            }
        }

        puts("Produto nao encontrado");
    }

    return LOJA_SUCESSO;
}

int loja_vender_produto(Loja **loja) {
    system(LIMPAR_TELA);
    puts("======== Vender Produto ========");

    if (estoque_vazio(&(*loja)->estoque)) {
        puts("Estoque vazio!");
    } else {
        int codigo;
        int tamanho = estoque_tamanho(&(*loja)->estoque);
        Produto produto;

        printf("Codigo: ");
        codigo = (int) ler_stdin(buffer, BUFFER_TAMANHO);

        for (int i = 1; i <= tamanho; i++) {
            if (estoque_obter_posicao(&(*loja)->estoque, &produto, i)) return -1;

            if (codigo == produto.codigo) {
                int quantidade;

                printf("Quantidade: ");
                quantidade = (int) ler_stdin(buffer, BUFFER_TAMANHO);

                if (quantidade > 0 && quantidade <= produto.quantidade) {
                    produto.quantidade -= quantidade;

                    if (estoque_alterar_posicao(&(*loja)->estoque, &produto, i)) return -1;

                    (*loja)->capital += quantidade * produto.preco;

                    puts("Produto vendido com sucesso!");

                    return LOJA_SUCESSO;
                } else {
                    puts("Quantidade invalida!");
                    return -1;
                }
            }
        }

        puts("Produto nao encontrado");
    }

    return LOJA_SUCESSO;
}

int loja_repor_produto(Loja **loja) {
    system(LIMPAR_TELA);
    puts("======== Repor Produto ========");

    if (estoque_vazio(&(*loja)->estoque)) {
        puts("Estoque vazio!");
    } else {
        int codigo;
        int tamanho = estoque_tamanho(&(*loja)->estoque);
        Produto produto;

        printf("Codigo: ");
        codigo = (int) ler_stdin(buffer, BUFFER_TAMANHO);

        for (int i = 1; i <= tamanho; i++) {
            if (estoque_obter_posicao(&(*loja)->estoque, &produto, i)) return -1;

            if (codigo == produto.codigo) {
                int quantidade;

                printf("Quantidade: ");
                quantidade = (int) ler_stdin(buffer, BUFFER_TAMANHO);

                if (quantidade > 0) {
                    produto.quantidade += quantidade;

                    if (estoque_alterar_posicao(&(*loja)->estoque, &produto, i)) return -1;

                    puts("Produto sucesso ao repor produto!");

                    return LOJA_SUCESSO;
                } else {
                    puts("Quantidade invalida!");
                    return -1;
                }
            }
        }

        puts("Produto nao encontrado");
    }

    return LOJA_SUCESSO;
}