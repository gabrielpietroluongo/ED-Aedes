#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/agente.h"
#include "../headers/casa.h"
#include "../headers/vizinho.h"
#include "../headers/sentinela.h"
#include "../headers/mosquito.h"
#include "../headers/utility.h"

struct agente
{
    Casa* CasaAtual;
    int erros;
    int acertos;
};

Agente* InitAgente(Casa* casa)
{
    Agente* a = malloc(sizeof(Agente));
    a->CasaAtual = casa;
    a->erros = 0;
    a->acertos = 0;
    return a;
}

int getErrosAgente(Agente* a)
{
    return a->erros;
}

int getAcertosAgente(Agente* a)
{
    return a->acertos;
}

Casa* getCasaAgente(Agente* a)
{
    return a->CasaAtual;
}

void imprime_agente(Agente* ag)
{
    fprintf(GLOBAL_log, "Agente (%s)\n", getNomeCasa(ag->CasaAtual));
}

int ProcessaAgente(Agente* ag)
{
    Casa* c = ag->CasaAtual;
    c = achaCasaIdealAgente(getVizinhosCasa(c));
    fprintf(GLOBAL_log, "Agente %s -> %s\n", getNomeCasa(ag->CasaAtual), 
            getNomeCasa(c));
    ag->CasaAtual = c;
    int q = getQtdMosquitosCasa(c);
    if(!q) ag->erros++; else ag->acertos++;
    MataMosquitos(getMosquitosCasa(c));
    UpdateMosquitosCasa(c, -q);
    return q;
}

void liberaAgente(Agente* s)
{
    free(s);
}