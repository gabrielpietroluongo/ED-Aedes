#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/agente.h"
#include "../headers/casa.h"
#include "../headers/vizinho.h"
#include "../headers/sentinela.h"
#include "../headers/mosquito.h"

struct agente
{
    Casa* CasaAtual;
    int erros;
    int acertos;
};

void imprime_agente(Agente* ag)
{
    printf("Agente (%s)\n", getNomeCasa(ag->CasaAtual));
}

Agente* InitAgente(Casa* casa)
{
    Agente* a = malloc(sizeof(Agente));
    a->CasaAtual = casa;
    a->erros = 0;
    a->acertos = 0;
    return a;
}

int ProcessaAgente(Agente* ag, void* s)
{
    Casa* c = ag->CasaAtual;
    c = achaCasaIdealAgente(getVizinhosCasa(c));
    printf("Agente %s -> %s\n", getNomeCasa(ag->CasaAtual), getNomeCasa(c));
    ag->CasaAtual = c;
    int q = getQtdMosquitosCasa(c);
    if(!q) ag->erros++; else ag->acertos++;
    MataMosquitos(getMosquitosCasa(c), s);
    UpdateMosquitosCasa(c, -q);
    return q;
}

int getErrosAgente(Agente* a)
{
    return a->erros;
}

int getAcertosAgente(Agente* a)
{
    return a->acertos;
}