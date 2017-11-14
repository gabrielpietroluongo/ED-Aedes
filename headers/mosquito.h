#ifndef MOSQUITO_H
#define MOSQUITO_H
#include "../headers/sentinela.h"

/*
 * Tipo que define o Mosquito (opaco)
 */
typedef struct mosquito Mosquito;

void adiciona_mosquito(Sentinela* mosquitos, int* mCount);

int getMosquitoId(Mosquito* m);

int getSteps(Mosquito* m);

Mosquito* getProxMosquito(Mosquito* m);

void PrintaMosquitos(Sentinela* mosquitos);

void TransfereMosquito(Sentinela* orig, Sentinela* dest, char* no, char* nd, void* s);

void AttachaMosquito(Mosquito* m, Sentinela* dest);

void MataMosquitos(Sentinela* mosquitos);

void liberaMosquitos(Sentinela* m);

#endif /* MOSQUITO_H */

