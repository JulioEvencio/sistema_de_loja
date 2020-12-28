//  Bibliotecas
#include "sistema.h"

/*  Funcoes */
/*  Menu */
//  Funcao que printa o menu
void printar_menu(void)
{
    printf("========MENU======== \n");
    printf("1. Cadastrar produto \n");
    printf("2. Localizar produto \n");
    printf("3. Listar produto \n");
    printf("4. Alterar produto \n");
    printf("5. Excluir produto \n");
    printf("6. Vender produto \n");
    printf("7. Repor produto \n");
    printf("8. Historico \n");
    printf("9. Formatar lista \n");
    printf("0. Fechar programa \n");
    printf("Opcoes: ");
}

//  Funcao que ler a opcao do usuario
void leitura_da_opcao(int op)
{
    switch(op)
    {
        case(cadastrar):
            cadastrar_produto(verificador_de_local_vazio());
            break;
        case(localizar):
            localizar_produto(verificador_de_produto());
            break;
        case(listar):
            listar_produto();
            break;
        case(alterar):
            alterar_produto(verificador_de_produto());
            break;
        case(excluir):
            excluir_produto(verificador_de_produto());
            break;
        case(vender):
            vender_produto(verificador_de_produto());
            break;
        case(repor):
            repor_produto(verificador_de_produto());
            break;
        case(historico_printar):
            printar_historico();
            break;
        case(formatar):
            confirmar_formatacao();
            break;
        case(fechar_loja):
            printf("Obrigado por utilizar este programa! \n");
            break;
        default:
            printf("OPCAO INVALIDA! \n");
    }
}

/*  Formatacao */
//  Funcao que vai confirmar a formatacao
void confirmar_formatacao(void)
{
    int opcao;

    printf("========FORMATAR======== \n");
    printf("AO FORMATAR A LISTA TODOS OS PRODUTOS REGISTRADOS SERAO EXCLUIDOS PARA SEMPRE (MUITO TEMPO)! \n");
    printf("Digite '34851' para formatar ou aperte '0' para voltar \n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);
    switch(opcao)
    {
        case(formatar_confirmar):
            formatar_lista();
            printf("Lista formatada com sucesso! \n");
            break;
        case(cancelar_formatacao):
            printf("Ainda bem que mudou de ideia, voce perderia todo seu trabalho de ter digitado! \n");
            break;
        default:
            printf("Nao foi possivel reconhecer o numero, entao a lista NAO foi formatada para sua seguranca! \n");
    }
}

//  Funcao que limpa a lista de produto
void formatar_lista(void)
{
    int i;
    for(i = 0; i <= PRODUTO_QUANTIDADE; i++)
    {
        produto[i].codigo = PRODUTO_CODIGO;
        strcpy(produto[i].nome, PRODUTO_NOME_FORMATADO);
        produto[i].preco = PRODUTO_PRECO;
        produto[i].preco_repor = PRODUTO_REPOR;
        produto[i].quantidade = PRODUTO_QUATIDADE;
        strcpy(historico[i].descricao, PRODUTO_DESCRICAO);
    }
    variavel_codigo = VARIAVEIL_CODIGO;
}

/*  Menu de login */
//  Funcao que printa o menu de login
void menu_login(void)
{
    printf("========LOGIN======== \n");
    printf("1. Logar \n");
    printf("2. Registrar-se \n");
    printf("0. Fechar programa \n");
    printf("Opcao: ");
}