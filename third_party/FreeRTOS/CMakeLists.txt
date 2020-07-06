add_library(freertos STATIC "")

set(FREERTOS_SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/amazon-freertos/freertos_kernel")
target_sources(freertos PRIVATE
  "${FREERTOS_SRC_DIR}/croutine.c"
  "${FREERTOS_SRC_DIR}/event_groups.c"
  "${FREERTOS_SRC_DIR}/list.c"
  "${FREERTOS_SRC_DIR}/queue.c"
  "${FREERTOS_SRC_DIR}/stream_buffer.c"
  "${FREERTOS_SRC_DIR}/tasks.c"
  "${FREERTOS_SRC_DIR}/timers.c"
  "${FREERTOS_SRC_DIR}/portable/GCC/ARM_CM4F/port.c"
  "${FREERTOS_SRC_DIR}/portable/MemMang/heap_4.c")
target_include_directories(freertos PUBLIC "${FREERTOS_SRC_DIR}/include")
target_include_directories(freertos PUBLIC "${CMAKE_CURRENT_LIST_DIR}/freertos_cfg")
target_include_directories(freertos PUBLIC "${FREERTOS_SRC_DIR}/portable/GCC/ARM_CM4F")

target_link_libraries(freertos nrf52)

target_compile_options(freertos PRIVATE -mcpu=cortex-m4 -mthumb -mabi=aapcs -mfloat-abi=hard -mfpu=fpv4-sp-d16)
target_compile_options(freertos PRIVATE $<$<COMPILE_LANGUAGE:C>:-Wall -Werror -g -gstrict-dwarf -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-builtin -fshort-enums>)
target_compile_options(freertos PRIVATE $<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp>)
target_compile_options(freertos PRIVATE "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")
target_compile_definitions(freertos PRIVATE FLOAT_ABI_HARD NRF52840_XXAA NRF_SD_BLE_API_VERSION=7 S140 SOFTDEVICE_PRESENT)
