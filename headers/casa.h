/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   casa.h
 * Author: 2017100480
 *
 * Created on 17 de Outubro de 2017, 08:30
 */

#ifndef CASA_H
#define CASA_H
#include "../headers/sentinela.h"

/*
 * Tipo opaco Casa.
 */
typedef struct casa Casa;

void adiciona_casa(Sentinela* casas, char* nome);

void adiciona_mosquito(Sentinela* casas, char* casa, int* mCount);

void liga_casas(Sentinela* s, char* c1, char* c2);

void imprime_casa(Casa* casa);

static Casa* AchaCasaPeloNome(Sentinela* casas, char* nome);


#endif /* CASA_H */

