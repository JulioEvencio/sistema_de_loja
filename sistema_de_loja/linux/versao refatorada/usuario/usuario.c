#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "../loja/loja.h"
#include "usuario.h"

int usuario_criar(Usuario **usuario) {
    *usuario = malloc(sizeof **usuario);

    if (*usuario == NULL) return USUARIO_SEM_MEMORIA;

    //  Code

    return USUARIO_SUCESSO;
}

int usuario_liberar(Usuario **usuario) {
    // Code
}