#ifndef SENTINELA_H
#define SENTINELA_H

#define TYPE_INVALIDO -1
#define TYPE_CASA 0
#define TYPE_VIZINHO 1
#define TYPE_MOSQUITO 2

/* 
 * Tipo opaco Sentinela
 */
typedef struct sentinela Sentinela;

Sentinela* InitSentinela(int tipo);

void* getIni(Sentinela* s);

void* getEnd(Sentinela* s);

void setIni(Sentinela* s, void* data, int type);

void setEnd(Sentinela*s, void* data, int type);

int getSentSize();

#endif /* SENTINELA_H */

