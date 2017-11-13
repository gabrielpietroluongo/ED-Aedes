#ifndef AGENTE_H
#define AGENTE_H
#include "../headers/casa.h"
/*
 * Tipo opaco Agente
 */
typedef struct agente Agente;

void imprime_agente(Agente* ag);

Agente* InitAgente(Casa* casa);

int ProcessaAgente(Agente* ag, void* s);

int getErrosAgente(Agente* a);

int getAcertosAgente(Agente* a);

Casa* getCasaAgente(Agente* a);

void liberaAgente(Agente* s);

#endif /* AGENTE_H */

