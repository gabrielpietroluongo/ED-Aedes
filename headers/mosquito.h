#ifndef MOSQUITO_H
#define MOSQUITO_H
#include "../headers/sentinela.h"

/*
 * Tipo opaco Mosquito.
 */
typedef struct mosquito Mosquito;

void adiciona_mosquito(Sentinela* mosquitos, int* mCount);

void PrintaMosquitos(Sentinela* mosquitos);

#endif /* MOSQUITO_H */

