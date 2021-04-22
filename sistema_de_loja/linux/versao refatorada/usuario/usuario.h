#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#define USUARIO_NOME 31
#define USUSARIO_LOGIN 16
#define USUSARIO_SENHA 16

struct Usuario {
    int id;
    char nome[USUARIO_NOME];
    char login[USUSARIO_LOGIN];
    char senha[USUSARIO_SENHA];
    float capital;
    Lista *usuarios;
};
typedef struct Usuario Usuario;

int usuario_criar(Usuario **usuario);
int usuario_liberar(Usuario **usuario);

#endif