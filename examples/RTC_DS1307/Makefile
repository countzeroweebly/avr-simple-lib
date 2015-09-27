MCU=atmega8
OBJCOPY=avr-objcopy
CC=avr-gcc
CFLAGS=-mmcu=$(MCU) -Os -DF_CPU=16000000UL -Wall -I ../../libs
LDFLAGS=-mmcu=$(MCU) -Wall -Os  -Werror
OBJ=main.o uart.o twi_hw.o
TARGET=rtc
.PHONY: all clean

%.o:	../../libs/%.c
	$(CC)  -c -o $@ $< $(CFLAGS)
all:	$(OBJ)
	$(CC) $(LDFLAGS) -o $(TARGET).elf  $(OBJ)
	$(OBJCOPY) -O ihex $(TARGET).elf $(TARGET).hex
install:
	avrdude  -p$(MCU) -carduino -P/dev/ttyUSB0 -b19200 -D -Uflash:w:./$(TARGET).hex:i
clean:
	@rm -v *.elf *.hex $(OBJ)
