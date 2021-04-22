#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define LISTA_SUCESSO 0
#define LISTA_SEM_MEMORIA -1
#define LISTA_VAZIA -2
#define LISTA_POSICAO_INEXISTENTE -3

struct Elemento {
    int x;
};
typedef struct Elemento Elemento;

typedef struct Lista Lista;

void lista_inicializar(Lista **lista);
void lista_liberar(Lista **lista);

int lista_tamanho(Lista **lista);
int lista_vazia(Lista **lista);

int lista_adicionar_inicio(Lista **lista, Elemento *elemento);
int lista_adicionar_posicao(Lista **lista, Elemento *elemento, int posicao);
int lista_adicionar_final(Lista **lista, Elemento *elemento);

int lista_remover_inicio(Lista **lista);
int lista_remover_posicao(Lista **lista, int posicao);
int lista_remover_final(Lista **lista);

int lista_alterar_inicio(Lista **lista, Elemento *elemento);
int lista_alterar_posicao(Lista **lista, Elemento *elemento, int posicao);
int lista_alterar_final(Lista **lista, Elemento *elemento);

int lista_obter_inicio(Lista **lista, Elemento *elemento);
int lista_obter_posicao(Lista **lista, Elemento *elemento, int posicao);
int lista_obter_final(Lista **lista, Elemento *elemento);

#endif