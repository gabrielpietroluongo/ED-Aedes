#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/utility.h"

void ChecaArgs(int argc, char** argv, char** path)
{
    if(argc <= 1)
    {
        printf("ERRO: Diretorio de configuracao nao informado!\n");
        exit(1);
    }
    *path = argv[1];
}