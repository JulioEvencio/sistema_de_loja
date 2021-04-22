#ifndef LOJA_H_INCLUDED
#define LOJA_H_INCLDUED

#define LOJA_SUCESSO 0
#define LOJA_SEM_MEMORIA -1

#define LOJA_NOME_TAMANHO 21

typedef struct Loja Loja;

int loja_inicializar(Loja **loja);
void loja_liberar(Loja **loja);

#endif