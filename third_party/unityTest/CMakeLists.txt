add_library(unityTest STATIC "")

set(UNITY_SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/Unity/src")
target_sources(unityTest PRIVATE ${UNITY_SRC_DIR}/unity.c ${UNITY_SRC_DIR}/../../cfg/nrf52_target_uart.c)

target_include_directories(unityTest PUBLIC ${UNITY_SRC_DIR})
target_include_directories(unityTest PUBLIC ${UNITY_SRC_DIR}/../../cfg)
target_include_directories(unityTest PUBLIC ${UNITY_SRC_DIR}/../extras/fixture/src)
target_include_directories(unityTest PUBLIC ${UNITY_SRC_DIR}/../extras/memory/src)


target_compile_options(unityTest PRIVATE -mcpu=cortex-m4 -mthumb -mabi=aapcs -mfloat-abi=hard -mfpu=fpv4-sp-d16)
target_compile_options(unityTest PRIVATE $<$<COMPILE_LANGUAGE:C>:-Wall -Werror -g -gstrict-dwarf -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-builtin -fshort-enums>)
target_compile_options(unityTest PRIVATE $<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp>)
target_compile_options(unityTest PRIVATE "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")

target_compile_definitions(unityTest PUBLIC UNITY_INCLUDE_CONFIG_H)
