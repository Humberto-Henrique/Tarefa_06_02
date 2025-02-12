# Controle de Servomotor por PWM com Raspberry Pi Pico W

Este projeto tem como objetivo simular o controle do ângulo de um servomotor utilizando o módulo PWM (Pulse Width Modulation) presente no microcontrolador **RP2040** (Raspberry Pi Pico W), usando a ferramenta **Pico SDK** e a plataforma de simulação **Wokwi**. O controle do servomotor será realizado com base em diferentes ciclos de trabalho, ajustando o braço do servomotor entre 0 e 180 graus de forma suave.

## Objetivo

Simular o controle do servomotor por PWM no ambiente de desenvolvimento **VS Code** com o SDK **Pico SDK**, integrando ao simulador de eletrônica **Wokwi**. O projeto é dividido nas seguintes etapas:

1. Configurar a GPIO 22 para PWM com frequência de aproximadamente **50Hz** (período de 20ms).
2. Definir o ciclo ativo para **2.400µs** (0,12% Duty Cycle) para posicionar o servomotor em **180 graus**.
3. Definir o ciclo ativo para **1.470µs** (0,0735% Duty Cycle) para posicionar o servomotor em **90 graus**.
4. Definir o ciclo ativo para **500µs** (0,025% Duty Cycle) para posicionar o servomotor em **0 graus**.
5. Criar uma rotina de movimentação periódica do servomotor entre **0 e 180 graus**, com incremento de ciclo ativo de ±5µs e atraso de 10ms para uma movimentação suave.
6. Realizar um experimento utilizando o LED RGB na **GPIO 12** com a ferramenta BitDogLab para observar o comportamento da iluminação.

## Componentes Utilizados

- **Microcontrolador Raspberry Pi Pico W**: Utilizado como controlador principal.
- **Servomotor (micro servo padrão)**: Simulado no Wokwi.
- **LED RGB**: Utilizado para visualização adicional com o BitDogLab.
- **VS Code**: Ambiente de desenvolvimento utilizado para programar o Pico SDK.
- **Pico SDK**: Kit de desenvolvimento utilizado para programação do Raspberry Pi Pico.
- **Wokwi**: Plataforma de simulação de circuitos eletrônicos.

## Requisitos

- **VS Code** com extensão do **Pico SDK**.
- **Raspberry Pi Pico W**.
- **Simulador Wokwi** (para simulação de circuitos).
- **GitHub** para versionamento do código.

## Estrutura do Código

O código foi implementado em **C** utilizando as bibliotecas do **Pico SDK**. A seguir, é mostrado um resumo das funcionalidades implementadas:

1. **Configuração do PWM**: Inicializa a GPIO 22 com uma frequência de 50Hz e ajusta os valores do ciclo ativo conforme necessário para posicionar o servomotor.
2. **Movimentação do Servomotor**: Realiza o ajuste do servomotor entre os ângulos de 0, 90 e 180 graus e executa um movimento suave de ida e volta entre esses ângulos.
3. **Experimento com o LED RGB**: Controla a iluminação do LED RGB na GPIO 12, observando as mudanças no comportamento da iluminação à medida que o servomotor se move.

## Vídeo Demonstração

Você pode visualizar a demonstração do código e o funcionamento do servomotor aqui: https://drive.google.com/file/d/1OzOo4JUZeAVrPtSjhfcTB8dyH3IOeO1r/view?usp=sharing

