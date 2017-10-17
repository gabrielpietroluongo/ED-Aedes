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


/*
 * Tipo opaco Casa.
 */
typedef struct casa Casa;

static void adiciona_casa(Casa** casas, char* nome);

static void adiciona_mosquito(Simulacao* s, char* nome);

static void liga_casas(Simulacao* s, char* c1, char* c2);

static Casa* AchaCasaPeloNome(Casa** casas, char* nome);


#endif /* CASA_H */

