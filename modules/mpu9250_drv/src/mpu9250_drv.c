#define _MPU9250_DRV_C_SRC

//-------------------------MODULES USED-------------------------------------
#include "nrfx_spi.h"
#include "nrf_gpio.h"

#include "mpu9250_drv.h"
//-------------------------DEFINITIONS AND MACORS---------------------------
#define SPI_INSTANCE  0
#define BUF_LEN 8

#define NRFX_SPI_SCK_PIN  29
#define NRFX_SPI_MOSI_PIN 4
#define NRFX_SPI_MISO_PIN 28
#define NRFX_SPI_SS_PIN   3

#define REG_SAMPLE_RATE_DIV 25
#define REG_CONFIGURATION 26
#define REG_GYRO_CONFIG 27
#define REG_WHO_AM_I 117
//-------------------------TYPEDEFS AND STRUCTURES--------------------------



//-------------------------PROTOTYPES OF LOCAL FUNCTIONS--------------------



//-------------------------EXPORTED VARIABLES ------------------------------



//-------------------------GLOBAL VARIABLES---------------------------------
static const nrfx_spi_t g_spi = NRFX_SPI_INSTANCE(SPI_INSTANCE);
static uint8_t g_tx_buf[BUF_LEN];
static uint8_t g_rx_buf[BUF_LEN];
static size_t g_tx_len = 0;
static size_t g_rx_len = 0;


//-------------------------EXPORTED FUNCTIONS-------------------------------
int32_t mpu9250_drv_init(void)
{
    nrfx_spi_config_t spi_config;

    spi_config.sck_pin = NRFX_SPI_SCK_PIN;
    spi_config.mosi_pin = NRFX_SPI_MOSI_PIN;
    spi_config.miso_pin = NRFX_SPI_MISO_PIN;
    spi_config.ss_pin = NRFX_SPI_SS_PIN;
    spi_config.irq_priority = 6;
    spi_config.orc = 'a';
    spi_config.frequency = NRF_SPI_FREQ_1M;
    spi_config.mode = NRF_SPI_MODE_3;
    spi_config.bit_order = NRF_SPI_BIT_ORDER_MSB_FIRST;
    int32_t ret = nrfx_spi_init(&g_spi, &spi_config, NULL, NULL);
    if(NRFX_SUCCESS != ret){
        return MPU9250_DRIVER_INIT_FAIL;
    }
    //nrf_gpio_cfg_output(NRFX_SPI_SS_PIN);

    return MPU9250_OK;
}

int32_t mpu9250_drv_unit(void)
{
    nrfx_spi_uninit(&g_spi);
    return MPU9250_OK;
}

int32_t mpu9250_drv_who_am_i(uint8_t * p_whoami)
{

    return mpu9250_drv_read((REG_WHO_AM_I), p_whoami, 1);

}

int32_t mpu9250_drv_set_sample_rate_divider(uint8_t divider)
{
    return mpu9250_drv_write(REG_SAMPLE_RATE_DIV, &divider, 1);
}

int32_t mpu9250_drv_get_sample_rate_divider(uint8_t * const p_divider)
{
    return mpu9250_drv_read(REG_SAMPLE_RATE_DIV, p_divider, 1);
}

int32_t mpu9250_drv_set_fifo_mode(fifo_mode_e mode)
{
    uint8_t reg_val;
    int32_t ret = mpu9250_drv_read(REG_CONFIGURATION, &reg_val, 1);
    if(0 != ret){
        return ret;
    }

    switch(mode){
        case FIFO_OVERWRITE:{
            reg_val &= ~0x40; //set bit6 hi
            break;
        }

        case FIFO_NO_OVERWRITE:{
            reg_val |= 0x40; //set bit6 low
            break;
        }
        default:{
            return MPU9250_ILLEGAL_VALUE;
            break;
        }
    }
    return mpu9250_drv_write(REG_CONFIGURATION, &reg_val, 1);
}

int32_t mpu9250_drv_get_fifo_mode(fifo_mode_e * const p_mode)
{
    uint8_t reg_val = 0;
    int32_t ret = mpu9250_drv_read(REG_CONFIGURATION, &reg_val, 1);
    if(0 != ret){
        return ret;
    }
    if(0x40 & reg_val){//check for bit 6 hi
        *p_mode = FIFO_NO_OVERWRITE;
    }else{
        *p_mode = FIFO_OVERWRITE;
    }

    return ret;
}



