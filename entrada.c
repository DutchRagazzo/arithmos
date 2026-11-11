#include <stdio.h>
#include <math.h>
#include "entrada.h"



// Exibe as opcoes disponiveis no programa
void exibirMenu() {

    printf("\n================================\n");
    printf("           ARITHMOS\n");
    printf("================================\n");

    printf("1. Transformacao de Euler\n");
    printf("2. Transformacao por numeros primos\n");
    printf("3. Exibir historico\n");
    printf("4. Fibonacci (em desenvolvimento)\n");
    printf("0. Finalizar programa\n");

    printf("================================\n");
}

// Recebe a opcao escolhida pelo usuario
int lerOpcao() {

    int opcao;

    printf("Escolha uma opcao: ");

    if (scanf("%d", &opcao) != 1) {
        return -1;
    }

    return opcao;
}

// Recebe um numero real positivo
double lerNumero() {

    double numero;

    printf("Digite um numero real positivo: ");

    if (scanf("%lf", &numero) != 1) {
        return NAN;
    }

    return numero;
}

// Recebe um numero inteiro
int lerInteiro() {

    int numero;

    printf("Digite um numero inteiro: ");

    if (scanf("%d", &numero) != 1) {
        return -1;
    }

    return numero;
}