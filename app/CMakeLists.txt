include(../cmake/utils.cmake)

add_executable(blue42 "")
target_sources(blue42 PRIVATE src/main.c)
target_include_directories(blue42 PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include" "${PROJECT_BINARY_DIR}")


target_compile_options(blue42 PRIVATE -mcpu=cortex-m4 -mthumb -mabi=aapcs -mfloat-abi=hard -mfpu=fpv4-sp-d16)
target_compile_options(blue42 PRIVATE $<$<COMPILE_LANGUAGE:C>:-Wall -Werror -g -gstrict-dwarf -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-builtin -fshort-enums>)
target_compile_options(blue42 PRIVATE $<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp>)
target_compile_options(blue42 PUBLIC "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")


target_compile_definitions(blue42 PRIVATE FLOAT_ABI_HARD NRF52840_XXAA NRF_SD_BLE_API_VERSION=7 S140 SOFTDEVICE_PRESENT)
target_compile_definitions(blue42 PRIVATE $<$<COMPILE_LANGUAGE:C>:FREERTOS>)
target_compile_definitions(blue42 PRIVATE $<$<COMPILE_LANGUAGE:ASM>:__HEAP_SIZE=8192 __STACK_SIZE=8192>)

target_link_libraries(blue42 nrf52)
target_link_libraries(blue42 freertos)


target_link_directories(blue42 PRIVATE "${PROJECT_SOURCE_DIR}/linker")
target_link_options(blue42 PRIVATE -mcpu=cortex-m4 -mthumb -mabi=aapcs -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,--gc-sections -lc -lm -lnosys --specs=nano.specs -Tblue42.ld)


firmware_size(blue42)
generate_object(blue42 .bin binary)

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
    generate_object(blue42 .hex ihex)
endif()



