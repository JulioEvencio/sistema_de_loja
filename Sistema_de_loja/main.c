/*  Sistema de loja */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Gomesh: Struct dos dados do historio
//Futuramente pode ser adicionado data e hora
typedef struct tipo_historico{
    char descricao[101];
}Historico;

//  Struct global do produto
typedef struct Lista_Produto
{
    int codigo;
    char nome[101];
    float preco;
    float preco_repor;
    int quantidade;
}Tipo_Produto;

Tipo_Produto produto[100];

Historico historico[100];

//  Variavel global do codigo e do historico
int variavel_codigo, variavel_historico;

//  Variaveis globais do usuario
char nome[101] = "";
char usuario[101] = "";
char senha[101] = "";
float capital;

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
//  Funcao que localiza produtos
void localizar_produto(int posicao);
//  Listar produtos
void listar_produto(void);
//  Alterar produto
void alterar_produto(int codigo);
//  Excluir produto
void excluir_produto(int codigo);
//  Vender produto
void vender_produto(int codigo);
//  Vender produto a vista
void vender_produto_a_vista(int codigo, int quantidade);
//  Vender produto parcelado
void vender_produto_parcelado(int codigo, int quantidade);
//  Repor produto
void repor_produto(int codigo);
//  Confirmar formatacao
void confirmar_formatacao(void);
//  Funcao que limpa a lista de produto
void formatar_lista(void);
//  Login do usuario
int login_do_usuario(void);
//  Registrar usuario
void registrar_usuario(void);
//  Menu do login
void menu_login(void);
//  Funcao que procura um lugar vazio no historico
int verificador_de_historico(void);
//  Funcao do historico
void printar_historico(void);

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
        printf("Nome: %s", nome);
        printf("Dinheiro: %.2f \n\n", capital);

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
            printar_historico();
            break;
        case(9):
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
    int x;
    variavel_codigo++;
    x = variavel_codigo;    //  variavel_codigo e uma variavel global
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
///Gomesh: funcionamento do historico alterado
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
        printf("Preco para repor: ");
        scanf("%f", &produto[posicao].preco_repor);
        setbuf(stdin, NULL);
        produto[posicao].codigo = gerador_de_codigo();

        ///Gomesh: A variavel i recebe a posicao vazia do historico.
        ///        A string informacao recebe o nome e a mensagem.
        ///        Por fim, o historico e armazenado.
        int i = verificador_de_historico();
        char informacao[101];
        char produto_nome[101];

        strcpy(produto_nome, produto[posicao].nome);
        int tam = strlen(produto_nome);
        produto_nome[tam-1]=' ';

        strcpy(informacao, produto_nome);
        strcat(informacao, "foi adicionado\0");

        strcpy(historico[i].descricao, informacao);
        ///--------------------------------------------------------

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
        printf("Preco para repor: %.2f \n", produto[posicao].preco_repor);
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
            localizar_produto(i);
        }
    }
}

//  Alterar produto
///Gomesh: funcionamento do historico alterado
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
        scanf("%f", &produto[codigo].preco);
        setbuf(stdin, NULL);
        printf("Novo Preco para repor: ");
        scanf("%f", &produto[codigo].preco_repor);
        setbuf(stdin, NULL);

        ///Gomesh: A variavel i recebe a posicao vazia do historico.
        ///        A string informacao recebe o nome e a mensagem.
        ///        Por fim, o historico e armazenado.
        int i = verificador_de_historico();
        char informacao[101];
        char produto_nome[101];

        strcpy(produto_nome, produto[codigo].nome);
        int tam = strlen(produto_nome);
        produto_nome[tam-1]=' ';

        strcpy(informacao, produto_nome);
        strcat(informacao, "foi alterado\0");

        strcpy(historico[i].descricao, informacao);
        ///--------------------------------------------------------

        printf("Poduto alterado com sucesso \n");
    }
}

