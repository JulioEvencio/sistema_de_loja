#include <stdio.h>
#include "cabecalho.h"
#include "loja/loja.h"

int main(void) {
    Loja *loja = NULL;;

    if (loja_inicializar(&loja)) return 1;
    pausar_tela();

    if (loja_cadastrar_produto(&loja)) {
        puts("Erro ao adicionar produto!");
    }
    pausar_tela();

    if (loja_repor_produto(&loja)) {
        puts("Erro ao repor produto!");
    }
    pausar_tela();

    if (loja_vender_produto(&loja)) {
        puts("Erro ao vender produto!");
    }
    pausar_tela();

    if (loja_listar_produtos(&loja)) return 2;;

    loja_liberar(&loja);

    puts("Programa funcionou com sucesso");

    return 0;
}