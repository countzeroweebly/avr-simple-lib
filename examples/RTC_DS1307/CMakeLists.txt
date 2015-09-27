cmake_minimum_required(VERSION 2.8)
project(rtc_ds1307)
include_directories(../../libs)

set(POJECT_NAME rtc)
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_OBJCOPY avr-objcopy)
set(CMAKE_AVRDUDE avrdude)
set(CWARN "-Wall -Wstrict-prototypes")
set(CMCU "-mmcu=atmega8")
set(COPT "-Os")
set(CDEFS "-DF_CPU=16000000UL")

set(CFLAGS "${CMCU} ${CDEFS} ${COPT} ${CWARN}")
set(CMAKE_C_FLAGS ${CFLAGS})
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

set(SOURCE_EXE main.c ../../libs/uart.c ../../libs/twi_hw.c)
set(HEADER uart.h twi_hw.c)
add_executable(${PROJECT_NAME} ${SOURCE_EXE})

add_custom_target(download
        COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME} ${PROJECT_NAME}.hex
        COMMAND ${CMAKE_AVRDUDE} -patmega8 -carduino -P/dev/ttyUSB0 -b19200 -D -Uflash:w:./${PROJECT_NAME}.hex:i
        )
