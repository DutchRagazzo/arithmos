#ifndef HISTORICO_H
#define HISTORICO_H

void registrarResultado(char transformacoes[][40],
                        double entradas[],
                        char resultados[][200],
                        int *quantidade,
                        char transformacao[],
                        double entrada,
                        char resultado[]);

void exibirRelatorio(char transformacoes[][40],
                     double entradas[],
                     char resultados[][200],
                     int quantidade);

#endif