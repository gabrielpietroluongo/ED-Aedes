#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/agente.h"
#include "../headers/casa.h"

struct agente
{
    Casa* CasaAtual;
};

void imprime_agente(Agente* ag)
{
    printf("Agente (%s)", getNomeCasa(ag->CasaAtual));
}

Agente* InitAgente(Casa* casa)
{
    Agente* a = malloc(sizeof(Agente));
    a->CasaAtual = casa;
    return a;
}