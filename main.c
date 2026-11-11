#include <stdio.h>
#include "entrada.h"
#include "euler.h"
#include "primo.h"
#include "historico.h"

int main() {

    int opcao;
    int quantidadeRegistros = 0;

    // Vetores que armazenam os quatro registros
    char transformacoes[4][40] = {{0}};
    double entradas[4] = {0};
    char resultados[4][200] = {{0}};

    // Variaveis temporarias para os resultados
    char resultadoAtual[200];
    double entradaAtual;

    do {

        exibirMenu();

        opcao = lerOpcao();

        switch (opcao) {

            case 1:

                if (quantidadeRegistros < 4) {
                    if (executarEuler(resultadoAtual, &entradaAtual)) {
                        registrarResultado(
                            transformacoes,
                            entradas,
                            resultados,
                            &quantidadeRegistros,
                            "Euler",
                            entradaAtual,
                            resultadoAtual
                        );
                    }
                } else {
                    printf("Limite de quatro registros atingido!\\n");
                }

                break;

            case 2:

                if (quantidadeRegistros < 4) {
                    if (executarPrimo(resultadoAtual, &entradaAtual)) {
                        registrarResultado(
                            transformacoes,
                            entradas,
                            resultados,
                            &quantidadeRegistros,
                            "Primos",
                            entradaAtual,
                            resultadoAtual
                        );
                    }
                } else {
                    printf("Limite de quatro registros atingido!\\n");
                }

                break;

            case 3:

                exibirRelatorio(
                    transformacoes,
                    entradas,
                    resultados,
                    quantidadeRegistros
                );

                break;
            
            case 0:

                printf("Encerrando o Arithmos...\n");
                break;

            default:

                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
