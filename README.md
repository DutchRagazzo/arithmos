# Arithmos — Especificação do Projeto

**Curso:** Engenharia de Robôs — Universidade Federal da Paraíba (UFPB)  
**Disciplina:** Laboratório de Programação em C  
**Desenvolvedores:** Gabriel Holanda e Vinícius Wallach.  
**Etapa:** 1  
**Status:** Projeto em desenvolvimento — a segunda parte ainda será implementada.

---

## 1. Contextualização do sistema

O **Arithmos** é um mini-sistema desenvolvido em linguagem C para realizar transformações e análises matemáticas a partir de valores informados pelo usuário. Nesta primeira etapa, o programa reúne operações envolvendo a constante de Euler e funcionalidades relacionadas a números primos.

O projeto foi desenvolvido como atividade da disciplina Laboratório de Programação em C, do curso de Engenharia de Robôs, com o objetivo de aplicar conceitos fundamentais da linguagem C, como funções, estruturas de repetição, seleção com `switch-case`, vetores, validação de entradas e passagem de parâmetros por referência.

O Arithmos está sendo desenvolvido em etapas. A Etapa 1 contempla as funcionalidades descritas neste documento; a Etapa 2 ainda está pendente e será desenvolvida posteriormente.

### 1.1. Regras de negócio

- O usuário acessa as funcionalidades por meio de um menu principal.
- Na transformação de Euler, o usuário informa um número real positivo. O sistema calcula os valores que satisfazem as relações matemáticas definidas com a constante de Euler, \(e \approx 2{,}7182818284\), e apresenta os resultados acompanhados de interpretações textuais.
- As transformações de Euler contemplam soma, subtração, produto, divisão, potência, logaritmo na base Euler e duas relações trigonométricas.
- Nas operações trigonométricas, o programa verifica se há solução real antes de calcular o ângulo. Os ângulos são apresentados em graus.
- Na funcionalidade de números primos, o usuário pode verificar se um número inteiro é primo ou solicitar a geração dos primeiros \(N\) números primos.
- As entradas devem respeitar as condições de cada operação. Por exemplo, o número utilizado nas transformações de Euler deve ser positivo.
- O sistema mantém um histórico de até **quatro registros**, contendo o nome da transformação, o valor de entrada e um resumo do resultado.
- O estado do histórico é controlado por vetores e atualizado por meio de ponteiros, sem a necessidade de utilizar variáveis globais para essa finalidade.

## 2. Explicação das funções

As funções estão organizadas em quatro blocos: Entrada, Histórico, Primo e Euler. Essa divisão separa a interação com o usuário, o armazenamento dos registros e os cálculos de cada funcionalidade.

### 2.1. Bloco de Entrada

| Função | Parâmetros e processamento | Saída / responsabilidade |
|---|---|---|
| `exibirMenu()` | Não recebe parâmetros. Apresenta as opções disponíveis no sistema. | Exibe o menu principal para o usuário. |

As leituras e validações específicas também são realizadas pelas funções responsáveis por cada operação, garantindo que os valores informados atendam às condições necessárias antes dos cálculos.

### 2.2. Bloco de Histórico

| Função | Parâmetros e processamento | Saída / responsabilidade |
|---|---|---|
| `registrarResultado(...)` | Recebe os vetores de transformações, entradas e resultados; o nome da operação; o valor de entrada; o resumo produzido; e um ponteiro `int *quantidade`. Armazena os dados na posição disponível e incrementa a quantidade de registros por referência. | Registra uma transformação no histórico e atualiza o contador. |
| `exibirHistorico(...)` | Recebe os vetores do histórico e a quantidade atual de registros. Percorre as posições preenchidas. | Exibe os registros armazenados. |

O histórico utiliza três vetores paralelos:

```c
transformacoes[4][40]
entradas[4]
resultados[4][200]
```

Os elementos de mesma posição correspondem ao mesmo registro. Dessa forma, o sistema armazena até quatro resultados sem utilizar `struct`.

### 2.3. Bloco de Primo

| Função | Parâmetros e processamento | Saída / responsabilidade |
|---|---|---|
| `ehPrimo(numero)` | Recebe um número inteiro por valor e verifica se ele possui exatamente dois divisores positivos. | Retorna um valor lógico indicando se o número é primo. |
| `proximoPrimo(numero)` | Recebe um número inteiro por valor e procura o próximo número primo a partir do valor informado, conforme a regra implementada. | Retorna o próximo número primo encontrado. |
| `executarPrimo(resultado, entrada)` | Coordena a funcionalidade de primos: realiza a leitura e validação dos dados, identifica a operação escolhida e chama as funções auxiliares. Recebe `resultado` para preencher o resumo e `entrada` como ponteiro para devolver o valor utilizado ao programa principal. | Apresenta o resultado da operação e devolve os dados necessários para o histórico. |

