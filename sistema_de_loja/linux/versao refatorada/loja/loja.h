#ifndef LOJA_H_INCLUDED
#define LOJA_H_INCLDUED

#define LOJA_SUCESSO 0
#define LOJA_SEM_MEMORIA -1
#define LOJA_CODIGO_INVALIDO -2

#define LOJA_NOME_TAMANHO 21

typedef struct Loja Loja;

int loja_inicializar(Loja **loja);
void loja_liberar(Loja **loja);
int loja_cadastrar_produto(Loja **loja);
int loja_listar_produtos(Loja **loja);
int loja_alterar_produto(Loja **loja);
int loja_remover_produto(Loja **loja);
int loja_vender_produto(Loja **loja);

#endif