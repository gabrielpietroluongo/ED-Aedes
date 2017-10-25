#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/casa.h"

/*
 * Tipo opaco Mosquito.
 */
typedef struct mosquito Mosquito;

/*
 * Tipo opaco Vizinho
 */
typedef struct vizinho Vizinho;

/* 
 * Tipo opaco Sentinela
 */
typedef struct sentinela Sentinela;

struct vizinho
{
    Casa* orig;
    Vizinho* prox;
};

struct sentinela
{
    void *ini,*fim;
};

struct casa
{
    char* nome;
    Casa* proxCasa;
    Sentinela* mosquitos;
    Sentinela* vizinhos;
};

struct mosquito
{
    char* nome; 
    Mosquito* proxMosquito;
};

static void adiciona_casa(Casa** casas, char* nome)
{
    Casa* c = malloc(sizeof(Casa));
    char* n = malloc(strlen(nome)+1);
    strcpy(nome, n);
    c->nome = n;
    c->mosquitos = NULL;
    c->proxCasa = NULL;
    c->vizinhos = NULL;
    if(*casas != NULL)
       (*casas)->proxCasa = c;
    else
        *casas = c;
}

static void adiciona_mosquito(Casa* casa, char* nome)
{
    Casa* c = AchaCasaPeloNome(s, nome);
    Mosquito* m = malloc(sizeof(Mosquito));
    if(c->mosquitos != NULL)
        c->mosquitos->proxMosquito = m;
    else
        c->mosquitos = m;
}

static Casa* AchaCasaPeloNome(Simulacao* s, char* nome)
{
    Casa* c = casas;
    while(c != NULL)
    {
        if(!strcmp(c->nome, nome))
            return c;
        c = c->proxCasa;
    }
    return NULL;
}

static void liga_casas(Simulacao* s, char* c1, char* c2)
{
    Casa* casa1 = AchaCasaPeloNome(s, c1);
    Casa* casa2 = AchaCasaPeloNome(s, c2);
    Vizinho* vizinhodec1 = malloc(sizeof(Vizinho));
    vizinhodec1->orig = casa2;
    vizinhodec1->prox = NULL;
    if(casa1->vizinhos == NULL)
        casa1->vizinhos = vizinhodec1;
    else
        casa1->vizinhos->prox = vizinhodec1;
    Vizinho* vizinhodec2 = malloc(sizeof(Vizinho));
    vizinhodec2->orig = casa1;
    vizinhodec2->prox = NULL;
    if(casa2->vizinhos == NULL)
        casa2->vizinhos = vizinhodec2;
    else
        casa2->vizinhos = vizinhodec2;
}