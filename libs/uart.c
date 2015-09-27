#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

inline void init_uart()
{
        UBRRL=103; // bitrate 9600 on 16MHz
        UCSRB=(1<<TXEN)|(1<<RXEN)|(1<<RXCIE);
        UCSRC=(1<<URSEL)|(3<<UCSZ0);

        DDRB |= (1<<PB5); //  pinMode(13,OUTPUT);
}

void blink13(uint8_t count)
{
        PORTB |= (1<<PB5);
        count =(count <<1);count--; //count=(count*2)-1;

	uint8_t i;
	for (i=0;i<count;i++)
        {
                _delay_ms(500);
                PORTB ^= (1<<PB5);
        };
};

uint8_t uart_putchar(char c, FILE *stream)
{
	if (c == '\n')
		uart_putchar('\r', stream);
        loop_until_bit_is_set(UCSRA, UDRE);
        UDR = c;
        return 0;
}

