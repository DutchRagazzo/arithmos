#include <stdio.h>
#include "historico.h"

// Registra os resultados e atualiza o contador
void registrarResultado(char transformacoes[][40],
                        double entradas[],
                        char resultados[][200],
                        int *quantidade,
                        char transformacao[],
                        double entrada,
                        char resultado[]) {

    // Verifica se ainda existe espaco para um registro
    if (*quantidade < 4) {

        // Armazena as informacoes na posicao atual
        snprintf(transformacoes[*quantidade], 40, "%s", transformacao);

        entradas[*quantidade] = entrada;

        snprintf(resultados[*quantidade], 200, "%s", resultado);

        // Atualiza o contador original da main
        (*quantidade)++;
    }
}

// Exibe todos os resultados armazenados
void exibirRelatorio(char transformacoes[][40],
                     double entradas[],
                     char resultados[][200],
                     int quantidade) {

    printf("\n===== HISTORICO DO ARITHMOS =====\n");

    if (quantidade == 0) {
        printf("Nenhum resultado registrado.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\nRegistro %d\n", i + 1);
        printf("Transformacao: %s\n", transformacoes[i]);
        printf("Entrada: %.4f\n", entradas[i]);
        printf("Resultado: %s\n", resultados[i]);
    }

    printf("\nTotal de registros: %d/4\n", quantidade);
}