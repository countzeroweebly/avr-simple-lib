#include <avr/io.h>
#include <uart.h>
#include <twi_hw.h>

static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

int main(void)
{
	init_uart();
	init_twi();
        DDRB |= (1<<PB5); //  pinMode(13,OUTPUT);
        blink13(3); //ready indication

	stdout = &mystdout;
	printf("Set address rtc1307: 0x00\n");
	if (!start_i2c(RTC))
	{
		uint8_t ret; ret=send_i2c(0x00);
		stop_i2c();
		if (!ret)
			printf("Set Address success!\n");
		uint8_t k, data; k=0;
		start_i2c(RTC|READ);
		for(k=0;k<64;k++)
		{
			data=read_i2c(READ_NOEND);
			printf("address: %d value: %d\n", k,data);
		}

		stop_i2c();
	} else
	{
		stop_i2c();
		printf("Set Address failure!\n");
	}

	for (;;){};

        return 0;
}
