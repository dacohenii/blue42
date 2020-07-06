#define _MAIN_TEST1_C_SRC

//-------------------------MODULES USED-------------------------------------
#include "unity.h"
#include "test_mpu9250_drv.h"


//-------------------------DEFINITIONS AND MACORS---------------------------

//-------------------------TYPEDEFS AND STRUCTURES--------------------------



//-------------------------PROTOTYPES OF LOCAL FUNCTIONS--------------------



//-------------------------EXPORTED VARIABLES ------------------------------



//-------------------------GLOBAL VARIABLES---------------------------------



//-------------------------EXPORTED FUNCTIONS-------------------------------


int main(void)
{
    UnityBegin("test_mpu9250_drv.c");
    DO_TEST(test_who_am_i_read);
    DO_TEST(test_sample_rate_divider);
    DO_TEST(test_enabling_disabling_fifo_modes);
    DO_TEST(test_gyro_fs_select);

    UnityEnd();
    while(1);
    return 0;
}


void HardFault_Handler(void)
{

    while(1);
}

//-------------------------LOCAL FUNCTIONS----------------------------------
