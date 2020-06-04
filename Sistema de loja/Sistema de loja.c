/*  Sistema de loja */

//  Bibliotecas
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

//  Definindo semente para a fun��o rand

/*  Fun��es */
//  Fun��o que printa o menu
void menu(void)
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

//  Fun��o que ler a op��o do usu�rio
void leitura_da_opcao(int op)
{
    switch(op)
    {
        case(1):
            cadastrar(verificador_da_lista());
            break;
        case(2):
            break;
        case(3):
            break;
        case(4):
            break;
        case(5):
            break;
        case(6):
            break;
        case(7):
            break;
        case(0):
            break;
        default:
            printf("OPCAO INVALIDA! \n");
    }
}

//  Fun��o que verifica um local vazio na lista
int verificador_da_lista(void)
{
    int loop;
    for(loop = 0; loop <= 100; loop++)
    {
        if(produto[loop].codigo == 0)
        {
            return loop;
        }
        else{
            return -1;
        }
    }
}

//  Fun��o que gera c�digos para os produtos
int codigo(void)
{
    //  Vari�veis
    int num1, num2, num3, x;

    num1 = rand() % 9;
    num2 = rand() % 9;
    num3 = rand() % 9;
    x = num1 + num2 + num3;

    return x;
}

//  Fun��o que cadastra o produto
void cadastrar(int posicao)
{
    printf("========CADASTRAR======== \n");
    //  Nome
    printf("Nome: ");
    fgets(produto[posicao].nome, 101, stdin);
    //  Pre�o
    printf("Preco: ");
    scanf("%f", &produto[posicao].preco);
    //  C�digo
    produto[posicao].codigo = codigo();
    //  Print avisando que o cadastro foi realizado
    printf("Cadastro realizado com sucesso! \n");
}

//  Listar produtos

//  Alterar produto

//  Excluir produto

//  Vender produto

//  Comprar produto

//  Fun��o que limpa a lista de produto
void formatar(void)
{
    //  Vari�vel
    int i;

    for(i = 0; i <= 100; i++)
    {
        produto[i].codigo = 0;
        strcpy(produto[i].nome, "");
        produto[i].preco = 0;
        produto[i].quantidade = 0;
    }
}

//  Fun��o main
int main()
{
    //  Vari�veis
    int opcao;

    //  Formatando a lista antes do uso
    formatar();

    //  Loop do programa
    do
    {
        //  Fun��o que mostra o menu
        menu();

        //  Leitura da op��o
        scanf("%d", &opcao);

        //  Verificando a op��o
        leitura_da_opcao(opcao);

        //  Pause
        system("pause");
        //  Limpador de tela
        system("cls");
    }while(opcao != 0);

    return 0;
}
