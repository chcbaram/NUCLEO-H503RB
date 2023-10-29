cmake_minimum_required(VERSION 3.13)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tools")
include(arm-none-eabi-gcc)

set(PRJ_NAME nucleo-h5-fw)


project(${PRJ_NAME}
  LANGUAGES ASM C CXX
)


set(EXECUTABLE ${PRJ_NAME}.elf)


file(GLOB SRC_FILES CONFIGURE_DEPENDS
  src/*.c
  src/bsp/*.c
  src/bsp/device/*.c
)

file(GLOB_RECURSE SRC_FILES_RECURSE CONFIGURE_DEPENDS
  src/ap/*.c
  src/bsp/*.s
  src/common/*.c
  src/hw/*.c

  src/lib/STM32H5xx_HAL_Driver/Src/*.c
)

add_executable(${EXECUTABLE} 
  ${SRC_FILES}
  ${SRC_FILES_RECURSE}
)



target_include_directories(${EXECUTABLE} PRIVATE 
  src  
  src/ap
  src/ap/modules
  src/bsp
  src/bsp/device
  src/bsp/rtos
  src/common 
  src/common/core
  src/common/hw/include 
  src/hw
  src/hw/driver
  src/lib

  src/lib/CMSIS/Include
  src/lib/CMSIS/Device/ST/STM32H5xx/Include
  src/lib/STM32H5xx_HAL_Driver/Inc
)

target_compile_definitions(${EXECUTABLE} PRIVATE
  -DUSE_HAL_DRIVER
  -DSTM32H503xx
  )

target_compile_options(${EXECUTABLE} PRIVATE
  -mcpu=cortex-m33
  -mthumb
  -mfpu=fpv5-sp-d16
  -mfloat-abi=hard

  -fdata-sections
  -ffunction-sections
  -fstack-usage  
  -Wmissing-field-initializers
  -Wuninitialized 

  -Wall
  -g3
  -O0
  )

target_link_options(${EXECUTABLE} PRIVATE
  -T../src/bsp/ldscript/STM32H503CBUX_FLASH.ld
  -mcpu=cortex-m33
  -mthumb
  -mfpu=fpv5-sp-d16
  -mfloat-abi=hard
  -specs=nano.specs
  -lc
  -lm
  -lstdc++
  -lsupc++

  -Wl,-Map=${PRJ_NAME}.map,--cref
  -Wl,--gc-sections
  -Xlinker -print-memory-usage -Xlinker
  )

add_custom_command(TARGET ${EXECUTABLE} 
  POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} ARGS -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin
  COMMENT "Invoking: Make Binary"
  )  