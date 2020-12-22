#ifndef HISTORICO_H_INCLUDED
#define HISTORICO_H_INCLUDED

/*  Constantes */
#define HISTORICO_CAPACIDADE 100
#define HISTORICO_DESCRICAO 100

/*  Variaveis */

/*  Structs */
struct Tipo_historico
{
    char descricao[HISTORICO_DESCRICAO];
    int tamanho_nome;
    char informacao1[HISTORICO_DESCRICAO];
    char informacao2[HISTORICO_DESCRICAO];
};
typedef struct tipo_historico Historico;

/*  Funcoes */
void printar_historico(void);
void descrever_historico(void);

#endif // HISTORICO_H_INCLUDED