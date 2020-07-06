add_subdirectory(FreeRTOS)
add_subdirectory(unityTest)

add_library(nrf52 STATIC "")
set(NRF52_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/nRF5_SDK_17.0.0_9d13099)
target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/modules/nrfx/mdk/gcc_startup_nrf52840.S
  ${NRF52_SRC_DIR}/modules/nrfx/mdk/system_nrf52840.c
  ${NRF52_SRC_DIR}/components/softdevice/common/nrf_sdh_freertos.c
  ${NRF52_SRC_DIR}/components/softdevice/common/nrf_sdh_soc.c
  ${NRF52_SRC_DIR}/components/softdevice/common/nrf_sdh.c)

target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/modules/nrfx/drivers/src/nrfx_spi.c
  ${NRF52_SRC_DIR}/modules/nrfx/drivers/src/prs/nrfx_prs.c)


target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/../nrf5_sdk_config)

target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/modules/nrfx
  ${NRF52_SRC_DIR}/modules/nrfx/soc
  ${NRF52_SRC_DIR}/modules/nrfx/mdk
  ${NRF52_SRC_DIR}/modules/nrfx/hal
  ${NRF52_SRC_DIR}/modules/nrfx/drivers
  ${NRF52_SRC_DIR}/modules/nrfx/drivers/include
  ${NRF52_SRC_DIR}/modules/nrfx/drivers/src
  ${NRF52_SRC_DIR}/modules/nrfx/drivers/src/prs
  ${NRF52_SRC_DIR}/modules/nrfx/templates
  ${NRF52_SRC_DIR}/modules/nrfx/templates/NRF52840
  ${NRF52_SRC_DIR}/modules/nrfx/helpers)


target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/integration/nrfx
  ${NRF52_SRC_DIR}/integration/nrfx/legacy)

target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/toolchain/cmsis/include)

target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/softdevice/common
  ${NRF52_SRC_DIR}/components/softdevice/mbr/headers
  ${NRF52_SRC_DIR}/components/softdevice/s140/headers
  ${NRF52_SRC_DIR}/components/softdevice/s140/headers/nrf52)

target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/ble/ble_advertising
  ${NRF52_SRC_DIR}/components/ble/ble_db_discovery
  ${NRF52_SRC_DIR}/components/ble/ble_dtm
  ${NRF52_SRC_DIR}/components/ble/ble_link_ctx_manager
  ${NRF52_SRC_DIR}/components/ble/ble_racp
  ${NRF52_SRC_DIR}/components/ble/ble_radio_notification
  ${NRF52_SRC_DIR}/components/ble/ble_services
  ${NRF52_SRC_DIR}/components/ble/common
  ${NRF52_SRC_DIR}/components/ble/nrf_ble_gatt
  ${NRF52_SRC_DIR}/components/ble/nrf_ble_gq
  ${NRF52_SRC_DIR}/components/ble/nrf_ble_qwr
  ${NRF52_SRC_DIR}/components/ble/nrf_ble_scan
  ${NRF52_SRC_DIR}/components/ble/peer_manager)

target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/components/libraries/util/app_error.c
  ${NRF52_SRC_DIR}/components/libraries/util/app_error_handler_gcc.c
  ${NRF52_SRC_DIR}/components/libraries/util/app_error_weak.c
  ${NRF52_SRC_DIR}/components/libraries/util/app_util_platform.c
  ${NRF52_SRC_DIR}/components/libraries/util/nrf_assert.c
  ${NRF52_SRC_DIR}/components/libraries/util/sdk_mapped_flags.c)
target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/libraries/util)

target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/components/libraries/experimental_section_vars/nrf_section_iter.c)
target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/libraries/experimental_section_vars)

target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/components/libraries/fstorage/nrf_fstorage.c
  ${NRF52_SRC_DIR}/components/libraries/fstorage/nrf_fstorage_nvmc.c
  ${NRF52_SRC_DIR}/components/libraries/fstorage/nrf_fstorage_sd.c)
target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/libraries/fstorage)

target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/components/libraries/log/src/nrf_log_backend_flash.c
  ${NRF52_SRC_DIR}/components/libraries/log/src/nrf_log_backend_rtt.c
  ${NRF52_SRC_DIR}/components/libraries/log/src/nrf_log_backend_serial.c
  ${NRF52_SRC_DIR}/components/libraries/log/src/nrf_log_backend_uart.c
  ${NRF52_SRC_DIR}/components/libraries/log/src/nrf_log_default_backends.c
  ${NRF52_SRC_DIR}/components/libraries/log/src/nrf_log_frontend.c
  ${NRF52_SRC_DIR}/components/libraries/log/src/nrf_log_str_formatter.c)
target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/libraries/log
  ${NRF52_SRC_DIR}/components/libraries/log/src)


target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/components/libraries/strerror/nrf_strerror.c)
target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/libraries/strerror)

target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/components/libraries/memobj/nrf_memobj.c)
target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/libraries/memobj)

target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/components/libraries/balloc/nrf_balloc.c)
target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/libraries/balloc)

target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/components/libraries/atomic/nrf_atomic.c)
target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/libraries/atomic)

target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/components/libraries/fds/fds.c)
target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/libraries/fds)

target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/components/libraries/ringbuf/nrf_ringbuf.c)
target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/components/libraries/ringbuf)

target_sources(nrf52 PRIVATE ${NRF52_SRC_DIR}/external/fprintf/nrf_fprintf.c
  ${NRF52_SRC_DIR}/external/fprintf/nrf_fprintf_format.c)
target_include_directories(nrf52 PUBLIC ${NRF52_SRC_DIR}/external/fprintf)


target_compile_options(nrf52 PRIVATE -mcpu=cortex-m4 -mthumb -mabi=aapcs -mfloat-abi=hard -mfpu=fpv4-sp-d16)
target_compile_options(nrf52 PRIVATE $<$<COMPILE_LANGUAGE:C>:-Wall -Werror -g -gstrict-dwarf -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-builtin -fshort-enums>)
target_compile_options(nrf52 PRIVATE $<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp>)
target_compile_options(nrf52 PRIVATE "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")

target_compile_definitions(nrf52 PUBLIC BOARD_PCA10056 FLOAT_ABI_HARD NRF52840_XXAA NRF_SD_BLE_API_VERSION=7 S140 SOFTDEVICE_PRESENT)
target_compile_definitions(nrf52 PRIVATE $<$<COMPILE_LANGUAGE:ASM>:__HEAP_SIZE=8192 __STACK_SIZE=8192>)


target_link_libraries(nrf52 freertos)
