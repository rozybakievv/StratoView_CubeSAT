#include <stdio.h>
#include <driver/gpio.h>
#include <driver/i2c_master.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <sdkconfig.h>
#include <math.h>
#include <esp_log.h>

#define I2C_MASTER_TIMEOUT_MS 1000

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

// Read byte from device, specify: reg, len and how many bytes 
static esp_err_t read_byte_i2c(i2c_master_dev_handle_t dev_handle, uint8_t reg_addr, uint8_t *data, size_t len) {
    return i2c_master_transmit_receive(dev_handle, &reg_addr, 1, data, len, I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);
}

static esp_err_t write_byte_i2c(i2c_master_dev_handle_t dev_handle, uint8_t reg_addr, uint8_t data) {
    uint8_t write_buf[2] = {reg_addr, data}; // Packet is 2 bytes, reg and data
    return i2c_master_transmit(dev_handle, write_buf, sizeof(write_buf), I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);
}