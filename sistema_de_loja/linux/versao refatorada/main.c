#include <stdio.h>
#include "loja/loja.h"

int main(void) {
    Loja *loja;

    if (loja_criar(&loja)) return -1;

    loja_liberar(&loja);

    return 0;
}