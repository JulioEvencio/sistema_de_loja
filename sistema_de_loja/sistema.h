#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

//  Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Constantes */

/*  Variaveis */
int variavel_codigo;
int tamanho_nome;
char informacao1[100];
char informacao2[100];
Usuario usuario;
Produto produto[100];
Historico historico[100];

/*  Structs */

/*  Funcoes */
//  Menu
void printar_menu(void);
void leitura_da_opcao(int op);
//  Formatacao
void confirmar_formatacao(void);
void formatar_lista(void);
//  Login
void menu_login(void);

#endif // SISTEMA_H_INCLUDED