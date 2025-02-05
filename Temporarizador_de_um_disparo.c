#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define Led_Vermelho 13
#define Led_Azul 12
#define Led_Verde 11
#define botao 5

bool ativo = false;

int64_t desligar_led_vermelho(alarm_id_t id, void *user_data);
int64_t desligar_led_azul(alarm_id_t id, void *user_data);
int64_t desligar_led_verde(alarm_id_t id, void *user_data);

int64_t desligar_led_vermelho(alarm_id_t id, void *user_data)
{
    gpio_put(Led_Vermelho, 0);
    add_alarm_in_ms(3000, desligar_led_azul, NULL, false);
    return 0;
}

int64_t desligar_led_azul(alarm_id_t id, void *user_data)
{
    gpio_put(Led_Azul, 0);
    add_alarm_in_ms(3000, desligar_led_verde, NULL, false);
    return 0;
}

int64_t desligar_led_verde(alarm_id_t id, void *user_data)
{
    gpio_put(Led_Verde, 0);
    ativo = false;
    return 0;
}

int main()
{

    stdio_init_all();

    gpio_init(Led_Vermelho);
    gpio_set_dir(Led_Vermelho, GPIO_OUT);

    gpio_init(Led_Azul);
    gpio_set_dir(Led_Azul, GPIO_OUT);

    gpio_init(Led_Verde);
    gpio_set_dir(Led_Verde, GPIO_OUT);

    gpio_init(botao);
    gpio_set_dir(botao, GPIO_IN);
    gpio_pull_up(botao);

    while (true)
    {
        if (gpio_get(botao) == 0 && ativo == false)
        {
            gpio_put(Led_Vermelho, 1);
            gpio_put(Led_Azul, 1);
            gpio_put(Led_Verde, 1);
            ativo = true;
            add_alarm_in_ms(3000, desligar_led_vermelho, NULL, false);
        }
    }
    return 0;
}
