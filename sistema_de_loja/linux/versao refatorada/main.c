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

        //
    } while (loop);

    loja_liberar(&loja);

    return 0;
}