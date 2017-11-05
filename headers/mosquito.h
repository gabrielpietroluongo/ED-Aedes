#ifndef MOSQUITO_H
#define MOSQUITO_H
#include "../headers/sentinela.h"

/*
 * Tipo opaco Mosquito.
 */
typedef struct mosquito Mosquito;

void adiciona_mosquito(Sentinela* mosquitos, int* mCount);

void PrintaMosquitos(Sentinela* mosquitos);

void TransfereMosquito(Sentinela* orig, Sentinela* dest, char* no, char* nd);

void AttachaMosquito(Mosquito* m, Sentinela* dest);

#endif /* MOSQUITO_H */

