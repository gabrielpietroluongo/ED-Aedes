#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/utility.h"
#include "../headers/sim.h"

#define PATH_CFG "%s/config.txt"
#define PATH_CFG_SIZE 11
#define PATH_LOG "%s/log.txt"
#define PATH_LOG_SIZE 8


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
    FILE* config;
    FILE* log;
    int steps;
};

void InitSim(char* path, Simulacao** sim)
{
    Simulacao* s = malloc(sizeof(Simulacao));
    /* 
     * Exemplo de caminho de entrada:
     * /home/pessoa/simulacao/
     * Dentro dessa pasta deve existir uma outra pasta chamada "input", e um
     * arquivo chamado config.txt.
     */
    char* path_in = malloc(strlen(path) + PATH_CFG_SIZE + 1);
    
    char* path_out = malloc(strlen(path) + PATH_LOG_SIZE + 1);
    printf("%s", path_in);
    sprintf(path_in, PATH_CFG, path);
    sprintf(path_out, PATH_LOG, path);
    s->config = fopen(path_in, "r");
    s->log = fopen(path_out, "w");
    if(s->config == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo de configuracao!");
        exit(1);
    }
    if(s->log == NULL)
    {
        printf("ERRO: Nao foi possivel criar o arquivo de log!");
        exit(1);
    }
    free(path_in);
    free(path_out);
    *sim = s;
}

void Simulate(Simulacao* sim)
{
    printf("Inicializando simulacao...");
}

void EndSim(Simulacao* sim)
{
    fclose(sim->config);
    fclose(sim->log);
}