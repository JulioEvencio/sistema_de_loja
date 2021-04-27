#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"
#include "loja/loja.h"

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

int imprimir_menu(int *opcao) {
	system(LIMPAR_TELA);
    puts("======== Menu ========");

    puts("1. Listar Produtos");
    puts("2. Cadastrar Produto");
    puts("3. Alterar Produto");
    puts("4. Remover Produto");
    puts("5. Vender Produto");
    puts("6. Repor Produto");
    puts("0. Sair");

    *opcao = (int) ler_stdin(buffer, BUFFER_TAMANHO);

	return 0;
}