//  Funcao que exclui um unico produto
///Gomesh: funcionamento do historico alterado
void excluir_produto(int codigo)
{
    if(codigo != -1)
    {
        int opcao;
        printf("========EXCLUIR======== \n");
        localizar_produto(codigo);
        printf("Digite 0 para confirmar ou aperte outra tecla para cancelar essa acao... \n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);
        if(opcao == 0)
        {
            strcpy(produto[codigo].nome, "");
            produto[codigo].codigo = 0;
            produto[codigo].preco = 0;
            produto[codigo].preco_repor = 0;
            produto[codigo].quantidade = 0;

            ///Gomesh: A variavel i recebe a posicao vazia do historico.
            ///        A string informacao recebe o nome e a mensagem.
            ///        Por fim, o historico e armazenado.
            int i = verificador_de_historico();
            char informacao[101];
            char produto_nome[101];

            strcpy(produto_nome, produto[codigo].nome);
            int tam = strlen(produto_nome);
            produto_nome[tam-1]=' ';

            strcpy(informacao, produto_nome);
            strcat(informacao, "foi excluido\0");

            strcpy(historico[i].descricao, informacao);
            ///--------------------------------------------------------

            printf("Produto excluido com sucesso! \n");
        }
        else
        {
            printf("Acao cancelada, o produto nao foi excluido! \n");
        }
    }
}

//  Funcao que vende um produto e retorna o valor ganho
void vender_produto(int codigo)
{
    if(codigo != -1)
    {
        int quantidade, opcao;

        printf("========VENDER======== \n");
        localizar_produto(codigo);
        printf("Quantidade: ");
        scanf("%d", &quantidade);
        setbuf(stdin, NULL);
        if(quantidade > 0 && quantidade <= produto[codigo].quantidade)
        {
            printf("========PAGAMENTO======== \n");
            printf("1. A vista \n");
            printf("2. Parcelado \n");
            printf("0. Cancelar \n");
            printf("Opcao: ");
            scanf("%d", &opcao);
            switch(opcao)
            {
                case(1):
                    vender_produto_a_vista(codigo, quantidade);
                    break;
                case(2):
                    vender_produto_parcelado(codigo, quantidade);
                    break;
                case(0):
                    printf("Venda cancelada! \n");
                    break;
                default:
                    printf("Opcao invalida! \n");
            }
        }
        else
        {
            printf("Quantidade invalida! \n");
            printf("Lembre-se que e necessario adicionar (repor) a quantidade depois de cadastrar o produto!! \n");
        }
    }
}

//  Funcao que repoe o produto, isto e, aumenta sua quantidade
///Gomesh: funcionamento do historico alterado
void repor_produto(int codigo)
{
    if(codigo != -1)
    {
        int quantidade;
        float valor;
        printf("========REPOR======== \n");
        localizar_produto(codigo);
        printf("Quantidade para repor no estoque: ");
        scanf("%d", &quantidade);
        setbuf(stdin, NULL);
        valor = quantidade * produto[codigo].preco_repor;
        if(valor > capital)
        {
            printf("Dinheiro insuficiente! \n");
        }
        else
        {
            if(quantidade > 0)
            {
                produto[codigo].quantidade = produto[codigo].quantidade + quantidade;
                capital = capital - valor;
                ///Gomesh: A variavel i recebe a posicao vazia do historico.
                ///        A string informacao recebe o nome e a mensagem.
                ///        Por fim, o historico e armazenado.
                int i = verificador_de_historico();
                char informacao[101];
                char produto_nome[101];

                strcpy(produto_nome, produto[codigo].nome);
                int tam = strlen(produto_nome);
                produto_nome[tam-1]=' ';

                strcpy(informacao, produto_nome);
                strcat(informacao, "foi reposto\0");

                strcpy(historico[i].descricao, informacao);
                ///--------------------------------------------------------

                printf("Reposicao concluida! \n");
            }
            else
            {
                printf("Quantidade invalida! \n");
            }
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
    int i, j;
    for(i = 0; i <= 100; i++)
    {
        produto[i].codigo = 0;
        strcpy(produto[i].nome, "");
        produto[i].preco = 0;
        produto[i].preco_repor = 0;
        produto[i].quantidade = 0;

        ///Gomesh: Inicializando o historico
        strcpy(historico[i].descricao, "");
    }
    variavel_codigo = 0;
    variavel_historico = 0;
}

//  Funcao que faz o login do usuario
int login_do_usuario(void)
{
    char user[101], pass[101];

    printf("========LOGIN======== \n");
    printf("Usuario: ");
    fgets(user, 101, stdin);
    setbuf(stdin, NULL);
    printf("Senha: ");
    fgets(pass, 101, stdin);
    setbuf(stdin, NULL);

    if(strcmp(usuario, user) == 0 && strcmp(pass, senha) == 0)
    {
        printf("Logado com sucesso! \n");
        return -1;
    }
    else
    {
        printf("Usuario ou senha incorreta! \n");
    }
}

//  Funcao que registra o usuario
void registrar_usuario(void)
{
    printf("========REGISTRAR======== \n");
    printf("Nome: ");
    fgets(nome, 101, stdin);
    setbuf(stdin, NULL);
    printf("Usuario: ");
    fgets(usuario, 101, stdin);
    setbuf(stdin, NULL);
    printf("Senha: ");
    fgets(senha, 101, stdin);
    setbuf(stdin, NULL);
    printf("Digite seu capital inicial: ");
    scanf("%f", &capital);
    setbuf(stdin, NULL);
    printf("Usuario registrado com sucesso! \n");
}

//  Funcao que printa o menu de login
void menu_login(void)
{
    printf("========LOGIN======== \n");
    printf("1. Logar \n");
    printf("2. Registrar-se \n");
    printf("0. Fechar programa \n");
    printf("Opcao: ");
}

//  Funcao que vender produto a vista
///Gomesh: funcionamento do historico alterado
void vender_produto_a_vista(int codigo, int quantidade)
{
    float capital_ganho, desconto;
    printf("========A VISTA======== \n");
    produto[codigo].quantidade = produto[codigo].quantidade - quantidade;
    desconto = (quantidade * produto[codigo].preco) * 0.15;
    capital_ganho = (quantidade * produto[codigo].preco) - desconto;
    capital = capital + capital_ganho;

    ///Gomesh: A variavel i recebe a posicao vazia do historico.
    ///        A string informacao recebe o nome e a mensagem.
    ///        Por fim, o historico e armazenado.
    int i = verificador_de_historico();
    char informacao[101];
    char produto_nome[101];

    strcpy(produto_nome, produto[codigo].nome);
    int tam = strlen(produto_nome);
    produto_nome[tam-1]=' ';

    strcpy(informacao, produto_nome);
    strcat(informacao, "foi vendido a vista\0");

    strcpy(historico[i].descricao, informacao);
    ///--------------------------------------------------------

    printf("Voce ganhou %.2f reais de desconto! \n", desconto);
    printf("Venda realizada com sucesso! \n");
    printf("Capital ganho: %.2f \n", capital_ganho);
}

//  Funcao que vende produto parcelado
///Gomesh: funcionamento do historico alterado
void vender_produto_parcelado(int codigo, int quantidade)
{
    int parcelas, juros;
    float capital_ganho;
    printf("========PARCELADO======== \n");
    printf("Parcelar em quantos meses? \n");
    scanf("%d", &parcelas);
    setbuf(stdin, NULL);
    if(parcelas < 3)
    {
        printf("Sem juros! \n");
        produto[codigo].quantidade = produto[codigo].quantidade - quantidade;
        capital_ganho = quantidade * produto[codigo].preco;

        ///Gomesh: A variavel i recebe a posicao vazia do historico.
        ///        A string informacao recebe o nome e a mensagem.
        ///        Por fim, o historico e armazenado.
        int i = verificador_de_historico();
        char informacao[101];
        char produto_nome[101];

        strcpy(produto_nome, produto[codigo].nome);
        int tam = strlen(produto_nome);
        produto_nome[tam-1]=' ';

        strcpy(informacao, produto_nome);
        strcat(informacao, "foi vendido parcelado\0");

        strcpy(historico[i].descricao, informacao);
        ///--------------------------------------------------------

        printf("Venda realizada com sucesso! \n");
        printf("Capital ganho: %.2f \n", capital_ganho);
    }
    else
    {
        if(parcelas >= 3 && parcelas <= 6)
        {
            printf("5 por cento de juros! \n");
            produto[codigo].quantidade = produto[codigo].quantidade - quantidade;
            juros = (quantidade * produto[codigo].preco) * 0.05;
            capital_ganho = (quantidade * produto[codigo].preco) + juros;

            ///Gomesh: A variavel i recebe a posicao vazia do historico.
            ///        A string informacao recebe o nome e a mensagem.
            ///        Por fim, o historico e armazenado.
            int i = verificador_de_historico();
            char informacao[101];
            char produto_nome[101];

            strcpy(produto_nome, produto[codigo].nome);
            int tam = strlen(produto_nome);
            produto_nome[tam-1]=' ';

            strcpy(informacao, produto_nome);
            strcat(informacao, "foi vendido parcelado\0");

            strcpy(historico[i].descricao, informacao);
            ///--------------------------------------------------------

            printf("Venda realizada com sucesso! \n");
            printf("Capital ganho: %.2f \n", capital_ganho);
        }
        else
        {
            if(parcelas >= 7 && parcelas <= 10)
            {
                printf("8 por cento de juros! \n");
                produto[codigo].quantidade = produto[codigo].quantidade - quantidade;
                juros = (quantidade * produto[codigo].preco) * 0.08;
                capital_ganho = (quantidade * produto[codigo].preco) + juros;

                ///Gomesh: A variavel i recebe a posicao vazia do historico.
                ///        A string informacao recebe o nome e a mensagem.
                ///        Por fim, o historico e armazenado.
                int i = verificador_de_historico();
                char informacao[101];
                char produto_nome[101];

                strcpy(produto_nome, produto[codigo].nome);
                int tam = strlen(produto_nome);
                produto_nome[tam-1]=' ';

                strcpy(informacao, produto_nome);
                strcat(informacao, "foi vendido parcelado\0");

                strcpy(historico[i].descricao, informacao);
                ///--------------------------------------------------------

                printf("Venda realizada com sucesso! \n");
                printf("Capital ganho: %.2f \n", capital_ganho);
            }
            else
            {
                if(parcelas == 11 || parcelas == 12)
                {
                    printf("10 por cento de juros! \n");
                    produto[codigo].quantidade = produto[codigo].quantidade - quantidade;
                    juros = (quantidade * produto[codigo].preco) * 0.10;
                    capital_ganho = (quantidade * produto[codigo].preco) + juros;

                    ///Gomesh: A variavel i recebe a posicao vazia do historico.
                    ///        A string informacao recebe o nome e a mensagem.
                    ///        Por fim, o historico e armazenado.
                    int i = verificador_de_historico();
                    char informacao[101];
                    char produto_nome[101];

                    strcpy(produto_nome, produto[codigo].nome);
                    int tam = strlen(produto_nome);
                    produto_nome[tam-1]=' ';

                    strcpy(informacao, produto_nome);
                    strcat(informacao, "foi vendido parcelado\0");

                    strcpy(historico[i].descricao, informacao);
                    ///--------------------------------------------------------

                    printf("Venda realizada com sucesso! \n");
                    printf("Capital ganho: %.2f \n", capital_ganho);
                }
                else
                {
                    printf("Voce pode parcelar ate em 12x, nada a mais ou a menos! \n");
                }
            }
        }
    }
    capital = capital + capital_ganho;
}

//  Funcao que verifica um lugar vazio no historico
///Gomesh: Funcao alterada para retornar o primeiro espaco vazio do historico
//Caso o historico esteja cheio, retorna -1;
int verificador_de_historico(void)
{
    int i;
    for(i=0; i<100; i++){
        if(strcmp(historico[i].descricao, "")==0){
            return i;
        }
    }
    return -1;

    /**
    if(variavel_historico <= 100)
    {
        variavel_historico++;
    }
    else
    {
        variavel_historico = 0;
    }
    return variavel_historico;
    */
}

//  Funcao que printa o historico
void printar_historico(void)
{
    int loop;
    printf("========HISTORICO======== \n");
    for(loop = 0; loop < 100; loop++)
    {
        if(strcmp(historico[loop].descricao, "") != 0)
        {
            printf("%s\n", historico[loop].descricao);
        }
    }
}
