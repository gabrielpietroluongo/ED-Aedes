#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/utility.h"
#include "../headers/sim.h"

/*
 * Creio que o cliente não precisará ter acesso aos tipos abaixo. Caso seja
 * necessário, mover para sim.h .
 */

/*
 * Tipo opaco Casa.
 */
typedef struct casa Casa;

/*
 * Tipo opaco Mosquito.
 */
typedef struct mosquito Mosquito;

/*
 * Tipo opaco Agente
 */
typedef struct agente Agente;


struct casa
{
    int id;
    Casa* proxCasa;
    Mosquito* mosquitos;
};

struct mosquito
{
    int id;
    Mosquito* proxMosquito;
};

struct agente
{
    int id;
    Casa* CasaAtual;
};

struct sim
{
    int steps;
};

void InitSim(FILE* input)
{
    //Abre o arquivo de configuração e lê as instruções
}

void Simulate(Simulacao* sim)
{
    
}