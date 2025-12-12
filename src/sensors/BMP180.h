#ifndef BMP180
#define BMP180

void bmp180_init(i2c_master_bus_handle_t *mst_bus_handle, i2c_master_bus_handle_t *bmp_bus_handle, int address);

#endif