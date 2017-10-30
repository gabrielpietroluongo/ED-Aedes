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
    int qntMosquitos;
    Casa* proxCasa;
    Sentinela* mosquitos;
    Sentinela* vizinhos;
};

struct mosquito
{
    int id;
    int steps;
    Mosquito* proxMosquito;
};

void adiciona_casa(Sentinela* casas, char* nome)
{
    Casa* c = malloc(sizeof(Casa));
    char* n = malloc(strlen(nome)+1);
    strcpy(n, nome);
    c->nome = n;
    c->qntMosquitos=0;
    c->mosquitos = malloc(getSentSize());
    setIni(c->mosquitos, NULL, TYPE_MOSQUITO);
    setEnd(c->mosquitos, NULL, TYPE_MOSQUITO);
    c->proxCasa = NULL;
    c->vizinhos = malloc(getSentSize());
    setIni(c->vizinhos, NULL, TYPE_VIZINHO);
    setEnd(c->vizinhos, NULL, TYPE_VIZINHO);

    if(getIni(casas) == NULL)
    {
        setIni(casas, c, TYPE_CASA);
        setEnd(casas, c, TYPE_CASA);
        
    }
    else
    {
        ((Casa*) getEnd(casas))->proxCasa = c;
        setEnd(casas, c, TYPE_CASA);
    }
}

void adiciona_mosquito(Sentinela* casas, char* casa, int* mCount)
{
    Casa* c = AchaCasaPeloNome(casas, casa);
    Mosquito* m = malloc(sizeof(Mosquito));
    m->id = *mCount;
    *mCount = *mCount + 1;
    m->steps=0;
    m->proxMosquito=NULL;
    
    if(getIni(c->mosquitos) == NULL)
    {
        setIni(c->mosquitos, m, TYPE_MOSQUITO);
        setEnd(c->mosquitos, m, TYPE_MOSQUITO);
    }
    else
        ((Mosquito*) getEnd(c->mosquitos))->proxMosquito = m;
    c->qntMosquitos++;
}

static Casa* AchaCasaPeloNome(Sentinela* s, char* nome)
{
    Casa* c = getIni(s);
    while(c != NULL)
    {
        if(!strcmp(c->nome, nome))
            return c;
        c = c->proxCasa;
    }
    printf("\n\n\n\n\nCASA NAO ENCONTRADA %s\n\n\n\n\n", nome);
    return NULL;
}

void liga_casas(Sentinela* s, char* c1, char* c2)
{
    Casa* casa1 = AchaCasaPeloNome(s, c1);
    Casa* casa2 = AchaCasaPeloNome(s, c2);
    Vizinho* vizinhodec1 = malloc(sizeof(Vizinho));
    vizinhodec1->orig = casa2;
    vizinhodec1->prox = NULL;
    if(getIni(casa1->vizinhos) == NULL)
    {
        setIni(casa1->vizinhos, vizinhodec1, TYPE_VIZINHO);
        setEnd(casa1->vizinhos, vizinhodec1, TYPE_VIZINHO);
    }
    else
    {
        ((Vizinho *)getEnd(casa1->vizinhos))->prox = vizinhodec1;
        setEnd(casa1->vizinhos, vizinhodec1, TYPE_VIZINHO);
    }
    Vizinho* vizinhodec2 = malloc(sizeof(Vizinho));
    vizinhodec2->orig = casa1;
    vizinhodec2->prox = NULL;
    if(getIni(casa2->vizinhos) == NULL)
    {
        setIni(casa2->vizinhos, vizinhodec2, TYPE_VIZINHO);
        setEnd(casa2->vizinhos, vizinhodec2, TYPE_VIZINHO);    }
    else
    {
        ((Vizinho *)getEnd(casa2->vizinhos))->prox = vizinhodec2;
        setEnd(casa2->vizinhos, vizinhodec2, TYPE_VIZINHO);
    }
}

void imprime_casa(Casa* casa){
    PrintaVizinhos(casa);
    PrintaMosquitos(casa);
}

void PrintaVizinhos(Casa* casa)
{
    printf("%s (vizinhos)",casa->nome);
    Vizinho* c = ((Vizinho*) getIni(casa->vizinhos));
    while(c != NULL)
    {
        printf(" -> %s", c->orig->nome);
        c = c->prox;
    }
    printf("\n");
}

void PrintaMosquitos(Casa* casa)
{
    printf("%s (mosquitos)",casa->nome);
    Mosquito* m = (Mosquito*) getIni(casa->mosquitos);
    if(m == NULL)
        printf("-> null");
    else
    {
        while(m != NULL)
        {
            printf(" -> M%d",m->id);
            m = m->proxMosquito;
        }
    }
    printf("\n");
}