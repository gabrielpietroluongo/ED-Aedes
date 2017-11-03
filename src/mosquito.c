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
    m->id = *mCount;
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