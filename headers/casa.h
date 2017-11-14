#ifndef CASA_H
#define CASA_H
#include "../headers/sentinela.h"

/*
 * Tipo que define a Casa (opaco)
 */
typedef struct casa Casa;

void adiciona_casa(Sentinela* casas, char* nome);

char* getNomeCasa(Casa* casa);

int getQtdMosquitosCasa(Casa* casa);

Casa* getProxCasa(Casa* casa);

Sentinela* getMosquitosCasa(Casa* casa);

Sentinela* getVizinhosCasa(Casa* casa);

int getQtdCasas(Sentinela* casas);

void imprime_casa(Casa* casa);

void imprime_casas(Sentinela* casas);

Casa* AchaCasaPeloNome(Sentinela* casas, char* nome);

void UpdateMosquitosCasa(Casa* casa, int delta);

void SetMosquitosCasa(Casa* casa, int delta);

void liberaCasas(Sentinela* s);

#endif /* CASA_H */

