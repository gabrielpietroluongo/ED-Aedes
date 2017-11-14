#ifndef VIZINHO_H
#define VIZINHO_H
#include "../headers/sentinela.h"
#include "../headers/casa.h"

/*
 * Tipo que define o Vizinho (opaco)
 */
typedef struct vizinho Vizinho;

/*
 * Liga duas casas, encadeando-as na lista de casas de determinada simulação.
 * Aloca dois tipos "vizinho" para inserir na lista de vizinhos das duas casas.
 */
void liga_casas(Sentinela* s, char* c1, char* c2);

/*
 * Imprime a lista de vizinhos de determinada casa
 */
void PrintaVizinhos(Sentinela* vizinhos);

/*
 * Compara as informações de vizinhos de determinada casa para encontrar o
 * vizinho ideal para um mosquito se mover
 */
Vizinho* achaVizinhoIdeal(Sentinela* vizinhos);

/*
 * Retorna uma referência para a casa original de determinado vizinho
 */
Casa* getCasaVizinho(Vizinho* v);

/*
 * Compara as informações de vizinhos de determinada casa para encontrar o
 * vizinho ideal para um agente se mover
 */
Casa* achaCasaIdealAgente(Sentinela* vizinhos);

/*
 * Libera toda a memória alocada para os vizinhos de determinada lista
 */
void liberaVizinhos(Sentinela* vizinhos);

#endif /* VIZINHO_H */

