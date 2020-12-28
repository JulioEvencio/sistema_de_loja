//  Bibliotecas
#include "sistema.h"

/*  Funcoes */
//  Funcao que printa o historico
void printar_historico(void)
{
    int loop;
    printf("========HISTORICO======== \n");
    for(loop = 0; loop <= HISTORICO_CAPACIDADE; loop++)
    {
        if(strcmp(historico[loop].descricao, "") != 0)
        {
            printf("%s \n", historico[loop].descricao);
        }
    }
}

//  Funcao que descreve o historico
void descrever_historico(void)
{
    int loop;
    //  Movendo as string de posicao
    for(loop = 0; loop < HISTORICO_CAPACIDADE; loop++)
    {
        strcpy(historico[loop].descricao, historico[loop + 1].descricao);
    }
    //  Concatenando os nomes no historico
    strcat(informacao1, informacao2);
    strcpy(historico[HISTORICO_CAPACIDADE - 1].descricao, informacao1);
}