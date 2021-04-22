#ifndef LOJA_INCLUDED
#define LOJA_INCLUDED

#define LOJA_SUCESSO 0
#define LOJA_SEM_MEMORIA -1

typedef struct Loja Loja;

int loja_criar(Loja **loja);
void loja_liberar(Loja **loja);

#endif