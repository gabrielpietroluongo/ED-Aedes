#ifndef AGENTE_H
#define AGENTE_H
#include "../headers/casa.h"
/*
 * Tipo que define o Agente (tipo opaco)
 */
typedef struct agente Agente;

Agente* InitAgente(Casa* casa);

int getErrosAgente(Agente* agente);

int getAcertosAgente(Agente* agente);

Casa* getCasaAgente(Agente* agente);

void imprime_agente(Agente* agente);

int ProcessaAgente(Agente* agente);

void liberaAgente(Agente* agente);

#endif /* AGENTE_H */

