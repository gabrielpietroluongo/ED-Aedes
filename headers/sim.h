#ifndef SIM_H
#define SIM_H
#include "../headers/sentinela.h"
#include "../headers/casa.h"
#include "../headers/utility.h"

/*
 * Este arquivo consiste nas definições gerais e da simulação e sua execução.
 */

/*
 * Tipo que define a Simulacao (opaco)
 */
typedef struct sim Simulacao;

/*
 * InitSim(): Funcao responsável pela preparação da simulação. Lê as instruçoẽs
 * do arquivo de configuração e as executa.
 * 
 * inputs: path (string com o endereço do diretorio da simulacao) e sim (
 *         ponteiro de ponteiro de Simulacao que contem os dados da simulacao)
 * outputs: nenhum
 * pre-condicao: sim diferente de NULL
 * pos-condicao: simulacao iniciada 
 */
void InitSim(char* path, Simulacao** sim);

/*
 * Simulate(): Funcao principal da simulação, que é a que executa a simulação
 * em si.
 * 
 * inputs: sim (ponteiro de Simulacao que contem os dados da simulacao)
 * outputs: nenhum
 * pre-condicao: sim iniciado
 * pos-condicao: simulacao chegou ao fim
 */
void Simulate(Simulacao* sim);

/*
 * EndSim(): Funcao que prepara o tipo estruturado de simulação para o fim do 
 * programa, fechando os arquivos abertos.
 * 
 * inputs: sim (ponteiro de Simulacao que contem os dados da simulacao)
 * outputs: nenhum
 * pre-condicao: sim iniciada
 * pos-condicao: memoria alacada para a simulacao liberada
 */
void EndSim(Simulacao* sim);

void UpdateMosquitoCount(Simulacao* sim, int delta);

int getMosquitoCount(Simulacao* s);

void update(char* n1, char* n2, Simulacao* s);

int getMosquitoBota(Simulacao* s);

void ProcessaMosquitoBota(int steps, void* m, char* c, Simulacao* s);

void AdicionaMovimentosTotais(Simulacao* s);

void LogaInformacao(char* msg);

#endif /* SIM_H */

