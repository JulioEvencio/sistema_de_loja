//  Bibliotecas
#include "sistema.h"
#include "historico.h"

/*  Variaveis */
Historico historico[HISTORICO_CAPACIDADE];

/*  Funcoes */
//  Funcao que printa o historico
void printar_historico(void)
{
    int loop;
    printf("========HISTORICO======== \n");
    for(loop = 0; loop <= 100; loop++)
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
    for(loop = 0; loop < 100; loop++)
    {
        strcpy(historico[loop].descricao, historico[loop + 1].descricao);
    }

    //  Retirando o /0 do nome
    tamanho_nome = strlen(informacao1);
    informacao1[tamanho_nome - 1] = ' ';
    //  Concatenando os nomes no historico
    strcat(informacao1, informacao2);
    strcpy(historico[99].descricao, informacao1);
}