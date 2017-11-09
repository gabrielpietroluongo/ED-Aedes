#include <stdio.h>
#include <stdlib.h>
#include "../headers/utility.h"
#include "../headers/sim.h"

int main(int argc, char** argv) 
{
    //Inicializa o caminho de I/O da simulação
    char* path;
    ChecaArgs(argc, argv, &path);
    
    //Cria a instância da simulação e configura
    Simulacao* sim;
    InitSim(path, &sim);
    
    //Fecha os arquivos
    EndSim(sim);
    
    return (EXIT_SUCCESS);
}

