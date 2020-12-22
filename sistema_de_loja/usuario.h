#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

/*  Constantes */
#define USUARIO_CAPACIDADE 3
#define USUARIO_NOME 50
#define USUARIO_LOGIN 16
#define USUARIO_SENHA 16

/*  Variaveis */

/*  Structs */
struct tipo_usuario
{
    char nome[USUARIO_NOME];
    char login[USUARIO_LOGIN];
    char senha[USUARIO_SENHA];
};
typedef struct tipo_usuario Usuario;

/*  Funcoes */

#endif // USUARIO_H_INCLUDED