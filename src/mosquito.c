#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/mosquito.h"
#include "../headers/sentinela.h"
#include "../headers/sim.h"

struct mosquito
{
    int id;
    int steps;
    Mosquito* proxMosquito;
};

void adiciona_mosquito(Sentinela* mosquitos, int* mCount)
{
    Mosquito* m = malloc(sizeof(Mosquito));
    m->id = (*mCount) + 1;
    *mCount = *mCount + 1;
    m->steps=0;
    m->proxMosquito=NULL;
    
    if(getIni(mosquitos) == NULL)
    {
        setIni(mosquitos, m, TYPE_MOSQUITO);
        setEnd(mosquitos, m, TYPE_MOSQUITO);
    }
    else
    {
        ((Mosquito*) getEnd(mosquitos))->proxMosquito = m;
        setEnd(mosquitos, m, TYPE_MOSQUITO);
    }
}

void PrintaMosquitos(Sentinela* mosquitos)
{
    Mosquito* m = (Mosquito*) getIni(mosquitos);
    if(m == NULL)
        printf(" -> null");
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

void TransfereMosquito(Sentinela* orig, Sentinela* dest, char* no, char* nd, void* s)
{
    Mosquito* m = (Mosquito*) getIni(orig);
    printf("Mosquito M%d %s -> %s\n", m->id, no, nd);
    setIni(orig, m->proxMosquito, TYPE_MOSQUITO);
    update(no, nd, s);
    AttachaMosquito(m, dest);
    m->steps ++;
    if(getSteps(m) % s->mosquitoBota == 0 && getSteps(m) != 0)
    {
        notifyBota(m, getNomeCasa(c));
        mosquito_bota(s, c);
    }
}

void AttachaMosquito(Mosquito* m, Sentinela* dest)
{
    if(getIni(dest) == NULL)
    {
        setIni(dest, m, TYPE_MOSQUITO);
        setEnd(dest, m, TYPE_MOSQUITO);
        m->proxMosquito = NULL;
    }
    else
    {
        ((Mosquito*) getEnd(dest))->proxMosquito = m;
        m->proxMosquito = NULL;
        setEnd(dest, m, TYPE_MOSQUITO);
    }
}

void MataMosquitos(Sentinela* mosquitos, void* s)
{
    Mosquito* m = getIni(mosquitos);
    Mosquito* m2 = m;
    while(m != NULL)
    {
        m2 = m->proxMosquito;
        printf("Agente eliminou o mosquito M%d!\n", m->id);
        free(m);
        m = m2;
    }
    setIni(mosquitos, NULL, TYPE_MOSQUITO);
    setEnd(mosquitos, NULL, TYPE_MOSQUITO);
}

int getSteps(Mosquito* m)
{
    return m->steps;
}

Mosquito* getProxMosquito(Mosquito* m)
{
    return m->proxMosquito;
}

void printaMosquito(Mosquito* m)
{
    printf("Mosquito %d", m->id);
}

void notifyBota(Mosquito* m, char* c)
{
    printf("Mosquito %d botou em %s", m->id, c);
}