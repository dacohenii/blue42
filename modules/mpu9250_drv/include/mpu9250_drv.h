#ifndef _MPU9150_DRV_INCLUDED
#define _MPU9150_DRV_INCLUDED
//-------------------------MODULES USED-------------------------------------
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


//-------------------------DEFINITIONS AND MACORS---------------------------
#define MPU9250_OK 0
#define MPU9250_ILLEGAL_VALUE -1
#define MPU9250_DRIVER_INIT_FAIL -2
#define MPU9250_DRIVER_READWRITE_FAIL -3
#define MPU9250_BUFFER_SIZE -4


//-------------------------TYPEDEFS AND STRUCTURES--------------------------
typedef enum fifo_mode{
    FIFO_OVERWRITE = 0,
    FIFO_NO_OVERWRITE = 1
}fifo_mode_e;

typedef enum gyro_fs{
    FS_250_DPS = 0,
    FS_500_DPS = 1,
    FS_1000_DPS = 2,
    FS_2000_DPS =3
}gyro_fs_e;

typedef enum accel_fs{
    FS_2G = 0,
    FS_4G = 1,
    FS_8G = 2,
    FS_16G = 3
}accel_fs_e;

typedef enum ext_sync{
    EXT_SYNC_DISABLED = 0,
    EXT_SYNC_TEMP_OUT = 1,
    EXT_SYNC_GYRO_XOUT = 2,
    EXT_SYNC_GYRO_YOUT = 3,
    EXT_SYNC_GYRO_ZOUT = 4,
    EXT_SYNC_ACCEL_XOUT = 5,
    EXT_SYNC_ACCEL_YOUT = 6,
    EXT_SYNC_ACCEL_ZOUT = 7
}ext_sync_e;

typedef enum lowpwr_clk{
    HZ_0_24 = 0,
    HZ_0_49 = 1,
    HZ_0_98 = 2,
    HZ_1_95 = 3,
    HZ_3_91 = 4,
    HZ_7_81 = 5,
    HZ_15_63 = 6,
    HZ_31_25 = 7,
    HZ_62_50 = 8,
    HZ_125 = 9,
    HZ_250 = 10,
    HZ_500 = 11
}lowpwr_clk_e;

typedef enum int_logic_level{
    LOGIC_ACTIVE_HIGH = 0,
    LOGIC_ACTIVE_LOW = 1
}int_logic_level_e;

typedef enum int_drv{
    DRV_PUSH_PULL = 0,
    DRV_OPEN_DRAIN = 1
}int_drv_e;

typedef enum latch_mode{
    INT_WIDTH_50US = 0,
    INT_HELD = 1
}latch_mode_e;

typedef enum status_clear{
    STATUS_CLEAR_STATUS_READ = 0,
    STATUS_CLEAR_ANY_READ = 1
}status_clear_e;

typedef enum fsync_logic_level{
    FSYNC_LOGIC_ACTIVE_HIGH = 0,
    FSYNC_LOGIC_ACTIVE_LOW = 1
}fsync_logic_level_e;
//-------------------------EXPORTED VARIABLES ------------------------------
#ifndef _MPU9150_DRV_C_SRC



#endif



//-------------------------EXPORTED FUNCTIONS-------------------------------
int32_t mpu9250_drv_init(void);
int32_t mpu9250_drv_unit(void);

int32_t mpu9250_drv_who_am_i(uint8_t * p_whoami);

int32_t mpu9250_drv_set_sample_rate_divider(uint8_t divider);
int32_t mpu9250_drv_get_sample_rate_divider(uint8_t * const p_divider);
int32_t mpu9250_drv_set_fifo_mode(fifo_mode_e mode);
int32_t mpu9250_drv_get_fifo_mode(fifo_mode_e * const p_mode);
int32_t mpu9250_drv_set_ext_sync_location(ext_sync_e location);
int32_t mpu9250_drv_enable_gdlpf(bool dlpf_en);
int32_t mpu9250_drv_cfg_gyro_dlpf(uint8_t dlpf_cfg);
int32_t mpu9250_drv_set_gyro_offset(int16_t x_offs, int16_t y_offs, int16_t z_offs);
int32_t mpu9250_drv_set_gyro_fs_sel(gyro_fs_e full_scale_dps);
int32_t mpu9250_drv_get_gyro_fs_sel(gyro_fs_e * const p_full_scale_dps);
int32_t mpu9250_drv_enable_gyro_self_test(bool x_self, bool y_self, bool z_self);
int32_t mpu9250_drv_enable_fifo_gyro(bool fifo_x_en, bool fifo_y_en, bool fifo_z_en);

int32_t mpu9250_drv_set_accel_fs_sel(accel_fs_e full_scale_g);
int32_t mpu9250_drv_enable_accel_self_test(bool x_self, bool y_self, bool z_self);
int32_t mpu9250_drv_enable_accel_dlpf(bool dlpf_en);
int32_t mpu9250_drv_cfg_accel_dlpf(uint8_t dlpf_cfg);
int32_t mpu9250_drv_enable_fifo_accel(bool fifo_en);

int32_t mpu9250_drv_enable_fifo_temp(bool fifo_en);


int32_t mpu9250_drv_set_lowpower_clk(lowpwr_clk_e freq);
int32_t mpu9250_drv_set_wake_on_motion_thrsh(uint8_t thrsh);
int32_t mpu9250_drv_enable_wake_on_motion_int(bool wom_en);
int32_t mpu9250_drv_enable_fifo_ovflw_int(bool fifo_ovflw_en);
int32_t mpu9250_drv_enable_fsync_int(bool fsync_en);
int32_t mpu9250_drv_enable_raw_rdy_int(bool raw_rdy_en);

int32_t mpu9250_drv_set_int_pin_logic_level(int_logic_level_e level);
int32_t mpu9250_drv_set_pin_drv(int_drv_e drv);
int32_t mpu9250_drv_set_latch_mode(latch_mode_e mode);
int32_t mpu9250_drv_set_status_clear_mode(status_clear_e mode);
int32_t mpu9250_drv_set_fsync_logic_level(fsync_logic_level_e level);
int32_t mpu9250_drv_enable_bypass(bool bypass_en);

int32_t mpu9250_drv_write(uint8_t reg_addr, uint8_t const * const p_write_buf, size_t len);
int32_t mpu9250_drv_read(uint8_t reg_addr, uint8_t * const p_read_buf, size_t len);




#endif
