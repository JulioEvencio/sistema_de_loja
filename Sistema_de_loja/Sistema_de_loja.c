/*  Sistema de loja */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//  Struct global do produto
typedef struct Lista_Produto
{
    int codigo;
    char nome[101];
    float preco;
    int quantidade;
}Tipo_Produto;
Tipo_Produto produto[100];

//  Variavel global do codigo
int variavel_codigo = 0;

/*  Funcoes */
//  Funcao que printa o menu
void printar_menu(void);
//  Fun��o que ler a opcao do usuario
void leitura_da_opcao(int op);
//  Funcao que verifica um local vazio na lista
int verificador_de_local_vazio(void);
//  Funcao que gera codigos para os produtos
int gerador_de_codigo(void);
//  Funcap que verifica se um produto existe
int verificador_de_produto(void);
//  Funcao que cadastra o produto
void cadastrar_produto(int posicao);
//  Funcoes futuras
//  Listar produtos
void listar_produto(void);
//  Alterar produto
void alterar_produto(int codigo);
//  Excluir produto
//  Vender produto
//  Comprar produto
//  Funcao que limpa a lista de produto
void formatar_lista(void);

//  Funcao main
int main()
{
    int opcao;

    //  Formatando a lista antes do uso
    formatar_lista();

    //  Loop do programa
    do
    {
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
    printf("Opcoes: ");
}

//  Funcao que ler a opcao do usuario
void leitura_da_opcao(int op)
{
    switch(op)
    {
        case(1):
            cadastrar_produto(verificador_de_local_vazio());
            break;
        case(2):
            break;
        case(3):
            listar_produto();
            break;
        case(4):
            alterar_produto(verificador_de_produto());
            break;
        case(5):
            break;
        case(6):
            break;
        case(7):
            break;
        case(0):
            printf("Obrigado por utilizar este programa! \n");
            break;
        default:
            printf("OPCAO INVALIDA! \n");
    }
}

//  Funcao que verifica um local vazio na lista
int verificador_de_local_vazio(void)
{
    int loop;
    for(loop = 0; loop <= 100; loop++)
    {
        if(produto[loop].codigo == 0)
        {
            return loop;
        }
    }
    return -1;
}

//  Funcao que gera codigos para os produtos
int gerador_de_codigo(void)
{
    int x;;
    x = variavel_codigo;
    variavel_codigo++;
    return x;
}

//  Funcao que verifica se um produto existe
int verificador_de_produto(void)
{
    int codigo, loop;
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    setbuf(stdin, NULL);
    for(loop = 0; loop <= 100; loop++)
    {
        if(produto[loop].codigo == codigo)
        {
            return codigo;
        }
    }
    return -1;
}

//  Funcao que cadastra o produto
void cadastrar_produto(int posicao)
{
    if(posicao != -1)
    {
        printf("========CADASTRAR======== \n");
        printf("Nome: ");
        fgets(produto[posicao].nome, 101, stdin);
        printf("Preco: ");
        scanf("%f", &produto[posicao].preco);
        produto[posicao].codigo = gerador_de_codigo();
        printf("Cadastro realizado com sucesso! \n");
    }
    else
    {
        printf("Lista cheia! \n");
    }
}

//  Listar produtos
void listar_produto(void)
{
    int i;
    printf("========PRODUTOS======== \n");
    for(i = 0; i <= 100; i++)
    {
        if(produto[i].codigo != 0)
        {
            printf("============= \n");
            printf("Nome: %s \n", produto[i].nome);
            printf("Codigo: %d \n", produto[i].codigo);
            printf("Preco: %.2f \n", produto[i].preco);
            printf("Quantidade: %d \n", produto[i].quantidade);
            printf("============= \n");
        }
    }
}

//  Alterar produto
void alterar_produto(int codigo)
{
    if(codigo != -1)
    {
        printf("========ALTERAR======== \n");
        printf("Nome: ");
        fgets(produto[codigo].nome, 101, stdin);
        printf("Preco: ");
        scanf("%d", &produto[codigo].preco);
        produto[codigo].codigo = gerador_de_codigo();
        produto[codigo].quantidade = 0;
        printf("Poduto alterado com sucesso \n");
    }
    else
    {
        printf("Produto nao encontrado! \n");
    }
}
//  Excluir produto
//  Vender produto
//  Comprar produto
//  Funcao que limpa a lista de produto
void formatar_lista(void)
{
    int i;
    for(i = 0; i <= 100; i++)
    {
        produto[i].codigo = 0;
        strcpy(produto[i].nome, "");
        produto[i].preco = 0;
        produto[i].quantidade = 0;
    }
}
