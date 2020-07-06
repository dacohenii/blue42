#define _TEST1_C_SRC

//-------------------------MODULES USED-------------------------------------
#include "unity.h"
#include "mpu9250_drv.h"

//-------------------------DEFINITIONS AND MACORS---------------------------
#define WHO_AM_I_VAL (0x71)


//-------------------------TYPEDEFS AND STRUCTURES--------------------------



//-------------------------PROTOTYPES OF LOCAL FUNCTIONS--------------------



//-------------------------EXPORTED VARIABLES ------------------------------



//-------------------------GLOBAL VARIABLES---------------------------------



//-------------------------EXPORTED FUNCTIONS-------------------------------
void setUp(void)
{
    mpu9250_drv_init();
}

void tearDown(void)
{
    mpu9250_drv_unit();
}


void test_who_am_i_read(void)
{
    uint8_t val_who_am_i = 0;
    int32_t ret = mpu9250_drv_who_am_i(&val_who_am_i);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);
    TEST_ASSERT_EQUAL_UINT8(WHO_AM_I_VAL, val_who_am_i);

}

void test_sample_rate_divider(void)
{
    for(int i = 0;i<=255;i++){
        uint8_t divider;
        if(0 == 1){
            divider = 1;
        }else{
            divider = 0;
        }

        int32_t ret = mpu9250_drv_set_sample_rate_divider(i);
        TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);
        ret = mpu9250_drv_get_sample_rate_divider(&divider);
        TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);
        TEST_ASSERT_EQUAL_UINT8(i, divider);
    }
}

void test_enabling_disabling_fifo_modes(void)
{
    int32_t ret = mpu9250_drv_set_fifo_mode(FIFO_OVERWRITE);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);
    fifo_mode_e mode;
    ret = mpu9250_drv_get_fifo_mode(&mode);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);
    TEST_ASSERT_EQUAL_INT(FIFO_OVERWRITE, mode);

    ret = mpu9250_drv_set_fifo_mode(FIFO_NO_OVERWRITE);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);
    ret = mpu9250_drv_get_fifo_mode(&mode);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);
    TEST_ASSERT_EQUAL_INT(FIFO_NO_OVERWRITE, mode);

}

void test_gyro_fs_select(void)
{
    int32_t ret = mpu9250_drv_set_gyro_fs_sel(FS_250_DPS);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);

    gyro_fs_e dps;
    ret = mpu9250_drv_get_gyro_fs_sel(&dps);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);
    TEST_ASSERT_EQUAL_INT(FS_250_DPS, dps);

    ret = mpu9250_drv_set_gyro_fs_sel(FS_500_DPS);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);

    ret = mpu9250_drv_get_gyro_fs_sel(&dps);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);
    TEST_ASSERT_EQUAL_INT(FS_500_DPS, dps);

    ret = mpu9250_drv_set_gyro_fs_sel(FS_1000_DPS);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);

    ret = mpu9250_drv_get_gyro_fs_sel(&dps);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);
    TEST_ASSERT_EQUAL_INT(FS_1000_DPS, dps);

    ret = mpu9250_drv_set_gyro_fs_sel(FS_2000_DPS);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);

    ret = mpu9250_drv_get_gyro_fs_sel(&dps);
    TEST_ASSERT_EQUAL_INT(MPU9250_OK, ret);
    TEST_ASSERT_EQUAL_INT(FS_2000_DPS, dps);

}

//-------------------------LOCAL FUNCTIONS----------------------------------
