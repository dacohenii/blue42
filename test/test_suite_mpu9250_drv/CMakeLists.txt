include(../../cmake/utils.cmake)

add_executable(blue42_test_mpu9250_drv "")
target_sources(blue42_test_mpu9250_drv PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/main_test_mpu9250.c src/test_mpu9250_drv.c)
target_include_directories(blue42_test_mpu9250_drv PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include ${PROJECT_BINARY_DIR})


target_compile_options(blue42_test_mpu9250_drv PRIVATE -mcpu=cortex-m4 -mthumb -mabi=aapcs -mfloat-abi=hard -mfpu=fpv4-sp-d16)
target_compile_options(blue42_test_mpu9250_drv PRIVATE $<$<COMPILE_LANGUAGE:C>:-Wall -Werror -g -gstrict-dwarf -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-builtin -fshort-enums>)
target_compile_options(blue42_test_mpu9250_drv PRIVATE $<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp>)
target_compile_options(blue42_test_mpu9250_drv PRIVATE "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")

target_compile_definitions(blue42_test_mpu9250_drv PRIVATE BOARD_PCA10056 CONFIG_GPIO_AS_PINRESET FLOAT_ABI_HARD NRF52840_XXAA NRF_SD_BLE_API_VERSION=7 S140 SOFTDEVICE_PRESENT)
target_compile_definitions(blue42_test_mpu9250_drv PUBLIC $<$<COMPILE_LANGUAGE:C>:FREERTOS UNITY_INCLUDE_CONFIG_H>)
target_compile_definitions(blue42_test_mpu9250_drv PRIVATE $<$<COMPILE_LANGUAGE:ASM>:__HEAP_SIZE=8192 __STACK_SIZE=8192>)


target_link_libraries(blue42_test_mpu9250_drv unityTest)
target_link_libraries(blue42_test_mpu9250_drv nrf52)
target_link_libraries(blue42_test_mpu9250_drv mpu9250_drv)



target_link_directories(blue42_test_mpu9250_drv PRIVATE "${PROJECT_SOURCE_DIR}/linker")
target_link_options(blue42_test_mpu9250_drv PRIVATE -mcpu=cortex-m4 -mthumb -mabi=aapcs -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,--gc-sections -lc -lm -lnosys --specs=nano.specs -Tblue42.ld)


firmware_size(blue42_test_mpu9250_drv)
generate_object(blue42_test_mpu9250_drv .bin binary)

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  generate_object(blue42_test_mpu9250_drv .hex ihex)
endif()
