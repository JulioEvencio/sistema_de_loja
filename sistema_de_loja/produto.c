//  Bibliotecas
#include "sistema.h"
#include "produto.h"

/*  Funcoes */
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
    char produto1[101];
    printf("========LOCALIZANDO PRODUTO======== \n");
    printf("Procurar produto pelo: \n");
    printf("1. Nome \n");
    printf("2. Codigo \n");
    printf("Opcao: ");
    scanf("%d", &loop);
    setbuf(stdin, NULL);

    switch(loop)
    {
        case(1):
            printf("Digite o nome do produto: ");
            fgets(produto1, 101, stdin);
            setbuf(stdin, NULL);
            for(loop = 0; loop <= 100; loop++)
            {
                if(strcmp(produto[loop].nome, produto1) == 0)
                {
                    return loop;
                }
            }
            printf("Produto nao encontrado! \n");
            return -1;
            break;
        case(2):
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
            break;
        default:
            printf("Opcao invalida! \n");
            return -1;
    }
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
        printf("Preco para repor: ");
        scanf("%f", &produto[posicao].preco_repor);
        setbuf(stdin, NULL);
        produto[posicao].codigo = gerador_de_codigo();
        strcpy(informacao1, produto[posicao].nome);
        strcpy(informacao2, " foi adicionado a lista");
        descrever_historico();
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
void alterar_produto(int codigo)
{
    if(codigo != -1)
    {
        printf("========ALTERAR======== \n");
        localizar_produto(codigo);
        strcpy(informacao1, produto[codigo].nome);
        strcpy(informacao2, " foi alterado");
        descrever_historico();
        printf("Novo Nome: ");
        fgets(produto[codigo].nome, 101, stdin);
        setbuf(stdin, NULL);
        printf("Novo Preco: ");
        scanf("%f", &produto[codigo].preco);
        setbuf(stdin, NULL);
        printf("Novo Preco para repor: ");
        scanf("%f", &produto[codigo].preco_repor);
        setbuf(stdin, NULL);
        printf("Produto alterado com sucesso \n");
    }
}

//  Funcao que exclui um unico produto
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
            strcpy(informacao1, produto[codigo].nome);
            strcpy(informacao2, " foi excluido");
            descrever_historico();
            strcpy(produto[codigo].nome, "");
            produto[codigo].codigo = 0;
            produto[codigo].preco = 0;
            produto[codigo].preco_repor = 0;
            produto[codigo].quantidade = 0;
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
        if(valor > usuario.capital)
        {
            printf("Dinheiro insuficiente! \n");
        }
        else
        {
            if(quantidade > 0)
            {
                produto[codigo].quantidade = produto[codigo].quantidade + quantidade;
                usuario.capital -= valor;
                strcpy(informacao1, produto[codigo].nome);
                strcpy(informacao2, " foi reposto");
                descrever_historico();
                printf("Reposicao concluida! \n");
            }
            else
            {
                printf("Quantidade invalida! \n");
            }
        }
    }
}

//  Funcao que vender produto a vista
void vender_produto_a_vista(int codigo, int quantidade)
{
    float capital_ganho, desconto;
    printf("========A VISTA======== \n");
    produto[codigo].quantidade = produto[codigo].quantidade - quantidade;
    desconto = (quantidade * produto[codigo].preco) * 0.15;
    capital_ganho = (quantidade * produto[codigo].preco) - desconto;
    usuario.capital = usuario.capital + capital_ganho;
    strcpy(informacao1, produto[codigo].nome);
    strcpy(informacao2, " foi vendido");
    descrever_historico();
    printf("Voce ganhou %.2f reais de desconto! \n", desconto);
    printf("Venda realizada com sucesso! \n");
    printf("Capital ganho: %.2f \n", capital_ganho);
}

//  Funcao que vende produto parcelado
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
        strcpy(informacao1, produto[codigo].nome);
        strcpy(informacao2, " foi vendido");
        descrever_historico();
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
            strcpy(informacao1, produto[codigo].nome);
            strcpy(informacao2, " foi vendido");
            descrever_historico();
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
                strcpy(informacao1, produto[codigo].nome);
                strcpy(informacao2, " foi vendido");
                descrever_historico();
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
                    strcpy(informacao1, produto[codigo].nome);
                    strcpy(informacao2, " foi vendido");
                    descrever_historico();
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
    usuario.capital += + capital_ganho;
}