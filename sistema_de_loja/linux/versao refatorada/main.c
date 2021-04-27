#include <stdio.h>
#include "cabecalho.h"
#include "loja/loja.h"

int main(void) {
    int loop;
    Loja *loja = NULL;

    if (loja_inicializar(&loja)) {
        puts("Erro ao inicializar loja");
        return 1;
    }

    do {
        imprimir_menu(&loop);

        switch (loop) {
            case RELATORIO:
                if (loja_relatorio(&loja)) puts("Erro ao imprimir relatorio!");
                break;

            case LISTAR_PRODUTOS:
                if (loja_listar_produtos(&loja)) puts("Erro ao listar produtos!");
                break;

            case CADASTRAR_PRODUTO:
                if (loja_cadastrar_produto(&loja)) puts("Erro ao cadastrar produto!");
                break;

            case ALTERAR_PRODUTO:
                if (loja_alterar_produto(&loja)) puts("Erro ao alterar produto!");
                break;
            
            case REMOVER_PRODUTO:
                if (loja_remover_produto(&loja)) puts("Erro ao remover produto!");
                break;

            case VENDER_PRODUTO:
                if (loja_vender_produto(&loja)) puts("Erro ao vender produto!");
                break;

            case REPOR_PRODUTO:
                if (loja_repor_produto(&loja)) puts("Erro ao repor produto!");
                break;

            case SAIR:
                puts("Obrigado por usar este programa!");
                break;

            default:
                puts("Opcao invalida!");
        }

        pausar_tela();
    } while (loop);

    loja_liberar(&loja);

    return 0;
}