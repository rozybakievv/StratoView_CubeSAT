#include <stdio.h>
#include <driver/gpio.h>
#include <driver/i2c_master.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <sdkconfig.h>
#include <math.h>
#include <esp_log.h>
#include <i2c/i2c.h>
#include <sensors/bmp180/BMP180.h>

void app_main() {
    // Init I2C and devices
    i2c_master_bus_handle_t mst_bus_handle; // Represenation of I2C bus in driver
    i2c_master_bus_handle_t bmp_bus_handle;
    i2c_mst_init(&mst_bus_handle);
    bmp180_init(&mst_bus_handle, &bmp_bus_handle);

    while (1)
    {

    }
}