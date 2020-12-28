//  Bibliotecas
#include "sistema.h"

/*  Funcoes */
//  Funcao que faz o login do usuario
int login_do_usuario(void)
{
    char user[USUARIO_LOGIN], pass[USUARIO_SENHA];

    printf("========LOGIN======== \n");
    printf("Usuario: ");
    fgets(user, USUARIO_LOGIN, stdin);
    remover_enter(user, USUARIO_LOGIN);
    setbuf(stdin, NULL);
    printf("Senha: ");
    fgets(pass, USUARIO_SENHA, stdin);
    remover_enter(pass, USUARIO_SENHA);
    setbuf(stdin, NULL);

    if(strcmp(usuario.login, user) == 0 && strcmp(pass, usuario.senha) == 0)
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
    fgets(usuario.nome, USUARIO_NOME, stdin);
    remover_enter(usuario.nome, USUARIO_NOME);
    setbuf(stdin, NULL);
    printf("Usuario: ");
    fgets(usuario.login, USUARIO_LOGIN, stdin);
    remover_enter(usuario.login, USUARIO_LOGIN);
    setbuf(stdin, NULL);
    printf("Senha: ");
    fgets(usuario.senha, USUARIO_SENHA, stdin);
    remover_enter(usuario.senha, USUARIO_SENHA);
    setbuf(stdin, NULL);
    printf("Digite seu capital inicial: ");
    scanf("%f", &usuario.capital);
    setbuf(stdin, NULL);
    strcpy(informacao1, usuario.nome);
    strcpy(informacao2, " foi cadastrado com sucesso");
    descrever_historico();
    printf("Usuario registrado com sucesso! \n");
}