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

static void mosquito_bota(Simulacao* s, Casa* casa);

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
    int mosquitosIniciais;
    int movimentosTotais;
    int mosquitosAtuais;
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
    s->mosquitosAtuais = 0;
    s->mosquitosIniciais = 0;
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
            //fprintf(s->log,"\nDeb: agente atua %d", i);
            s->agenteAtua = i;
        }
        else if (!strcmp("MOSQUITO_BOTA", buf))
        {
            int i;
            fscanf(s->config, "%d\n", &i);
            //printf("\nDeb: mosquito bota %d", i);
            s->mosquitoBota = i;
        }
        else if (!strcmp(buf, "inserecasa"))
        {
            char bufB[99];
            fscanf(s->config, "%s\n", &bufB);
            //printf("\nDeb: insere casa %s", bufB);
            adiciona_casa(s->casas, bufB);
        }
        else if(!strcmp(buf,"inseremosquito"))
        {
            char bufB[99];
            fscanf(s->config, "%s\n", &bufB);            
            //printf("\nDeb: insere mosquito %s", bufB);
            adiciona_mosquito(getMosquitosCasa(AchaCasaPeloNome(s->casas, bufB)), &s->mosquitoCount);
            s->mosquitosAtuais++;
            UpdateMosquitosCasa(AchaCasaPeloNome(s->casas, bufB) ,1);
        }
        else if(!strcmp(buf, "insereagente"))
        {
            char bufB[99];
            fscanf(s->config, "%s\n", &bufB);                  
            //printf("\nDeb: insere agente %s", bufB);
            s->agente = InitAgente(AchaCasaPeloNome(s->casas, bufB));
        }
        else if (!strcmp(buf, "iniciasimulacao"))
        {
            int i;
            fscanf(s->config, "%d\n", &i);
            s->steps=i;
            //printf("\nDeb: inicia simulacao %d", i);
            Simulate(s);
        }
        else if(!strcmp(buf, "FIM"))
        {
            //printf("\nDeb: FIM");
        }
        else if(!strcmp(buf, "ligacasas"))
        {
            char bufB[99];
            char bufC[99];
            fscanf(s->config, "%s %s\n", &bufB, &bufC); 
            //printf("\nDeb: ligacasas %s %s", bufB, bufC);
            liga_casas(s->casas, bufB, bufC);
        }
        else
            printf("\nError: %s unmatched", buf);
    }
}

void Simulate(Simulacao* sim)
{
    //printf("Inicializando simulacao...\n");
    sim->mosquitosIniciais = sim->mosquitoCount;
    sim->mosquitosAtuais = sim->mosquitoCount;
    imprime_inifim(sim, 0);
    printf("\n");
    mosquito_move(sim);
    imprime_inifim(sim, 1);
    imprime_agente(sim->agente);
    printf("Número de mosquitos iniciais: %d\n", sim->mosquitosIniciais);
    printf("Número de mosquitos finais: %d\n", sim->mosquitoCount);
    printf("Número de movimentos totais dos mosquitos: %d\n", sim->movimentosTotais);
    printf("Número de erros dos agentes: %d\n", getErrosAgente(sim->agente));
    printf("Número de acertos dos agentes: %d", getAcertosAgente(sim->agente));
    
}

void EndSim(Simulacao* sim)
{
    fclose(sim->config);
    fclose(sim->log);
}

static void mosquito_move(Simulacao* s)
{
    while(s->movimentosTotais < s->steps && s->mosquitoCount > 0)
    {
        Casa* c = (Casa*) getIni(s->casas);
        while(c != NULL && s->mosquitoCount > 0)
        {
            //Bota antes de mover
            while(getIni(getMosquitosCasa(c)) != NULL)
            {
                Mosquito* m = getIni(getMosquitosCasa(c));
                while(m != NULL)
                {
                    
                    m = getProxMosquito(m);
                }
                Vizinho* ideal;
                ideal = achaVizinhoIdeal(getVizinhosCasa(c));
                TransfereMosquito(getMosquitosCasa(c), 
                                  getMosquitosCasa(getCasaVizinho(ideal)), 
                                  getNomeCasa(c), 
                                  getNomeCasa(getCasaVizinho(ideal)), s);
                s->movimentosTotais++;
                if(!(s->movimentosTotais % s->agenteAtua)&& s->movimentosTotais != 1)
                    agente_atua(s);
            }
            c = (Casa*) getProxCasa(c);
        }
    }
        
}

static void agente_atua(Simulacao* s)
{
    s->mosquitosAtuais -= ProcessaAgente(s->agente, s);
}

static void mosquito_bota(Simulacao* s, Casa* casa)
{
    //printf("\nMosquito botou em %s\n", getNomeCasa(casa));
    adiciona_mosquito(getMosquitosCasa(casa), &s->mosquitoCount);

    adiciona_mosquito(getMosquitosCasa(casa), &s->mosquitoCount);
    UpdateMosquitosCasa(casa, 2);
    s->mosquitosAtuais += 2;
}

static void imprime_inifim(Simulacao* sim, int tipo)
{
    if(tipo == 0)
    {
        printf("Inicial:\n\n");
        imprime_casas(sim->casas);
        imprime_agente(sim->agente);
        return;
    }
    printf("\nFinal:\n\n");
    imprime_casas(sim->casas);
    return;
}

void UpdateMosquitoCount(Simulacao* sim, int delta)
{
    sim->mosquitoCount += delta;
}

int getMosquitoCount(Simulacao* s)
{
    return s->mosquitoCount;
}

void update(char* n1, char* n2, Simulacao* s)
{
    Casa* c1 = AchaCasaPeloNome(s->casas, n1);
    Casa* c2 = AchaCasaPeloNome(s->casas, n2);
    UpdateMosquitosCasa(c1, -1);
    UpdateMosquitosCasa(c2, 1);
}

int getMosquitoBota(Simulacao* s)
{
    return s->mosquitoBota;
}