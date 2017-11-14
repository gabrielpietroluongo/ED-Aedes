#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/mosquito.h"
#include "../headers/sentinela.h"
#include "../headers/sim.h"
#include "../headers/utility.h"


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

int getMosquitoId(Mosquito* m)
{
    return m->id;
}

int getSteps(Mosquito* m)
{
    return m->steps;
}

Mosquito* getProxMosquito(Mosquito* m)
{
    return m->proxMosquito;
}

void PrintaMosquitos(Sentinela* mosquitos)
{
    Mosquito* m = (Mosquito*) getIni(mosquitos);
    if(m == NULL)
        fprintf(GLOBAL_log, " -> null");
    else
    {
        while(m != NULL)
        {
            fprintf(GLOBAL_log, " -> M%d",m->id);
            m = m->proxMosquito;
        }
    }
    fprintf(GLOBAL_log, "\n");
}

void TransfereMosquito(Sentinela* orig, Sentinela* dest, char* no, char* nd, void* s)
{
    Mosquito* m = (Mosquito*) getIni(orig);
    fprintf(GLOBAL_log, "Mosquito M%d %s -> %s\n", m->id, no, nd);
    setIni(orig, m->proxMosquito, TYPE_MOSQUITO);
    update(no, nd, s);
    AttachaMosquito(m, dest);
    m->steps ++;
    AdicionaMovimentosTotais(s);
    ProcessaMosquitoBota(getSteps(m), m, nd, s);
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

void MataMosquitos(Sentinela* mosquitos)
{
    Mosquito* m = getIni(mosquitos);
    Mosquito* m2 = m;
    while(m != NULL)
    {
        m2 = m->proxMosquito;
        fprintf(GLOBAL_log, "Agente eliminou o mosquito M%d!\n", m->id);
            free(m);
        free(m);
        m = m2;
    }
    setIni(mosquitos, NULL, TYPE_MOSQUITO);
    setEnd(mosquitos, NULL, TYPE_MOSQUITO);
}

void printaMosquito(Mosquito* m)
{
    fprintf(GLOBAL_log, "Mosquito %d", m->id);
}

void liberaMosquitos(Sentinela* m)
{
    Mosquito* mosquito = getIni(m);
    Mosquito* prox = NULL;
    while(mosquito != NULL)
    {
        prox = mosquito->proxMosquito;
        free(mosquito);
        mosquito = prox;
    }
    free(m);
}