#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/agente.h"
#include "../headers/casa.h"
#include "../headers/vizinho.h"

struct agente
{
    Casa* CasaAtual;
};

void imprime_agente(Agente* ag)
{
    printf("Agente (%s)\n", getNomeCasa(ag->CasaAtual));
}

Agente* InitAgente(Casa* casa)
{
    Agente* a = malloc(sizeof(Agente));
    a->CasaAtual = casa;
    return a;
}

void ProcessaAgente(Agente* ag)
{
    Casa* c = ag->CasaAtual;
    c = achaCasaIdealAgente(getVizinhosCasa(c));
    printf("\n Agente %s -> %s", getNomeCasa(ag->CasaAtual), getNomeCasa(c));
    ag->CasaAtual = c;
    MataMosquitos(getMosquitosCasa(c));
}