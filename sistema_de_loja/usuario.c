//  Bibliotecas
#include "sistema.h"
#include "usuario.h"

/*  Funcoes */
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
    strcpy(informacao1, nome);
    strcpy(informacao2, " foi cadastrado com sucesso");
    descrever_historico();
    printf("Usuario registrado com sucesso! \n");
}