#include <stdlib.h>
#include "../headers/sentinela.h"

struct sentinela
{
    void *ini;
    void *fim;
    int tipo;
};

Sentinela* InitSentinela(int tipo)
{
    Sentinela* s = (Sentinela*) malloc(sizeof(Sentinela));
    
    s->tipo = tipo;
    return s;
}

void* getIni(Sentinela* s)
{
    return s->ini;
}

void* getEnd(Sentinela* s)
{
    return s->fim;
}

void setIni(Sentinela* s, void* data, int type)
{
    s->ini = data;
}

void setEnd(Sentinela*s, void* data, int type)
{
    s->fim = data;
}

int getSentSize()
{
    return sizeof(Sentinela);
}