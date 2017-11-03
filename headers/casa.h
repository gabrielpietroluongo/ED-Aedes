#ifndef CASA_H
#define CASA_H
#include "../headers/sentinela.h"

/*
 * Tipo opaco Casa.
 */
typedef struct casa Casa;

void adiciona_casa(Sentinela* casas, char* nome);

void imprime_casa(Casa* casa);

void imprime_casas(Sentinela* casas);

Casa* AchaCasaPeloNome(Sentinela* casas, char* nome);

Sentinela* getMosquitosCasa(Casa* c);

Sentinela* getVizinhosCasa(Casa* c);

char* getNomeCasa(Casa* c);

int getQtdCasas(Sentinela* casas);

int getQtdMosquitosCasa(Casa* c);

void processaMosquitos(Sentinela* casas);

void moveMosquitos(Casa* orig, Casa* dest);

#endif /* CASA_H */

