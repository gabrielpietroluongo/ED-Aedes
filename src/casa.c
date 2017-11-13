#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/casa.h"
#include "../headers/vizinho.h"
#include "../headers/mosquito.h"

Casa* AchaCasaPeloNome(Sentinela* casas, char* nome);

struct casa
{
    char* nome;
    int qntMosquitos;
    Casa* proxCasa;
    Sentinela* mosquitos;
    Sentinela* vizinhos;
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

Casa* AchaCasaPeloNome(Sentinela* s, char* nome)
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


void imprime_casa(Casa* casa)
{
    printf("%s(vizinhos)", casa->nome);
    PrintaVizinhos(casa->vizinhos);
    printf("%s(mosquitos)", casa->nome);
    PrintaMosquitos(casa->mosquitos);
}

Sentinela* getMosquitosCasa(Casa* c)
{
    return c->mosquitos;
}

Sentinela* getVizinhosCasa(Casa* c)
{
    return c->vizinhos;
}

void imprime_casas(Sentinela* casas)
{
    Casa* c = getIni(casas);
    while(c != NULL)
    {
        imprime_casa(c);
        c = c->proxCasa;
    }
}

char* getNomeCasa(Casa* c)
{
    return c->nome;
}

int getQtdCasas(Sentinela* casas)
{
    int n;
    Casa* c = getIni(casas);
    while(c != NULL)
    {
        c = c->proxCasa;
        n++;
    }
    return n;
}

int getQtdMosquitosCasa(Casa* c)
{
    return c->qntMosquitos;
}

Casa* getProxCasa(Casa* c)
{
    return (Casa*) c->proxCasa;
}

void UpdateMosquitosCasa(Casa* c, int delta)
{
    c->qntMosquitos += delta;
}

void SetMosquitosCasa(Casa* c, int delta)
{
    c->qntMosquitos = delta;
}

void liberaCasas(Sentinela* s)
{
    Casa* c = getIni(s);
    
    Casa* prox = NULL;
    while(c != NULL)
    {
        
        prox = c->proxCasa;
        liberaMosquitos(c->mosquitos);
        free(c->nome);
        liberaVizinhos(c->vizinhos);
        free(c);
        c = prox;
    }
    free(s);
}