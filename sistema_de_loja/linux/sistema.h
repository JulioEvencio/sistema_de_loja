#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

//  Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "produto.h"
#include "historico.h"

/*  Constantes */
#define VARIAVEIL_CODIGO 0
#define INFORMACAO_TAMANHO 100

/*  Variaveis */
int variavel_codigo;
int tamanho_nome;
char informacao1[INFORMACAO_TAMANHO];
char informacao2[INFORMACAO_TAMANHO];
Usuario usuario;
Produto produto[PRODUTO_QUANTIDADE];
Historico historico[HISTORICO_CAPACIDADE];

/*  Structs */
//  Menu principal
enum menu_principal
{
    sair_login = -1,
    fechar_loja,
    login,
    registrar,
    opcao_invalida
};
//  Menu da loja
enum menu_loja
{
    fechar_loja,
    cadastrar,
    localizar,
    listar,
    alterar,
    excluir,
    vender,
    repor,
    historico_printar,
    formatar
};
//  Formatar lista
enum menu_formatar
{
    cancelar_formatacao,
    formatar_confirmar= 34851
};

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