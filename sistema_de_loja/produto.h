#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

/*  Constantes */
#define PRODUTO_QUANTIDADE 100
#define PRODUTO_NOME 50

/*  Variaveis */

/*  Structs */
struct tipo_produto
{
    int codigo;
    char nome[PRODUTO_NOME];
    float preco;
    float preco_repor;
    int quantidade;
};
typedef struct tipo_produto Produto;

/*  Funcoes */
int verificador_de_local_vazio(void);
int gerador_de_codigo(void);
int verificador_de_produto(void);
void cadastrar_produto(int posicao);
void localizar_produto(int posicao);
void listar_produto(void);
void alterar_produto(int codigo);
void excluir_produto(int codigo);
void vender_produto(int codigo);
void repor_produto(int codigo);
void vender_produto_a_vista(int codigo, int quantidade);
void vender_produto_parcelado(int codigo, int quantidade);

#endif // PRODUTO_H_INCLUDED