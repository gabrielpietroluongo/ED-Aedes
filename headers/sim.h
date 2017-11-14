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

/*
 * Atualiza a quantidade de mosquitos globais da simulação
 */
void UpdateMosquitoCount(Simulacao* sim, int delta);

/*
 * Retorna a quantidade de mosquitos globais da simulação
 */
int getMosquitoCount(Simulacao* s);

/*
 * Atualiza a contagem de mosquitos de duas casas (chamada no movimento de 
 * mosquitos de uma casa 1 para uma casa 2). Mantém a contagem de mosquitos
 * na simulação consistente
 */
void update(char* n1, char* n2, Simulacao* s);

/*
 * Retorna a quantidade de movimentos necessários para qualquer mosquito botar 
 * ovos
 */
int getMosquitoBota(Simulacao* s);

/*
 * Faz o processamento de quando o mosquito deve botar ovos. 
 * int steps: Quantidade de passos atuais do mosquito
 * void* m: Referência para o mosquito que está sendo processado
 * char* c: Nome da casa atual do mosquito
 * Simulacao* s: Referência para a instância da simulação
 */
void ProcessaMosquitoBota(int steps, void* m, char* c, Simulacao* s);

/*
 * Incrementa a quantidade de movimentos totais da simulação em 1
 */
void AdicionaMovimentosTotais(Simulacao* s);

#endif /* SIM_H */

