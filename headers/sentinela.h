#ifndef SENTINELA_H
#define SENTINELA_H

#define TYPE_INVALIDO -1
#define TYPE_CASA 0
#define TYPE_VIZINHO 1
#define TYPE_MOSQUITO 2

/* 
 * Tipo que define a Sentinela (opaco)
 */
typedef struct sentinela Sentinela;

/*
 * Inicializa uma sentinela de determinado tipo
 */
Sentinela* InitSentinela(int tipo);

/*
 * Retorna um ponteiro para o início da sentinela
 */
void* getIni(Sentinela* s);

/*
 * Retorna um ponteiro para o fim da sentinela
 */
void* getEnd(Sentinela* s);

/*
 * Altera o ponteiro do início da sentinela
 */
void setIni(Sentinela* s, void* data, int type);

/*
 * Altera o ponteiro do final da sentinela
 */
void setEnd(Sentinela*s, void* data, int type);

/*
 * Retorna o tamanho do tipo sentinela
 */
int getSentSize();

#endif /* SENTINELA_H */

