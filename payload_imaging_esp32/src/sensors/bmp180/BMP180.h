#ifndef BMP180_H
#define BMP180_H

#include "driver/i2c_master.h"

void bmp180_init(
    i2c_master_bus_handle_t *mst_bus_handle,
    i2c_master_dev_handle_t *bmp_dev_handle
);

#endif