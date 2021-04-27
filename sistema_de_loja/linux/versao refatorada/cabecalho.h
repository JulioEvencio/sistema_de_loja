#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

#include "loja/loja.h"

#define BUFFER_TAMANHO 51
#define LIMPAR_TELA "clear || cls"

char buffer[BUFFER_TAMANHO];

enum Menu {
    SAIR,
    RELATORIO,
    LISTAR_PRODUTOS,
    CADASTRAR_PRODUTO,
    ALTERAR_PRODUTO,
    REMOVER_PRODUTO,
    VENDER_PRODUTO,
    REPOR_PRODUTO
};

void pausar_tela(void);
float ler_stdin(char *nome, int tamanho);
int imprimir_menu(int *opcao);

#endif
