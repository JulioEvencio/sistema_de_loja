#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

/*  Constantes */
#define PRODUTO_QUANTIDADE 100
#define PRODUTO_NOME 50
#define PRODUTO_DESCONTO 0.15
#define PRODUTO_JUROS_1 0.05
#define PRODUTO_JUROS_2 0.08
#define PRODUTO_JUROS_3 0.10
//  Produto formatado
#define PRODUTO_CODIGO 0
#define PRODUTO_NOME_FORMATADO ""
#define PRODUTO_PRECO 0
#define PRODUTO_REPOR 0
#define PRODUTO_QUANTIDADE_FORMATAR 0
#define PRODUTO_DESCRICAO ""

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