#include <stdio.h>
#include "loja/loja.h"

int main(void) {
    Loja *loja = NULL;;

    if (loja_inicializar(&loja)) return 1;

    loja_liberar(&loja);

    return 0;
}