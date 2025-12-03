#include <stdio.h>
#include <driver/gpio.h>

#define GPIO_BUTTON_PIN GPIO_NUM_4

void app_main() {
    // Configure GPIO button (check gpio.h for struct)
    gpio_config_t buttonConfig = {
        .pin_bit_mask = (1ULL << GPIO_BUTTON_PIN), // 1ULL is 1 in 64bit
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE, 
        .pull_down_en = GPIO_PULLDOWN_DISABLE, // Disabled because GPIO_04 is externally pulled down (GND -> 10K Ohm -> GPIO_04)
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config(&buttonConfig);

    while (1)
    {
        int button_state = gpio_get_level(GPIO_BUTTON_PIN);

        if (button_state == 1) // Button HIGH (pressed)
        {
            printf(":D \r\n");
        } else {
            printf(":( \r\n");
        }
    }
}