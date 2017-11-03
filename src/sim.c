#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/sim.h"
#include "../headers/casa.h"
#include "../headers/mosquito.h"
#include "../headers/vizinho.h"
#include "../headers/sentinela.h"
#include "../headers/agente.h"

#define PATH_CFG "%s/entrada.txt"
#define PATH_CFG_SIZE 12
#define PATH_LOG "%s/log.txt"
#define PATH_LOG_SIZE 8

static void LoadInstructions(Simulacao* s);

static void mosquito_move(Simulacao* s);

static void agente_atua(Simulacao* s);

static void mosquito_bota(Simulacao* s);

static void imprime_inifim(Simulacao* sim, int status);

struct sim
{
    FILE *config,*log;
    Sentinela* casas;
    Agente* agente;
    int steps;
    int mosquitoBota;
    int agenteAtua;
    int mosquitoCount;
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
    s->casas = InitSentinela(TYPE_CASA);
    s->mosquitoCount = 0;
    s->agente = NULL;
    *sim = s;
    LoadInstructions(s);
    fclose(s->config);
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
            int i;
            fscanf(s->config, "%d\n", &i);
            fprintf(s->log,"\nDeb: agente atua %d", i);
            s->agenteAtua = i;
        }
        else if (!strcmp("MOSQUITO_BOTA", buf))
        {
            int i;
            fscanf(s->config, "%d\n", &i);
            printf("\nDeb: mosquito bota %d", i);
            s->mosquitoBota = i;
        }
        else if (!strcmp(buf, "inserecasa"))
        {
            char bufB[99];
            fscanf(s->config, "%s\n", &bufB);
            printf("\nDeb: insere casa %s", bufB);
            adiciona_casa(s->casas, bufB);
        }
        else if(!strcmp(buf,"inseremosquito"))
        {
            char bufB[99];
            fscanf(s->config, "%s\n", &bufB);            
            printf("\nDeb: insere mosquito %s", bufB);
            adiciona_mosquito(getMosquitosCasa(AchaCasaPeloNome(s->casas, bufB)), &s->mosquitoCount);
        }
        else if(!strcmp(buf, "insereagente"))
        {
            char bufB[99];
            fscanf(s->config, "%s\n", &bufB);                  
            printf("\nDeb: insere agente %s", bufB);
            s->agente = InitAgente(AchaCasaPeloNome(s->casas, bufB));
        }
        else if (!strcmp(buf, "iniciasimulacao"))
        {
            int i;
            fscanf(s->config, "%d\n", &i);
            s->steps=i;
            printf("\nDeb: inicia simulacao %d", i);
            Simulate(s);
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
            liga_casas(s->casas, bufB, bufC);
        }
        else
            printf("\nError: %s unmatched", buf);
    }
}

void Simulate(Simulacao* sim)
{
    printf("Inicializando simulacao...\n");
    int counter = 0;
    imprime_inifim(sim, counter);
    for(counter; counter < sim->steps; counter++)
    {
        mosquito_move(sim);
        agente_atua(sim);
        mosquito_bota(sim);
    }
    imprime_inifim(sim, counter);
}

void EndSim(Simulacao* sim)
{
    fclose(sim->config);
    fclose(sim->log);
}

static void mosquito_move(Simulacao* s)
{
    processaMosquitos(s->casas);
}

static void agente_atua(Simulacao* s)
{
    
}

static void mosquito_bota(Simulacao* s)
{
    
}

static void imprime_inifim(Simulacao* sim, int tipo)
{
    if(tipo == 0)
    {
        printf("Inicial:\n");
        imprime_casas(sim->casas);
        return;
    }
    printf("Final:\n");
    imprime_casas(sim->casas);
    return;
}