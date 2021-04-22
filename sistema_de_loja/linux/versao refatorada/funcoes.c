#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

void pausar_tela(void) {
    char letra;

    printf("Digite enter para continuar...");

    while ((letra = getchar()) != '\n');
}

float ler_stdin(char *nome, int tamanho) {
    int i = 0, tem_letra = 0;
    char letra;

    while ((letra = getchar()) != '\n') {
        if (letra != '\n' && i < tamanho - 1) {
            if ((letra < '0' || letra > '9') && letra != '.') tem_letra = 1;
            *(nome + i) = letra;
            i++;
        }
    }

    *(nome + i) = '\0';

    if (tem_letra) return -1;

    return atof(nome);
}