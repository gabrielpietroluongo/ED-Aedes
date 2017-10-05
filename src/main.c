#include <stdio.h>
#include <stdlib.h>
#include "../headers/utility.h"
#include "../headers/sim.h"

/*
 * 
 */

int main(int argc, char** argv) 
{
    //Cria a instância da configuração e configura
    Configuracao* cfg;
    InitConfig(argc, argv, cfg);
    
    //Cria a instância da simulação e configura
    Simulacao* sim;
    InitSim(GetInput(cfg));
    
    //Simula
    Simulate(sim);
    
    //Fecha os arquivos
    EndConfig(cfg);
    
    return (EXIT_SUCCESS);
}

