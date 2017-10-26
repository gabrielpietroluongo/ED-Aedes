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

struct vizinho
{
    Casa* orig;
    Vizinho* prox;
};

struct casa
{
    char* nome;
    Casa* proxCasa;
    Sentinela mosquitos;
    Sentinela vizinhos;
};

struct mosquito
{
    char* nome; 
    Mosquito* proxMosquito;
};

static void adiciona_casa(Casa** ini, Casa** fim, char* nome)
{
    Casa* c = malloc(sizeof(Casa));
    char* n = malloc(strlen(nome)+1);
    strcpy(nome, n);
    c->nome = n;
    c->mosquitos.ini = c->mosquitos.fim = NULL;
    c->vizinhos.ini = c->vizinhos.fim = NULL;
    c->proxCasa = NULL;
    if(*ini != NULL)
        (*fim)->proxCasa = *fim = c;
    else
        *ini = *fim = c;
}

static void adiciona_mosquito(Casa** ini, Casa** fim, char* casa, char* nome)
{
    Casa* c = AchaCasaPeloNome(ini, fim, casa);
    Mosquito* m = malloc(sizeof(Mosquito));
    m->nome=nome;
    m->proxMosquito=NULL;
    if(c->mosquitos->ini != NULL){
        c->mosquitos->fim->proxMosquito = m;
        c->mosquitos->fim = m;
    }else
        c->mosquitos = m;
}

static Casa* AchaCasaPeloNome(Casa** ini, Casa** fim, char* nome)
{
    if(*ini == NULL)
        return NULL;
    Casa* c = *ini;
    while(c != NULL)
    {
        if(!strcmp(c->nome, nome))
            return c;
        c = c->proxCasa;
    }
    return NULL;
}

static void liga_casas(Sentinela* s, char* c1, char* c2)
{
    Casa* casa1 = AchaCasaPeloNome(s, c1);
    Casa* casa2 = AchaCasaPeloNome(s, c2);
    Vizinho* vizinhodec1 = malloc(sizeof(Vizinho));
    vizinhodec1->orig = casa2;
    vizinhodec1->prox = NULL;
    if(casa1->vizinhos == NULL){
        casa1->vizinhos->ini = vizinhodec1;
        casa1->vizinhos->fim = vizinhodec1;
    }else{
        casa1->vizinhos->fim->prox = vizinhodec1;
        casa1->vizinhos->fim = vizinhodec1;
    }
    Vizinho* vizinhodec2 = malloc(sizeof(Vizinho));
    vizinhodec2->orig = casa1;
    vizinhodec2->prox = NULL;
    if(casa2->vizinhos == NULL)
        casa2->vizinhos = vizinhodec2;
    else
        casa2->vizinhos = vizinhodec2;
}