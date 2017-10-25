#ifndef SIM_H
#define SIM_H
#include "../headers/casa.h"
#include "../headers/utility.h"

/*
 * Este arquivo consiste nas definições gerais e da simulação e sua execução.
 */

/*
 * Tipo opaco Simulacao
 */
typedef struct sim Simulacao;

/*
 * InitSim(): Função responsável pela preparação da simulação. Lê as instruçoẽs
 * do arquivo de configuração e as executa.
 */
void InitSim(char* path, Simulacao** sim);

/*
 * Simulate(): Função principal da simulação, que é a que executa a simulação
 * em si.
 */
void Simulate(Simulacao* sim);

/*
 * EndSim(): Prepara o tipo estruturado de simulação para o fim do 
 * programa, fechando os arquivos abertos.
 */
void EndSim(Simulacao* sim);

#endif /* SIM_H */