int32_t mpu9250_drv_set_ext_sync_location(ext_sync_e location)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_enable_gdlpf(bool dlpf_en)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_cfg_gyro_dlpf(uint8_t dlpf_cfg)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_set_gyro_offset(int16_t x_offs, int16_t y_offs, int16_t z_offs)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_set_gyro_fs_sel(gyro_fs_e full_scale_dps)
{
    uint8_t reg_val = 0;
    int32_t ret = mpu9250_drv_read(REG_GYRO_CONFIG, &reg_val, 1);
    if(0 != ret){
        return ret;
    }
    switch(full_scale_dps){
        case FS_250_DPS:{
            reg_val &= ~(0x18);
            break;
        }

        case FS_500_DPS:{
            reg_val &= ~(0x18);
            reg_val |= 0x08;
            break;
        }

        case FS_1000_DPS:{
            reg_val &= ~(0x18);
            reg_val |= 0x10;
            break;
        }

        case FS_2000_DPS:{
            reg_val &= ~(0x18);
            reg_val |= 0x18;
            break;
        }

        default:{
            return MPU9250_ILLEGAL_VALUE;
            break;
        }
    }
    return mpu9250_drv_write(REG_GYRO_CONFIG, &reg_val, 1);

}

int32_t mpu9250_drv_get_gyro_fs_sel(gyro_fs_e * const p_full_scale_dps)
{
    uint8_t reg_val = 0;
    int32_t ret = mpu9250_drv_read(REG_GYRO_CONFIG, &reg_val, 1);
    if(0 != ret){
        return ret;
    }

    reg_val = (reg_val>>3) & (0x03);
    switch(reg_val){
        case 0:{
            *p_full_scale_dps = FS_250_DPS;
            break;
        }

        case 1:{
            *p_full_scale_dps = FS_500_DPS;
            break;
        }
        case 2:{
            *p_full_scale_dps = FS_1000_DPS;
            break;
        }

        case 3:{
            *p_full_scale_dps = FS_2000_DPS;
            break;
        }

        default:{
            return MPU9250_ILLEGAL_VALUE;
            break;
        }
    }

    return MPU9250_OK;
}

int32_t mpu9250_drv_enable_gyro_self_test(bool x_self, bool y_self, bool z_self)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_enable_fifo_gyro(bool fifo_x_en, bool fifo_y_en, bool fifo_z_en)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_set_accel_fs_sel(accel_fs_e full_scale_g)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_enable_accel_self_test(bool x_self, bool y_self, bool z_self)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_enable_accel_dlpf(bool dlpf_en)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_cfg_accel_dlpf(uint8_t dlpf_cfg)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_enable_fifo_accel(bool fifo_en)
{

    return MPU9250_OK;
}


int32_t mpu9250_drv_enable_fifo_temp(bool fifo_en)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_set_lowpower_clk(lowpwr_clk_e freq)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_set_wake_on_motion_thrsh(uint8_t thrsh)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_enable_wake_on_motion_int(bool wom_en)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_enable_fifo_ovflw_int(bool fifo_ovflw_en)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_enable_fsync_int(bool fsync_en)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_enable_raw_rdy_int(bool raw_rdy_en)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_set_int_pin_logic_level(int_logic_level_e level)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_set_pin_drv(int_drv_e drv)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_set_latch_mode(latch_mode_e mode)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_set_status_clear_mode(status_clear_e mode)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_set_fsync_logic_level(fsync_logic_level_e level)
{

    return MPU9250_OK;
}


int32_t mpu9250_drv_enable_bypass(bool bypass_en)
{

    return MPU9250_OK;
}

int32_t mpu9250_drv_write(uint8_t reg_addr, uint8_t const * const p_write_buf, size_t len)
{
    if(len > (BUF_LEN - 1)){
        return MPU9250_BUFFER_SIZE;
    }
    g_tx_buf[0] = reg_addr;
    memcpy(g_tx_buf+1, p_write_buf, len);
    g_tx_len = len+1;
    nrfx_spi_xfer_desc_t xfer_desc = NRFX_SPI_XFER_TX(g_tx_buf, g_tx_len);
    nrfx_err_t err = nrfx_spi_xfer(&g_spi, &xfer_desc, 0);
    if(NRFX_SUCCESS != err){
        return  MPU9250_DRIVER_READWRITE_FAIL;
    }

    return MPU9250_OK;
}

int32_t mpu9250_drv_read(uint8_t reg_addr, uint8_t * const p_read_buf, size_t len)
{
    if(len > (BUF_LEN - 1)){
        return MPU9250_BUFFER_SIZE;
    }
    reg_addr |= 0x80;
    g_tx_buf[0] = reg_addr;
    g_tx_len = len+1;
    g_rx_len = len+1;
    nrfx_spi_xfer_desc_t xfer_desc = NRFX_SPI_SINGLE_XFER(g_tx_buf, g_tx_len, g_rx_buf, g_tx_len);
    nrfx_err_t err = nrfx_spi_xfer(&g_spi, &xfer_desc, 0);
    if(NRFX_SUCCESS != err){
        return  MPU9250_DRIVER_READWRITE_FAIL;
    }
    memcpy(p_read_buf, g_rx_buf + 1, len);

    return MPU9250_OK;
}


//-------------------------LOCAL FUNCTIONS----------------------------------
