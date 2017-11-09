#ifndef VIZINHO_H
#define VIZINHO_H
#include "../headers/sentinela.h"
#include "../headers/casa.h"

/*
 * Tipo opaco Vizinho
 */
typedef struct vizinho Vizinho;

void liga_casas(Sentinela* s, char* c1, char* c2);

void PrintaVizinhos(Sentinela* vizinhos);

Vizinho* achaVizinhoIdeal(Sentinela* vizinhos);

Casa* getCasaVizinho(Vizinho* v);

Casa* achaCasaIdealAgente(Sentinela* vizinhos);

#endif /* VIZINHO_H */

