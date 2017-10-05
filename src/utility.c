#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/utility.h"

struct config
{
    FILE* input;
    FILE* log;
};

void InitConfig(int argCount, char** argVal, Configuracao* cfg)
{
    if(argCount <= 1)
    {
        printf("ERRO: Diretorio de configuracao nao informado!\n");
        exit(1);
    }
    
    Configuracao* configObj = malloc(sizeof(Configuracao));
    
    /* 
     * Exemplo de caminho de entrada:
     * /home/pessoa/simulacao/
     * Dentro dessa pasta deve existir uma outra pasta chamada "input", e um
     * arquivo chamado config.txt.
     */
    char path_cfg = "%s/input/config.txt";
    char path_log = "%s/log.txt";
    char* path_in = malloc(strlen(argVal[1]) + strlen(path_cfg) - 2);
    char* path_out = malloc(strlen(argVal[1]) + strlen(path_log) - 2);
    sprintf(path_in, path_cfg, argVal[1]);
    sprintf(path_out, path_log, argVal[1]);
    configObj->input = fopen(path_in, "r");
    configObj->log = fopen(path_out, "w");
    if(configObj->input == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo de configuracao!");
        exit(1);
    }
    if(configObj->log == NULL)
    {
        printf("ERRO: Nao foi possivel criar o arquivo de log!");
        exit(1);
    }
    free(path_in);
    free(path_out);
    cfg = configObj;
}

void EndConfig(Configuracao* cfg)
{
    fclose(cfg->input);
    fclose(cfg->log);
}

FILE* GetInput(Configuracao* cfg)
{
    return cfg->input;
}

FILE* GetOutput(Configuracao* cfg)
{
    return cfg->log;
}
