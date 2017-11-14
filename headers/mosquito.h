#ifndef MOSQUITO_H
#define MOSQUITO_H
#include "../headers/sentinela.h"

/*
 * Tipo que define o Mosquito (opaco)
 */
typedef struct mosquito Mosquito;

/*
 * Adiciona um mosquito a uma lista de mosquitos de determinada casa
 */
void adiciona_mosquito(Sentinela* mosquitos, int* mCount);

/*
 * Retorna o ID de determinado mosquito
 */
int getMosquitoId(Mosquito* m);

/*
 * Retorna a quantidade de movimentos total de determinado mosquito
 */
int getSteps(Mosquito* m);

/*
 * Retorna o próximo mosquito na sequência de mosquitos de determinada casa
 */
Mosquito* getProxMosquito(Mosquito* m);

/*
 * Printa os mosquitos da lista de mosquitos de determinada casa
 */
void PrintaMosquitos(Sentinela* mosquitos);

/*
 * Transfere os mosquitos entre duas casas
 * Sentinela* orig: Lista de mosquitos da casa original
 * Sentinela* dest: Lista de mosquitos da casa de destino
 * char* no: String com o nome da casa original
 * char* nd: String com o nome da casa nova
 * void* s: Referência para a simulação
 */
void TransfereMosquito(Sentinela* orig, Sentinela* dest, char* no, char* nd, void* s);

/*
 * Junta o mosquito m à lista de mosquitos de determinada casa
 */
void AttachaMosquito(Mosquito* m, Sentinela* dest);

/*
 * Mata os mosquitos da lista de determinada casa (libera a memória)
 */
void MataMosquitos(Sentinela* mosquitos);

/*
 * Libera toda a memória alocada para todos os mosquitos de determinada lista de
 * determinada casa
 */
void liberaMosquitos(Sentinela* m);

#endif /* MOSQUITO_H */

