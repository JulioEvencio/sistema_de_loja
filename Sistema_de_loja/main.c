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
int variavel_codigo = 1;

/*  Funcoes */
//  Funcao que printa o menu
void printar_menu(void);
//  Função que ler a opcao do usuario
void leitura_da_opcao(int op);
//  Funcao que verifica um local vazio na lista
int verificador_de_local_vazio(void);
//  Funcao que gera codigos para os produtos
int gerador_de_codigo(void);
//  Funcap que verifica se um produto existe
int verificador_de_produto(void);
//  Funcao que cadastra o produto
void cadastrar_produto(int posicao);
//  Funcao que localiza produtos
void localizar_produto(int posicao);
//  Funcoes futuras
//  Listar produtos
void listar_produto(void);
//  Alterar produto
void alterar_produto(int codigo);
//  Excluir produto
void excluir_produto(int codigo);
//  Vender produto
float vender_produto(int codigo);
//  Repor produto
void repor_produto(int codigo);
//  Confirmar formatacao
void confirmar_formatacao(void);
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
    printf("8. Formatar lista \n");
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
            localizar_produto(verificador_de_produto());
            break;
        case(3):
            listar_produto();
            break;
        case(4):
            alterar_produto(verificador_de_produto());
            break;
        case(5):
            excluir_produto(verificador_de_produto());
            break;
        case(6):
            vender_produto(verificador_de_produto());
            break;
        case(7):
            repor_produto(verificador_de_produto());
            break;
        case(8):
            confirmar_formatacao();
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
    printf("Lista cheia! \n");
    return -1;
}

//  Funcao que gera codigos para os produtos
int gerador_de_codigo(void)
{
    int x;;
    x = variavel_codigo;    //  variavel_codigo e uma variavel global
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
            return loop;
        }
    }
    printf("Produto nao encontrado! \n");
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
        setbuf(stdin, NULL);
        printf("Preco: ");
        scanf("%f", &produto[posicao].preco);
        setbuf(stdin, NULL);
        produto[posicao].codigo = gerador_de_codigo();
        printf("Cadastro realizado com sucesso! \n");
    }
}

//  Funcao que localiza produtos
void localizar_produto(int posicao)
{
    if(posicao != -1)
    {
        printf("================ \n");
        printf("Nome: %s", produto[posicao].nome);
        printf("Codigo: %d \n", produto[posicao].codigo);
        printf("Preco: %.2f \n", produto[posicao].preco);
        printf("Quantidade: %d \n", produto[posicao].quantidade);
        printf("================ \n");
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
            printf("======================== \n");
            printf("Nome: %s", produto[i].nome);
            printf("Codigo: %d \n", produto[i].codigo);
            printf("Preco: %.2f \n", produto[i].preco);
            printf("Quantidade: %d \n", produto[i].quantidade);
            printf("======================== \n");
        }
    }
}

//  Alterar produto
void alterar_produto(int codigo)
{
    if(codigo != -1)
    {
        printf("========ALTERAR======== \n");
        localizar_produto(codigo);
        printf("Novo Nome: ");
        fgets(produto[codigo].nome, 101, stdin);
        setbuf(stdin, NULL);
        printf("Novo Preco: ");
        scanf("%d", &produto[codigo].preco);
        setbuf(stdin, NULL);
        produto[codigo].codigo = gerador_de_codigo();
        produto[codigo].quantidade = 0;
        printf("Poduto alterado com sucesso \n");
    }
}

//  Funcao que exclui um unico produto
void excluir_produto(int codigo)
{
    if(codigo != -1)
    {
        printf("========EXCLUIR======== \n");
        localizar_produto(codigo);
        strcpy(produto[codigo].nome, "");
        produto[codigo].codigo = 0;
        produto[codigo].preco = 0;
        produto[codigo].quantidade = 0;
        printf("Produto excluido com sucesso! \n");
    }
}

//  Funcao que vende um produto e retorna o valor ganho
float vender_produto(int codigo)
{
    if(codigo != -1)
    {
        int quantidade;
        float capital_ganho;

        printf("========VENDER======== \n");
        localizar_produto(codigo);
        printf("Quantidade: ");
        scanf("%d", &quantidade);
        setbuf(stdin, NULL);
        if(quantidade > 0 && quantidade <= produto[codigo].quantidade)
        {
            produto[codigo].quantidade = produto[codigo].quantidade - quantidade;
            capital_ganho = quantidade * produto[codigo].preco;
            printf("Venda realizada com sucesso! \n");
            printf("Capital ganho: %.2f \n", capital_ganho);
        }
        else
        {
            printf("Quantidade invalida! \n");
            printf("Lembre-se que e necessario adicionar (repor) a quantidade depois de cadastrar o produto!! \n");
        }
    }
}

//  Funcao que repoe o produto, isto e, aumenta sua quantidade
void repor_produto(int codigo)
{
    if(codigo != -1)
    {
        int quantidade;
        printf("========REPOR======== \n");
        localizar_produto(codigo);
        printf("Quantidade para repor no estoque: ");
        scanf("%d", &quantidade);
        setbuf(stdin, NULL);
        if(quantidade > 0)
        {
            produto[codigo].quantidade = produto[codigo].quantidade + quantidade;
            printf("Reposicao concluida! \n");
        }
        else
        {
            printf("Quantidade invalida! \n");
        }
    }
}

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
        case(34851):
            formatar_lista();
            printf("Lista formatada com sucesso! \n");
            break;
        case(0):
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
    for(i = 0; i <= 100; i++)
    {
        produto[i].codigo = 0;
        strcpy(produto[i].nome, "");
        produto[i].preco = 0;
        produto[i].quantidade = 0;
    }
}
