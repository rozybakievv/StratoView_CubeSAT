#include <stdio.h>
#include <driver/gpio.h>
#include <driver/i2c_master.h>
#include <freertos/FreeRTOS.h>
#include <sensors/BMP180.h>

#define GPIO_BUTTON_PIN GPIO_NUM_4

#define BMP180_ADDRESS 0x77

// --- I2C Configuration --- //
static const gpio_num_t i2c_sda_pin = 21; // GPIO for SDA
static const gpio_num_t i2c_scl_pin = 22; // GPIO number for SCL

void i2c_mst_init(i2c_master_bus_handle_t *bus_handle) {
    i2c_master_bus_config_t i2c_mst_cfg = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .i2c_port = I2C_NUM_0, // Can be port 0 or 1
        .scl_io_num = i2c_scl_pin,
        .sda_io_num = i2c_sda_pin,
        .glitch_ignore_cnt = 7, // Standard
        .flags.enable_internal_pullup = false // Using external pull ups on breadboard
    };

    // Create I2C bus using handle
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_cfg, &bus_handle));
}

void app_main() {
    // -------- Button -------- //
    // Configure GPIO button (check gpio.h for struct)
    /* gpio_config_t buttonConfig = {
        .pin_bit_mask = (1ULL << GPIO_BUTTON_PIN), // 1ULL is 1 in 64bit
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE, 
        .pull_down_en = GPIO_PULLDOWN_DISABLE, // Disabled because GPIO_04 is externally pulled down (GND -> 10K Ohm -> GPIO_04)
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config(&buttonConfig); */

    i2c_master_bus_handle_t mst_bus_handle; // Represenation of I2C bus in driver
    i2c_master_bus_handle_t bmp_bus_handle;
    i2c_mst_init(&mst_bus_handle);
    bmp180_init(&mst_bus_handle, &bmp_bus_handle, BMP180_ADDRESS);

    while (1)
    {
        /* int button_state = gpio_get_level(GPIO_BUTTON_PIN);

        if (button_state == 1) // Button HIGH (pressed)
        {
            printf(":D \r\n");
        } else {
            printf(":( \r\n");
        } */


    }
}