#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/utility.h"
#include "../headers/sim.h"

#define PATH_CFG "%s/config.txt"
#define PATH_CFG_SIZE 11
#define PATH_LOG "%s/log.txt"
#define PATH_LOG_SIZE 8


static void LoadInstructions(Simulacao* s);

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
    char* nome;
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
    Casa* casas;
};

void InitSim(char* path, Simulacao** sim)
{
    Simulacao* s = malloc(sizeof(Simulacao));
    /* 
     * Exemplo de caminho de entrada:
     * /home/pessoa/simulacao/
     * Dentro dessa pasta deve existir um arquivo chamado config.txt.
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
    
    LoadInstructions(s);
    
}

/*
 * Carregador de instruções rudimentar
 */
static void LoadInstructions(Simulacao* s)
{
    char buf[99];
    while(!feof(s->config))
    {
        fscanf(s->config, "%s ", &buf);
        if(!strcmp("AGENTE_ATUA", buf))
        {
            /*
             * AGENTE_ATUA <movimentos>:
             * Especifica  o  número  de  movimentações  dos  mosquitos 
             * (ao  todo)  antes  de  cada  chamada  da  função  agente_atua().
             * O  número  de  movimentos nunca pode ser 0.
             */
            int i;
            fscanf(s->config, "%d\n", &i);
            printf("\nDeb: agente atua %d", i);
        }
        else if (!strcmp("MOSQUITO_BOTA", buf))
        {
            int i;
            fscanf(s->config, "%d\n", &i);
            printf("\nDeb: mosquito bota %d", i);
        }
        else if (!strcmp(buf, "inserecasa"))
        {
            char bufB[99];
            fscanf(s->config, "%s\n", &bufB);
            printf("\nDeb: insere casa %s", bufB);
        }
        else if(!strcmp(buf,"inseremosquito"))
        {
            char bufB[99];
            fscanf(s->config, "%s\n", &bufB);            
            printf("\nDeb: insere mosquito %s", bufB);
        }
        else if(!strcmp(buf, "insereagente"))
        {
            char bufB[99];
            fscanf(s->config, "%s\n", &bufB);                  
            printf("\nDeb: insere agente %s", bufB);
        }
        else if (!strcmp(buf, "iniciasimulacao"))
        {
            int i;
            fscanf(s->config, "%d\n", &i);
            printf("\nDeb: inicia simulacao %d", i);
        }
        else if(!strcmp(buf, "FIM"))
        {
            printf("\nDeb: FIM");
        }
        else if(!strcmp(buf, "ligacasas"))
        {
            char bufB[99];
            char bufC[99];
            fscanf(s->config, "%s %s\n", &bufB, &bufC); 
            printf("\nDeb: ligacasas %s %s", bufB, bufC);
        }
        else
            printf("\nError: %s unmatched", buf);
    }
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