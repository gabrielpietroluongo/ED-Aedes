#ifndef UTILITY_H
#define UTILITY_H

/*
 * Este arquivo consiste nas funções utilizadas para utilidades gerais do 
 * programa, tais como manipulação de arquivos.
 */

typedef struct config Configuracao;

/*
 * InitConfig(): Checa os argumentos chamados na execução do programa, se
 * certificando de que o usuário passou o caminho do arquivo de configuração
 * como argumento. Retorna o tipo estruturado que contém as configurações da
 * simulação.
 */
void InitConfig(int argCount, char** argVal, Configuracao* cfg);

/*
 * EndConfig(): Prepara o tipo estruturado de configuração para o fim do 
 * programa, fechando os arquivos abertos.
 */
void EndConfig(Configuracao* cfg);

/*
 * GetInput(): Retorna o arquivo de entrada de configuração.
 */
FILE* GetInput(Configuracao* cfg);

/*
 * GetOutput(): Retorna o arquivo de saída (log).
 */
FILE* GetOutput(Configuracao* cfg);

#endif /* UTILITY_H */

