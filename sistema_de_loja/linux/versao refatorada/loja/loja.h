#ifndef LOJA_INCLUDED
#define LOJA_INCLUDED

#define LOJA_SUCESSO 0
#define LOJA_SEM_MEMORIA -1

struct Loja {
    float capital;
    Lista *estoque;
};
typedef struct Loja Loja;
typedef struct Loja Elemento;

int loja_criar(Loja **loja);
void loja_liberar(Loja **loja);

int loja_cadastrar_produto(Loja **loja);

#endif