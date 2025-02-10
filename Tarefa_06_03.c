#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_PIN 22  // Definir a GPIO 22 como pino de controle do servomotor

int main() {
    // Inicializando a GPIO e PWM
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);
    
    // Definindo a frequência para 50Hz (período de 20ms)
    pwm_set_clkdiv(slice_num, 125.0);  // Divisor para definir a frequência
    pwm_set_wrap(slice_num, 20000);  // Para ter o período de 20ms (50Hz)

    // Iniciando o PWM
    pwm_set_enabled(slice_num, true);

    // Requisito 1: Ajuste para 180 graus - 2400µs (~0,12% de Duty Cycle)
    pwm_set_chan_level(slice_num, 0, 2400);  // 2400µs
    sleep_ms(5000);  // Aguarda 5 segundos

    // Requisito 2: Ajuste para 90 graus - 1470µs (~0,0735% de Duty Cycle)
    pwm_set_chan_level(slice_num, 0, 1470);  // 1470µs
    sleep_ms(5000);  // Aguarda 5 segundos

    // Requisito 3: Ajuste para 0 graus - 500µs (~0,025% de Duty Cycle)
    pwm_set_chan_level(slice_num, 0, 500);   // 500µs
    sleep_ms(5000);  // Aguarda 5 segundos

    // Requisito 5: Movimentação suave do servomotor entre 0 e 180 graus
    while (true) {
        // Movimentando de 0 até 180 graus com incremento de ±5µs
        for (int pulse = 500; pulse <= 2400; pulse += 5) {
            pwm_set_chan_level(slice_num, 0, pulse);  // Ajusta a posição
            sleep_ms(10);  // Atraso de 10ms para suavizar o movimento
        }

        // Movimentando de 180 até 0 graus com incremento de ±5µs
        for (int pulse = 2400; pulse >= 500; pulse -= 5) {
            pwm_set_chan_level(slice_num, 0, pulse);  // Ajusta a posição
            sleep_ms(10);  // Atraso de 10ms para suavizar o movimento
        }
    }

    return 0;
}
