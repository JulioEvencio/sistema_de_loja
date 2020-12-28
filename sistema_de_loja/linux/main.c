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
        system("clear");
        switch(opcao)
        {
            case(login):
                opcao = login_do_usuario();
                break;
            case(registrar):
                registrar_usuario();
                break;
            case(fechar_menu):
                printf("Obrigado por utilizar este programa! \n");
                break;
            default:
                printf("Opcao invalida! \n");
                opcao = opcao_invalida;
        }
        printf("Pressione enter para continuar... \n");
        getchar();
        system("clear");
    }while(opcao != sair_login);

    //  Formatando a lista antes do uso
    /*  formatar_lista(); Por motivos misteriosos o formatar ta zerando o dinheiro*/

    //  Loop do programa
    while(opcao != fechar_menu)
    {
        //  Informacoes do usuario
        printf("========USUARIO======== \n");
        printf("Nome: %s \n", usuario.nome);
        printf("Dinheiro: %.2f \n", usuario.capital);

        //  Printando o menu
        printar_menu();

        //  Leitura da opcao
        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        //  Limpando o menu
        system("clear");

        //  Verificando a opcao
        leitura_da_opcao(opcao);

        //  Pause
        printf("Pressione enter para continuar... \n");
        getchar();
        //  Limpador de tela
        system("clear");
    }

    return 0;
}