#ifndef SIM_H
#define SIM_H

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
void InitSim(FILE* input);

/*
 * Simulate(): Função principal da simulação, que é a que executa a simulação
 * em si.
 */
void Simulate(Simulacao* sim);

#endif /* SIM_H */