### 2.4. Bloco de Euler

| Função | Parâmetros e processamento | Saída / responsabilidade |
|---|---|---|
| `soma(numero)` | Recebe um número real por valor e calcula `e - numero`. | Retorna o valor que deve ser somado ao número informado para obter Euler. |
| `subtracao(numero)` | Recebe um número real por valor e calcula `numero - e`. | Retorna o valor que deve ser subtraído do número informado para obter Euler. |
| `produto(numero)` | Recebe um número real por valor e calcula `e / numero`. | Retorna o fator que, multiplicado pelo número informado, resulta em Euler. |
| `divisao(numero)` | Recebe um número real por valor e calcula `numero / e`. | Retorna o divisor que faz o número informado, dividido por ele, resultar em Euler. |
| `potencia(numero)` | Recebe um número real por valor e calcula o expoente da relação `numero^x = e`, utilizando logaritmos. | Retorna o expoente calculado. |
| `raiz(numero)` | Recebe um número real por valor e calcula o logaritmo do número informado na base Euler. | Retorna o resultado do logaritmo. |
| `trigonometrica1(numero)` | Recebe um número real por valor e calcula o ângulo cujo seno corresponde a `numero / e`. | Retorna o ângulo em graus, quando existe solução real. |
| `trigonometrica2(numero)` | Recebe um número real por valor e calcula o ângulo cujo seno, multiplicado pelo número informado, resulta em Euler; portanto, utiliza `e / numero` como valor do seno. | Retorna o ângulo em graus, quando existe solução real. |
| `trigonometrica3(numero)` | Recebe um número real por valor e calcula o ângulo cujo cosseno corresponde a `numero / e`. | Retorna o ângulo em graus, quando existe solução real. |
| `trigonometrica4(numero)` | Recebe um número real por valor e calcula o ângulo cujo cosseno, multiplicado pelo número informado, resulta em Euler; portanto, utiliza `e / numero` como valor do cosseno. | Retorna o ângulo em graus, quando existe solução real. |
| `executarEuler(resultado, entrada)` | Coordena a leitura e validação do número, chama as funções auxiliares, apresenta os resultados e suas interpretações. Recebe `resultado` para preencher o resumo e `entrada` como ponteiro para devolver o número informado ao programa principal. | Apresenta as transformações de Euler e fornece os dados para o histórico. |

### 2.5. Passagem de parâmetros

Na **passagem por valor**, a função recebe uma cópia do dado. É o caso dos números utilizados nas funções matemáticas: os cálculos trabalham com o valor recebido sem alterar diretamente a variável original.

Na **passagem por referência**, utiliza-se um ponteiro para permitir que a função acesse ou modifique uma variável do chamador. No Arithmos, esse recurso é empregado, por exemplo, para que `executarEuler()` e `executarPrimo()` devolvam ao programa principal o valor utilizado na operação e para que `registrarResultado()` atualize o contador do histórico por meio de `int *quantidade`.

## 3. Como compilar e executar

O projeto utiliza a biblioteca matemática padrão de C (`math.h`). Por isso, ao compilar com GCC, é necessário incluir a opção `-lm` no comando.

### 3.1. Linux (GCC)

```bash
gcc main.c -o arithmos -lm
./arithmos
```

### 3.2. Windows (MinGW/GCC)

```bash
gcc main.c -o arithmos.exe -lm
arithmos.exe
```

### 3.3. CLion

Abra o projeto no CLion, confira se `main.c` está incluído no alvo de compilação do CMake e execute a configuração do projeto pelo botão Run.

Caso o projeto utilize CMake, a biblioteca matemática deve estar vinculada ao executável no `CMakeLists.txt`, por exemplo:

```cmake
target_link_libraries(arithmos PRIVATE m)
```

Se o ambiente Windows/MinGW não reconhecer a biblioteca `m` separadamente, verifique a configuração do toolchain e a forma de vinculação aceita pelo compilador utilizado.

## 4. Organização geral

A função `main()` controla o ciclo do menu, interpreta a opção escolhida por meio de `switch-case`, chama a função principal da funcionalidade selecionada e coordena o armazenamento e a exibição do histórico.

As funções auxiliares concentram os cálculos, enquanto `executarEuler()` e `executarPrimo()` coordenam seus respectivos módulos.

---

**Andamento:** esta documentação descreve a primeira etapa do Arithmos. O desenvolvimento da segunda parte do projeto ainda está pendente.
