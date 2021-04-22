#ifndef ESTOQUE_H_INCLUDED
#define ESTOQUE_H_INCLUDED

#define ESTOQUE_SUCESSO 0
#define ESTOQUE_SEM_MEMORIA -1
#define ESTOQUE_VAZIO -2
#define ESTOQUE_POSICAO_INEXISTENTE -3

#define ESTOQUE_PRODUTO_NOME 31

struct Produto {
    int codigo;
    char nome[ESTOQUE_PRODUTO_NOME];
    float preco;
    int quantidade;
};
typedef struct Produto Produto;

typedef struct Estoque Estoque;

void estoque_inicializar(Estoque **estoque);
void estoque_liberar(Estoque **estoque);

int estoque_tamanho(Estoque **estoque);
int estoque_vazio(Estoque **estoque);

int estoque_adicionar_inicio(Estoque **estoque, Produto *produto);
int estoque_adicionar_posicao(Estoque **estoque, Produto *produto, int posicao);
int estoque_adicionar_final(Estoque **estoque, Produto *produto);

int estoque_remover_inicio(Estoque **estoque);
int estoque_remover_posicao(Estoque **estoque, int posicao);
int estoque_remover_final(Estoque **estoque);

int estoque_alterar_inicio(Estoque **estoque, Produto *produto);
int estoque_alterar_posicao(Estoque **estoque, Produto *produto, int posicao);
int estoque_alterar_final(Estoque **estoque, Produto *produto);

int estoque_obter_inicio(Estoque **estoque, Produto *produto);
int estoque_obter_posicao(Estoque **estoque, Produto *produto, int posicao);
int estoque_obter_final(Estoque **estoque, Produto *produto);

#endif