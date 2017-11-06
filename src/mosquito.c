#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/mosquito.h"
#include "../headers/sentinela.h"

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
        ((Mosquito*) getEnd(mosquitos))->proxMosquito = m;
}

void PrintaMosquitos(Sentinela* mosquitos)
{
    Mosquito* m = (Mosquito*) getIni(mosquitos);
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

void TransfereMosquitos(Sentinela* orig, Sentinela* dest, char* no, char* nd)
{
    Mosquito* m = getIni(orig);
    while(m != NULL)
    {
        printf("Mosquito M%d %s -> %s\n", m->id, no, nd);
        AttachaMosquito(m, dest);
        setIni(orig, m->proxMosquito, TYPE_MOSQUITO);
        m = m->proxMosquito;
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

void MataMosquitos(Sentinela* mosquitos)
{
    Mosquito* m = getIni(mosquitos);
    Mosquito* m2 = m;
    while(m != NULL)
    {
        m2 = m->proxMosquito;
        printf("\n MATOU mosquito M%d", m->id);
        free(m);
        m = m2;
    }
    setIni(mosquitos, NULL, TYPE_MOSQUITO);
    setEnd(mosquitos, NULL, TYPE_MOSQUITO);
}