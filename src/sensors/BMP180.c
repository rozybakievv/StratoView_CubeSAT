#include <stdio.h>
#include <sensors/BMP180.h>
#include <driver/i2c_master.h>
#include <freertos/FreeRTOS.h>

void bmp180_init(i2c_master_bus_handle_t *mst_bus_handle, i2c_master_bus_handle_t *bmp_bus_handle, int address) {
    i2c_device_config_t bmp180_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_7,
        .device_address = address,
        .scl_speed_hz = 100000, // 100kHz (standard mode) - 400kHz (fast mode)
        .scl_wait_us = 0 // Use default register value
    };

    ESP_ERROR_CHECK(i2c_master_bus_add_device(mst_bus_handle, &bmp180_cfg, &bmp_bus_handle));
}