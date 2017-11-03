#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/vizinho.h"
#include "../headers/casa.h"
#include "../headers/sentinela.h"

struct vizinho
{
    Casa* orig;
    Vizinho* prox;
};

void liga_casas(Sentinela* s, char* c1, char* c2)
{
    Casa* casa1 = AchaCasaPeloNome(s, c1);
    Casa* casa2 = AchaCasaPeloNome(s, c2);
    Vizinho* vizinhodec1 = malloc(sizeof(Vizinho));
    vizinhodec1->orig = casa2;
    vizinhodec1->prox = NULL;
    if(getIni(getVizinhosCasa(casa1)) == NULL)
    {
        setIni(getVizinhosCasa(casa1), vizinhodec1, TYPE_VIZINHO);
        setEnd(getVizinhosCasa(casa1), vizinhodec1, TYPE_VIZINHO);
    }
    else
    {
        ((Vizinho *)getEnd(getVizinhosCasa(casa1)))->prox = vizinhodec1;
        setEnd(getVizinhosCasa(casa1), vizinhodec1, TYPE_VIZINHO);
    }
    Vizinho* vizinhodec2 = malloc(sizeof(Vizinho));
    vizinhodec2->orig = casa1;
    vizinhodec2->prox = NULL;
    if(getIni(getVizinhosCasa(casa2)) == NULL)
    {
        setIni(getVizinhosCasa(casa2), vizinhodec2, TYPE_VIZINHO);
        setEnd(getVizinhosCasa(casa2), vizinhodec2, TYPE_VIZINHO);    }
    else
    {
        ((Vizinho *)getEnd(getVizinhosCasa(casa2)))->prox = vizinhodec2;
        setEnd(getVizinhosCasa(casa2), vizinhodec2, TYPE_VIZINHO);
    }
}

void PrintaVizinhos(Sentinela* vizinhos)
{
    Vizinho* c = ((Vizinho*) getIni(vizinhos));
    while(c != NULL)
    {
        printf(" -> %s", getNomeCasa(c->orig));
        c = c->prox;
    }
    printf("\n");
}
