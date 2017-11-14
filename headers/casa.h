#ifndef CASA_H
#define CASA_H
#include "../headers/sentinela.h"

/*
 * Tipo que define a Casa (opaco)
 */
typedef struct casa Casa;

/*
 * Adiciona uma casa à lista de casas da simulação
 */
void adiciona_casa(Sentinela* casas, char* nome);

/*
 * Retorna o nome de determinada casa
 */
char* getNomeCasa(Casa* casa);

/*
 * Retorna a quantidade de mosquitos de determinada casa
 */
int getQtdMosquitosCasa(Casa* casa);

/*
 * Retorna a próxima casa na sequência de casas da simulação
 */
Casa* getProxCasa(Casa* casa);

/*
 * Retorna a lista de mosquitos de determinada casa
 */
Sentinela* getMosquitosCasa(Casa* casa);

/*
 * Retorna a lista de vizinhos de determinada casa
 */
Sentinela* getVizinhosCasa(Casa* casa);

/*
 * Retorna a quantidade de casas de determinada simulação
 */
int getQtdCasas(Sentinela* casas);

/*
 * Imprime as informações de determinada casa
 */
void imprime_casa(Casa* casa);

/*
 * Imprime as informações de todas as casas de determinada simulação
 */
void imprime_casas(Sentinela* casas);

/*
 * Percorre a lista de casas da simulação procurando por uma casa de determinado
 * nome
 */
Casa* AchaCasaPeloNome(Sentinela* casas, char* nome);

/*
 * Atualiza a quantidade de mosquitos de determinada casa em +delta unidades
 */
void UpdateMosquitosCasa(Casa* casa, int delta);

/*
 * Atualiza a quantidade de mosquitos de determinada casa para delta unidades
 */
void SetMosquitosCasa(Casa* casa, int delta);

/*
 * Libera a memória alocada para as casas
 */
void liberaCasas(Sentinela* s);

#endif /* CASA_H */

