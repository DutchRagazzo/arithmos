#include <stdio.h>
#include "primo.h"
#include "entrada.h"
int ehPrimo(int numero) {

    // Numeros menores ou iguais a 1 nao sao primos
    if (numero <= 1) {
        return 0;
    }

    // O numero 2 e primo
    if (numero == 2) {
        return 1;
    }

    // Numeros pares maiores que 2 nao sao primos
    if (numero % 2 == 0) {
        return 0;
    }

    // Testa os divisores impares ate a raiz quadrada
    for (int i = 3; i <= numero / i; i += 2) {

        if (numero % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Encontra o proximo numero primo
int proximoPrimo(int numero) {

    numero++;

    while (!ehPrimo(numero)) {
        numero++;
    }

    return numero;
}

// Funcao mae da transformacao de primos
int executarPrimo(char resultado[], double *entrada) {

    int opcao;
    int numero;
    int atual;

    printf("\n===== TRANSFORMACAO POR PRIMOS =====\n");

    printf("1. Verificar se um numero e primo\n");
    printf("2. Encontrar os primeiros N primos\n");

    printf("Escolha uma opcao: ");

    if (scanf("%d", &opcao) != 1) {
        return 0;
    }

    // Verifica se um numero especifico e primo
    if (opcao == 1) {

        numero = lerInteiro();

        if (numero < 0) {
            printf("Informe um numero inteiro nao negativo.\n");
            return 0;
        }

        *entrada = numero;

        if (ehPrimo(numero)) {

            printf("%d e um numero primo.\n", numero);

            snprintf(resultado, 200, "%d e um numero primo", numero);
                     
        } else {

            printf("%d nao e um numero primo.\n", numero);

            snprintf(resultado, 200,
                     "%d nao e um numero primo", numero);
        }

        return 1;
    }

    // Encontra os primeiros N numeros primos
    else if (opcao == 2) {

        numero = lerInteiro();

        if (numero < 1 || numero > 1000) {

            printf("Informe uma quantidade entre 1 e 1000.\n");
            return 0;
        }

        *entrada = numero;

        printf("\nOs primeiros %d numeros primos sao:\n", numero);

        atual = 2;

        for (int i = 0; i < numero; i++) {

            printf("%d", atual);

            if (i < numero - 1) {
                printf(", ");
                atual = proximoPrimo(atual);
            }
        }

        printf("\n");

        snprintf(resultado, 200,
                 "Foram encontrados os primeiros %d primos",
                 numero);

        return 1;
    }

    else {

        printf("Opcao invalida!\n");
        return 0;
    }
}
