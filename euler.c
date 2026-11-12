#include <stdio.h>
#include <math.h>
#include "euler.h"
#include "entrada.h"

const double euler = 2.7182818284;
const double PI = 3.14159265358979323846;

/* ==========================================
   TRANSFORMACAO DE EULER
   ========================================== */

// Calcula o valor de X, tal que: X + numero_entrada = euler
double soma(double numero) {

    // numero + incognita = euler
    // incognita = euler - numero

    return euler - numero;
}

// Calcula o valor de X, tal que: X - numero_entrada = euler
double subtracao(double numero) {

    // numero - incognita = euler
    // incognita = numero - euler

    return numero - euler;
}

// Calcula o valor de X, tal que: X * numero_entrada = euler
double produto(double numero) {

    // numero * incognita = euler
    // incognita = euler / numero

    return euler / numero;
}

// Calcula o valor de X, tal que: X / numero_entrada = euler
double divisao(double numero) {

    // numero / incognita = euler
    // incognita = numero / euler

    return numero / euler;
}

// Calcula o valor de X, tal que: (numero_entrada) ^ X = euler
double potencia(double numero) {

    // numero ^ incognita = euler
    // incognita = log(euler) / log(numero)

    if (numero <= 0 || numero == 1) {
        return NAN;
    }

    return 1.0 / log(numero);
}

// Calcula o logaritmo na base Euler
double raiz(double numero) {

    // euler ^ incognita = numero
    // incognita = log(numero) / log(euler)

    if (numero <= 0) {
        return NAN;
    }

    return log(numero) / log(euler);
}

// Calcula o angulo da primeira relacao: N / euler = sen(X)
double trigonometrica1(double numero) {
    double seno = numero / euler;
    if (seno < -1 || seno > 1) return NAN;
    return asin(seno) * 180.0 / PI;
}

// Calcula o angulo da segunda relacao: N * sen(X) = euler
double trigonometrica2(double numero) {
    double seno = euler / numero;
    if (seno < -1 || seno > 1) return NAN;
    return asin(seno) * 180.0 / PI;
}


// Calcula o angulo da primeira relacao: N / euler = cos(X)
double trigonometrica3(double numero) {
    double cosseno = numero / euler;
    if (cosseno < -1 || cosseno > 1) return NAN;
    return acos(cosseno) * 180.0 / PI;
}

// Calcula o angulo da segunda relacao: N * cos(X) = euler
double trigonometrica4(double numero) {
    double cosseno = euler / numero;
    if (cosseno < -1 || cosseno > 1) return NAN;
    return acos(cosseno) * 180.0 / PI;
}

// Funcao mae da transformacao de Euler
int executarEuler(char resultado[], double *entrada) {
    double numero;
    double valorSoma, valorSubtracao, valorProduto, valorDivisao;
    double valorPotencia, valorRaiz, angulo1, angulo2, angulo3, angulo4;

    printf("\n===== TRANSFORMACAO DE EULER =====\n");
    numero = lerNumero();

    if (!isfinite(numero) || numero <= 0) {
        printf("Numero invalido! Informe um numero positivo.\n");
        return 0;
    }

    // Guarda o numero para o historico sem pedir novamente
    *entrada = numero;

    // Calcula os resultados usando as funcoes auxiliares
    valorSoma = soma(numero);
    valorSubtracao = subtracao(numero);
    valorProduto = produto(numero);
    valorDivisao = divisao(numero);
    valorPotencia = potencia(numero);
    valorRaiz = raiz(numero);
    angulo1 = trigonometrica1(numero);
    angulo2 = trigonometrica2(numero);
    angulo3 = trigonometrica3(numero);
    angulo4 = trigonometrica4(numero);

    printf("\n========== OPERACOES ARITMETICAS ==========\n");

    printf("\n1. SOMA\n");
    printf("Valor encontrado: %.10f\n", valorSoma);
    printf("Interpretacao: %.10f + %.10f = %.10f.\n",
           numero, valorSoma, euler);

    printf("\n2. SUBTRACAO\n");
    printf("Valor encontrado: %.10f\n", valorSubtracao);
    printf("Interpretacao: %.10f - %.10f = %.10f.\n",
           numero, valorSubtracao, euler);

    printf("\n3. PRODUTO\n");
    printf("Valor encontrado: %.10f\n", valorProduto);
    printf("Interpretacao: %.10f * %.10f = %.10f.\n",
           numero, valorProduto, euler);

    printf("\n4. DIVISAO\n");
    printf("Valor encontrado: %.10f\n", valorDivisao);
    printf("Interpretacao: %.10f / %.10f = %.10f.\n",
           numero, valorDivisao, euler);

    printf("\n5. POTENCIA\n");
    if (isnan(valorPotencia)) {
        printf("Transformacao nao definida para N = %.10f.\n", numero);
    } else {
        printf("Valor encontrado: %.10f\n", valorPotencia);
        printf("Interpretacao: %.10f elevado a %.10f = %.10f.\n",
               numero, valorPotencia, euler);
    }

    printf("\n6. LOGARITMO NA BASE EULER\n");
    printf("Valor encontrado: %.10f\n", valorRaiz);
    printf("Interpretacao: o logaritmo de %.10f na base %.10f e %.10f.\n",
           numero, euler, valorRaiz);

    printf("\n========== OPERACOES TRIGONOMETRICAS ==========\n");

    printf("\n7. PRIMEIRA RELACAO TRIGONOMETRICA\n");
    printf("Relacao: N / e = sen(X)\n");
    if (isnan(angulo1)) {
        printf("Nao existe angulo real para essa transformacao.\n");
    } else {
        printf("Valor encontrado: X = %.4f graus\n", angulo1);
        printf("Interpretacao: o seno de %.4f graus corresponde a %.10f / %.10f.\n",
               angulo1, numero, euler);
    }

    printf("\n8. SEGUNDA RELACAO TRIGONOMETRICA\n");
    printf("Relacao: N * sen(X) = e\n");
    if (isnan(angulo2)) {
        printf("Nao existe angulo real para essa transformacao.\n");
    } else {
        printf("Valor encontrado: X = %.4f graus\n", angulo2);
        printf("Interpretacao: o seno de %.4f graus, multiplicado por %.10f, resulta em %.10f.\n",
               angulo2, numero, euler);
    }

    printf("\n9. TERCEIRA RELACAO TRIGONOMETRICA\n");
    printf("Relacao: N / e = cos(X)\n");
    if (isnan(angulo3)) {
        printf("Nao existe angulo real para essa transformacao.\n");
    } else {
        printf("Valor encontrado: X = %.4f graus\n", angulo3);
        printf("Interpretacao: o cosseno de %.4f graus corresponde a %.10f / %.10f.\n",
               angulo3, numero, euler);
    }

     printf("\n10. QUARTA RELACAO TRIGONOMETRICA\n");
    printf("Relacao: N * cos(X) = e\n");
    if (isnan(angulo4)) {
        printf("Nao existe angulo real para essa transformacao.\n");
    } else {
        printf("Valor encontrado: X = %.4f graus\n", angulo4);
        printf("Interpretacao: o cosseno de %.4f graus corresponde a %.10f / %.10f.\n",
               angulo4, numero, euler);
    }



    snprintf(resultado, 200,
             "Transformacoes aritmeticas e trigonometricas de Euler para N = %.4f",
             numero);
    return 1;
}
