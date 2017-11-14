#ifndef AGENTE_H
#define AGENTE_H
#include "../headers/casa.h"
/*
 * Tipo que define o Agente (tipo opaco)
 */
typedef struct agente Agente;

/*
 * Inicializa uma instância do tipo agente
 */
Agente* InitAgente(Casa* casa);

/*
 * Retorna a quantidade de erros do agente
 */
int getErrosAgente(Agente* agente);

/*
 * Retorna a quantidade de acertos do agente
 */
int getAcertosAgente(Agente* agente);

/*
 * Retorna a casa do agente
 */
Casa* getCasaAgente(Agente* agente);

/*
 * Imprime informações do agente
 */
void imprime_agente(Agente* agente);

/*
 * Move o agente da casa atual para a casa ideal usando achaCasaIdealAgente()
 */
int ProcessaAgente(Agente* agente);

/*
 * Libera a memória alocada para o agente
 */
void liberaAgente(Agente* agente);

#endif /* AGENTE_H */

