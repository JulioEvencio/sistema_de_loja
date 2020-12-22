/*  Sistema de loja */

//  Bibliotecas
#include "sistema.h"
#include "sistema.c"
#include "usuario.c"
#include "produto.c"
#include "historico.c"

//  Funcao main
int main()
{
    int opcao;

    //  Formatando lista antes do uso
    formatar_lista();

    //  Loop do login
    do
    {

        menu_login();
        scanf("%d", &opcao);
        setbuf(stdin, NULL);
        system("cls");
        switch(opcao)
        {
            case(1):
                opcao = login_do_usuario();
                break;
            case(2):
                registrar_usuario();
                break;
            case(0):
                printf("Obrigado por utilizar este programa! \n");
                return 0;
                break;
            default:
                printf("Opcao invalida! \n");
        }
        system("pause");
        system("cls");
    }while(opcao != -1);

    //  Formatando a lista antes do uso
    /*  formatar_lista(); Por motivos misteriosos o formatar ta zerando o dinheiro*/

    //  Loop do programa
    do
    {
        //  Informacoes do usuario
        printf("========USUARIO======== \n");
        printf("Nome: %s", usuario.nome);
        printf("Dinheiro: %.2f \n\n", usuario.capital);

        //  Printando o menu
        printar_menu();

        //  Leitura da opcao
        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        //  Limpando o menu
        system("cls");

        //  Verificando a opcao
        leitura_da_opcao(opcao);

        //  Pause
        system("pause");
        //  Limpador de tela
        system("cls");
    }while(opcao != 0);

    return 0;
}