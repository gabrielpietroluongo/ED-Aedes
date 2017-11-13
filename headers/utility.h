#ifndef UTILITY_H
#define UTILITY_H
#include "../headers/sentinela.h"

/*
 * Este arquivo consiste nas funções utilizadas para utilidades gerais do 
 * programa.
 */

/*
 * ChecaArgs(): Checa os argumentos chamados na execução do programa, se
 * certificando de que o usuário passou o caminho do arquivo de configuração
 * como argumento.
 */
void ChecaArgs(int argc, char** argv, char** path);

#endif /* UTILITY_H */

